#include "DRIVER.HXX"

extern "C"
{
    PULONG            mbox_handle = NULL;
    __declspec(align(16)) volatile PULONG
                      mbox_packet = NULL;

    ULONG_PTR         dev_framebuffer1 = 0x00000000;
    UINT32            dev_pitchspace1 = 0x00000000;
    UINT32            dev_width1 = 0x00000000;
    UINT32            dev_height1 = 0x00000000;

    ULONG_PTR         dev_framebuffer2 = 0x00000000;
    UINT32            dev_pitchspace2 = 0x00000000;
    UINT32            dev_width2 = 0x00000000;
    UINT32            dev_height2 = 0x00000000;

    volatile UINT32   t1 = 0;
    volatile UINT32   t2 = 0;
    volatile UINT32   t3 = 0;
}

//=====================[MMIO port from PiX-iES]=====================

void mbox_mmio_setup()
{
    debug("[CALL]: void mbox_mmio_setup");
    PHYSICAL_ADDRESS base = { 0 };
    PHYSICAL_ADDRESS lowest = { 0 };
    PHYSICAL_ADDRESS highest = { 0 };

    // Map Mailbox Handle
    base.QuadPart = MBOX_BASE;
    mbox_handle = (PULONG)MmMapIoSpace(base, MBOX_SIZE, MmNonCached);
    if (!mbox_handle) { debug("[WARN]: Failed to Memory-Map Mailbox"); return; }

    // Map Mailbox Packet
    highest.QuadPart = MBOX_MAX;
    mbox_packet = (PULONG)MmAllocateContiguousMemory(MBOX_MTU, highest);
    if (!mbox_packet) { debug("[WARN]: Failed to Memory-Map Mailbox Packet"); MmUnmapIoSpace(mbox_handle, MBOX_SIZE); return; }
    for (size_t i = 0; i < (MBOX_MTU / 4); ++i) { mbox_packet[i] = 0; }
}

void mbox_mmio_cleanup()
{
    debug("[CALL]: void mbox_mmio_cleanup"); // Same sequence as Map but in reverse
    if (mbox_packet)
    {
        MmFreeContiguousMemory(mbox_packet);
        mbox_packet = NULL;
    }
    if (mbox_handle)
    {
        MmUnmapIoSpace(mbox_handle, MBOX_SIZE);
        mbox_handle = NULL;
    }
}

//==================[Implementation from PiX-iES]===================

UINT32 mbox_setup(BYTE channel)
{
    debug("[CALL]: UINT32 mbox_setup");
    if ((!mbox_handle) || (!mbox_packet)) { debug("[MBOX]: Lock-up in Sector 7G"); return MBOX_FAILURE; }

    UINT32 checked = 0;
    UINT32 mail = (((UINT32)MmGetPhysicalAddress(mbox_packet).QuadPart) & ~0xF) | (channel & 0xF); // 0xF reserved for 4-bit channel // <--Needs to be a physical address so the VC knows where it is
    debug("[MBOX]: physical = 0x%016llX", MmGetPhysicalAddress(mbox_packet).QuadPart);
    debug("[MBOX]: mail = 0x%08lX", mail);

    t1 = 0;
    t2 = 0;
    t3 = 0;

    for (size_t i = 0; i <= MBOX_CONFIG; ++i) { mmio_write(mbox_handle, i, 0x0); }
    mmio_write(mbox_handle, MBOX_CONFIG, MBOX_DEFCONFIG);
    mmio_write(mbox_handle, MBOX_READ, 0x0);

    while ((mbox_peek() & MBOX_FULL) != 0)
    {
        KeStallExecutionProcessor(MBOX_TIMEOUT);
        ++t1; if (t1 >= MBOX_RETRIES) { break; } //{ goto failure; }
    }

    mbox_write(mail);
    for (size_t i = 0; i < (MBOX_SIZE / 4); ++i)
    {
        debug("[MBOX]: mbox_handle[%llu] | Address: 0x%016llX | Value: 0x%08lX",
            i, MmGetPhysicalAddress(mbox_handle + i).QuadPart, mmio_read(mbox_handle, i));
    }

    while (1)
    {
        KeStallExecutionProcessor(MBOX_TIMEOUT);
        while ((mbox_peek() & MBOX_EMPTY) != 0)
        {
            KeStallExecutionProcessor(MBOX_TIMEOUT);
            ++t2; if (t2 >= MBOX_RETRIES) { goto failure; }
        }

        checked = mbox_read();
        if (mail == checked)
        {
            if (mbox_packet[1] & MBOX_SUCCESS) { goto success; }
            else { debug("[WARN]: Malformed Status Code: 0x%08lX", mbox_packet[1]); mbox_write(mail); }
        }
        ++t3; if (t3 >= MBOX_RETRIES) { goto failure; }
    }

failure:
    for (size_t j = 0; j < mbox_packet[0] / 4; ++j) { debug("[MBOX]: mbox_packet[%llu] = 0x%08lX", j, mbox_packet[j]); }
    debug("[INFO]: t1 = %d, t2 = %d, t3 = %d", t1, t2, t3);
    return MBOX_FAILURE;
success:
    return MBOX_SUCCESS;
}

UINT32 mbox_get_num_displays()
{
    debug("[CALL]: UINT32 mbox_get_num_displays");
    UINT32 i = 1;
    UINT32 a = 0;
    mbox_packet[i++] = MBOX_REQUEST; // Mailbox Request

    mbox_packet[i++] = 0x00040013;   // MBOX_TAG_GET_DISPLAY_NUM
    mbox_packet[i++] = 4;            // Data Length (bytes)
    mbox_packet[i++] = 4;            // Data Length (again)
    a = i; mbox_packet[i++] = 0;     // Value

    mbox_packet[i++] = 0;            // End Mark
    mbox_packet[0] = i * 4;          // Update Packet Size

    if (MBOX_SUCCESS == mbox_setup(8)) { return mbox_packet[a]; }
    else { return 0; }
}

void mbox_set_display(UINT32 display)
{
    debug("[CALL]: void mbox_set_display");
    UINT32 i = 1;
    mbox_packet[i++] = MBOX_REQUEST; // Mailbox Request

    mbox_packet[i++] = 0x00048013;   // MBOX_TAG_SET_DISPLAY_NUM
    mbox_packet[i++] = 4;            // Data Length (bytes)
    mbox_packet[i++] = 4;            // Data Length (again)
    mbox_packet[i++] = display;      // Value

    mbox_packet[i++] = 0;            // End Mark
    mbox_packet[0] = i * 4;          // Update Packet Size

    if (MBOX_SUCCESS != mbox_setup(8)) { debug("[WARN]: Mailbox Transaction Error"); }
}

BOOLEAN mbox_get_display_info()
{
    debug("[CALL]: BOOLEAN mbox_get_display_info");
    UINT32 i = 1;
    UINT32 a = 0;
    //UINT32 b = 0;

    mbox_set_display(1);
    mbox_packet[i++] = MBOX_REQUEST; // Mailbox Request Header

    mbox_packet[i++] = 0x00048003;   // MBOX_TAG_SET_FB_PGEOM
    mbox_packet[i++] = 8;            // Data Length (bytes)
    mbox_packet[i++] = 8;            // Data Length (again)
    mbox_packet[i++] = dev_width2;   // Value // <-- TEMPORARY SOLUTION
    mbox_packet[i++] = dev_height2;  // Value // <-- TEMPORARY SOLUTION
/*
    mbox_packet[i++] = 0x00048004;   // MBOX_TAG_SET_FB_VGEOM
    mbox_packet[i++] = 8;            // Data Length (bytes)
    mbox_packet[i++] = 8;            // Data Length (again)
    mbox_packet[i++] = dev_width2;   // Value // <-- TEMPORARY SOLUTION
    mbox_packet[i++] = dev_height2;  // Value // <-- TEMPORARY SOLUTION
*/
    mbox_packet[i++] = 0x00040001;   // MBOX_TAG_ALLOC_FB
    mbox_packet[i++] = 8;            // Data Length (bytes)
    mbox_packet[i++] = 8;            // Data Length (again)
a=i;mbox_packet[i++] = 32;           // Value // Alignment
    mbox_packet[i++] = 0;            // Value
/*
    mbox_packet[i++] = 0x00040008;   // MBOX_TAG_GET_FB_LINELENGTH
    mbox_packet[i++] = 4;            // Data Length (bytes)
    mbox_packet[i++] = 4;            // Data Length (again)
b=i;mbox_packet[i++] = 0;            // Value
*/
    mbox_packet[i++] = 0;            // End Mark
    mbox_packet[0] = i * 4;          // Update Packet Size

    if (MBOX_SUCCESS == mbox_setup(8))
    {
        dev_framebuffer2 = mbox_packet[a] & 0x3FFFFFFF; // Translate from VC to ARM address
        //dev_pitchspace2 = mbox_packet[b];
        //debug("[MBOX]: dev_framebuffer2 = 0x%016llX", dev_framebuffer2);
        //debug("[MBOX]: dev_pitchspace2 = 0x%016llX", dev_pitchspace2);
        return TRUE;
    }
    return FALSE;
}

//==================================================================