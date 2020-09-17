#include "z_boss_01.h"
#include "overlays/actors/ovl_En_Tanron1/z_en_tanron1.h"

#define FLAGS 0x00000035

#define THIS ((Boss01*)thisx)

void Boss01_Init(Actor* thisx, GameState* gameState);
void Boss01_Destroy(Actor* thisx, GameState* gameState);
void Boss01_Update(Actor* thisx, GameState* gameState);
void Boss01_Draw(Actor* thisx, GameState* gameState);

void func_809D694C(Actor* thisx, GlobalContext* globalCtx);
void func_809D6BB4(Actor* thisx, GlobalContext* globalCtx);
void func_809D5B0C(Actor* thisx, GlobalContext* globalCtx);

void func_809D1EA4(Boss01* this, GlobalContext* globalCtx, u8 arg2);
void func_809D2A44(Boss01* this, GlobalContext* globalCtx, u8 arg2);

void func_809D5FB4(u8* texture, Boss01* this, GlobalContext* globalCtx);
void func_809D606C(u8* texture, Boss01* this, GlobalContext* globalCtx);
void func_809D73D4(GlobalContext* globalCtx);

void func_809D65E0(Boss01* this, GlobalContext* globalCtx);
void func_809D62D4(Boss01* this, GlobalContext* globalCtx);
void func_809D1258(Boss01* this, GlobalContext* globalCtx);
void func_809D6588(Boss01* this, GlobalContext* globalCtx);
void func_809D6488(Boss01* this, GlobalContext* globalCtx);
void func_809D64E0(Boss01* this, GlobalContext* globalCtx);
void func_809D3A7C(Boss01* this, GlobalContext* globalCtx);
void func_809D20D0(Boss01* this, GlobalContext* globalCtx);
void func_809D1B2C(Boss01* this, GlobalContext* globalCtx);
void func_809D6314(Boss01* this, GlobalContext* globalCtx);
void func_809D12B4(Boss01* this, GlobalContext* globalCtx);
void func_809D3ADC(Boss01* this, GlobalContext* globalCtx);
void func_809D2858(Boss01* this, GlobalContext* globalCtx);
void func_809D2AA0(Boss01* this, GlobalContext* globalCtx);
void func_809D2914(Boss01* this, GlobalContext* globalCtx);
void func_809D2BCC(Boss01* this, GlobalContext* globalCtx);
void func_809D2CDC(Boss01* this, GlobalContext* globalCtx);
void func_809D2780(Boss01* this, GlobalContext* globalCtx);
void func_809D3074(Boss01* this, GlobalContext* globalCtx);
void func_809D34D4(Boss01* this, GlobalContext* globalCtx);
void func_809D3400(Boss01* this, GlobalContext* globalCtx);
void func_809D2664(Boss01* this, GlobalContext* globalCtx);
void func_809D2DE8(Boss01* this, GlobalContext* globalCtx);
void func_809D27D4(Boss01* this, GlobalContext* globalCtx);
void func_809D30D0(Boss01* this, GlobalContext* globalCtx);
void func_809D3530(Boss01* this, GlobalContext* globalCtx);
void func_809D345C(Boss01* this, GlobalContext* globalCtx);
void func_809D26B8(Boss01* this, GlobalContext* globalCtx);
void func_809D2E4C(Boss01* this, GlobalContext* globalCtx);
void func_809D6E7C(Boss01* this, GlobalContext* globalCtx);
void func_809D441C(Boss01* this, GlobalContext* globalCtx);
void func_809D3C10(Boss01* this, GlobalContext* globalCtx);
void func_809D3CD0(Boss01* this, GlobalContext* globalCtx);
void func_809D365C(Boss01* this, GlobalContext* globalCtx);
void func_809D25E8(Boss01* this, GlobalContext* globalCtx);
void func_809D4464(Boss01* this, GlobalContext* globalCtx);
void func_809D1E5C(Boss01* this, GlobalContext* globalCtx);
void func_809D1E74(Boss01* this, GlobalContext* globalCtx);
void func_809D3374(Boss01* this, GlobalContext* globalCtx);

extern s32 D_809D8A4C;
extern s32 D_809D8A50;
extern s32 D_809D8A54;

extern SkeletonHeader D_060222D0;
extern SkeletonHeader D_0600F0A8;
extern AnimationHeader D_06022550;
extern AnimationHeader D_06018438;
extern AnimationHeader D_0601F6A4;
extern AnimationHeader D_06012D10;
extern AnimationHeader D_06012B70;
extern AnimationHeader D_06019C10;
extern AnimationHeader D_06012EBC;
extern AnimationHeader D_06016168;
extern AnimationHeader D_06013480;
extern AnimationHeader D_060204AC;
extern AnimationHeader D_06001884;
extern AnimationHeader D_06015A30;
extern AnimationHeader D_0601407C;
extern AnimationHeader D_060164CC;
extern AnimationHeader D_06000C44;
extern AnimationHeader D_0600FDEC;
extern AnimationHeader D_06014F14;
extern AnimationHeader D_060124CC;
extern AnimationHeader D_06010980;
extern AnimationHeader D_0600FF94;
extern AnimationHeader D_06010150;

extern Gfx D_06022118[];
extern Gfx D_060220A0[];
extern Gfx D_060213A8[];
extern Gfx D_0600C498[];
extern Gfx D_0600C5E0[];
extern Gfx D_0600C7A8[];
extern Gfx D_0600C7C8[];
extern Gfx D_0407D590[];
extern Gfx D_0600E3E8[];

extern Vtx D_0600C338[];
extern u8 D_0600C7F8[];
extern UNK_TYPE D_04076BC0;

static Vec3f D_809D7980 = { 0.0f, 1000.0f, 0.0f};
static f32 D_809D798C = 10.0f;

static ActorDamageChart D_809D7990 = {
    0x10, 0xF1, 0x00, 0xE1, 0xF1, 0xF1, 0x00, 0x00, 0xE1, 0xE1, 0xF1, 0x22, 0x32, 0x42, 0xF1, 0xF1,
    0x10, 0xE1, 0x10, 0xB0, 0x00, 0x00, 0xF1, 0xE1, 0xD1, 0xC2, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE1,
};

static ActorDamageChart D_809D79B0 = {
    0x10, 0xF1, 0x00, 0xF2, 0x10, 0xF2, 0x00, 0x00, 0xF1, 0xF1, 0xF1, 0x22, 0x32, 0x42, 0xF1, 0x10,
    0x10, 0xF1, 0x10, 0x10, 0x00, 0x00, 0xF1, 0xE1, 0xD2, 0xD2, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF1,
};

static ColSphereGroupElementInit sJntSphItemsInit1[3] = {
    {
        { 0x02, { 0xF7CFFFFF, 0x04, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 0, { { 0, 0, 0 }, 35 }, 100 },
    },
    {
        { 0x02, { 0xF7CFFFFF, 0x04, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 0, { { 0, 0, 0 }, 35 }, 100 },
    },
    {
        { 0x02, { 0xF7CFFFFF, 0x04, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 0, { { 0, 0, 0 }, 70 }, 100 },
    },
};

// D_809D7A3C
static ColSphereGroupInit sJntSphInit1 = {
    { COLTYPE_METAL_SHIELD, 0x11, 0x0D, 0x09, 0x10, COLSHAPE_JNTSPH },
    3,
    sJntSphItemsInit1,
};

static ColSphereGroupElementInit sJntSphItemsInit2[1] = {
    {
        { 0x02, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 0, { { 0, 0, 0 }, 36 }, 100 },
    },
};

// D_809D7A70
static ColSphereGroupInit sJntSphInit2 = {
    { COLTYPE_METAL_SHIELD, 0x11, 0x0D, 0x09, 0x10, COLSHAPE_JNTSPH },
    1,
    sJntSphItemsInit2,
};

static ColSphereGroupElementInit sJntSphItemsInit3[11] = {
    {
        { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 0, { { 0, 0, 0 }, 20 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 1, { { 0, 0, 0 }, 30 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 1, { { 0, 0, 0 }, 25 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 1, { { 0, 0, 0 }, 15 }, 100 },
    },
};

// D_809D7C0C
static ColSphereGroupInit sJntSphInit3 = {
    { COLTYPE_UNK3, 0x11, 0x09, 0x09, 0x10, COLSHAPE_JNTSPH },
    11,
    sJntSphItemsInit3,
};

static ColSphereGroupElementInit sJntSphItemsInit4[2] = {
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x09, 0x01, 0x01 },
        { 0, { { 0, 0, 0 }, 36 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x09, 0x01, 0x01 },
        { 0, { { 0, 0, 0 }, 36 }, 100 },
    },
};

// D_809D7C64
static ColSphereGroupInit sJntSphInit4 = {
    { COLTYPE_UNK3, 0x11, 0x09, 0x09, 0x10, COLSHAPE_JNTSPH },
    2,
    sJntSphItemsInit4,
};

// D_809D7C74
static ColCylinderInit sCylinderInit1 = {
    { COLTYPE_UNK3, 0x11, 0x09, 0x39, 0x10, COLSHAPE_CYLINDER },
    { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7FFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
    { 15, 15, 10, { 0, 0, 0 } },
};

// D_809D7CA0
static ColCylinderInit sCylinderInit2 = {
    { COLTYPE_UNK3, 0x11, 0x09, 0x39, 0x10, COLSHAPE_CYLINDER },
    { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7FFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
    { 8, 15, 10, { 0, 0, 0 } },
};

const ActorInit Boss_01_InitVars = {
    ACTOR_BOSS_01,
    ACTORTYPE_BOSS,
    FLAGS,
    OBJECT_BOSS01,
    sizeof(Boss01),
    (ActorFunc)Boss01_Init,
    (ActorFunc)Boss01_Destroy,
    (ActorFunc)Boss01_Update,
    (ActorFunc)Boss01_Draw,
};

ColorRGBA8 D_809D7CEC = { 60, 50, 20, 255 };
ColorRGBA8 D_809D7CF0 = { 40, 30, 30, 255 };

AnimationHeader* D_809D7CF4[] = {
    0x06018438, 0x0601AAF4, 0x0601AF18, 0x0601BA94, 0x0601C700, 0x0601CE88,
    0x0601D8C8, 0x0601E68C, 0x0601EEA8, 0x0601F6A4, 0x0601FC10, 0x060204AC,
};

f32 D_809D7D24[] = {
    0.0f, 350.0f, -350.0f, 350.0f, -350.0f,
};

f32 D_809D7D38[] = {
    0.0f, 350.0f, 350.0f, -350.0f, -350.0f,
};

Vec3f D_809D7D54 = { 0.0f, -1.0f, 0.0f };
ColorRGBA8 D_809D7D4C = { 170, 255, 255, 255 };
ColorRGBA8 D_809D7D50 = { 200, 200, 255, 255 };

u8 D_809D7D60[] = {
    0x00, 0x02, 0x04, 0x06, 0x08, 0x0A, 0x0C, 0x0E, 0x10, 0x12, 0x14,
};

u8 D_809D7D6C[] = {
    0x01, 0x03, 0x05, 0x07, 0x09, 0x0B, 0x0D, 0x0F, 0x11, 0x13, 0x15,
};

s8 D_809D7D78[] = {
    0xFF, 0xFF, 0x02, 0xFF, 0x09, 0xFF, 0x0A, 0xFF, 0xFF, 0x07, 0xFF, 0x08, 0xFF, 0xFF, 0xFF,
    0x01, 0xFF, 0x03, 0xFF, 0x04, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x05, 0xFF, 0x06, 0xFF, 0xFF,
    0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

Vec3f D_809D7DB4[] = {
    { 1300.0f, 0.0f, 0.0f }, { 1000.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f },    { 1000.0f, 0.0f, 0.0f },
    { 1000.0f, 0.0f, 0.0f }, { 1000.0f, 0.0f, 0.0f }, { 1000.0f, 0.0f, 0.0f }, { 1500.0f, 0.0f, 0.0f },
    { 1500.0f, 0.0f, 0.0f }, { 1500.0f, 0.0f, 0.0f }, { 1500.0f, 0.0f, 0.0f },
};

Vec3f D_809D7E38 = { 0.0f, 500.0f, 0.0f };
Vec3f D_809D7E44 = { 500.0f, -2500.0f, 0.0f };
Vec3f D_809D7E50 = { 1500.0f, -7000.0f, 0.0f };
Vec3f D_809D7E5C = { 5000.0f, 0.0f, 9000.0f };

s8 D_809D7E68[] = {
    0xFF, 0xFF, 0x02, 0xFF, 0x09, 0xFF, 0x0A, 0x0B, 0xFF, 0x0C, 0xFF, 0x0D, 0x0E, 0xFF, 0xFF, 0x01, 0xFF, 0x03, 0xFF,
    0x04, 0xFF, 0xFF, 0xFF, 0x05, 0xFF, 0x06, 0xFF, 0x07, 0xFF, 0xFF, 0xFF, 0x08, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
};

Vec3f D_809D7EA0 = { 10000.0f, 10000.0f, 10000.0f };

s32 D_809D7EAC[] = {
    0x00000001, 0x00000002, 0x00000003, 0x00000003, 0x00000002, 0x00000001,
};

s32 D_809D7EC4[] = {
    0x00000002, 0x00000003, 0x00000004, 0x00000004, 0x00000004, 0x00000003, 0x00000002,
};

s32 D_809D7EE0[] = {
    0x00000002, 0x00000003, 0x00000004, 0x00000004, 0x00000004, 0x00000004, 0x00000003, 0x00000002,
};

s32 D_809D7F00[] = {
    0x00000002, 0x00000004, 0x00000005, 0x00000005, 0x00000006, 0x00000006,
    0x00000006, 0x00000006, 0x00000005, 0x00000005, 0x00000004, 0x00000002,
};

s32 D_809D7F30[] = {
    0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000003, 0x00000004, 0x00000001, 0x00000006,
    0x00000007, 0x00000002, 0x00000009, 0x0000000A, 0x00000002, 0x0000000C, 0x0000000D,
};

u8 D_809D7F6C[] = {
    0x03, 0x02, 0x02, 0x01, 0x03, 0x02, 0x01, 0x03, 0x03, 0x01, 0x00, 0x03, 0x01, 0x00, 0x03,
};

s16 D_809D8A10;
Boss01* D_809D8A14;
EnTanron1* D_809D8A18;
f32 D_809D8A1C;
f32 D_809D8A20;
f32 D_809D8A24;
f32 D_809D8A28;
f32 D_809D8A2C;
f32 D_809D8A30;
f32 D_809D8A34;
u8 D_809D8A38;
Vec3f D_809D8A40;
Boss01Effect D_809D8A58[100];

void func_809D0530(s32 arg0, s32 arg1, s32 arg2) {
    D_809D8A4C = arg0;
    D_809D8A50 = arg1;
    D_809D8A54 = arg2;
}

f32 func_809D0550(void) {
    f32 rand;

    D_809D8A4C = (D_809D8A4C * 171) % 30269;
    D_809D8A50 = (D_809D8A50 * 172) % 30307;
    D_809D8A54 = (D_809D8A54 * 170) % 30323;
    rand = ((D_809D8A4C / 30269.0f) + (D_809D8A50 / 30307.0f)) + (D_809D8A54 / 30323.0f);

    while (rand >= 1.0f) {
        rand -= 1.0f;
    }
    return fabsf(rand);
}

void func_809D0678(Boss01Effect* effect, Vec3f* arg1, s16 arg2) {
    s16 i;

    for (i = 1; i < 100; i++, effect++) {
        if (effect->unk_28 == 0) {
            effect->unk_28 = 1;
            effect->unk_00 = *arg1;
            effect->unk_2A = 0;
            effect->unk_1C = randZeroOneScaled(65536.0f);
            effect->unk_1E = randZeroOneScaled(65536.0f);
            effect->unk_2C = arg2;
            effect->unk_18 = -1.0f;
            if (arg2 == 0) {
                effect->unk_30 = randPlusMinusPoint5Scaled(800.0f);
                effect->unk_2E = randPlusMinusPoint5Scaled(800.0f);
                effect->unk_34 = 0.008f;
                effect->unk_0C = D_801D15B0;
            } else {
                effect->unk_30 = randPlusMinusPoint5Scaled(8000.0f);
                effect->unk_2E = randPlusMinusPoint5Scaled(8000.0f);
                effect->unk_34 = randPlusMinusPoint5Scaled(0.0016f) + 0.0032f;
                effect->unk_0C.x = randPlusMinusPoint5Scaled(13.0f);
                effect->unk_0C.y = randZeroOneScaled(4.0f) + 7.0f;
                effect->unk_0C.z = randPlusMinusPoint5Scaled(13.0f);
            }
            break;
        }
    }
}

void func_809D082C(Boss01Effect* effect, Vec3f* pos) {
    if (effect->unk_28 == 0) {
        effect->unk_28 = 3;
        effect->unk_00 = *pos;
        effect->unk_2A = 0;
        effect->unk_0C = D_801D15B0;
        effect->unk_18 = 0.0f;
        effect->unk_34 = 0.0f;
        effect->unk_38 = 230.0f;
    }
}

void func_809D089C(s32 index, ColSphereGroup* sphereGroup, Vec3f* arg2) {
    sphereGroup->spheres[index].params.colInfo.loc.x = arg2->x;
    sphereGroup->spheres[index].params.colInfo.loc.y = arg2->y;
    sphereGroup->spheres[index].params.colInfo.loc.z = arg2->z;
    sphereGroup->spheres[index].params.colInfo.radius =
        sphereGroup->spheres[index].params.unk6 * sphereGroup->spheres[index].params.unk10;
}

void func_809D092C(Boss01* this, GlobalContext* globalCtx, u8 arg2) {
    ActorPlayer* player = PLAYER;

    if (player->base.currPosRot.pos.y > 200.0f) {
        func_809D1EA4(this, globalCtx, 0x64);
    } else if ((randZeroOne() < 0.2f) && (arg2 == 0)) {
        func_809D2780(this, globalCtx);
    } else if (this->actor.xzDistanceFromLink <= 250.0f) {
        if (this->actor.xzDistanceFromLink <= 150.0f) {
            if (randZeroOne() < 0.5f) {
                func_809D3400(this, globalCtx);
            } else {
                func_809D34D4(this, globalCtx);
            }
        } else {
            func_809D3074(this, globalCtx);
        }
    } else if (((s8)this->actor.colChkInfo.health < 8) && (randZeroOne() < 0.75f)) {
        func_809D2664(this, globalCtx);
    } else {
        func_809D2DE8(this, globalCtx);
    }
}

void func_809D0AA4(Boss01* this, GlobalContext* globalCtx, u8 arg2) {
    s32 pad;
    Vec3f spB0;
    Vec3f spA4;
    Vec3f sp98;
    u8 i;

    if ((this->unk_144 & arg2) == 0) {
        if ((this->unk_1C4 > 1.0f) || (this->unk_1C8 > 1.0f) || (arg2 == 0) || (this->actor.speedXZ > 1.0f)) {
            for (i = 0; i < 2; i++) {
                spA4.x = randPlusMinusPoint5Scaled(5.0f);
                spA4.y = randZeroOneScaled(2.0f) + 1.0f;
                spA4.z = randPlusMinusPoint5Scaled(5.0f);
                sp98.y = -0.1f;
                sp98.x = sp98.z = 0.0f;
                spB0.x = this->unk_440[i].x + randPlusMinusPoint5Scaled(20.0f);
                spB0.y = randZeroOneScaled(10.0f) + 3.0f;
                spB0.z = this->unk_440[i].z + randPlusMinusPoint5Scaled(20.0f);
                func_800B0EB0(globalCtx, &spB0, &spA4, &sp98, &D_809D7CEC, &D_809D7CF0,
                              randZeroOneScaled(150.0f) + 350.0f, 0xA, randZeroOneScaled(5.0f) + 14.0f);
            }
        }
    }
}

void Boss01_Init(Actor* thisx, GameState* gameState) {
    Boss01* this = THIS;
    GlobalContext* globalCtx = (GlobalContext*)gameState;
    s16 i;

    Actor_SetScale(&this->actor, 0.015f);
    if (this->actor.params == 0xA) {
        SkelAnime_Init(globalCtx, &this->skelAnime, &D_060222D0, &D_06022550, this->limbDrawTable,
                       this->transitionDrawTable, 21);
        this->actor.update = func_809D694C;
        this->actor.draw = func_809D6BB4;
        this->unk_14C = 1;
        func_809D62D4(this, globalCtx);
        this->actor.gravity = -2.0f;
        Collision_InitCylinder(globalCtx, &this->collider1, &this->actor, &sCylinderInit1);
        Collision_InitCylinder(globalCtx, &this->collider2, &this->actor, &sCylinderInit2);
        Actor_SetDrawParams(&this->actor.shape, 0.0f, func_800B3FC0, 12.0f);
        Actor_SetScale(&this->actor, 0.025f);
        this->actor.colChkInfo.health = 2;
        D_809D8A10++;
        func_800B8EC8(&this->actor, 0x295B);
        this->actor.colChkInfo.damageChart = &D_809D79B0;
        D_809D8A14->actor.naviEnemyId = 0x63;
    } else if (this->actor.params == 0x23) {
        SkelAnime_Init(globalCtx, &this->skelAnime, &D_0600F0A8, &D_06018438, this->limbDrawTable,
                       this->transitionDrawTable, 52);
        func_809D1E5C(this, globalCtx);
        this->unk_14E[0] = this->actor.currPosRot.rot.z;
        this->actor.currPosRot.rot.z = 0;
        this->actor.draw = func_809D5B0C;
        this->actor.flags &= ~1;
    } else {
        if (gSaveContext.perm.weekEventReg[20] & 2) {
            Actor_SpawnWithParent(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_DOOR_WARP1, 0.0f, 0.0f, 0.0f, 0,
                                  0, 0, 1);
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, 0.0f, 0.0f, 250.0f, 0, 0, 0, 0);
            Actor_MarkForDeath(&this->actor);
            return;
        }

        globalCtx->kankyoContext.unkC3 = 0;
        globalCtx->kankyoContext.unkE0 = 2;
        globalCtx->kankyoContext.unkDC = 0.0f;
        D_809D8A14 = this;
        D_809D8A10 = 0;
        globalCtx->actorEffects = D_809D8A58;

        for (i = 0; i < 100; i++) {
            D_809D8A58[i].unk_28 = 0;
        }

        this->actor.naviEnemyId = 0x5E;
        this->actor.unk1F = 5;
        this->actor.colChkInfo.mass = 0xFE;
        this->actor.colChkInfo.damageChart = &D_809D7990;
        this->actor.colChkInfo.health = 20;
        Actor_SetDrawParams(&this->actor.shape, 0.0f, NULL, 0.0f);
        Collision_InitSphereGroup(globalCtx, &this->colliderSphere1, &this->actor, &sJntSphInit1,
                                  this->colliderSphere1Items);
        Collision_InitSphereGroup(globalCtx, &this->colliderSphere2, &this->actor, &sJntSphInit2,
                                  this->colliderSphere2Items);
        Collision_InitSphereGroup(globalCtx, &this->colliderSphere3, &this->actor, &sJntSphInit3,
                                  this->colliderSphere3Items);
        Collision_InitSphereGroup(globalCtx, &this->colliderSphere4, &this->actor, &sJntSphInit4,
                                  this->colliderSphere4Items);
        SkelAnime_Init(globalCtx, &this->skelAnime, &D_0600F0A8, &D_06018438, this->limbDrawTable,
                       this->transitionDrawTable, 52);
        if ((KREG(64) != 0) || ((gSaveContext.owl.unk5 & 0x10) != 0)) {
            func_809D1EA4(this, globalCtx, 0);
            this->actor.gravity = -2.5f;
            D_809D8A38 = KREG(15) + 20;
        } else {
            func_809D1258(this, globalCtx);
        }
        D_809D8A18 = (EnTanron1*)Actor_SpawnWithParent(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_EN_TANRON1,
                                                       0.0f, 437.0f, -750.0f, 0, 0, 0, 0x100);
    }

    this->unk_154 = -2.0f;
    this->unk_158 = -4.0f;
}

void Boss01_Destroy(Actor* thisx, GameState* gameState) {
}

void func_809D119C(Boss01* this, GlobalContext* globalCtx) {
    Actor* explosive = globalCtx->actorCtx.actorList[ACTORTYPE_EXPLOSIVES].first;

    while (explosive != NULL) {
        if (sqrtf(SQ(explosive->currPosRot.pos.x - this->actor.currPosRot.pos.x) +
                  SQ(explosive->currPosRot.pos.y - this->actor.currPosRot.pos.y) +
                  SQ(explosive->currPosRot.pos.z - this->actor.currPosRot.pos.z)) < 150.0f) {
            func_809D2A44(this, globalCtx, 0);
        }
        explosive = explosive->next;
    }
}

void func_809D1258(Boss01* this, GlobalContext* globalCtx) {
    this->actionFunc = func_809D12B4;
    this->actor.currPosRot.pos.x = 0.0f;
    this->actor.currPosRot.pos.z = 0.0f;
    this->actor.gravity = 0.0f;
    this->actor.currPosRot.pos.y = 2400.0f;
    func_80137594(&this->skelAnime, &D_06012D10, 0.0f);
}

void func_809D12B4(Boss01* this, GlobalContext* globalCtx) {
    ActorPlayer* player = PLAYER;

    this->unk_9DC++;
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);

    switch (this->unk_9E0) {
        case 0:
            if (ActorCutscene_GetCurrentIndex() != -1) {
                break;
            }

            if (!(player->base.currPosRot.pos.z < 590.0f)) {
                break;
            }

            func_800EA0D4(globalCtx, &globalCtx->csCtx);
            func_800B7298(globalCtx, &this->actor, 7);
            this->unk_9E2 = func_801694DC(globalCtx);
            func_80169590(globalCtx, 0, 1);
            func_80169590(globalCtx, this->unk_9E2, 7);
            this->actor.flags &= ~1;
            this->unk_9DC = 0;
            this->unk_9E0 = 1;
            this->unk_9FC.x = 0.0;
            this->unk_9FC.y = 1.0f;
            this->unk_9FC.z = 0.0f;

        case 1:
            player->base.currPosRot.rot.y = -0x8000;
            player->base.shape.rot.y = -0x8000;
            player->base.currPosRot.pos.x = -9.0f;
            player->base.currPosRot.pos.z = 587.0f;

            this->unk_9E4.x = -9.0f;
            this->unk_9E4.y = (func_800B6FC8(player) + player->base.currPosRot.pos.y) - 24.0f;
            this->unk_9E4.z = (player->base.currPosRot.pos.z - 200.0f) + 110.0f;

            this->unk_9F0.x = player->base.currPosRot.pos.x;
            this->unk_9F0.y = (func_800B6FC8(player) + player->base.currPosRot.pos.y) - 14.0f;
            this->unk_9F0.z = player->base.currPosRot.pos.z;

            if (player->unk14B == 0) {
                this->unk_9E4.y -= 30.0f + BREG(16);
                this->unk_9F0.y -= 30.0f + BREG(17);
            }

            if (this->unk_9DC >= 0x14) {
                func_800B8EC8(&this->actor, 0x3010);
            }

            if (this->unk_9DC == 0x28) {
                func_800B7298(globalCtx, &this->actor, 0x15);
            }

            if (this->unk_9DC == 0x64) {
                func_800B7298(globalCtx, &this->actor, 4);
            }

            if (this->unk_9DC >= 0x5A) {
                play_sound(0x3008);
            }

            if (this->unk_9DC == 0x78) {
                this->actor.currPosRot.pos.y = 1500.0f;
                this->actor.gravity = -2.5f;
                this->unk_9E0 = 2;
                this->unk_9DC = 0;

                func_80137488(&this->skelAnime, &D_06012EBC, 0.0f);

                this->unk_9E4.x = this->actor.currPosRot.pos.x;
                this->unk_9F0.x = this->actor.currPosRot.pos.x;
                this->unk_9F0.y = 80.0f;
                this->unk_9E4.y = 30.0f;
                this->unk_9E4.z = ((this->actor.currPosRot.pos.z + 200.0f) + 50.0f) - 150.0f;
                this->unk_9F0.z = this->actor.currPosRot.pos.z;
                this->unk_9FC.x = 2.0f;
            }
            break;

        case 2:
            func_800B8EC8(&this->actor, 0x3010);
            Math_SmoothDownscaleMaxF(&this->unk_9FC.x, 0.1f, 0.1f);
            play_sound(0x3008);
            this->unk_1C0 = 2;
            Math_SmoothScaleMaxF(&this->unk_9F0.y, this->actor.currPosRot.pos.y + 80.0f, 0.25f, 30.0f);
            if (this->actor.currPosRot.pos.y < 40.0f) {
                func_80137488(&this->skelAnime, &D_06012D10, -2.0f);
                this->unk_9E0 = 3;
                this->unk_9DC = 0;
            }
            break;

        case 3:
            if (this->unk_9DC < 0x33) {
                func_800B8EC8(&this->actor, 0x3010);
            }

            if ((this->unk_9DC == 1) || (this->unk_9DC == 3)) {
                u8 i;

                for (i = 0; i < 10; i++) {
                    func_809D0AA4(this, globalCtx, 0);
                }
                play_sound(0x380C);
                func_8013EC44(0.0f, 0xC8, 0x14, 0x14);
                this->unk_A28 = 10.0f;
            }

            if (this->unk_9DC == 5) {
                func_80137594(&this->skelAnime, &D_06019C10, -20.0f);
            }

            if ((this->unk_9DC >= 6) &&
                ((func_801378B8(&this->skelAnime, 30.0f) != 0) || (func_801378B8(&this->skelAnime, 54.0f) != 0))) {
                func_800B8EC8(&this->actor, 0x3811);
            }

            if (this->unk_9DC < 0x1E) {
                Math_SmoothScaleMaxF(&this->unk_9F0.y, this->actor.currPosRot.pos.y + 80.0f, 0.25f, 1000.0f);
            } else {
                Math_SmoothScaleMaxF(&this->unk_9E4.x, this->actor.currPosRot.pos.x + 70.0f, 0.05f,
                                     this->unk_A1C * 70.0f);
                Math_SmoothScaleMaxF(&this->unk_9E4.y, 200.0f, 0.05f, this->unk_A1C * 170.0f);
                Math_SmoothScaleMaxF(&this->unk_9E4.z, ((this->actor.currPosRot.pos.z + 200.0f) + 50.0f) - 30.0f, 0.05f,
                                     this->unk_A1C * 120.0f);
                Math_SmoothScaleMaxF(&this->unk_9F0.y, (this->actor.currPosRot.pos.y + 80.0f) + 20.0f, 0.05f,
                                     this->unk_A1C * 20.0f);
                Math_SmoothScaleMaxF(&this->unk_A1C, 1.0f, 1.0f, 0.001f);
            }

            if (this->unk_9DC == 0x14) {
                func_801A89A8(0x801B);
            }

            if (this->unk_9DC == 0x32) {
                Actor_TitleCardCreate(globalCtx, &globalCtx->actorCtx.titleCtxt, Lib_PtrSegToVirt(D_0600C7F8), 0xA0,
                                      0xB4, 0x80, 0x28);
            }

            if (this->unk_9DC == 0x8C) {
                Camera* camera = Play_GetCamera(globalCtx, 0);
                this->unk_9E0 = 0;
                this->unk_148 = 0;
                func_809D1EA4(this, globalCtx, 0);
                camera->eye = this->unk_9E4;
                camera->unk74 = this->unk_9E4;
                camera->focalPoint = this->unk_9F0;
                func_80169AFC(globalCtx, this->unk_9E2, 0);
                this->unk_9E2 = 0;
                func_800EA0EC(globalCtx, &globalCtx->csCtx);
                func_800B7298(globalCtx, &this->actor, 6);
                this->actor.flags |= 1;
                gSaveContext.owl.unk5 |= 0x10;
            }
            break;
    }

    if (this->unk_9E2 != 0) {
        Vec3f sp40;

        ShrinkWindow_SetLetterboxTarget(0x1B);
        this->unk_A24 = Math_Coss(globalCtx->unk18840 * 0x8000) * this->unk_A28;
        Math_SmoothDownscaleMaxF(&this->unk_A28, 1.0f, 0.75f);
        sp40 = this->unk_9F0;
        sp40.y += this->unk_A24;
        func_8016981C(globalCtx, this->unk_9E2, &sp40, &this->unk_9E4, &this->unk_9FC);
    }
}

void func_809D1AB8(Boss01* this, GlobalContext* globalCtx) {
    this->actionFunc = func_809D1B2C;
    func_80137594(&this->skelAnime, &D_0601F6A4, -10.0f);
    this->unk_9E0 = 0;
    this->unk_9DC = 0;
    this->unk_1C1++;
    this->unk_1BE = 0x1E;
    this->actor.speedXZ = 0.0f;
    this->unk_1C8 = 0.0f;
    this->unk_1C4 = 0.0f;
}

void func_809D1B2C(Boss01* this, GlobalContext* globalCtx) {
    ActorPlayer* player = PLAYER;
    Vec3f sp60;
    f32 sp5C;
    s32 pad;
    f32 sp54;

    this->unk_9DC++;
    this->unk_1BE = 0x1E;
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    switch (this->unk_9E0) {
        case 0:
            if (ActorCutscene_GetCurrentIndex() != -1) {
                break;
            }

            func_800EA0D4(globalCtx, &globalCtx->csCtx);
            func_800B7298(globalCtx, &this->actor, 7);
            this->unk_9E2 = func_801694DC(globalCtx);
            func_80169590(globalCtx, 0, 1);
            func_80169590(globalCtx, this->unk_9E2, 7);
            this->actor.flags &= ~1;
            this->unk_9E0 = 1;
            this->actor.shape.rot.y = 0;
            this->actor.currPosRot.pos.z = 0.0f;
            this->actor.currPosRot.pos.x = 0.0f;
            this->unk_A1C = 0.0f;
            this->unk_A08.y = 100.0f;

        case 1:
            func_800B8EC8(&this->actor, 0x3015);
            SysMatrix_InsertYRotation_s(this->actor.shape.rot.y, 0);
            SysMatrix_GetStateTranslationAndScaledZ(250.0f, &sp60);

            this->unk_9E4.x = this->actor.currPosRot.pos.x + sp60.x;
            this->unk_9E4.y = (this->actor.currPosRot.pos.y + sp60.y) + 40.0f;
            this->unk_9E4.z = this->actor.currPosRot.pos.z + sp60.z;

            this->unk_9F0.x = this->actor.currPosRot.pos.x;
            this->unk_9F0.y = this->actor.currPosRot.pos.y + this->unk_A08.y;
            this->unk_9F0.z = this->actor.currPosRot.pos.z;

            if (this->unk_9DC >= 0x29) {
                Math_SmoothScaleMaxF(&this->unk_A08.y, 800.0f, 0.1f, this->unk_A1C);
                Math_SmoothScaleMaxF(&this->unk_A1C, 100.0f, 1.0f, 1.0f);
                if ((this->unk_9DC >= 0x51) && ((this->unk_9DC & 0xF) == 0)) {
                    SysMatrix_GetStateTranslationAndScaledZ(100.0f, &sp60);
                    sp54 = randPlusMinusPoint5Scaled(200.0f) + (this->actor.currPosRot.pos.x + sp60.x);
                    sp5C = randPlusMinusPoint5Scaled(200.0f) + (this->actor.currPosRot.pos.z + sp60.z);
                    play_sound(0x9AC);
                    Actor_Spawn(&globalCtx->actorCtx, globalCtx, 0x129, sp54, 1200.0f, sp5C, 0,
                                randZeroOneScaled(65536.0f), 0, 0xA);
                }
            }

            if (this->unk_9DC >= 0xAA) {
                func_809D1EA4(this, globalCtx, 0);
                func_80169AFC(globalCtx, this->unk_9E2, 0);
                this->unk_9E2 = 0;
                func_800EA0EC(globalCtx, &globalCtx->csCtx);
                func_800B7298(globalCtx, &this->actor, 6);
                this->actor.flags |= 1;
                player->base.currPosRot.rot.y = player->base.shape.rot.y = -0x8000;
                player->base.currPosRot.pos.x = 0.0f;
                player->base.currPosRot.pos.z = -600.0f;
            }
            break;
    }

    if (this->unk_9E2 != 0) {
        ShrinkWindow_SetLetterboxTarget(0x1B);
        func_8016970C(globalCtx, this->unk_9E2, &this->unk_9F0, &this->unk_9E4);
    }
}

void func_809D1E5C(Boss01* this, GlobalContext* globalCtx) {
    this->actionFunc = func_809D1E74;
}

void func_809D1E74(Boss01* this, GlobalContext* globalCtx) {
    if (this->unk_14E[0] == 0) {
        Actor_MarkForDeath(&this->actor);
    }
}

void func_809D1EA4(Boss01* this, GlobalContext* globalCtx, u8 arg2) {
    if (this->unk_148 >= 0x3E9) {
        if (this->unk_1C1 == 0) {
            func_809D1AB8(this, globalCtx);
            return;
        }
        if (arg2 == 0x64) {
            if (randZeroOne() < 0.3f) {
                func_809D3A7C(this, globalCtx);
                return;
            }
            this->unk_162 = randZeroOneScaled(11.99f);
        } else {
            this->unk_162 = arg2;
        }
    } else {
        this->unk_162 = 0;
    }

    func_80137594(&this->skelAnime, D_809D7CF4[this->unk_162], this->unk_158 * 2.0f);
    this->unk_1A8 = SkelAnime_GetFrameCount(&D_809D7CF4[this->unk_162]->genericHeader);
    this->actionFunc = func_809D20D0;
    this->unk_14E[0] = 0x50;
    this->unk_14C = randZeroOneScaled(1.99f);
    this->unk_9DC = 0;
}

void func_809D20D0(Boss01* this, GlobalContext* globalCtx) {
    s16 i;
    ActorPlayer* player = PLAYER;
    Vec3f sp4C;

    this->unk_163 = 1;
    if ((this->unk_162 == 1) || (this->unk_162 == 2) || (this->unk_162 == 5) || (this->unk_162 == 6)) {
        func_800B8EC8(&this->actor, 0x3015);
    } else {
        func_800B8EC8(&this->actor, 0x3016);
    }

    if ((this->unk_162 == 0) || (this->unk_162 == 1) || (this->unk_162 == 2) || (this->unk_162 == 3)) {
        this->unk_1BB = 1;
        this->unk_1BA = 1;
    }

    if ((this->unk_162 == 2) || (this->unk_162 == 8) || (this->unk_162 == 9)) {
        if (func_801378B8(&this->skelAnime, 6.0f) != 0) {
            func_800B8EC8(&this->actor, 0x380C);
            for (i = 0; i < 3; i++) {
                func_809D0AA4(this, globalCtx, 0);
            }
        }
    }

    if (this->unk_162 == 9) {
        this->unk_158 = 0.0f;
        this->unk_154 = 0.0f;
    }

    this->unk_1B8 = 1;
    this->unk_9DC++;
    if (this->unk_162 == 6) {
        if (this->unk_9DC == 7) {
            func_800B8EC8(&this->actor, 0x3812);
        }
    } else if ((this->unk_162 == 7) && ((this->unk_9DC == 0xC) || (this->unk_9DC == 0x14))) {
        func_800B8EC8(&this->actor, 0x3812);
    }

    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    Math_SmoothScaleMaxS(&this->actor.currPosRot.rot.y, this->actor.rotTowardsLinkY, 0xA, 0x800);
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.5f);
    if (this->actor.xzDistanceFromLink <= 150.0f) {
        if (this->unk_14C != 0) {
            func_809D2A44(this, globalCtx, 0);
            this->unk_1BB = 0;
        }
    }

    if (((this->unk_14E[0] == 0) && (this->unk_162 != 6) && (this->unk_162 != 7)) ||
        ((func_801378B8(&this->skelAnime, this->unk_1A8) != 0) && ((this->unk_162 == 6) || (this->unk_162 == 7)))) {
        if (this->actor.xzDistanceFromLink <= 450.0f) {
            func_809D092C(this, globalCtx, 0);
        } else if (randZeroOne() < 0.5f) {
            func_809D2A44(this, globalCtx, 1);
        } else {
            func_809D2858(this, globalCtx);
        }
    }

    func_809D0AA4(this, globalCtx, 1);
    this->unk_154 = -2.0f;
    this->unk_158 = -4.0f;
    if (((this->unk_162 == 3) || (this->unk_162 == 4) || (this->unk_162 == 7) || (this->unk_162 == 8)) &&
        (this->unk_9DC == 0x1E)) {
        func_809D082C((Boss01Effect*)globalCtx->actorEffects, &player->base.currPosRot.pos);
        this->unk_14E[0] = 0x78;
    }

    if (((this->unk_14E[0] & 0xF) == 0) && (this->unk_162 != 0) && (D_809D8A10 < 5)) {
        ActorPlayer* player2 = PLAYER;
        s32 pad;

        if (randZeroOne() < 0.2f) {
            sp4C = player2->base.currPosRot.pos;
        } else {
            sp4C.x = randPlusMinusPoint5Scaled(1200.0f);
            sp4C.z = randPlusMinusPoint5Scaled(1200.0f);
        }
        sp4C.y = 1200.0f;

        switch (this->unk_162) {
            case 1:
            case 2:
            case 5:
            case 6:
                Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_BOSS_01, sp4C.x, sp4C.y, sp4C.z, 0,
                            randZeroOneScaled(65536.0f), 0, 0xA);
                break;

            case 9:
            case 10:
            case 11:
                func_8019F1C0(&D_809D7980, 0x295B);
                func_809D0678((Boss01Effect*)globalCtx->actorEffects, &sp4C, 0);
                break;

            case 3:
            case 4:
            case 7:
            case 8:
                break;
        }
    }
}

void func_809D2588(Boss01* this, GlobalContext* globalCtx) {
    func_80137594(&this->skelAnime, &D_06014F14, this->unk_158);
    if (this->actionFunc != func_809D25E8) {
        this->unk_14E[0] = 0x46;
        this->actionFunc = func_809D25E8;
    }
    this->unk_1BB = 0;
}

void func_809D25E8(Boss01* this, GlobalContext* globalCtx) {
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    func_800B8EC8(&this->actor, 0x301B);
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.5f);
    if (this->unk_14E[0] == 0) {
        func_809D1EA4(this, globalCtx, 0x64);
    }
    this->unk_1BB = 0;
    func_809D0AA4(this, globalCtx, 1);
}

void func_809D2664(Boss01* this, GlobalContext* globalCtx) {
    func_80137594(&this->skelAnime, &D_060164CC, this->unk_158);
    this->unk_14E[0] = 0x78;
    this->actionFunc = func_809D26B8;
    this->unk_1BB = 0;
}

void func_809D26B8(Boss01* this, GlobalContext* globalCtx) {
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    Math_SmoothScaleMaxF(&this->actor.speedXZ, 7.0f, 1.0f, 1.5f);
    Math_SmoothScaleMaxS(&this->actor.currPosRot.rot.y, this->actor.rotTowardsLinkY, 4, 0x1000);
    if (func_801378B8(&this->skelAnime, 5.0f) != 0) {
        func_800B8EC8(&this->actor, 0x3811);
        func_800B8EC8(&this->actor, 0x381D);
    }
    if (this->unk_14E[0] == 0) {
        func_809D1EA4(this, globalCtx, 0x64);
    }
    this->unk_1BB = 0;
    this->unk_1B8 = 1;
    this->unk_1BA = 1;
    func_809D0AA4(this, globalCtx, 1);
    this->unk_1C0 = 1;
}

void func_809D2780(Boss01* this, GlobalContext* globalCtx) {
    func_80137594(&this->skelAnime, &D_060204AC, this->unk_158);
    this->unk_14E[0] = 0x28;
    this->actionFunc = func_809D27D4;
    this->unk_1BB = 0;
}

void func_809D27D4(Boss01* this, GlobalContext* globalCtx) {
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.5f);
    func_800B8EC8(&this->actor, 0x3016);
    if (this->unk_14E[0] == 0) {
        func_809D092C(this, globalCtx, 1);
    }
    this->unk_1BB = 0;
    this->unk_1BA = 1;
    func_809D0AA4(this, globalCtx, 1);
}

void func_809D2858(Boss01* this, GlobalContext* globalCtx) {
    func_80137594(&this->skelAnime, &D_06016168, this->unk_158);
    this->actionFunc = func_809D2914;
    this->unk_14E[0] = randZeroOneScaled(100.0f) + 50.0f;
    this->unk_1B0 = 0.07f;
    if (randZeroOne() < 0.5f) {
        this->unk_1B0 *= -1.0f;
    }
    this->actor.gravity = -3.0f;
}

void func_809D2914(Boss01* this, GlobalContext* globalCtx) {
    Vec3f sp34;
    f32 xDiff;
    f32 zDiff;

    this->unk_163 = 1;
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    if ((this->actor.bgCheckFlags & 1) &&
        ((func_801378B8(&this->skelAnime, 6.0f) != 0) || (func_801378B8(&this->skelAnime, 16.0f) != 0))) {
        this->actor.velocity.y = 10.0f;
        func_800B8EC8(&this->actor, 0x380C);
    }
    this->unk_1B4 += this->unk_1B0;
    SysMatrix_InsertYRotation_f(this->unk_1B4, 0);
    SysMatrix_GetStateTranslationAndScaledZ(450.0f, &sp34);

    xDiff = sp34.x - this->actor.currPosRot.pos.x;
    zDiff = sp34.z - this->actor.currPosRot.pos.z;

    Math_SmoothScaleMaxS(&this->actor.currPosRot.rot.y, atans_flip(zDiff, xDiff), 0xA, 0x1000);
    Math_SmoothScaleMaxF(&this->actor.speedXZ, 12.0f, 1.0f, 3.0f);
    if (this->unk_14E[0] == 0) {
        func_809D1EA4(this, globalCtx, 0x64);
    }
    func_809D0AA4(this, globalCtx, 3);
    this->unk_1B8 = 1;
    this->unk_1BA = 1;
}

void func_809D2A44(Boss01* this, GlobalContext* globalCtx, u8 arg2) {
    this->unk_14C = arg2;
    func_80137594(&this->skelAnime, &D_06012D10, this->unk_158);
    this->actionFunc = func_809D2AA0;
    this->unk_14E[0] = 5;
}

void func_809D2AA0(Boss01* this, GlobalContext* globalCtx) {
    s32 pad[2];
    u8 i;
    Vec3f sp30;
    f32 sp2C;

    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    if (this->unk_14E[0] == 0) {
        this->actionFunc = func_809D2BCC;
        func_80137488(&this->skelAnime, &D_06012EBC, this->unk_154);
        this->actor.velocity.y = 35.0f;
        this->actor.gravity = -2.5f;
        SysMatrix_InsertYRotation_s(this->actor.currPosRot.rot.y, 0);
        if (this->unk_14C == 0) {
            sp2C = randZeroOneScaled(10.0f) + 10.0f;
        } else {
            sp2C = 12.0f;
        }
        SysMatrix_GetStateTranslationAndScaledZ(sp2C, &sp30);
        this->unk_1C4 = sp30.x;
        this->unk_1C8 = sp30.z;
        for (i = 0; i < 5; i++) {
            func_809D0AA4(this, globalCtx, 0);
        }
        func_800B8EC8(&this->actor, 0x3813);
        func_800B8EC8(&this->actor, 0x3014);
        this->unk_1BE = 5;
    }
    this->unk_1BA = 1;
}

void func_809D2BCC(Boss01* this, GlobalContext* globalCtx) {
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    func_800B8EC8(&this->actor, 0x3014);
    if (this->unk_14C == 0) {
        Math_SmoothScaleMaxS(&this->actor.currPosRot.rot.y, this->actor.rotTowardsLinkY, 5, 0x1000);
    } else if ((this->actor.velocity.y < -5.0f) && (this->unk_1AC >= -5.0f)) {
        func_80137488(&this->skelAnime, &D_06013480, this->unk_154);
        func_800B8EC8(&this->actor, 0x3811);
    }

    if (this->actor.currPosRot.pos.y < 40.0f) {
        this->actionFunc = func_809D2CDC;
        func_80137488(&this->skelAnime, &D_06012D10, this->unk_154);
        this->unk_14E[0] = 5;
        this->unk_161 = 0;
    }

    this->unk_1B8 = 1;
    this->unk_1BA = 1;
    this->unk_1C0 = 2;
    this->unk_1AC = this->actor.velocity.y;
}

void func_809D2CDC(Boss01* this, GlobalContext* globalCtx) {
    u8 i;

    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    if ((this->unk_161 == 0) && (this->actor.bgCheckFlags & 1)) {
        this->unk_161 = 1;
        for (i = 0; i < 5; i++) {
            func_809D0AA4(this, globalCtx, 0);
        }
        func_800B8EC8(&this->actor, 0x380C);
    }
    if (this->unk_14C == 0) {
        Math_SmoothScaleMaxS(&this->actor.currPosRot.rot.y, this->actor.rotTowardsLinkY, 4, 0x2800);
    }
    if (this->unk_14E[0] == 0) {
        if (this->actor.xzDistanceFromLink <= 450.0f) {
            func_809D092C(this, globalCtx, 0);
        } else {
            func_809D1EA4(this, globalCtx, 0x64);
        }
    }
    this->unk_1B8 = 1;
    this->unk_1BA = 1;
}

void func_809D2DE8(Boss01* this, GlobalContext* globalCtx) {
    func_80137488(&this->skelAnime, &D_06000C44, this->unk_158);
    this->unk_1A8 = SkelAnime_GetFrameCount(&D_06000C44.genericHeader);
    this->actionFunc = func_809D2E4C;
    this->unk_14E[0] = 0x14;
}

void func_809D2E4C(Boss01* this, GlobalContext* globalCtx) {
    Vec3f sp2C;

    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    if ((this->skelAnime.animCurrentFrame >= 10.0f) && (this->skelAnime.animCurrentFrame <= 15.0f)) {
        this->unk_160 = 1;
    }
    if ((this->unk_14E[0] >= 7) && (this->unk_14E[0] < 0xD)) {
        SysMatrix_InsertYRotation_f((this->actor.currPosRot.rot.y / 32768.0f) * M_PI, 0);
        SysMatrix_GetStateTranslationAndScaledZ(20.0f, &sp2C);
        this->unk_1C4 = sp2C.x;
        this->unk_1C8 = sp2C.z;
        func_809D0AA4(this, globalCtx, 0);
    }

    D_809D8A1C = 0.0f;
    D_809D8A20 = 90.0f;
    D_809D8A24 = -70.0f;
    D_809D8A28 = 0.471238791943f;
    D_809D8A2C = M_PI;
    D_809D8A30 = 1.72787606716f;

    if (func_801378B8(&this->skelAnime, 12.0f) != 0) {
        D_809D8A34 = 255.0f;
        D_809D798C = 100.0f;
    }
    if (func_801378B8(&this->skelAnime, 13.0f) != 0) {
        D_809D798C = 20.0f;
    }
    if (func_801378B8(&this->skelAnime, 14.0f) != 0) {
        D_809D798C = 7.0f;
    }
    if (func_801378B8(&this->skelAnime, 7.0f) != 0) {
        func_800B8EC8(&this->actor, 0x380A);
    }
    if (func_801378B8(&this->skelAnime, 10.0f) != 0) {
        func_800B8EC8(&this->actor, 0x3811);
    }
    if (func_801378B8(&this->skelAnime, this->unk_1A8) != 0) {
        func_809D1EA4(this, globalCtx, 0x64);
        this->unk_1C8 = 0.0f;
        this->unk_1C4 = 0.0f;
    }
    this->unk_1B8 = 1;
    this->unk_1BA = 1;
}

void func_809D3074(Boss01* this, GlobalContext* globalCtx) {
    func_80137488(&this->skelAnime, &D_06001884, this->unk_158);
    this->unk_1A8 = SkelAnime_GetFrameCount(&D_06001884.genericHeader);
    this->actionFunc = func_809D30D0;
}

void func_809D30D0(Boss01* this, GlobalContext* globalCtx) {
    Vec3f sp2C;

    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    if ((this->skelAnime.animCurrentFrame >= 10.0f) && (this->skelAnime.animCurrentFrame <= 15.0f)) {
        this->unk_1B8 = 2;
    }
    if ((this->unk_14E[0] >= 7) && (this->unk_14E[0] < 0xD)) {
        SysMatrix_InsertYRotation_f((this->actor.currPosRot.rot.y / 32768.0f) * M_PI, 0);
        SysMatrix_GetStateTranslation(&sp2C);
        this->unk_1C4 = sp2C.x;
        this->unk_1C8 = sp2C.z;
        func_809D0AA4(this, globalCtx, 0);
    }

    D_809D8A1C = 0.0f;
    D_809D8A20 = 140.0f;
    D_809D8A24 = 0.0f;
    D_809D8A28 = 0.471238791943f;
    D_809D8A2C = 0.0f;
    D_809D8A30 = 0.0f;

    if (func_801378B8(&this->skelAnime, 12.0f) != 0) {
        D_809D8A34 = 255.0f;
        D_809D798C = 100.0f;
    }
    if (func_801378B8(&this->skelAnime, 13.0f) != 0) {
        D_809D798C = 20.0f;
    }
    if (func_801378B8(&this->skelAnime, 14.0f) != 0) {
        D_809D798C = 7.0f;
    }
    if (func_801378B8(&this->skelAnime, 10.0f) != 0) {
        func_800B8EC8(&this->actor, 0x3811);
    }
    if (func_801378B8(&this->skelAnime, this->unk_1A8) != 0) {
        func_809D1EA4(this, globalCtx, 0x64);
        this->unk_1C8 = 0.0f;
        this->unk_1C4 = 0.0f;
    }
    this->unk_1BA = 1;
}

void func_809D32B4(Boss01* this, GlobalContext* globalCtx, u8 arg2) {
    if (this->actionFunc != func_809D3374) {
        if (arg2 == 0) {
            func_80137488(&this->skelAnime, &D_0600FF94, this->unk_154);
            this->unk_1A8 = SkelAnime_GetFrameCount(&D_0600FF94.genericHeader);
        } else {
            func_80137488(&this->skelAnime, &D_06010150, this->unk_154);
            this->unk_1A8 = SkelAnime_GetFrameCount(&D_06010150.genericHeader);
        }
        this->actionFunc = func_809D3374;
    }
    this->unk_14E[0] = 5;
}

void func_809D3374(Boss01* this, GlobalContext* globalCtx) {
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    Math_SmoothScaleMaxS(&this->actor.currPosRot.rot.y, this->actor.rotTowardsLinkY, 2, 0x500);
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.0f);
    if (this->unk_14E[0] != 0) {
        this->unk_1BA = 1;
    } else {
        func_809D1EA4(this, globalCtx, 0x64);
    }
    this->unk_1BB = 1;
}

void func_809D3400(Boss01* this, GlobalContext* globalCtx) {
    func_80137488(&this->skelAnime, &D_0601407C, this->unk_158);
    this->unk_1A8 = SkelAnime_GetFrameCount(&D_0601407C.genericHeader);
    this->actionFunc = func_809D345C;
}

void func_809D345C(Boss01* this, GlobalContext* globalCtx) {
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.0f);
    if (func_801378B8(&this->skelAnime, this->unk_1A8) != 0) {
        func_809D1EA4(this, globalCtx, 0x64);
    }
    this->unk_1B9 = 1;
}

void func_809D34D4(Boss01* this, GlobalContext* globalCtx) {
    func_80137488(&this->skelAnime, &D_06015A30, this->unk_158);
    this->unk_1A8 = SkelAnime_GetFrameCount(&D_06015A30.genericHeader);
    this->actionFunc = func_809D3530;
}

void func_809D3530(Boss01* this, GlobalContext* globalCtx) {
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.0f);
    if (func_801378B8(&this->skelAnime, this->unk_1A8) != 0) {
        func_809D1EA4(this, globalCtx, 0x64);
    }
    this->unk_1B9 = 1;
}

void func_809D35A8(Boss01* this, GlobalContext* globalCtx, u8 dmgEffect) {
    if (this->actionFunc != func_809D365C) {
        this->unk_14E[0] = 0x14;
        func_80137488(&this->skelAnime, &D_0600FDEC, 0.0f);
        this->unk_1A8 = SkelAnime_GetFrameCount(&D_0600FDEC.genericHeader);
        this->actionFunc = func_809D365C;
    } else if (dmgEffect == 0xE) {
        if (this->unk_14E[0] >= 6) {
            this->unk_1BE = 0x14;
        } else {
            this->unk_14E[0] = 0x14;
        }
    }
}

void func_809D365C(Boss01* this, GlobalContext* globalCtx) {
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.0f);
    if (func_801378B8(&this->skelAnime, this->unk_1A8) != 0) {
        func_80137594(&this->skelAnime, &D_06010980, this->unk_158);
        this->unk_1A8 = 1000.0f;
    }
    if (this->unk_14E[0] == 0) {
        func_809D2A44(this, globalCtx, 0);
    }
    func_809D0AA4(this, globalCtx, 1);
}

#ifdef NON_MATCHING
// Many regalloc problems
// colliderSphere3 loop, i optimised away, but 2 pointers going up by 0x40
void func_809D370C(Boss01* this, GlobalContext* globalCtx) {
    ActorPlayer* player = PLAYER;
    ColSphereGroupElement* sphere;
    s32 i;
    u8 dmg;

    if (this->colliderSphere2.spheres[0].body.unk16 & 2) {
        this->unk_1BC = 5;
        if ((this->unk_15C == 0) && (this->colliderSphere2.spheres[0].body.unk24->toucher.collidesWith == 0x2000000)) {
            Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_CLEAR_TAG, this->actor.topPosRot.pos.x,
                        this->actor.topPosRot.pos.y, this->actor.topPosRot.pos.z, 0, 0, 3, 4);
            func_800B8EC8(&this->actor, 0x1806);
            this->unk_15C = 5;
            return;
        }
    } else if (this->unk_15C == 0) {
        for (i = 0; i < 3; i++) {
            if (this->colliderSphere1.spheres[i].body.unk15 & 2) {
                this->colliderSphere1.spheres[i].body.unk15 &= ~2;
                player->unkB84 = this->actor.rotTowardsLinkY;
                player->unkB80 = 15.0f;
            }
        }
        for (i = 0; i < 2; i++) {
            if (this->colliderSphere4.spheres[i].body.unk15 & 2) {
                this->colliderSphere4.spheres[i].body.unk15 &= ~2;
                player->unkB84 = this->actor.rotTowardsLinkY;
                player->unkB80 = 20.0f;
            }
        }

        for (i = 0, sphere = &this->colliderSphere3.spheres[0]; i < 11; i++, sphere++) {

            if (sphere->body.unk16 & 2) {
                sphere->body.unk16 &= ~2;
                switch (this->actor.colChkInfo.damageEffect) {
                    case 3:
                        this->unk_AD9 = 0xA;
                        goto block_22;
                    case 2:
                        this->unk_AD9 = 1;
                        goto block_23;
                    case 4:
                        this->unk_AD9 = 0x14;
                        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_CLEAR_TAG, this->actor.topPosRot.pos.x,
                                    this->actor.topPosRot.pos.y, this->actor.topPosRot.pos.z, 0, 0, 0, 4);
                        goto block_23;
                    case 11:
                        this->unk_AD9 = 0x28;
                        goto block_22;
                    case 12:
                        this->unk_AD9 = 0x1E;
                        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_EN_CLEAR_TAG, this->actor.topPosRot.pos.x,
                                    this->actor.topPosRot.pos.y, this->actor.topPosRot.pos.z, 0, 0, 3, 4);
                        goto block_23;
                    case 1:
block_22:
                        func_809D441C(this, globalCtx);
                        this->unk_15C = 0xF;
                        func_800B8EC8(&this->actor, 0x389E);
                        this->unk_1BB = 0;
                        return;

                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                    case 10:
block_23:
                        dmg = this->actor.colChkInfo.damage;
                        D_809D8A18->unk0148 = 0;
                        if (this->actor.colChkInfo.damageEffect == 1) {
                            func_809D441C(this, globalCtx);
                            this->unk_15C = 0xF;
                        } else if (this->actor.colChkInfo.damageEffect == 0xF) {
                            func_809D2588(this, globalCtx);
                            func_8019F1C0(&D_809D8A40, 0x3809);
                            this->unk_15C = 0xF;
                        } else {
                            this->unk_15E = 0xF;
                            this->actor.colChkInfo.health -= dmg;
                            this->unk_15C = 5;
                            if ((s8)this->actor.colChkInfo.health <= 0) {
                                func_809D3C10(this, globalCtx);
                                func_800B8EC8(&this->actor, 0x380B);
                                func_800BBA88(globalCtx, &this->actor);
                            } else {
                                func_809D35A8(this, globalCtx, this->actor.colChkInfo.damageEffect);
                                func_8019F1C0(&D_809D8A40, 0x3809);
                            }
                        }
                        this->unk_1BB = 0;
                        return;
                }
            }
        }
    }
}
#else
GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D370C.asm")
#endif

void func_809D3A7C(Boss01* this, GlobalContext* globalCtx) {
    func_80137594(&this->skelAnime, &D_06012B70, -5.0f);
    this->unk_1A8 = SkelAnime_GetFrameCount(&D_06012B70.genericHeader);
    this->actionFunc = func_809D3ADC;
    this->unk_9DC = 0;
}

void func_809D3ADC(Boss01* this, GlobalContext* globalCtx) {
    this->unk_9DC++;
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    func_800B8EC8(&this->actor, 0x3017);
    if (func_801378B8(&this->skelAnime, this->unk_1A8) != 0) {
        this->skelAnime.animCurrentFrame = this->unk_1A8 - 20.0f;
    }

    if (this->unk_9DC >= 0x1E) {
        D_809D8A18->actor.currPosRot.pos.x = this->unk_928[0].x;
        D_809D8A18->actor.currPosRot.pos.y = this->unk_928[0].y;
        D_809D8A18->actor.currPosRot.pos.z = this->unk_928[0].z;
        D_809D8A18->actor.currPosRot.rot.y = this->actor.currPosRot.rot.y;
        if (this->unk_9DC == 0x1E) {
            D_809D8A18->unk0148 = 0x64;
            func_800B8EC8(&this->actor, 0x484F);
        }
    }

    Math_SmoothScaleMaxS(&this->actor.currPosRot.rot.y, this->actor.rotTowardsLinkY, 5, 0x500);
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.0f);
    if (this->unk_9DC >= 0x83) {
        func_809D1EA4(this, globalCtx, 0xA);
    }
}

void func_809D3C10(Boss01* this, GlobalContext* globalCtx) {
    func_80137488(&this->skelAnime, &D_060124CC, this->unk_154);
    this->unk_1A8 = SkelAnime_GetFrameCount(&D_060124CC.genericHeader);
    this->actionFunc = func_809D3CD0;
    func_800B8EC8(&this->actor, 0x38AF);
    this->actor.flags &= ~1;
    this->unk_1BE = 0x3E8;
    this->unk_9DC = 0;
    this->unk_9E0 = 0;
    func_801A89A8(0x100100FF);
    D_809D8A18->unk0144 = 0xFA;
    func_800BC154(globalCtx, &globalCtx->actorCtx, &D_809D8A18->actor, 9);
}

void func_809D3CD0(Boss01* this, GlobalContext* globalCtx) {
    Vec3f spB4;
    f32 xDiff;
    f32 zDiff;
    Camera* camera = Play_GetCamera(globalCtx, 0); // spA8
    s16 i;
    s16 spA4;
    Vec3f sp98;
    Vec3f sp8C;
    s16 sp8A;

    this->unk_1BE = 0x3E8;
    this->actor.flags &= ~1;
    SkelAnime_FrameUpdateMatrix(&this->skelAnime);
    this->unk_9DC++;
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.0f);
    switch (this->unk_9E0) {
        case 0:
            if (ActorCutscene_GetCurrentIndex() != -1) {
                break;
            }

            func_800EA0D4(globalCtx, &globalCtx->csCtx);
            func_800B7298(globalCtx, &this->actor, 1);
            this->unk_9E2 = func_801694DC(globalCtx);
            func_80169590(globalCtx, 0, 1);
            func_80169590(globalCtx, this->unk_9E2, 7);
            this->unk_9DC = 0;
            this->unk_9E0 = 1;
            this->unk_9E4.x = camera->eye.x;
            this->unk_9E4.y = camera->eye.y;
            this->unk_9E4.z = camera->eye.z;
            this->unk_9F0.x = camera->focalPoint.x;
            this->unk_9F0.y = camera->focalPoint.y;
            this->unk_9F0.z = camera->focalPoint.z;
            xDiff = this->unk_9E4.x - this->actor.currPosRot.pos.x;
            zDiff = this->unk_9E4.z - this->actor.currPosRot.pos.z;
            this->unk_A14 = atan_flip(zDiff, xDiff);
            this->unk_A18 = -0.5f;

        case 1:
            if (this->unk_9DC < 0xF) {
                Math_SmoothScaleMaxF(&this->actor.currPosRot.pos.x, 0.0f, 0.1f, 5.0f);
                Math_SmoothScaleMaxF(&this->actor.currPosRot.pos.z, 0.0f, 0.1f, 5.0f);
            }
            if (this->unk_9DC == 0x46) {
                func_801A89A8(0x8021);
            }
            if (this->unk_9DC == 0x47) {
                func_800B8EC8(&this->actor, 0x380E);
                this->unk_9E0 = 2;
                this->unk_9DC = 0;
            }

        case 2:
            Math_SmoothScaleMaxF(&this->unk_A18, 1.3f, 0.1f, 0.008f);
            spB4.x = 0.0f;
            spB4.y = 30.0f;
            spB4.z = 300.0f;
            SysMatrix_InsertYRotation_f(this->unk_A14 + this->unk_A18, 0);
            SysMatrix_MultiplyVector3fByState(&spB4, &this->unk_A08);
            this->unk_A08.x += this->unk_458.x;
            this->unk_A08.y += this->unk_458.y;
            this->unk_A08.z += this->unk_458.z;
            Math_SmoothScaleMaxF(&this->unk_9E4.x, this->unk_A08.x, 0.1f, 40.0f);
            Math_SmoothScaleMaxF(&this->unk_9E4.y, this->unk_A08.y, 0.1f, 40.0f);
            Math_SmoothScaleMaxF(&this->unk_9E4.z, this->unk_A08.z, 0.1f, 40.0f);
            Math_SmoothScaleMaxF(&this->unk_9F0.x, this->unk_458.x, 0.1f, 70.0f);
            Math_SmoothScaleMaxF(&this->unk_9F0.y, this->unk_458.y + 50.0f, 0.1f, 70.0f);
            Math_SmoothScaleMaxF(&this->unk_9F0.z, this->unk_458.z, 0.1f, 70.0f);
            if (this->unk_9DC >= 0x47) {
                sp98 = D_801D15B0;
                sp98.y = 0.03f;
                if (this->unk_9DC >= 0x51) {
                    Math_SmoothDownscaleMaxF(&this->actor.scale.y, 0.1f, this->unk_A20 * 0.00075f);
                    Math_SmoothScaleMaxF(&this->unk_A20, 1.0f, 1.0f, 0.01f);
                }
                if (this->unk_9DC >= 0x79) {
                    spA4 = 1;
                } else {
                    spA4 = 2;
                }

                for (i = 0; i < spA4; i++) {
                    sp8A = randZeroOneScaled(14.8999996185f);
                    sp8C.x = this->unk_928[sp8A].x + randPlusMinusPoint5Scaled(40.0f);
                    sp8C.y = this->unk_928[sp8A].y - 10.0f;
                    sp8C.z = this->unk_928[sp8A].z + randPlusMinusPoint5Scaled(40.0f);
                    EffectSS_SpawnKakarikoFire(globalCtx, &sp8C, &D_801D15B0, &sp98, randZeroOneScaled(30.0f) + 30.0f,
                                               0);
                }
                func_800B8EC8(&this->actor, 0x321F);
            }

            if (this->unk_9DC == 0x47) {
                Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, this->actor.topPosRot.pos.x,
                            this->actor.topPosRot.pos.y, this->actor.topPosRot.pos.z, 0, 0, 0, 0);
            }

            if (this->unk_9DC == 0xB4) {
                ActorPlayer* player = PLAYER;
                f32 xPos;
                f32 zPos;
                s32 j;

                for (j = 0; j < 5; j++) {
                    xPos = D_809D7D24[j];
                    zPos = D_809D7D38[j];

                    // Required to match
                    if (0) {};

                    if ((!(fabsf(xPos - this->actor.topPosRot.pos.x) < 220.0f) ||
                         !(fabsf(zPos - this->actor.topPosRot.pos.z) < 220.0f)) &&
                        (!(fabsf(xPos - player->base.currPosRot.pos.x) < 220.0f) ||
                         !(fabsf(zPos - player->base.currPosRot.pos.z) < 220.0f))) {
                        break;
                    }
                }

                Actor_SpawnWithParent(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_DOOR_WARP1, xPos, 0.0f, zPos,
                                      0, 0, 0, 1);
                this->unk_9E0 = 3;
                camera->eye = this->unk_9E4;
                camera->unk74 = this->unk_9E4;
                camera->focalPoint = this->unk_9F0;
                func_80169AFC(globalCtx, this->unk_9E2, 0);
                this->unk_9E2 = 0;
                func_800EA0EC(globalCtx, &globalCtx->csCtx);
                func_800B7298(globalCtx, &this->actor, 6);
                this->actor.flags &= ~1;
            }
            break;

        case 3:
            this->actor.currPosRot.pos.y = 5000.0f;
            break;
    }

    if (this->unk_9E2 != 0) {
        Vec3f sp6C;

        this->unk_A24 = Math_Coss(globalCtx->unk18840 * 0x8000) * this->unk_A28;
        Math_SmoothDownscaleMaxF(&this->unk_A28, 1.0f, 0.75f);
        sp6C = this->unk_9F0;
        sp6C.y += this->unk_A24;
        func_8016970C(globalCtx, this->unk_9E2, &sp6C, &this->unk_9E4);
    }
}

void func_809D441C(Boss01* this, GlobalContext* globalCtx) {
    this->actionFunc = func_809D4464;
    this->unk_14E[0] = 0x28;
    func_800BCB70(&this->actor, 0, 0x78, 0, 0x28);
}

void func_809D4464(Boss01* this, GlobalContext* globalCtx) {
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.0f);
    if (this->unk_14E[0] == 0) {
        func_809D1EA4(this, globalCtx, 0x64);
    }
}

void func_809D44C0(Boss01* this, GlobalContext* globalCtx) {
    Vec3f sp8C;
    Vec3f sp80;
    s32 i;

    func_800F0568(globalCtx, this->unk_928, 0x1E, 0x28CB);
    for (i = 0; i < 30; i++) {
        sp80.x = randPlusMinusPoint5Scaled(7.0f);
        sp80.z = randPlusMinusPoint5Scaled(7.0f);
        sp80.y = randZeroOneScaled(6.0f) + 4.0f;

        sp8C.x = this->unk_928[i / 2].x + sp80.x;
        sp8C.y = this->unk_928[i / 2].y + sp80.y;
        sp8C.z = this->unk_928[i / 2].z + sp80.z;

        func_800B2BC0(globalCtx, &sp8C, randZeroOneScaled(1.0f) + 1.5f, &sp80, &D_809D7D54, &D_809D7D4C, &D_809D7D50,
                      0x1E);
    }
}

#ifdef NON_MATCHING
// Odd generation on the second ABS
s32 func_809D4668(Boss01* this, GlobalContext* globalCtx) {
    ActorPlayer* player = PLAYER;

    if ((ABS16(this->actor.rotTowardsLinkY - this->actor.shape.rot.y) < 0x3000) &&
        (ABS16(this->actor.rotTowardsLinkY - (player->base.shape.rot.y - 0x8000)) < 0x3000)) {
        return 1;
    }
    return 0;
}
#else
GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D4668.asm")
#endif

void Boss01_Update(Actor* thisx, GameState* gameState) {
    Boss01* this = THIS;
    // Required to match
    GlobalContext* globalCtx = (GlobalContext*)gameState;
    s32 i;
    ActorPlayer* player = PLAYER;
    s32 pad2[2];
    f32 yDiff;
    s16 sp62;
    s16 sp60;
    f32 xDiff;
    f32 zDiff;

    if (this->actor.params == 0x23) {
        if (KREG(63) == 0) {
            DECR(this->unk_14E[0]);
            this->actionFunc(this, globalCtx);
        }
        return;
    }

    Math_Vec3f_Copy(&D_809D8A40, &this->actor.unkEC);
    globalCtx->kankyoContext.unkC1 = 0;
    globalCtx->kankyoContext.unkC2 = 1;
    Math_SmoothDownscaleMaxF(&globalCtx->kankyoContext.unkDC, 1.0f, 0.03f);
    this->unk_144++;
    if (KREG(63) == 0) {
        this->unk_148++;
        if (this->unk_148 == 0x320) {
            D_809D8A14->actor.naviEnemyId = 0x62;
        }
        this->unk_1BB = 0;
        this->unk_1BA = 0;
        this->unk_160 = 0;
        this->unk_1C0 = 0;
        this->unk_1B9 = 0;
        this->unk_1B8 = 0;
        for (i = 0; i < 3; i++) {
            DECR(this->unk_14E[i]);
        }

        DECR(this->unk_15C);
        DECR(this->unk_15E);

        this->actor.flags |= 1;
        this->actionFunc(this, globalCtx);
        Actor_SetVelocityAndMoveYRotationAndGravity(&this->actor);
        this->actor.currPosRot.pos.x += this->unk_1C4;
        this->actor.currPosRot.pos.z += this->unk_1C8;
    }

    func_800B78B8(globalCtx, &this->actor, 50.0f, 150.0f, 100.0f, 5);
    if (this->actor.bgCheckFlags & 1) {
        Math_SmoothDownscaleMaxF(&this->unk_1C4, 1.0f, 1.0f);
        Math_SmoothDownscaleMaxF(&this->unk_1C8, 1.0f, 1.0f);
    }

    this->actor.shape.rot = this->actor.currPosRot.rot;
    if (this->unk_1BE == 0) {
        func_809D370C(this, globalCtx);
        if (this->unk_1BC == 0) {
            Collision_AddAC(globalCtx, &globalCtx->colCheckCtx, &this->colliderSphere3.base);
        } else {
            this->unk_1BC--;
            for (i = 0; i < 11; i++) {
                this->colliderSphere3.spheres[i].body.unk16 &= ~2;
            }
        }
        if (this->unk_1BA != 0) {
            Collision_AddAC(globalCtx, &globalCtx->colCheckCtx, &this->colliderSphere2.base);
            Collision_AddOT(globalCtx, &globalCtx->colCheckCtx, &this->colliderSphere2.base);
            Collision_AddAC(globalCtx, &globalCtx->colCheckCtx, &this->colliderSphere1.base);
        }
        if (this->unk_1B8 != 0) {
            Collision_AddAT(globalCtx, &globalCtx->colCheckCtx, &this->colliderSphere1.base);
        }
        if (this->unk_1B9 != 0) {
            Collision_AddAT(globalCtx, &globalCtx->colCheckCtx, &this->colliderSphere4.base);
        }
    } else {
        this->unk_1BE--;
        for (i = 0; i < 11; i++) {
            this->colliderSphere3.spheres[i].body.unk16 &= ~2;
        }
    }

    Collision_AddOT(globalCtx, &globalCtx->colCheckCtx, &this->colliderSphere3.base);
    if (this->unk_1BB != 0) {
        if ((player->unkD57 != 0) || ((player->unkADC != 0) && (this->actor.xzDistanceFromLink <= 120.0f))) {
            if (func_809D4668(this, globalCtx) != 0) {
                if ((randZeroOne() < 0.25f) && (this->actionFunc != func_809D3374)) {
                    func_809D2A44(this, globalCtx, 0);
                    this->unk_1BE = 0xA;
                } else if ((player->unkADC != 0) && (this->actor.xzDistanceFromLink <= 120.0f)) {
                    func_809D32B4(this, globalCtx, 1);
                } else {
                    func_809D32B4(this, globalCtx, 0);
                }
            }
        }
    }

    if (this->unk_1BB != 0) {
        func_809D119C(this, globalCtx);
    }

    if (((this->unk_144 & (this->unk_1C0 - 1)) == 0) && (this->unk_1C0 != 0)) {
        Boss01* child = (Boss01*)Actor_SpawnWithParent(
            &globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_BOSS_01, this->actor.currPosRot.pos.x,
            this->actor.currPosRot.pos.y, this->actor.currPosRot.pos.z, this->actor.currPosRot.rot.x,
            this->actor.currPosRot.rot.y, (this->actionFunc == func_809D26B8) ? 4 : 10, 0x23);
        if (child != NULL) {
            for (i = 0; i < 52; i++) {
                child->skelAnime.limbDrawTbl[i] = this->skelAnime.limbDrawTbl[i];
            }
        }
    }

    func_809D6E7C(this, globalCtx);
    if (D_809D8A38 != 0) {
        D_809D8A38--;
        if (D_809D8A38 == 0) {
            func_801A89A8(0x801B);
        }
    }

    if (this->unk_163) {
        sp62 = this->actor.rotTowardsLinkY - this->actor.shape.rot.y;
        if ((sp62 > 0x3800) || (sp62 < -0x3800)) {
            sp62 = 0;
        }

        xDiff = player->base.currPosRot.pos.x - this->actor.topPosRot.pos.x;
        yDiff = KREG(36) + ((player->base.currPosRot.pos.y + 25.0f) - this->actor.topPosRot.pos.y);
        zDiff = player->base.currPosRot.pos.z - this->actor.topPosRot.pos.z;

        sp60 = atans(yDiff, sqrtf(SQ(xDiff) + SQ(zDiff)));
        this->unk_163 = 0;
    } else {
        sp60 = 0;
        sp62 = 0;
    }

    Math_SmoothScaleMaxS(&this->unk_1CC, sp62, 3, 0x2000);
    Math_SmoothScaleMaxS(&this->unk_1CE, sp60, 3, 0x2000);

    DECR(this->unk_ADA);

    switch (this->unk_AD9) {
        case 0:
            this->unk_AD8 = 0;
            this->unk_ADA = 0;
            this->unk_AD4 = 0.0f;
            break;

        case 1:
            this->unk_AD4 = 1.0f;
            this->unk_ACC = 0.0f;
            this->unk_AD8 = 0;
            this->unk_ADA = 0x28;
            this->unk_AD9++;
            func_800BCB70(&this->actor, 0x4000, 0x78, 0, 0x3C);

        case 2:
            if (this->unk_ADA == 0) {
                Math_SmoothDownscaleMaxF(&this->unk_AD4, 1.0f, 0.02f);
                if (this->unk_AD4 == 0.0f) {
                    this->unk_AD9 = 0;
                }
            } else {
                Math_SmoothScaleMaxF(&this->unk_ACC, 1.0f, 0.1f, 0.5f);
            }
            break;

        case 10:
            this->unk_AD8 = 0xB;
            this->unk_ADA = 0x28;
            this->unk_AD9++;
            this->unk_AD4 = 1.0f;
            this->unk_ACC = 0.0f;
            this->unk_AD0 = 1.0f;

        case 11:
            if (this->unk_ADA == 0) {
                func_809D44C0(this, globalCtx);
                this->unk_AD9 = 0;
                break;
            } else if (this->unk_ADA == 0x32) {
                this->unk_AD8 = 0xA;
            }
            Math_SmoothScaleMaxF(&this->unk_ACC, 1.0f, 1.0f, 0.08f);
            Math_SmoothScaleMaxF(&this->unk_AD0, 1.0f, 0.05f, 0.05f);
            break;

        case 20:
            this->unk_AD8 = 0x14;
            this->unk_ADA = 0x28;
            this->unk_ACC = 1.0f;
            goto block_82;

        case 30:
            this->unk_AD8 = 0x15;
            this->unk_ADA = 0x28;
            this->unk_ACC = 3.0f;
        block_82:
            this->unk_AD9 = 0x15;
            this->unk_AD4 = 1.0f;

        case 21:
            if (this->unk_ADA == 0) {
                Math_SmoothDownscaleMaxF(&this->unk_ACC, 1.0f, 0.03f);
                if (this->unk_ACC == 0.0f) {
                    this->unk_AD9 = 0;
                    this->unk_AD4 = 0.0f;
                }
            } else {
                Math_SmoothScaleMaxF(&this->unk_ACC, 1.5f, 0.5f, 0.5f);
            }
            break;

        case 40:
            this->unk_AD8 = 0x1E;
            this->unk_ADA = 0x32;
            this->unk_AD4 = 1.0f;
            this->unk_ACC = (KREG(18) * 0.1f) + 1.0f;
            this->unk_AD9++;

        case 41:
            if (this->unk_ADA == 0) {
                Math_SmoothDownscaleMaxF(&this->unk_ACC, 1.0f, 0.05f);
                if (this->unk_ACC == 0.0f) {
                    this->unk_AD9 = 0;
                    this->unk_AD4 = 0.0f;
                }
            }
            break;
    }
}

void func_809D519C(Boss01* this, GlobalContext* globalCtx) {
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    Vtx* vertices = Lib_PtrSegToVirt(D_0600C338);
    u32 i;

    for (i = 0; i < 11; i++) {
        vertices[D_809D7D60[i]].v.ob[0] = __cosf((i * M_PI) / D_809D798C) * 200.0f;
        vertices[D_809D7D60[i]].v.ob[1] = 0;
        vertices[D_809D7D60[i]].v.ob[2] = __sinf((i * M_PI) / D_809D798C) * 200.0f;

        vertices[D_809D7D6C[i]].v.ob[0] = __cosf((i * M_PI) / D_809D798C) * 100.0f;
        vertices[D_809D7D6C[i]].v.ob[1] = 0;
        vertices[D_809D7D6C[i]].v.ob[2] = __sinf((i * M_PI) / D_809D798C) * 100.0f;
    }

    gSPSegment(
        gfxCtx->polyXlu.p++, 0x08,
        Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x20, 1, globalCtx->unk18840 * 18, 0, 0x20, 0x20));
    gDPPipeSync(gfxCtx->polyXlu.p++);
    gDPSetPrimColor(gfxCtx->polyXlu.p++, 0, 0, 255, 255, 255, (u8)D_809D8A34);

    SysMatrix_InsertTranslation(this->actor.currPosRot.pos.x + D_809D8A1C, this->actor.currPosRot.pos.y + D_809D8A20,
                                this->actor.currPosRot.pos.z + D_809D8A24, 0);
    SysMatrix_InsertYRotation_f(this->actor.shape.rot.y * 0.000009587f, 1);
    SysMatrix_RotateStateAroundXAxis(D_809D8A28);
    SysMatrix_InsertZRotation_f(D_809D8A30, 1);
    SysMatrix_InsertYRotation_f(D_809D8A2C, 1);

    gSPMatrix(gfxCtx->polyXlu.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfxCtx->polyXlu.p++, D_0600C498);
}

s32 func_809D5584(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx) {
    Boss01* this = THIS;

    if (limbIndex == 0x20) {
        rot->x += this->unk_1CC;
        rot->y += this->unk_1CE;
    }
    return 0;
}

void func_809D55CC(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* thisx) {
    Boss01* this = THIS;
    s32 pad;
    s8 idx;
    s8 idx2;
    Vec3f sp40;

    if (limbIndex == 0x20) {
        SysMatrix_GetStateTranslation(&this->actor.topPosRot.pos);
    }
    idx = D_809D7E68[limbIndex];
    if (idx >= 0) {
        SysMatrix_GetStateTranslation(&this->unk_928[idx]);
    }

    idx = D_809D7D78[limbIndex];
    if (idx >= 0) {
        SysMatrix_MultiplyVector3fByState(&D_809D7DB4[idx], &sp40);
        func_809D089C(idx, &this->colliderSphere3, &sp40);
    }

    idx2 = 2;
    if (&D_809D7D78[idx2] == &D_809D7D78[limbIndex]) {
        SysMatrix_GetStateTranslation(&this->unk_458);
        if (this->unk_1B8 == 2) {
            SysMatrix_MultiplyVector3fByState(&D_809D7E5C, &sp40);
            func_809D089C(2, &this->colliderSphere1, &sp40);
        }
    }

    idx2 = 0x1F;
    if (&D_809D7D78[idx2] == &D_809D7D78[limbIndex]) {
        SysMatrix_MultiplyVector3fByState(&D_809D7E44, &sp40);
        func_809D089C(0, &this->colliderSphere1, &sp40);
        SysMatrix_MultiplyVector3fByState(&D_809D7E50, &sp40);
        func_809D089C(1, &this->colliderSphere1, &sp40);
    }

    idx2 = 0x17;
    if (&D_809D7D78[idx2] == &D_809D7D78[limbIndex]) {
        SysMatrix_MultiplyVector3fByState(&D_809D7E38, &sp40);
        func_809D089C(0, &this->colliderSphere2, &sp40);
        func_809D089C(0, &this->colliderSphere4, &sp40);
    }

    idx2 = 0x7;
    if (&D_809D7D78[idx2] == &D_809D7D78[limbIndex]) {
        SysMatrix_GetStateTranslation(&this->unk_440[0]);
    }

    idx2 = 0xC;
    if (&D_809D7D78[idx2] == &D_809D7D78[limbIndex]) {
        SysMatrix_GetStateTranslation(&this->unk_440[1]);
        SysMatrix_GetStateTranslation(&sp40);
        func_809D089C(1, &this->colliderSphere4, &sp40);
    }

    idx2 = 0x20;
    if (&D_809D7D78[idx2] == &D_809D7D78[limbIndex]) {
        GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
        // Should be Gfx* and/or referenced directly in the calls,
        // but stack issues arise as it swaps with globalCtx->unk187FC.
        // Kenix had this same issue in OOT,
        // and a u32 was the only solution found
        u32 sym = D_0600C5E0;

        gDPSetPrimColor(gfxCtx->polyXlu.p++, 0, 0, 255, 0, 0, 255);
        gDPSetEnvColor(gfxCtx->polyXlu.p++, 255, 0, 0, 0);

        SysMatrix_StatePush();
        SysMatrix_InsertTranslation(1470.0f, 400.0f, 450.0f, 1);
        SysMatrix_InsertScale(0.35f, 0.35f, 0.35f, 1);
        SysMatrix_NormalizeXYZ(&globalCtx->unk187FC);

        gSPMatrix(gfxCtx->polyXlu.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfxCtx->polyXlu.p++, sym);

        SysMatrix_StatePop();
        SysMatrix_StatePush();
        SysMatrix_InsertTranslation(1470.0f, -360.0f, 450.0f, 1);
        SysMatrix_InsertScale(0.35f, 0.35f, 0.35f, 1);
        SysMatrix_NormalizeXYZ(&globalCtx->unk187FC);

        gSPMatrix(gfxCtx->polyXlu.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfxCtx->polyXlu.p++, sym);

        SysMatrix_StatePop();
    }
}

void Boss01_Draw(Actor* thisx, GameState* gameState) {
    Boss01* this = THIS;
    GlobalContext* globalCtx = (GlobalContext*)gameState;
    s32 pad[2];
    GraphicsContext* gfxCtx;
    u8* texture;

    texture = globalCtx->state.gfxCtx->polyOpa.d - 0x200;
    globalCtx->state.gfxCtx->polyOpa.d = texture;

    gfxCtx = globalCtx->state.gfxCtx;
    OPEN_DISPS(gfxCtx);

    func_809D089C(2, &this->colliderSphere1, &D_809D7EA0);
    func_8012C28C(globalCtx->state.gfxCtx);
    func_8012C2DC(globalCtx->state.gfxCtx);
    if ((this->unk_15E & 1) != 0) {
        oGfxCtx->polyOpa.p = Gfx_SetFog(oGfxCtx->polyOpa.p, 0xFF, 0, 0, 0xFF, 0x384, 0x44B);
    }
    SkelAnime_DrawSV(globalCtx, this->skelAnime.skeleton, this->skelAnime.limbDrawTbl, this->skelAnime.dListCount,
                     func_809D5584, func_809D55CC, &this->actor);
    oGfxCtx->polyOpa.p = func_801660B8(globalCtx, oGfxCtx->polyOpa.p);
    func_809D5FB4(texture, this, globalCtx);
    func_809D606C(texture, this, globalCtx);
    if (D_809D8A34 > 0.0f) {
        func_809D519C(this, globalCtx);
        Math_SmoothDownscaleMaxF(&D_809D8A34, 1.0f, 50.0f);
    }
    func_800BE680(globalCtx, &this->actor, &this->unk_928[0], 0xF, this->unk_ACC, this->unk_AD0, this->unk_AD4,
                  this->unk_AD8);
    func_809D73D4(globalCtx);

    CLOSE_DISPS(gfxCtx);
}

void func_809D5B0C(Actor* thisx, GlobalContext* globalCtx) {
    Boss01* this = THIS;
    s32 pad;
    Boss01* parent = (Boss01*)this->actor.parent;

    OPEN_DISPS(globalCtx->state.gfxCtx);

    func_8012C28C(globalCtx->state.gfxCtx);
    func_8012C2DC(globalCtx->state.gfxCtx);
    oGfxCtx->polyOpa.p = Gfx_SetFog(oGfxCtx->polyOpa.p, 0x32, 0, 0x28, 0xFF, 0x384, 0x44B);
    SkelAnime_DrawSV(globalCtx, parent->skelAnime.skeleton, this->skelAnime.limbDrawTbl, parent->skelAnime.dListCount,
                     NULL, NULL, &this->actor);
    oGfxCtx->polyOpa.p = func_801660B8(globalCtx, oGfxCtx->polyOpa.p);

    CLOSE_DISPS(globalCtx->state.gfxCtx);
}

void func_809D5BC4(Boss01* this, u8* texture, f32 arg2) {
    s32 i;
    s32 idx1;
    s32 idx2;
    s32 idx3;
    s32 y;
    s32 x = 0;
    s32 offset;
    f32 x1;
    f32 y1;
    f32 z1;
    Vec3f sp74;
    Vec3f sp68;

    for (i = 0; i < 15; i++) {

        if (arg2 != 0.0f) {
            x = D_809D7F30[i];
            if (x < 0) {
                continue;
            }
        }

        if (arg2 > 0.0f) {
            x1 = this->unk_928[i].x + ((this->unk_928[x].x - this->unk_928[i].x) * arg2);
            y1 = this->unk_928[i].y + ((this->unk_928[x].y - this->unk_928[i].y) * arg2);
            z1 = this->unk_928[i].z + ((this->unk_928[x].z - this->unk_928[i].z) * arg2);

            sp74.x = x1 - this->actor.currPosRot.pos.x;
            sp74.y = ((((y1 - this->actor.currPosRot.pos.y) + 76.0f) + 30.0f) + 30.0f) + 100.0f;
            sp74.z = z1 - this->actor.currPosRot.pos.z;
        } else {
            sp74.x = this->unk_928[i].x - this->actor.currPosRot.pos.x;
            sp74.y = ((((this->unk_928[i].y - this->actor.currPosRot.pos.y) + 76.0f) + 30.0f) + 30.0f) + 100.0f;
            sp74.z = this->unk_928[i].z - this->actor.currPosRot.pos.z;
        }

        x = 0;
        SysMatrix_MultiplyVector3fByState(&sp74, &sp68);
        sp68.x *= 0.2f;
        sp68.y *= 0.2f;
        idx1 = (s32)(sp68.x + 32.0f) & 0xFFFF;
        idx2 = sp68.y;
        idx2 = (idx2 * 64) & 0xFFFF;

        if (D_809D7F6C[i] == 2) {
            for (x = 0, offset = -0x180; x < 12; x++, offset += 0x40) {
                for (y = -D_809D7F00[x]; y < D_809D7F00[x]; y++) {
                    idx3 = ((idx1 + y) + idx2) + offset;
                    if ((idx3 >= 0) && (idx3 < 0x1000)) {
                        texture[idx3] = 0xFF;
                    }
                }
            }
        } else if (D_809D7F6C[i] == 1) {
            for (x = 0, offset = -0x100; x != 8; x++, offset += 0x40) {
                for (y = -D_809D7EE0[x]; y < D_809D7EE0[x]; y++) {
                    idx3 = ((idx1 + y) + idx2) + offset;
                    if ((idx3 >= 0) && (idx3 < 0x1000)) {
                        texture[idx3] = 0xFF;
                    }
                }
            }
        } else if (D_809D7F6C[i] == 0) {
            for (x = 0, offset = -0xC0; x != 7; x++, offset += 0x40) {
                for (y = -D_809D7EC4[x]; y < D_809D7EC4[x] - 1; y++) {
                    idx3 = ((idx1 + y) + idx2) + offset;
                    if ((idx3 >= 0) && (idx3 < 0x1000)) {
                        texture[idx3] = 0xFF;
                    }
                }
            }
        } else {
            for (x = 0, offset = -0x80; x != 6; x++, offset += 0x40) {
                for (y = -D_809D7EAC[x]; y < D_809D7EAC[x] - 1; y++) {
                    idx3 = ((idx1 + y) + idx2) + offset;
                    if ((idx3 >= 0) && (idx3 < 0x1000)) {
                        texture[idx3] = 0xFF;
                    }
                }
            }
        }
    }
}

void func_809D5FB4(u8* texture, Boss01* this, GlobalContext* globalCtx) {
    u32* tex32 = (u32*)texture;
    s16 i;

    for (i = 0; i < 0x400; i++, tex32++) {
        *tex32 = 0;
    }

    SysMatrix_SetStateXRotation(1.0f);

    for (i = 0; i < 6; i++) {
        func_809D5BC4(this, texture, i / 5.0f);
    }
}

#ifdef NON_MATCHING
// Odd register usage (gfxCtx in t0?)
void func_809D606C(u8* texture, Boss01* this, GlobalContext* globalCtx) {
    f32 alpha;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;
    OPEN_DISPS(gfxCtx);

    func_8012C28C(globalCtx->state.gfxCtx);

    alpha = (400.0f - this->actor.currPosRot.pos.y) * 0.0025f;
    if (alpha < 0.0f) {
        alpha = 0.0f;
    }
    if (alpha > 1.0f) {
        alpha = 1.0f;
    }

    gDPSetPrimColor(oGfxCtx->polyOpa.p++, 0, 0, 0, 0, 0, (s8)(alpha * 80.0f));
    gDPSetEnvColor(oGfxCtx->polyOpa.p++, 0, 0, 0, 0);

    SysMatrix_InsertTranslation(this->actor.currPosRot.pos.x, this->actor.unk88, this->actor.currPosRot.pos.z - 20.0f,
                                0);
    SysMatrix_InsertScale(1.64999997616f, 1.0f, 1.64999997616f, 1);

    gSPMatrix(oGfxCtx->polyOpa.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(oGfxCtx->polyOpa.p++, D_0600C7A8);
    gDPLoadTextureBlock(oGfxCtx->polyOpa.p++, texture, G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD);
    gSPDisplayList(oGfxCtx->polyOpa.p++, D_0600C7C8);

    CLOSE_DISPS(gfxCtx);
}
#else
GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D606C.asm")
#endif

void func_809D62D4(Boss01* this, GlobalContext* globalCtx) {
    this->actionFunc = func_809D6314;
    func_80137594(&this->skelAnime, &D_06022550, -5.0f);
}

void func_809D6314(Boss01* this, GlobalContext* globalCtx) {
    s32 pad[2];
    f32 sp2C = 3.0f;
    Actor* refActor = &PLAYER->base;
    Actor* explosive = globalCtx->actorCtx.actorList[ACTORTYPE_EXPLOSIVES].first;
    s16 sp22 = 0x3E8;

    if (this->actor.bgCheckFlags & 1) {
        this->skelAnime.animPlaybackSpeed = 1.0f;

        while (explosive != NULL) {
            if (explosive->params == 1) {
                explosive = explosive->next;
                continue;
            }
            refActor = explosive;
            sp2C = 5.0f;
            this->skelAnime.animPlaybackSpeed = 1.5f;
            sp22 = 0x7D0;
            break;
        }

        SkelAnime_FrameUpdateMatrix(&this->skelAnime);
        func_800B8EC8(&this->actor, 0x319D);
        Math_SmoothScaleMaxF(&this->actor.speedXZ, sp2C, 1.0f, 1.0f);
        Math_SmoothScaleMaxS(&this->actor.currPosRot.rot.y,
                             atans(refActor->currPosRot.pos.x - this->actor.currPosRot.pos.x,
                                   refActor->currPosRot.pos.z - this->actor.currPosRot.pos.z),
                             5, sp22);
    }
}

void func_809D6424(Boss01* this, GlobalContext* globalCtx) {
    if ((s8)this->actor.colChkInfo.health > 0) {
        this->actionFunc = func_809D6488;
        this->unk_14E[0] = 0x1E;
    } else {
        this->unk_14E[0] = 0xF;
        func_800BBA88(globalCtx, &this->actor);
        func_809D64E0(this, globalCtx);
    }
}

void func_809D6488(Boss01* this, GlobalContext* globalCtx) {
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.0f);
    if (this->unk_14E[0] == 0) {
        func_809D62D4(this, globalCtx);
    }
}

void func_809D64E0(Boss01* this, GlobalContext* globalCtx) {
    this->actionFunc = func_809D65E0;
    this->unk_1C4 = this->unk_1C8 = 0.0f;
    this->unk_AC8 = 1.0f;
    this->actor.speedXZ = -15.0f;
    this->actor.velocity.y = 12.0f;
    this->actor.currPosRot.rot.y = this->actor.rotTowardsLinkY;
    this->actor.flags &= ~1;
}

void func_809D6540(Boss01* this, GlobalContext* globalCtx) {
    this->actionFunc = func_809D6588;
    this->unk_14E[0] = 0x28;
    func_800BCB70(&this->actor, 0, 0x78, 0, 0x28);
}

void func_809D6588(Boss01* this, GlobalContext* globalCtx) {
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.0f);
    if (this->unk_14E[0] == 0) {
        func_809D62D4(this, globalCtx);
    }
}

void func_809D65E0(Boss01* this, GlobalContext* globalCtx) {
    if (this->actor.bgCheckFlags & 1) {
        func_800B8EC8(&this->actor, 0x321F);
        Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 2.0f);
        Math_SmoothDownscaleMaxF(&this->actor.scale.y, 1.0f, 0.00075f);
        Math_SmoothScaleMaxF(&this->unk_AC4, 1.0f, 0.5f, 0.15f);
        if (this->actor.scale.y < 0.001f) {
            Math_SmoothDownscaleMaxF(&this->unk_AC8, 1.0f, 0.05f);
            if (this->unk_AC8 < 0.01f) {
                Actor_MarkForDeath(&this->actor);
                func_800A7D28(globalCtx, NULL, &this->actor.currPosRot.pos, 0x60);
                D_809D8A10--;
            }
        }
        Math_SmoothScaleMaxS(&this->actor.shape.rot.x, 0, 1, 0x800);
    } else {
        this->actor.shape.rot.x -= 0x2000;
        this->actor.shape.rot.z += 0x1000;
    }
}

void func_809D670C(Boss01* this, GlobalContext* globalCtx) {
    Vec3f sp3C;
    s32 pad[2];
    u8 dmg;
    ColBodyInfo* colliderBody;
    Boss01Effect* effect = globalCtx->actorEffects;

    if (this->collider1.base.flagsAC & 2) {
        this->collider1.base.flagsAC &= ~2;
        colliderBody = this->collider1.body.unk24;
        if (this->unk_15C == 0) {
            SysMatrix_InsertYRotation_s(this->actor.rotTowardsLinkY, 0);
            if (colliderBody->toucher.collidesWith & 0x300000) {
                this->unk_15C = 0xA;
                SysMatrix_GetStateTranslationAndScaledZ(-10.0f, &sp3C);
                this->unk_1C4 = sp3C.x;
                this->unk_1C8 = sp3C.z;
            } else {
                this->unk_15C = 0xF;
                this->unk_15E = 0xF;
                SysMatrix_GetStateTranslationAndScaledZ(-20.0f, &sp3C);
                this->unk_1C4 = sp3C.x;
                this->unk_1C8 = sp3C.z;
                if (this->actor.colChkInfo.damageEffect == 1) {
                    func_809D6540(this, globalCtx);
                    func_800B8EC8(&this->actor, 0x389E);
                } else {
                    dmg = this->actor.colChkInfo.damage;
                    this->actor.colChkInfo.health -= dmg;
                    func_809D6424(this, globalCtx);
                    func_800B8EC8(&this->actor, 0x3807);
                }
            }
        }
    }

    if ((D_809D8A14 != NULL) && (D_809D8A14->actionFunc == func_809D3CD0)) {
        func_809D64E0(this, globalCtx);
        this->actor.speedXZ = this->actor.velocity.y = 0.0f;
    }

    if ((effect->unk_28 == 3) && (effect->unk_2A < 0x96)) {
        f32 sqrt = sqrtf(SQ(effect->unk_00.x - this->actor.currPosRot.pos.x) +
                         SQ(effect->unk_00.z - this->actor.currPosRot.pos.z));

        if ((sqrt < (KREG(49) + 210.0f)) && (sqrt > (KREG(49) + 190.0f))) {
            func_800B8EC8(&this->actor, 0x3807);
            func_809D64E0(this, globalCtx);
            this->unk_15E = 0xF;
            this->unk_14C = 0;
            this->actor.speedXZ = 0.0f;
            this->actor.velocity.y = 5.0f;
        }
    }
}

void func_809D694C(Actor* thisx, GlobalContext* globalCtx) {
    Boss01* this = THIS;
    s32 pad;
    s32 i;

    this->unk_144++;
    for (i = 0; i < 3; i++) {
        DECR(this->unk_14E[i]);
    }

    DECR(this->unk_15C);
    DECR(this->unk_15E);

    this->actionFunc(this, globalCtx);
    Actor_SetVelocityAndMoveYRotationAndGravity(&this->actor);
    this->actor.currPosRot.pos.x += this->unk_1C4;
    this->actor.currPosRot.pos.z += this->unk_1C8;
    Actor_SetHeight(&this->actor, 10.0f);
    func_800B78B8(globalCtx, &this->actor, 50.0f, 21.0f, 100.0f, 5);
    if (this->actor.bgCheckFlags & 1) {
        Math_SmoothDownscaleMaxF(&this->unk_1C4, 1.0f, 1.0f);
        Math_SmoothDownscaleMaxF(&this->unk_1C8, 1.0f, 1.0f);
    }

    if (this->actionFunc != func_809D65E0) {
        func_809D670C(this, globalCtx);
        Collision_CylinderMoveToActor(&this->actor, &this->collider1);
        Collision_AddAC(globalCtx, &globalCtx->colCheckCtx, &this->collider1.base);
        Collision_CylinderMoveToActor(&this->actor, &this->collider2);
        Collision_AddAT(globalCtx, &globalCtx->colCheckCtx, &this->collider2.base);
        this->actor.shape.rot = this->actor.currPosRot.rot;
    }
}

s32 func_809D6B08(GlobalContext* globalCtx, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* actor) {
    if ((limbIndex == 2) && (D_809D8A14->actionFunc == func_809D1B2C)) {
        *dList = D_060213A8;
    }

    if (limbIndex == 4) {
        OPEN_DISPS(globalCtx->state.gfxCtx);

        if (D_809D8A14->actionFunc == func_809D1B2C) {
            gSPDisplayList(oGfxCtx->polyOpa.p++, D_06022118);
        } else {
            gSPDisplayList(oGfxCtx->polyOpa.p++, D_060220A0);
        }

        CLOSE_DISPS(globalCtx->state.gfxCtx);
    }

    return 0;
}

void func_809D6BB4(Actor* thisx, GlobalContext* globalCtx) {
    Boss01* this = THIS;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    func_8012C28C(globalCtx->state.gfxCtx);
    if ((this->unk_15E & 1) != 0) {
        gfxCtx->polyOpa.p = Gfx_SetFog(gfxCtx->polyOpa.p, 0xFF, 0, 0, 0xFF, 0x384, 0x44B);
    }

    SkelAnime_DrawSV(globalCtx, this->skelAnime.skeleton, this->skelAnime.limbDrawTbl, this->skelAnime.dListCount,
                     func_809D6B08, NULL, &this->actor);
    gfxCtx->polyOpa.p = func_801660B8(globalCtx, gfxCtx->polyOpa.p);
    func_800BE680(globalCtx, &this->actor, &this->actor.currPosRot.pos, 1, this->unk_AC4, 0.0f, this->unk_AC8,
                  this->unk_14C);
}

void func_809D6C98(GlobalContext* globalCtx, Vec3f* arg1, f32 arg2) {
    s16 i;
    Vec3f spA0;
    Vec3f sp94;
    Vec3f sp88;

    for (i = 0; i < 5; i++) {
        spA0.x = randPlusMinusPoint5Scaled(5.0f);
        spA0.y = randZeroOneScaled(2.0f) + 1.0f;
        spA0.z = randPlusMinusPoint5Scaled(5.0f);
        sp94.x = sp94.z = 0.0f;
        sp94.y = -0.1f;
        sp88.x = (randPlusMinusPoint5Scaled(70.0f) * arg2) + arg1->x;
        sp88.y = (randZeroOneScaled(10.0f) * arg2) + arg1->y;
        sp88.z = (randPlusMinusPoint5Scaled(70.0f) * arg2) + arg1->z;
        func_800B0EB0(globalCtx, &sp88, &spA0, &sp94, &D_809D7CEC, &D_809D7CF0,
                      (randZeroOneScaled(150.0f) + 350.0f) * arg2, 0xA, randZeroOneScaled(5.0f) + 14.0f);
    }
}

void func_809D6E7C(Boss01* this, GlobalContext* globalCtx) {
    Boss01Effect* effect = (Boss01Effect*)globalCtx->actorEffects;
    ActorPlayer* player = PLAYER;
    s16 i;
    s16 j;
    s32 idx;
    f32 xDiff;
    f32 zDiff;
    f32 sqrt;
    s16 rand;

    for (i = 0; i < 100; i++, effect++) {
        if (effect->unk_28 != 0) {
            effect->unk_2A++;
            idx = effect->unk_28;
            if (idx == 3) {
                if (effect->unk_2A < 0x96) {
                    Math_SmoothScaleMaxF(&globalCtx->kankyoContext.unkDC,
                                         (Math_Sins(effect->unk_2A * 4096) * 0.1f) + 0.9f, 1.0f, 0.2f);
                    D_809D8A18->unk0144 = 0xFA;
                    if ((D_809D8A14 != NULL) && (D_809D8A14->actionFunc == func_809D3CD0)) {
                        effect->unk_2A = 0x96;
                    }
                    play_sound(0x2034);
                    Math_SmoothScaleMaxF(&effect->unk_34, 1.0f, 0.1f, 0.3f);
                    if (!(player->unkA74 & 0x1000) && (player->base.currPosRot.pos.y < 70.0f)) {
                        xDiff = effect->unk_00.x - player->base.currPosRot.pos.x;
                        zDiff = effect->unk_00.z - player->base.currPosRot.pos.z;
                        sqrt = sqrtf(SQ(xDiff) + SQ(zDiff));

                        if ((player->unkD5C == 0) && (sqrt < (KREG(49) + 210.0f)) && (sqrt > (KREG(49) + 190.0f))) {
                            for (j = 0; j < 18; j++) {
                                player->unkD45[j] = Math_Rand_S16Offset(0, 0xC8);
                            }

                            player->unkD44 = 1;
                            rand = atans_flip(zDiff, xDiff);
                            if (sqrt > (KREG(49) + 100.0f)) {
                                rand += 0x8000;
                            }

                            func_800B8D50(globalCtx, &this->actor, 10.0f, rand, 0.0f, 8);
                        }
                    }
                } else {
                    Math_SmoothDownscaleMaxF(&effect->unk_38, 1.0f, 10.0f);
                    if (effect->unk_38 < 0.1f) {
                        effect->unk_28 = 0;
                    }
                }
            } else {
                effect->unk_00.x += effect->unk_0C.x;
                effect->unk_00.y += effect->unk_0C.y;
                effect->unk_00.z += effect->unk_0C.z;
                effect->unk_0C.y += effect->unk_18;

                if (idx == 1) {
                    effect->unk_1E += effect->unk_30;
                    effect->unk_1C += effect->unk_2E;
                    if (effect->unk_2C == 0) {
                        xDiff = player->base.currPosRot.pos.x - effect->unk_00.x;
                        sqrt = (player->base.currPosRot.pos.y + 20.0f) - effect->unk_00.y;
                        zDiff = player->base.currPosRot.pos.z - effect->unk_00.z;

                        if ((SQ(xDiff) + SQ(zDiff) + SQ(sqrt)) < 2500.0f) {
                            func_800B8D50(globalCtx, NULL, 0.0f, randZeroOneScaled(65526.0f), 0.0f, 8);
                        }

                        if (effect->unk_00.y < 10.0f) {
                            effect->unk_00.y = 10.0f;
                            rand = randZeroOneScaled(2.0f) + 4.0f;
                            for (j = 0; j < rand; j++) {
                                func_809D0678(globalCtx->actorEffects, effect, 1);
                            }
                            effect->unk_28 = 0;
                            func_800F0568(globalCtx, &effect->unk_00, 0x28, 0x2810);
                            func_809D6C98(globalCtx, &effect->unk_00, 1.0f);
                            func_800E85D4(globalCtx, &effect->unk_00);
                            func_800BC848(this, globalCtx, 3, 0xA);
                        }
                    } else if ((effect->unk_00.y < 10.0f) && (effect->unk_0C.y < 0.0f)) {
                        effect->unk_00.y = 10.0f;
                        effect->unk_28 = 0;
                        func_809D6C98(globalCtx, effect, 0.5f);
                    }
                }
            }
        }
    }
}

void func_809D73D4(GlobalContext* globalCtx) {
    s16 i;
    f32 alpha;
    Boss01Effect* effect = globalCtx->actorEffects;

    OPEN_DISPS(globalCtx->state.gfxCtx);

    func_8012C28C(globalCtx->state.gfxCtx);
    func_8012C2DC(globalCtx->state.gfxCtx);

    for (i = 1; i < 100; i++, effect++) {
        if (effect->unk_28 == 1) {
            SysMatrix_InsertTranslation(effect->unk_00.x, effect->unk_00.y, effect->unk_00.z, 0);
            SysMatrix_InsertYRotation_s(effect->unk_1E, 1);
            SysMatrix_InsertXRotation_s(effect->unk_1C, 1);
            SysMatrix_InsertScale(effect->unk_34, effect->unk_34, effect->unk_34, 1);
            gSPMatrix(oGfxCtx->polyOpa.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(oGfxCtx->polyOpa.p++, D_0600E3E8);
        }
    }

    effect = globalCtx->actorEffects;
    func_8012C448(globalCtx->state.gfxCtx);
    gDPSetPrimColor(oGfxCtx->polyXlu.p++, 0, 0, 0, 0, 0, 100);

    for (i = 1; i < 100; i++, effect++) {
        if (effect->unk_28 == 1) {
            SysMatrix_InsertTranslation(effect->unk_00.x, 0.0f, effect->unk_00.z, 0);
            SysMatrix_InsertScale(effect->unk_34 * 50.0f, 1.0f, effect->unk_34 * 50.0f, 1);

            gSPMatrix(oGfxCtx->polyXlu.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(oGfxCtx->polyXlu.p++, SEGMENTED_TO_VIRTUAL(&D_04076BC0));
        }
    }

    func_8012C2DC(globalCtx->state.gfxCtx);
    effect = globalCtx->actorEffects;
    func_809D0530(1, 0x71A5, 0x263A);

    if (effect->unk_28 == 3) {
        gDPSetEnvColor(oGfxCtx->polyXlu.p++, 255, 10, 0, 0);
        SysMatrix_InsertTranslation(effect->unk_00.x, 0.0f, effect->unk_00.z, 0);

        for (i = 0; i < 32; i++) {
            SysMatrix_StatePush();
            alpha = effect->unk_38 - (func_809D0550() * 50.0f);
            if (alpha < 0.0f) {
                alpha = 0.0f;
            }

            gDPSetPrimColor(oGfxCtx->polyXlu.p++, 0x80, 0x80, 255, 255, 0, (u8)alpha);
            gSPSegment(oGfxCtx->polyXlu.p++, 0x08,
                       Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, 0, 0, 0x20, 0x40, 1, 0,
                                        ((effect->unk_2A + (i * 10)) * -20) & 0x1FF, 0x20, 0x80));

            SysMatrix_InsertYRotation_f(i * 0.196349546313f, 1);
            SysMatrix_InsertTranslation(0.0f, 0.0f, KREG(49) + 200.0f, 1);
            SysMatrix_NormalizeXYZ(&globalCtx->unk187FC);
            if (func_809D0550() < 0.5f) {
                SysMatrix_InsertYRotation_f(M_PI, 1);
            }

            SysMatrix_InsertScale(
                (KREG(48) * 0.00001f) + 0.0179999992251f,
                ((0.007f + (KREG(54) * 0.00001f)) + ((func_809D0550() * 30.0f) * 0.00001f)) * effect->unk_34, 1.0f, 1);

            gSPMatrix(oGfxCtx->polyXlu.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx),
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(oGfxCtx->polyXlu.p++, D_0407D590);

            SysMatrix_StatePop();
        }
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx);
}
