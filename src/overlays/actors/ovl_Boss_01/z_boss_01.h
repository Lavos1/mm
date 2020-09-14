#ifndef Z_BOSS_01_H
#define Z_BOSS_01_H

#include <global.h>

struct Boss01;

typedef void (*Boss01ActionFunc)(struct Boss01*, GlobalContext*);

typedef struct {
    Vec3f unk_00;
    Vec3f unk_0C;
    f32 unk_18;
    s16 unk_1C;
    s16 unk_1E;
    char unk20[0x8];
    u8 unk_28;
    s16 unk_2A;
    s16 unk_2C;
    s16 unk_2E;
    s16 unk_30;
    f32 unk_34;
    f32 unk_38;
} Boss01Struct1; // size = 0x3C

typedef struct Boss01 {
    /* 0x000 */ Actor actor;
    /* 0x144 */ s16 unk_144;
    /* 0x146 */ char unk_146[0x2];
    /* 0x148 */ s32 unk_148;
    /* 0x14C */ u8 unk_14C;
    /* 0x14E */ s16 unk_14E[3];
    /* 0x154 */ f32 unk_154;
    /* 0x158 */ f32 unk_158;
    /* 0x15C */ s16 unk_15C;
    /* 0x15E */ s16 unk_15E;
    /* 0x160 */ char unk160[0x1];
    /* 0x161 */ u8 unk_161;
    /* 0x162 */ u8 unk_162;
    /* 0x163 */ u8 unk_163;
    /* 0x164 */ SkelAnime skelAnime;
    /* 0x1A8 */ f32 unk_1A8;
    /* 0x1AC */ f32 unk_1AC;
    /* 0x1B0 */ f32 unk_1B0;
    /* 0x1B4 */ f32 unk_1B4;
    /* 0x1B8 */ u8 unk_1B8;
    /* 0x1B9 */ char unk_1B9[0x1];
    /* 0x1BA */ u8 unk_1BA;
    /* 0x1BB */ s8 unk_1BB;
    /* 0x1BC */ char unk1BC[0x2];
    /* 0x1BE */ s16 unk_1BE;
    /* 0x1C0 */ s8 unk_1C0;
    /* 0x1C1 */ u8 unk_1C1;
    /* 0x1C2 */ char unk1C2[0x2];
    /* 0x1C4 */ f32 unk_1C4;
    /* 0x1C8 */ f32 unk_1C8;
    /* 0x1CC */ char unk1CC[0x4];
    /* 0x1D0 */ Vec3s limbDrawTable[52];
    /* 0x308 */ Vec3s transitionDrawTable[52];
    /* 0x440 */ Vec3f unk_440[2];
    /* 0x458 */ Vec3f unk_458;
    /* 0x464 */ Boss01ActionFunc actionFunc;
    /* 0x468 */ ColSphereGroup colliderSphere1;
    /* 0x488 */ ColSphereGroupElement colliderSphere1Items[3];
    /* 0x548 */ ColSphereGroup colliderSphere2;
    /* 0x568 */ ColSphereGroupElement colliderSphere2Items[1];
    /* 0x5A8 */ ColSphereGroup colliderSphere3;
    /* 0x5C8 */ ColSphereGroupElement colliderSphere3Items[11];
    /* 0x888 */ ColSphereGroup colliderSphere4;
    /* 0x8A8 */ ColSphereGroupElement colliderSphere4Items[2];
    /* 0x928 */ Vec3f unk_928[15];
    /* 0x9DC */ u32 unk_9DC;
    /* 0x9E0 */ s16 unk_9E0;
    /* 0x9E2 */ s16 unk_9E2;
    /* 0x9E4 */ Vec3f unk_9E4;
    /* 0x9F0 */ Vec3f unk_9F0;
    /* 0x9FC */ Vec3f unk_9FC;
    /* 0xA08 */ Vec3f unk_A08;
    /* 0xA14 */ f32 unk_A14;
    /* 0xA18 */ f32 unk_A18;
    /* 0xA1C */ f32 unk_A1C;
    /* 0xA20 */ f32 unk_A20;
    /* 0xA24 */ f32 unk_A24;
    /* 0xA28 */ f32 unk_A28;
    /* 0xA2C */ ColCylinder collider1;
    /* 0xA78 */ ColCylinder collider2;
    /* 0xAC4 */ f32 unk_AC4;
    /* 0xAC8 */ f32 unk_AC8;
} Boss01; // size = 0xADC

extern const ActorInit Boss_01_InitVars;

#endif // Z_BOSS_01_H
