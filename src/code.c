#include "gba/gba.h"

extern u32 (*gSomeFuncPtr)(int code, ...);

extern void sub_020005C4();
extern u8 gUnknown_02001070[];
extern u8 gUnknown_02000D8C[];
extern u8 gUnknown_020010B4;

struct SubC0
{
    u8 filler0[0x48];
};

struct Struct10D0_child
{
    u8 unk0;
    u8 unk1;
    u16 unk2;
};

extern struct Struct10D0
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4[2];
    u8 filler6[2];
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 fillerC[0x14-0xC];
    s32 unk14;
    s32 unk18[2];
    u8 filler20[0x28-0x20];
    struct Struct10D0_child *unk28;
    void *unk2C;
    u16 *unk30[2];
    u8 filler38[8];
    u16 *unk40[4];
    u16 *unk50[4];
    void *unk60[2];
    u8 filler68[0x78-0x68];
    void *unk78[2];
    u8 filler80[0x90-0x80];
    struct SubC0 unk90[0];
    u8 filler98[0xA8-0x90];
    struct SubC0 unkA8[0];
    u8 fillerB0[0xC0-0xA8];
    struct SubC0 unkC0[0];
} gUnknown_020010D0;

// simple black and white palette
__attribute__((aligned(4)))
u16 gUnknown_02000D48[16] = { 0, 0x7FFF };

u8 gUnknown_02000D68[] = { 5, 6, 6, 7, 8, 7 };
u8 gUnknown_02000D6E[] = { 0, 0, 0, 0, 4, 0 };

void sub_02000260(void);
void sub_0200046C(void *arg0);
int sub_020004E0(u8 *arg0);
int sub_020008A4(u16 arg0);
void sub_02000980(void *arg0, u32 arg1);
void sub_020009A0(u8 arg0);

int AgbMain(void)
{
    u8 r7;
    u8 sp0[0x100];
    u8 *dest;
    u8 *src;
    u8 r4;
    u16 r4_;

    gSomeFuncPtr(0x2EA, 0x64);
    gSomeFuncPtr(0x210, 0x4E, 0);
    gSomeFuncPtr(0x27E, gUnknown_02001070, 0, 0x10);
    gSomeFuncPtr(0x27E, gUnknown_02000D48, 0x10, 0x10);
    sub_02000260();
    sub_02000980(gUnknown_02000D8C, 0x2D4);
    gSomeFuncPtr(0x2C3, sub_020005C4);
    r7 = gSomeFuncPtr(0x290, 0x101, 0x102, 0x1E03);
    gSomeFuncPtr(0x29A, r7 << 8);
    gSomeFuncPtr(0x291, r7, 0);
    gSomeFuncPtr(0x292, r7);
    gSomeFuncPtr(0x298, r7, 0x100);
    gSomeFuncPtr(0x299, r7, 0x508, "Mario vs. Donkey Kong-e");
    sp0[0] = 0x20;
    sp0[1] = 0x22;
    src = gUnknown_02000D8C + 0x10;
    dest = sp0 + 2;
    while (*src != 0)
        *dest++ = *src++;
    *dest++ = 0x22;
    *dest++ = 0;
    gSomeFuncPtr(0x299, r7, 0x510, sp0);
    r7 = gSomeFuncPtr(0x290, 0x101, 0x105, 0x1E10);
    gSomeFuncPtr(0x29A, r7 << 8);
    gSomeFuncPtr(0x291, r7, 0);
    gSomeFuncPtr(0x292, r7);
    gSomeFuncPtr(0x298, r7, 0x100);
    r4 = gSomeFuncPtr(0x290, 0x101, 0, 0x1E02);
    gSomeFuncPtr(0x29A, (r4 << 8) | 2);
    gSomeFuncPtr(0x291, r4, 0);
    gSomeFuncPtr(0x292, r4);
    gSomeFuncPtr(0x298, r4, 0x100);
    gSomeFuncPtr(0x299, r4, 0x402, "Mario vs. Donkey Kong");
    gSomeFuncPtr(0x21A, 0x10, 0x23);
    gSomeFuncPtr(0x200, 0x10);
    r4_ = 0;
    gUnknown_020010B4 = r4_;
    do
    {
        gSomeFuncPtr(0x300, 1);
        gUnknown_020010B4 = sub_020008A4(r4_);
        sub_020009A0(r7);
        r4_ = gSomeFuncPtr(0x301);
    } while (gUnknown_020010B4 == 0);
    return 2;
}

const char unusedString[] = "MultiSio010918";

const char *gStringTable[] =
{
    "Is now available.\n\n"
    "Link e-Reader to Mario vs. Donkey Kong\n"
    "and select the e-Reader card Menu\n"
    "then select ADD LEVEL to begin.\n\n"
    "Press B Button to Cancel\n",
    
    "Is now available.\n\n"
    "Link e-Reader to Mario vs. Donkey Kong\n"
    "and select the e-Reader card Menu\n"
    "then select ADD LEVEL to begin.\n\n"
    "Press B Button to Cancel\n",
    
    "Is ready to send.\n\n"
    "Press the A Button on the GBA with\n"
    "Mario vs. Donkey Kong to begin\n"
    "sending the level.",
    
    "Sending...\n\n"
    "Please DO NOT TURN OFF\n"
    "Game Boy Advance Systems or Disconnect\n"
    "the Game Boy Advance Game Link cable.",
    
    "Level has been sent!\n\n"
    "Press A Button to Resend.\n"
    "Press B Button to Cancel.",
    
    "Sending...\n\n"
    "Please DO NOT TURN OFF\n"
    "Game Boy Advance Systems or Disconnect the\n"
    "Game Boy Advance Game Link cable.",
};

void sub_02000260(void)
{
    u16 r1;
    int i;

    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;
    REG_RCNT = 0;
    *(u32 *)&REG_SIOCNT = 0x80 << 6;
    REG_SIOCNT |= 0x4003;
    CpuFill32(0, &gUnknown_020010D0, 0x48*4);
    gUnknown_020010D0.unk14 = -1;
    gUnknown_020010D0.unk28 = &gUnknown_020010D0.unk60;
    gUnknown_020010D0.unk2C = &gUnknown_020010D0.unk78;
    for (i = 0; i < 2; i++)
    {
        gUnknown_020010D0.unk30[i] = &gUnknown_020010D0.unk90[i];
        gUnknown_020010D0.unk40[i] = &gUnknown_020010D0.unkA8[i];
        gUnknown_020010D0.unk50[i] = &gUnknown_020010D0.unkC0[i];
    }
    REG_IME = 0;
    REG_IE |= 0x80;
    REG_IME = 1;
}

struct SomeBitfield
{
    u8 unk0;
    u8 filler1:6;
    u8 unk1_6:1;
};

static inline u32 someinline(void)
{
    u32 r3 = gUnknown_020010D0.unk3;
    u32 r2 = gUnknown_020010D0.unk2 << 8;
    u32 ret;

    if (gUnknown_020010D0.unk0 == 8)
        ret = 0x80 | r3 | r2;
    else
        ret = r3 | r2;
    return ret;
}

int sub_02000340(void *arg0, int arg1)
{
    u32 r5 = *(u32 *)&REG_SIOCNT;
    u32 r2_;
    u32 r1;
    u32 r0;
    register u32 temp asm("r1");

    switch (gUnknown_020010D0.unk1)
    {
    case 0:
        temp = 0x30;
        if (!(r5 & temp))
        {
            u8 r2;
            u8 r4 = r5 & 0x88;
            if (r4 != 8)
                break;
            r2 = r5 & 4;
            if (r2 == 0 && gUnknown_020010D0.unk14 == -1)
            {
                REG_IME = 0;
                REG_IE &= 0xFF7F;
                REG_IE |= 0x40;
                REG_IME = 1;
                ((struct SomeBitfield *)&REG_SIOCNT)->unk1_6 = 0;
                REG_IF = 0xC0;
                REG_TM3CNT = 0xB1FC;
                gUnknown_020010D0.unk0 = r4;
            }
        }
        gUnknown_020010D0.unk1 = 1;
        // fall through
    case 1:
        if (gUnknown_020010D0.unk2 != 0)
        {
            if (gUnknown_020010D0.unkA <= 7)
                gUnknown_020010D0.unkA++;
            else
                gUnknown_020010D0.unk1 = 2;
        }
        // fall through
    case 2:
        sub_020004E0(arg1);
        sub_0200046C(arg0);
        break;
    }
    gUnknown_020010D0.unkB++;
    r2_ = someinline();
    if (gUnknown_020010D0.unk9 != 0)
        r2_ |= 0x80 << 5;
    r1 = (gUnknown_020010D0.unkA >> 3) << 15;
    if (((r5 << 0x1A) >> 0x1E) > 1)
        r0 = r2_ | (0x80 << 6) | r1;
    else
        r0 = r2_ | r1;
    return r0;
}

void sub_0200046C(void *arg0)
{
    u32 i;
    int r5 = 0;

    gUnknown_020010D0.unk28->unk0 = gUnknown_020010D0.unkB;
    gUnknown_020010D0.unk28->unk1 = gUnknown_020010D0.unk2 ^ gUnknown_020010D0.unk3;
    gUnknown_020010D0.unk28->unk2 = 0;
    CpuCopy32(arg0, gUnknown_020010D0.unk28 + 1, 16);
    for (i = 0; i < 10; i++)
        r5 += ((u16 *)gUnknown_020010D0.unk28)[i];
    gUnknown_020010D0.unk28->unk2 = ~r5 - 12;
    if (gUnknown_020010D0.unk0 != 0)
        REG_TM3CNT_H = 0;
    gUnknown_020010D0.unk14 = -1;
    if (gUnknown_020010D0.unk0 != 0 && gUnknown_020010D0.unk8 != 0)
        REG_TM3CNT_H = 0xC0;
}

int sub_020004E0(u8 *arg0)
{
    int i;
    u32 j;
    volatile int unused = 0;
    u8 sp4[4];

    REG_IME = 0;
    for (i = 0; i < 4; i++)
    {
        void *r1 = gUnknown_020010D0.unk50[i];
        gUnknown_020010D0.unk50[i] = gUnknown_020010D0.unk40[i];
        gUnknown_020010D0.unk40[i] = r1;
    }
    *(u32 *)sp4 = *(u32 *)gUnknown_020010D0.unk4;
    *(u32 *)gUnknown_020010D0.unk4 = 0;
    REG_IME = 1;
    gUnknown_020010D0.unk3 = 0;
    for (i = 0; i < 2; i++)
    {
        int r3 = 0;

        for (j = 0; j < 10; j++)
            r3 += gUnknown_020010D0.unk50[i][j];
        if (sp4[i] != 0 && (s16)r3 == -13)
        {
            CpuCopy32(gUnknown_020010D0.unk50[i] + 2, arg0 + i * 16, 16);
            gUnknown_020010D0.unk3 |= 1 << i;
        }
        CpuFill32(0, gUnknown_020010D0.unk50[i] + 2, 16);
    }

    gUnknown_020010D0.unk2 |= gUnknown_020010D0.unk3;
    return gUnknown_020010D0.unk3;
}

void sub_020005C4(void)
{
    u16 sp0[4];
    int i;
    u16 *r3;

    *(u64 *)sp0 = *(u64 *)&REG_SIOMULTI0;  // Well, I guess that's one way to copy it!

    gUnknown_020010D0.unk9 = (*(u32 *)&REG_SIOCNT << 0x19) >> 0x1F;
    r3 = &REG_SIOCNT;
    if (gUnknown_020010D0.unk14 == -1)
    {
        void *temp;
        register u32 r0 asm("r0");

        r0 = 0xFEFE;
        r3[1] = r0;
        temp = gUnknown_020010D0.unk2C;
        gUnknown_020010D0.unk2C = gUnknown_020010D0.unk28;
        gUnknown_020010D0.unk28 = temp;
    }
    else if (gUnknown_020010D0.unk14 >= 0)
    {
        r3[1] = ((u16 *)gUnknown_020010D0.unk2C)[gUnknown_020010D0.unk14];
    }
    if (gUnknown_020010D0.unk14 < 11)
        gUnknown_020010D0.unk14++;
    for (i = 0; i < 2; i++)
    {
        if (sp0[i] == 0xFEFE && gUnknown_020010D0.unk18[i] > 9)
            gUnknown_020010D0.unk18[i] = -1;
        else
        {
            gUnknown_020010D0.unk30[i][gUnknown_020010D0.unk18[i]] = sp0[i];
            if (gUnknown_020010D0.unk18[i] == 9)
            {
                void *r1 = gUnknown_020010D0.unk40[i];
                gUnknown_020010D0.unk40[i] = gUnknown_020010D0.unk30[i];
                gUnknown_020010D0.unk30[i] = r1;
                gUnknown_020010D0.unk4[i] = 1;
            }
        }
        if (gUnknown_020010D0.unk18[i] < 11)
            gUnknown_020010D0.unk18[i]++;
    }
    if (gUnknown_020010D0.unk0 == 8)
    {
        REG_TM3CNT_H = 0;
        REG_SIOCNT |= 0x80;
        REG_TM3CNT_H = 0xC0;
    }
}

void sub_020006D8(void)
{
    if (gUnknown_020010D0.unk0 != 0)
        gUnknown_020010D0.unk8 = 1;
}

void sub_020006F0(void)
{
    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;

    REG_SIOCNT = 0x2003;
    REG_TM3CNT = 0xB1FC;
    REG_IF = 0xC0;
    gUnknown_020010D0.unk8 = 0;
}

void sub_02000740(void)
{
    gUnknown_020010D0.unk1 = 0;
}

extern struct
{
    u32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 filler7[1];
    u8 unk8[1];
    u8 filler9[0x10-0x9];
    u8 filler10;
    u8 filler11[3];
    u8 unk14;
    u8 unk15;
    u8 filler16[0x34-0x16];
    u32 unk34;
    u8 *unk38;
    s32 unk3C;
    u32 unk40;
    s32 unk44;
    u32 unk48;
    u32 unk4C;
} gUnknown_020011F0;

void sub_0200074C(int unused)
{
    int r5;
    int r6;
    int r4;

    gUnknown_020011F0.unk4 = gUnknown_02000D68[gUnknown_020011F0.unk34];
    if (gUnknown_020011F0.unk34 == 3)
    {
        r5 = 12;
        r6 = gUnknown_020011F0.unk15;
        r4 = r5 * r6;
        if (r4 >= gUnknown_020011F0.unk3C)
        {
            r6 = gUnknown_020011F0.unk40;
            r5 = 0;
            gUnknown_020011F0.unk4 = 4;
            gUnknown_020011F0.unk34 = 4;
            gSomeFuncPtr(0x105, 3);
        }
        else if (r4 + 12 >= gUnknown_020011F0.unk3C)
        {
            r5 = gUnknown_020011F0.unk3C - r4;
            gUnknown_020011F0.unk4 = 4;
            gUnknown_020011F0.unk34 = 4;
            gSomeFuncPtr(0x105, 3);
        }
        if (r5 > 0)
            CpuCopy16(gUnknown_020011F0.unk38 + r4, gUnknown_020011F0.unk8, r5);
        gUnknown_020011F0.unk5 = r6;
        gUnknown_020011F0.unk6 = r5;
    }
}

int sub_020007E0(int unused)
{
    u32 r2 = gUnknown_020011F0.unk14;

    switch (gUnknown_020011F0.unk34)
    {
    default:
    case 0:
        if (r2 == 1)
            gUnknown_020011F0.unk34 = r2;
        else if (r2 == 2)
            gUnknown_020011F0.unk34 = r2;
        break;
    case 1:
        if (r2 == 2)
        {
            gUnknown_020011F0.unk34 = r2;
            gSomeFuncPtr(0x105, 11);
        }
        break;
    case 2:
        gUnknown_020011F0.unk48++;
        if (r2 == 3)
        {
            gUnknown_020011F0.unk34 = r2;
            gSomeFuncPtr(0x105, 2);
        }
        else if (r2 == 1)
            gUnknown_020011F0.unk34 = r2;
        break;
    case 3:
        gUnknown_020011F0.unk4C = 1;
        if (r2 == 4)
        {
            gUnknown_020011F0.unk34 = r2;
            gSomeFuncPtr(0x105, 3);
        }
        else if (r2 != 3)
            gUnknown_020011F0.unk34 = 5;
        break;
    case 4:
        break;
    case 5:
        if (r2 == 4)
        {
            gUnknown_020011F0.unk34 = r2;
            gSomeFuncPtr(0x105, 3);
        }
        else if (r2 == 3)
            gUnknown_020011F0.unk34 = r2;
        break;
    }
    return 0;
}

int sub_020008A4(u16 arg0)
{
    if ((arg0 & 2) && (gUnknown_020011F0.unk34 < 2 || gUnknown_020011F0.unk34 == 4))
    {
        gSomeFuncPtr(0x105, 6);
        return 1;
    }
    if ((arg0 & 1) && gUnknown_020011F0.unk34 == 4)
    {
        gUnknown_020011F0.unk34 = 0;
        gSomeFuncPtr(0x105, 5);
    }
    sub_0200074C(arg0);
    gUnknown_020011F0.unk0 = sub_02000340(&gUnknown_020011F0.unk4, &gUnknown_020011F0.unk14);
    if (gUnknown_020011F0.unk0 & 0x3000)
    {
        gUnknown_020011F0.unk44 = 60;
        gUnknown_020011F0.unk34 = gUnknown_02000D6E[gUnknown_020011F0.unk34];
        return 0;
    }
    if (gUnknown_020011F0.unk0 != 0)
    {
        if ((gUnknown_020011F0.unk0 & 0xF) == ((gUnknown_020011F0.unk0 >> 8) & 0xF))
        {
            sub_020007E0(arg0);
            gUnknown_020011F0.unk44 = 0;
            return 0;
        }
        if (gUnknown_020011F0.unk44 < 60)
            gUnknown_020011F0.unk44++;
        else
            gUnknown_020011F0.unk34 = gUnknown_02000D6E[gUnknown_020011F0.unk34];
    }
    return 0;
}

void sub_02000980(void *arg0, u32 arg1)
{
    gUnknown_020011F0.unk34 = 0;
    gUnknown_020011F0.unk38 = arg0;
    gUnknown_020011F0.unk3C = arg1;
    gUnknown_020011F0.unk40 = arg1 / 12;
}

extern u32 gUnknown_02001060;

void sub_020009A0(u8 arg0)
{
    u32 r5 = gStringTable[gUnknown_020011F0.unk34];
    
    if (gUnknown_02001060 != r5)
    {
        gUnknown_02001060 = r5;
        gSomeFuncPtr(0x292, arg0);
        gSomeFuncPtr(0x299, arg0, 0x500, r5);
    }
}

void CpuSet(const void *src, void *dest, u32 control)
{
    asm("svc #11");
}
