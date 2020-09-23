#ifndef Z_BOSS_02_H
#define Z_BOSS_02_H

#include <global.h>

struct Boss02;

typedef void (*Boss02ActionFunc)(struct Boss02*, GlobalContext*);

typedef struct {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ char unk_18[0x4];
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ char unk_20[0x4];
    /* 0x24 */ u8 unk_24;
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ char unk_28[0x4];
    /* 0x2C */ s16 unk_2C;
    /* 0x2E */ s16 unk_2E;
    /* 0x30 */ s16 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
} Boss02Effects; // size = 0x3C

typedef struct Boss02 {
    /* 0x0000 */ Actor actor;
    /* 0x0144 */ u8 unk_0144;
    /* 0x0146 */ s16 unk_0146;
    /* 0x0148 */ char unk_0148[0x4];
    /* 0x014C */ s16 unk_014C;
    /* 0x014E */ char unk_014E[0x2];
    /* 0x0150 */ s16 unk_0150;
    /* 0x0152 */ char unk_0152[0x42];
    /* 0x0194 */ u8 unk_0194;
    /* 0x0195 */ char unk_0195[0x13];
    /* 0x01A8 */ f32 unk_01A8;
    /* 0x01AC */ f32 unk_01AC;
    /* 0x01B0 */ char unk_01B0[0xC];
    /* 0x01BC */ Vec3f unk_01BC[200];
    /* 0x0B1C */ char unk_0B1C[0x960];
    /* 0x147C */ Vec3f unk_147C[23];
    /* 0x1590 */ SkelAnime skelAnime;
    /* 0x15D4 */ Vec3s limbDrawTable[13];
    /* 0x1622 */ Vec3s transitionDrawTable[13];
    /* 0x1670 */ Boss02ActionFunc actionFunc;
    /* 0x1674 */ struct Boss02* unk_1674; // points to the other's instance
    /* 0x1678 */ s32 unk_1678;
    /* 0x167C */ char unk_167C[0xC];
    /* 0x1688 */ ColSphereGroup colliderSphere1;
    /* 0x16A8 */ ColSphereGroupElement colliderSphere1Items[22];
    /* 0x1C28 */ ColSphereGroup colliderSphere2;
    /* 0x1C48 */ ColSphereGroupElement colliderSphere2Items[2];
    /* 0x1CC8 */ ColCylinder colliderCylinder;
    /* 0x1D14 */ char unk_1D14[0x8];
    /* 0x1D1C */ u32 unk_1D1C;
    /* 0x1D20 */ s16 unk_1D20;
    /* 0x1D22 */ s16 unk_1D22;
    /* 0x1D24 */ Vec3f unk_1D24;
    /* 0x1D30 */ Vec3f unk_1D30;
    /* 0x1D3C */ f32 unk_1D3C;
    /* 0x1D40 */ f32 unk_1D40;
    /* 0x1D44 */ f32 unk_1D44;
    /* 0x1D48 */ Vec3f unk_1D48;
    /* 0x1D54 */ char unk_1D54[0x8];
    /* 0x1D5C */ f32 unk_1D5C;
    /* 0x1D60 */ char unk_1D60[0x10];
    /* 0x1D70 */ f32 unk_1D70;
    /* 0x1D74 */ f32 unk_1D74;
    /* 0x1D78 */ char unk_1D78[0x4];
    /* 0x1D7C */ s16 unk_1D7C;
    /* 0x1D7E */ s16 unk_1D7E;
} Boss02; // size = 0x1D80

extern const ActorInit Boss_02_InitVars;

#endif // Z_BOSS_02_H
