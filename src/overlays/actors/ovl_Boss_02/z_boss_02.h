#ifndef Z_BOSS_02_H
#define Z_BOSS_02_H

#include <global.h>

struct Boss02;

typedef struct {
    /* 0x0000 */ char unk_00[0x1];
} Boss02Effects; // size = ?

typedef struct Boss02 {
    /* 0x0000 */ Actor actor;
    /* 0x0144 */ char unk_0144[0x8];
    /* 0x014C */ s16 unk_014C;
    /* 0x014E */ char unk_014E[0x5E];
    /* 0x01AC */ f32 unk_01AC;
    /* 0x01B0 */ char unk_01B0[0xC];
    /* 0x01BC */ Vec3f unk_01BC[200];
    /* 0x0B1C */ char unk_0B1C[0xA74];
    /* 0x1590 */ SkelAnime skelAnime;
    /* 0x15D4 */ Vec3s limbDrawTable[13];
    /* 0x1622 */ Vec3s transitionDrawTable[13];
    /* 0x1670 */ char unk_1670[0x4];
    /* 0x1674 */ struct Boss02* unk_1674; // points to the other's instance
    /* 0x1678 */ s32 unk_1678;
    /* 0x167C */ char unk_167C[0xC];
    /* 0x1688 */ ColSphereGroup colliderSphere1;
    /* 0x16A8 */ ColSphereGroupElement colliderSphere1Items[22];
    /* 0x1C28 */ ColSphereGroup colliderSphere2;
    /* 0x1C48 */ ColSphereGroupElement colliderSphere2Items[2];
    /* 0x1CC8 */ ColCylinder colliderCylinder;
    /* 0x1D14 */ char unk_1D14[0xC];
    /* 0x1D20 */ s16 unk_1D20;
    /* 0x1D22 */ char unk_1D22[0x1A];
    /* 0x1D3C */ f32 unk_1D3C;
    /* 0x1D40 */ f32 unk_1D40;
    /* 0x1D44 */ f32 unk_1D44;
    /* 0x1D48 */ char unk_1D48[0x28];
    /* 0x1D70 */ f32 unk_1D70;
} Boss02; // size = 0x1D80

extern const ActorInit Boss_02_InitVars;

#endif // Z_BOSS_02_H
