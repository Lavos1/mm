#include "z_boss_01.h"
#include "overlays/actors/ovl_En_Tanron1/z_en_tanron1.h"

#define FLAGS 0x00000035

#define THIS ((Boss01*)thisx)

void Boss01_Init(Actor* thisx, GlobalContext* globalCtx);
void Boss01_Destroy(Actor* thisx, GlobalContext* globalCtx);
void Boss01_Update(Boss01* this, GlobalContext* globalCtx);
void Boss01_Draw(Boss01* this, GlobalContext* globalCtx);

void func_809D694C(Actor* thisx, GlobalContext* globalCtx);
void func_809D6BB4(Actor* thisx, GlobalContext* globalCtx);
void func_809D5B0C(Actor* thisx, GlobalContext* globalCtx);

void func_809D1EA4(Boss01* this, GlobalContext* globalCtx, u8 arg2);
void func_809D2A44(Boss01* this, GlobalContext* globalCtx, u8 arg2);

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


extern Gfx D_06022118[];
extern Gfx D_060220A0[];
extern Gfx D_060213A8[];
extern u8 D_809D7980;
extern u8 D_0600C7F8[];

const ActorInit Boss_01_InitVars = {
    ACTOR_BOSS_01,
    ACTORTYPE_BOSS,
    FLAGS,
    OBJECT_BOSS01,
    sizeof(Boss01),
    (ActorFunc)Boss01_Init,
    (ActorFunc)Boss01_Destroy,
    (ActorFunc)Boss01_Update,
    (ActorFunc)Boss01_Draw
};

ColorRGBA8 D_809D7CEC = { 60, 50, 20, 255 };
ColorRGBA8 D_809D7CF0 = { 40, 30, 30, 255 };

AnimationHeader* D_809D7CF4[] = {
    0x06018438, 
    0x0601AAF4, 
    0x0601AF18, 
    0x0601BA94, 
    0x0601C700, 
    0x0601CE88, 
    0x0601D8C8, 
    0x0601E68C, 
    0x0601EEA8, 
    0x0601F6A4, 
    0x0601FC10, 
    0x060204AC, 
};

f32 D_809D7D24[] = {
    0.0f, 
    350.0f, 
    -350.0f, 
    350.0f, 
    -350.0f, 
};

f32 D_809D7D38[] = {
    0.0f, 
    350.0f, 
    350.0f, 
    -350.0f, 
    -350.0f, 
};

ActorDamageChart D_809D7990 = {
    0x10, 0xF1, 0x00, 0xE1,
    0xF1, 0xF1, 0x00, 0x00,
    0xE1, 0xE1, 0xF1, 0x22,
    0x32, 0x42, 0xF1, 0xF1,
    0x10, 0xE1, 0x10, 0xB0,
    0x00, 0x00, 0xF1, 0xE1,
    0xD1, 0xC2, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xE1,
};

ActorDamageChart D_809D79B0 = {
    0x10, 0xF1, 0x00, 0xF2, 
    0x10, 0xF2, 0x00, 0x00, 
    0xF1, 0xF1, 0xF1, 0x22, 
    0x32, 0x42, 0xF1, 0x10, 
    0x10, 0xF1, 0x10, 0x10, 
    0x00, 0x00, 0xF1, 0xE1, 
    0xD2, 0xD2, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xF1, 
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
static ColSphereGroupInit sJntSphInit1 =
{
    { COLTYPE_METAL_SHIELD, 0x11, 0x0D, 0x09, 0x10, COLSHAPE_JNTSPH },
    3, sJntSphItemsInit1,
};

static ColSphereGroupElementInit sJntSphItemsInit2[1] = {
    {
        { 0x02, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 0, { { 0, 0, 0 }, 36 }, 100 },
    },
};

// D_809D7A70
static ColSphereGroupInit sJntSphInit2 =
{
    { COLTYPE_METAL_SHIELD, 0x11, 0x0D, 0x09, 0x10, COLSHAPE_JNTSPH },
    1, sJntSphItemsInit2,
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
static ColSphereGroupInit sJntSphInit3 =
{
    { COLTYPE_UNK3, 0x11, 0x09, 0x09, 0x10, COLSHAPE_JNTSPH },
    11, sJntSphItemsInit3,
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
static ColSphereGroupInit sJntSphInit4 =
{
    { COLTYPE_UNK3, 0x11, 0x09, 0x09, 0x10, COLSHAPE_JNTSPH },
    2, sJntSphItemsInit4,
};

// D_809D7C74
static ColCylinderInit sCylinderInit1 =
{
    { COLTYPE_UNK3, 0x11, 0x09, 0x39, 0x10, COLSHAPE_CYLINDER },
    { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7FFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
    { 15, 15, 10, { 0, 0, 0 } },
};

// D_809D7CA0
static ColCylinderInit sCylinderInit2 =
{
    { COLTYPE_UNK3, 0x11, 0x09, 0x39, 0x10, COLSHAPE_CYLINDER },
    { 0x03, { 0xF7CFFFFF, 0x00, 0x04 }, { 0xF7FFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
    { 8, 15, 10, { 0, 0, 0 } },
};


s16 D_809D8A10;
Boss01* D_809D8A14;
EnTanron1* D_809D8A18;
u8 D_809D8A38;
Boss01Struct1 D_809D8A58[100];

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D0530.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D0550.asm")

void func_809D0678(Boss01Struct1 *effect, Vec3f *arg1, s16 arg2) {
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

void func_809D082C(Boss01Struct1 *effect, Vec3f *pos) {
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

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D089C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D092C.asm")

void func_809D0AA4(Boss01 *this, GlobalContext *globalCtx, u8 arg2) {
    s32 pad;
    Vec3f spB0;
    Vec3f spA4;
    Vec3f sp98;
    u8 i;

    if ((this->unk_144 & arg2) == 0) {
        if ((this->unk_1C4 > 1.0f) || (this->unk_1C8 > 1.0f) || 
            (arg2 == 0) || (this->actor.speedXZ > 1.0f)) {
            for (i = 0; i < 2; i++) {
                spA4.x = randPlusMinusPoint5Scaled(5.0f);
                spA4.y = randZeroOneScaled(2.0f) + 1.0f;
                spA4.z = randPlusMinusPoint5Scaled(5.0f);
                sp98.y = -0.1f;
                sp98.x = sp98.z = 0.0f;
                spB0.x = this->unk_440[i].x + randPlusMinusPoint5Scaled(20.0f);
                spB0.y = randZeroOneScaled(10.0f) + 3.0f;
                spB0.z = this->unk_440[i].z + randPlusMinusPoint5Scaled(20.0f);
                func_800B0EB0(globalCtx, &spB0, &spA4, &sp98, &D_809D7CEC, &D_809D7CF0, randZeroOneScaled(150.0f) + 350.0f, 0xA, randZeroOneScaled(5.0f) + 14.0f);
            }
        }
    }
}

void Boss01_Init(Actor* thisx, GlobalContext *globalCtx) {
    Boss01 *this = THIS;
    s32 pad;
    s16 i;

    Actor_SetScale(&this->actor, 0.015f);
    if (this->actor.params == 0xA) {
        SkelAnime_Init(globalCtx, &this->skelAnime, &D_060222D0, &D_06022550, this->limbDrawTable, this->transitionDrawTable, 21);
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
        SkelAnime_Init(globalCtx, &this->skelAnime, &D_0600F0A8, &D_06018438, this->limbDrawTable, this->transitionDrawTable, 52);
        func_809D1E5C(this, globalCtx);
        this->unk_14E[0] = this->actor.currPosRot.rot.z;
        this->actor.currPosRot.rot.z = 0;
        this->actor.draw = func_809D5B0C;
        this->actor.flags &= ~1;
    } else {
        if (gSaveContext.perm.weekEventReg[20] & 2) {
            Actor_SpawnWithParent(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_DOOR_WARP1, 0.0f, 0.0f, 0.0f, 0, 0, 0, 1);
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
        Collision_InitSphereGroup(globalCtx, &this->colliderSphere1, &this->actor, &sJntSphInit1, this->colliderSphere1Items);
        Collision_InitSphereGroup(globalCtx, &this->colliderSphere2, &this->actor, &sJntSphInit2, this->colliderSphere2Items);
        Collision_InitSphereGroup(globalCtx, &this->colliderSphere3, &this->actor, &sJntSphInit3, this->colliderSphere3Items);
        Collision_InitSphereGroup(globalCtx, &this->colliderSphere4, &this->actor, &sJntSphInit4, this->colliderSphere4Items);
        SkelAnime_Init(globalCtx, &this->skelAnime, &D_0600F0A8, &D_06018438, this->limbDrawTable, this->transitionDrawTable, 52);
        if ((KREG(64) != 0) || ((gSaveContext.owl.unk5 & 0x10) != 0)) {
            func_809D1EA4(this, globalCtx, 0);
            this->actor.gravity = -2.5f;
            D_809D8A38 = KREG(15) + 20;
        } else {
            func_809D1258(this, globalCtx);
        }
        D_809D8A18 = (EnTanron1*)Actor_SpawnWithParent(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_EN_TANRON1, 0.0f, 437.0f, -750.0f, 0, 0, 0, 0x100);
    }

    this->unk_154 = -2.0f;
    this->unk_158 = -4.0f;
}

void Boss01_Destroy(Actor* thisx, GlobalContext *globalCtx) {

}

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D119C.asm")

void func_809D1258(Boss01 *this, GlobalContext *globalCtx) {
    this->actionFunc = func_809D12B4;
    this->actor.currPosRot.pos.x = 0.0f;
    this->actor.currPosRot.pos.z = 0.0f;
    this->actor.gravity = 0.0f;
    this->actor.currPosRot.pos.y = 2400.0f;
    func_80137594(&this->skelAnime, &D_06012D10, 0.0f);
}

void func_809D12B4(Boss01 *this, GlobalContext *globalCtx) {
    ActorPlayer *player = PLAYER;

    this->unk_9DC++;
    func_80136CD0(&this->skelAnime);

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
                ((func_801378B8(&this->skelAnime, 30.0f) != 0) ||
                (func_801378B8(&this->skelAnime, 54.0f) != 0))) {
                func_800B8EC8(&this->actor, 0x3811);
            }

            if (this->unk_9DC < 0x1E) {
                Math_SmoothScaleMaxF(&this->unk_9F0.y, this->actor.currPosRot.pos.y + 80.0f, 0.25f, 1000.0f);
            } else {
                Math_SmoothScaleMaxF(&this->unk_9E4.x, this->actor.currPosRot.pos.x + 70.0f, 0.05f, this->unk_A1C * 70.0f);
                Math_SmoothScaleMaxF(&this->unk_9E4.y, 200.0f, 0.05f, this->unk_A1C * 170.0f);
                Math_SmoothScaleMaxF(&this->unk_9E4.z, ((this->actor.currPosRot.pos.z + 200.0f) + 50.0f) - 30.0f, 0.05f, this->unk_A1C * 120.0f);
                Math_SmoothScaleMaxF(&this->unk_9F0.y, (this->actor.currPosRot.pos.y + 80.0f) + 20.0f, 0.05f, this->unk_A1C * 20.0f);
                Math_SmoothScaleMaxF(&this->unk_A1C, 1.0f, 1.0f, 0.001f);
            }
            if (this->unk_9DC == 0x14) {
                func_801A89A8(0x801B);
            }
            if (this->unk_9DC == 0x32) {
                Actor_TitleCardCreate(globalCtx, &globalCtx->actorCtx.titleCtxt, Lib_PtrSegToVirt(D_0600C7F8), 0xA0, 0xB4, 0x80, 0x28);
            }
            if (this->unk_9DC == 0x8C) {
                Camera *camera = Play_GetCamera(globalCtx, 0);
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

void func_809D1AB8(Boss01 *this, GlobalContext *globalCtx) {
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

void func_809D1B2C(Boss01 *this, GlobalContext *globalCtx) {
    ActorPlayer* player = PLAYER;
    Vec3f sp60;
    f32 sp5C;
    s32 pad;
    f32 sp54;

    this->unk_9DC++;
    this->unk_1BE = 0x1E;
    func_80136CD0(&this->skelAnime);
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
                    Actor_Spawn(&globalCtx->actorCtx, globalCtx, 0x129, sp54, 1200.0f, sp5C, 0, randZeroOneScaled(65536.0f), 0, 0xA);
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

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D1E5C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D1E74.asm")

void func_809D1EA4(Boss01 *this, GlobalContext *globalCtx, u8 arg2) {
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

void func_809D20D0(Boss01 *this, GlobalContext *globalCtx) {
    s16 i; //sp5E;
    ActorPlayer* player = PLAYER;// sp58;
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
    } else if ((this->unk_162 == 7) && 
        ((this->unk_9DC == 0xC) || (this->unk_9DC == 0x14))) {
        func_800B8EC8(&this->actor, 0x3812);
    }

    func_80136CD0(&this->skelAnime);
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
        func_809D082C((Boss01Struct1*)globalCtx->actorEffects, &player->base.currPosRot.pos);
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
                Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_BOSS_01, sp4C.x, sp4C.y, sp4C.z, 0, randZeroOneScaled(65536.0f), 0, 0xA);
                break;

            case 9:
            case 10:
            case 11:
                func_8019F1C0(&D_809D7980, 0x295B);
                func_809D0678((Boss01Struct1*)globalCtx->actorEffects, &sp4C, 0);
                break;

            case 3:
            case 4:
            case 7:
            case 8:
                break;

        }
    }
}

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D2588.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D25E8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D2664.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D26B8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D2780.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D27D4.asm")

void func_809D2858(Boss01 *this, GlobalContext *globalCtx) {
    func_80137594(&this->skelAnime, &D_06016168, this->unk_158);
    this->actionFunc = func_809D2914;
    this->unk_14E[0] = randZeroOneScaled(100.0f) + 50.0f;
    this->unk_1B0 = 0.07f;
    if (randZeroOne() < 0.5f) {
        this->unk_1B0 *= -1.0f;
    }
    this->actor.gravity = -3.0f;
}

void func_809D2914(Boss01 *this, GlobalContext *globalCtx) {
    Vec3f sp34;
    f32 xDiff;
    f32 zDiff;

    this->unk_163 = 1;
    func_80136CD0(&this->skelAnime);
    if (this->actor.bgCheckFlags & 1) {
        if ((func_801378B8(&this->skelAnime, 6.0f) != 0) || (func_801378B8(&this->skelAnime, 16.0f) != 0)) {
            this->actor.velocity.y = 10.0f;
            func_800B8EC8(&this->actor, 0x380C);
        } else {

        }
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

void func_809D2A44(Boss01 *this, GlobalContext *globalCtx, u8 arg2) {
    this->unk_14C = arg2;
    func_80137594(&this->skelAnime, &D_06012D10, this->unk_158);
    this->actionFunc = func_809D2AA0;
    this->unk_14E[0] = 5;
}

void func_809D2AA0(Boss01 *this, GlobalContext *globalCtx) {
    s32 pad[2];
    u8 i;
    Vec3f sp30;
    f32 sp2C;

    func_80136CD0(&this->skelAnime);
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

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D2BCC.asm")

void func_809D2BCC(Boss01 *this, GlobalContext *globalCtx) {

    func_80136CD0(&this->skelAnime);
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

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D2CDC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D2DE8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D2E4C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D3074.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D30D0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D32B4.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D3374.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D3400.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D345C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D34D4.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D3530.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D35A8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D365C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D370C.asm")

void func_809D3A7C(Boss01 *this, GlobalContext *globalCtx) {
    func_80137594(&this->skelAnime, &D_06012B70, -5.0f);
    this->unk_1A8 = SkelAnime_GetFrameCount(&D_06012B70.genericHeader);
    this->actionFunc = func_809D3ADC;
    this->unk_9DC = 0;
}

void func_809D3ADC(Boss01 *this, GlobalContext *globalCtx) {
    this->unk_9DC++;
    func_80136CD0(&this->skelAnime);
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

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D3C10.asm")

void func_809D3CD0(Boss01 *this, GlobalContext *globalCtx) {
    Vec3f spB4;
    f32 temp;
    f32 temp2;
    Camera *camera = Play_GetCamera(globalCtx, 0); //spA8
    s16 i;
    s16 spA4;
    Vec3f sp98;
    Vec3f sp8C;
    s16 sp8A;

    this->unk_1BE = 0x3E8;
    this->actor.flags &= ~1;
    func_80136CD0(&this->skelAnime);
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
            temp = this->unk_9E4.x - this->actor.currPosRot.pos.x;
            temp2 = this->unk_9E4.z - this->actor.currPosRot.pos.z;
            this->unk_A14 = atan_flip(temp2, temp);
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
                    EffectSS_SpawnKakarikoFire(globalCtx, &sp8C, &D_801D15B0, &sp98, randZeroOneScaled(30.0f) + 30.0f, 0);
                }
                func_800B8EC8(&this->actor, 0x321F);
            }
            if (this->unk_9DC == 0x47) {
                Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, this->actor.topPosRot.pos.x, this->actor.topPosRot.pos.y, this->actor.topPosRot.pos.z, 0, 0, 0, 0);
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
                    if (0){};

                    if ((!(fabsf(xPos - this->actor.topPosRot.pos.x) < 220.0f) || !(fabsf(zPos - this->actor.topPosRot.pos.z) < 220.0f)) &&
                        (!(fabsf(xPos - player->base.currPosRot.pos.x) < 220.0f) || !(fabsf(zPos - player->base.currPosRot.pos.z) < 220.0f))) {
                        break;
                    }
                }

                Actor_SpawnWithParent(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_DOOR_WARP1, xPos, 0.0f, zPos, 0, 0, 0, 1);
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

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D441C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D4464.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D44C0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D4668.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/Boss01_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D519C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D5584.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D55CC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/Boss01_Draw.asm")

void func_809D5B0C(Actor* thisx, GlobalContext *globalCtx) {
    Boss01 *this = THIS;
    s32 pad;
    Boss01* parent = (Boss01*)this->actor.parent;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    func_8012C28C(globalCtx->state.gfxCtx);
    func_8012C2DC(globalCtx->state.gfxCtx);
    gfxCtx->polyOpa.p = Gfx_SetFog(gfxCtx->polyOpa.p, 0x32, 0, 0x28, 0xFF, 0x384, 0x44B);
    SkelAnime_DrawSV(globalCtx, parent->skelAnime.skeleton, this->skelAnime.limbDrawTbl, parent->skelAnime.dListCount, NULL, NULL, &this->actor);
    gfxCtx->polyOpa.p = func_801660B8(globalCtx, gfxCtx->polyOpa.p);
}

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D5BC4.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D5FB4.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D606C.asm")

void func_809D62D4(Boss01 *this, GlobalContext *globalCtx) {
    this->actionFunc = func_809D6314;
    func_80137594(&this->skelAnime, &D_06022550, -5.0f);
}

void func_809D6314(Boss01 *this, GlobalContext *globalCtx) {
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

        func_80136CD0(&this->skelAnime);
        func_800B8EC8(&this->actor, 0x319D);
        Math_SmoothScaleMaxF(&this->actor.speedXZ, sp2C, 1.0f, 1.0f);
        Math_SmoothScaleMaxS(&this->actor.currPosRot.rot.y, atans(refActor->currPosRot.pos.x - this->actor.currPosRot.pos.x, refActor->currPosRot.pos.z - this->actor.currPosRot.pos.z), 5, sp22);
    }
}

void func_809D6424(Boss01 *this, GlobalContext *globalCtx) {
    if ((s8)this->actor.colChkInfo.health > 0) {
        this->actionFunc = func_809D6488;
        this->unk_14E[0] = 0x1E;
    } else {
        this->unk_14E[0] = 0xF;
        func_800BBA88(globalCtx, &this->actor);
        func_809D64E0(this, globalCtx);
    }
}

void func_809D6488(Boss01 *this, GlobalContext *globalCtx) {
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.0f);
    if (this->unk_14E[0] == 0) {
        func_809D62D4(this, globalCtx);
    }
}

void func_809D64E0(Boss01 *this, GlobalContext *globalCtx) {
    this->actionFunc = func_809D65E0;
    this->unk_1C4 = this->unk_1C8 = 0.0f;
    this->unk_AC8 = 1.0f;
    this->actor.speedXZ = -15.0f;
    this->actor.velocity.y = 12.0f;
    this->actor.currPosRot.rot.y = this->actor.rotTowardsLinkY;
    this->actor.flags &= ~1;
}

void func_809D6540(Boss01 *this, GlobalContext *globalCtx) {
    this->actionFunc = func_809D6588;
    this->unk_14E[0] = 0x28;
    func_800BCB70(&this->actor, 0, 0x78, 0, 0x28);
}

void func_809D6588(Boss01 *this, GlobalContext *globalCtx) {
    Math_SmoothDownscaleMaxF(&this->actor.speedXZ, 1.0f, 1.0f);
    if (this->unk_14E[0] == 0) {
        func_809D62D4(this, globalCtx);
    }
}

void func_809D65E0(Boss01 *this, GlobalContext *globalCtx) {
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

void func_809D670C(Boss01 *this, GlobalContext *globalCtx) {
    Vec3f sp3C;
    s32 pad[2];
    u8 dmg;
    ColBodyInfo* colliderBody;

    Boss01Struct1* ptr = globalCtx->actorEffects;

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

    if ((ptr->unk_28 == 3) && (ptr->unk_2A < 0x96)) {
        f32 sqrt = sqrtf(SQ(ptr->unk_00.x - this->actor.currPosRot.pos.x) + SQ(ptr->unk_00.z - this->actor.currPosRot.pos.z));
        if ((sqrt < (KREG(49) + 210.0f)) && 
            (sqrt > (KREG(49) + 190.0f))) {
            func_800B8EC8(&this->actor, 0x3807);
            func_809D64E0(this, globalCtx);
            this->unk_15E = 0xF;
            this->unk_14C = 0;
            this->actor.speedXZ = 0.0f;
            this->actor.velocity.y = 5.0f;
        }
    }
}

void func_809D694C(Actor* thisx, GlobalContext *globalCtx) {
    Boss01 *this = THIS;
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

s32 func_809D6B08(GlobalContext *globalCtx, s32 limbIndex, Gfx **dList, Vec3f *pos, Vec3s *rot, Actor *actor) {
    if ((limbIndex == 2) && (D_809D8A14->actionFunc == func_809D1B2C)) {
        *dList = D_060213A8;
    }

    if (limbIndex == 4) {
        GraphicsContext *gfxCtx = globalCtx->state.gfxCtx;

        if (D_809D8A14->actionFunc == func_809D1B2C) {
            gSPDisplayList(gfxCtx->polyOpa.p++, D_06022118);
        } else {
            gSPDisplayList(gfxCtx->polyOpa.p++, D_060220A0);
        }
    }

    return 0;
}

void func_809D6BB4(Actor* thisx, GlobalContext *globalCtx) {
    Boss01 *this = THIS;
    GraphicsContext* gfxCtx = globalCtx->state.gfxCtx;

    func_8012C28C(globalCtx->state.gfxCtx);
    if ((this->unk_15E & 1) != 0) {
        gfxCtx->polyOpa.p = Gfx_SetFog(gfxCtx->polyOpa.p, 0xFF, 0, 0, 0xFF, 0x384, 0x44B);
    }

    SkelAnime_DrawSV(globalCtx, this->skelAnime.skeleton, this->skelAnime.limbDrawTbl, this->skelAnime.dListCount, func_809D6B08, NULL, &this->actor);
    
    gfxCtx->polyOpa.p = func_801660B8(globalCtx, gfxCtx->polyOpa.p);
    func_800BE680(globalCtx, &this->actor, &this->actor.currPosRot.pos, 1, this->unk_AC4, 0.0f, this->unk_AC8, this->unk_14C);
}

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D6C98.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D6E7C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_01_0x809D0530/func_809D73D4.asm")
