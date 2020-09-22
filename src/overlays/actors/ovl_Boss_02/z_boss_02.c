#include "z_boss_02.h"
#include "overlays/actors/ovl_Door_Warp1/z_door_warp1.h"

#define FLAGS 0x00000035

#define THIS ((Boss02*)thisx)

void Boss02_Init(Actor* thisx, GlobalContext* globalCtx);
void Boss02_Destroy(Boss02* this, GlobalContext* globalCtx);
void Boss02_Update(Boss02* this, GlobalContext* globalCtx);
void Boss02_Draw(Boss02* this, GlobalContext* globalCtx);

void func_809DC78C(Boss02* this, GlobalContext* globalCtx); // ACTOR
void func_809DD0A8(Boss02* this, GlobalContext* globalCtx); // ACTOR
void func_809DC218(Boss02* this, GlobalContext* globalCtx); // ACTOR

void func_809DAA74(Boss02* this, GlobalContext* globalCtx);
void func_809DAAA8(Boss02* this, GlobalContext* globalCtx);


extern SkeletonHeader D_06009B10;
extern AnimationHeader D_06009C78;

ActorDamageChart D_809DF550 = {
    0x00, 0xF1, 0x00, 0xF1, 
    0x00, 0xF1, 0x00, 0x00, 
    0xF2, 0xF1, 0xF0, 0x25, 
    0x31, 0x42, 0xF1, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xF1, 0xF1, 
    0xF1, 0xF2, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xF1, 
};

ActorDamageChart D_809DF570 = {
    0x00, 0xF1, 0x00, 0xF1, 
    0x00, 0xF1, 0x00, 0x00, 
    0xF2, 0xF1, 0xF0, 0x21, 
    0x35, 0x42, 0xF1, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xF1, 0xF1, 
    0xF1, 0xF2, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xF1, 
};

const ActorInit Boss_02_InitVars = {
    ACTOR_BOSS_02,
    ACTORTYPE_BOSS,
    FLAGS,
    OBJECT_BOSS02,
    sizeof(Boss02),
    (ActorFunc)Boss02_Init,
    (ActorFunc)Boss02_Destroy,
    (ActorFunc)Boss02_Update,
    (ActorFunc)Boss02_Draw
};

ColSphereGroupElementInit D_809DF614[22] = {
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 1, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 2, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 3, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 4, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 5, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 6, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 7, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 8, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 9, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 10, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 11, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 12, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 13, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 14, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 15, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 16, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 17, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 18, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 19, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 20, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 21, { { 0, 0, 0 }, 85 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 0, { { 0, 0, 0 }, 130 }, 100 },
    },
};

ColSphereGroupInit D_809DF92C =
{
    { COLTYPE_METAL_SHIELD, 0x11, 0x0D, 0x09, 0x10, COLSHAPE_JNTSPH },
    22, D_809DF614,
};

ColSphereGroupElementInit D_809DF93C[2] = {
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 0, { { 0, 0, 0 }, 130 }, 100 },
    },
    {
        { 0x03, { 0xF7CFFFFF, 0x04, 0x10 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
        { 22, { { 0, 0, 0 }, 110 }, 100 },
    },
};

ColSphereGroupInit D_809DF984 =
{
    { COLTYPE_UNK0, 0x11, 0x09, 0x09, 0x10, COLSHAPE_JNTSPH },
    2, D_809DF93C,
};

ColCylinderInit D_809DF994 =
{
    { COLTYPE_METAL_SHIELD, 0x11, 0x0D, 0x39, 0x10, COLSHAPE_CYLINDER },
    { 0x02, { 0xF7CFFFFF, 0x04, 0x00 }, { 0xF7CFFFFF, 0x00, 0x00 }, 0x01, 0x01, 0x01 },
    { 150, 200, 0, { 0, 0, 0 } },
};

Boss02* D_809E0424;
Boss02* D_809E0428;
Boss02* D_809E042C;
s8 D_809E0430;
DoorWarp1* D_809E0434;
Boss02Effects D_809E0438[1];

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DA1D0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DA22C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DA24C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DA264.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DA344.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DA460.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DA50C.asm")

void Boss02_Init(Actor* thisx, GlobalContext *globalCtx) {
    Boss02 *this = THIS;
    s32 i;
    s32 pad[2];

    if ((gSaveContext.perm.weekEventReg[52] & 0x20) && (this->actor.params == 0)) {
        D_809E0434 = (DoorWarp1*)Actor_SpawnWithParent(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_DOOR_WARP1, 0.0f, 60.0f, 0.0f, 0, 0, 0, 1);
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, 0.0f, 30.0f, -150.0f, 0, 1, 0, 0);
    }

    this->actor.unk1F = 10;
    this->unk_1D44 = this->unk_1D3C = 0.0f;
    this->unk_1D40 = 1.0f;
    if (this->actor.params == 0xC8) {
        D_809E042C = this;
        globalCtx->actorEffects = D_809E0438;
        this->actor.update = func_809DC78C;
        this->actor.draw = func_809DD0A8;
        this->actor.flags &= ~1;
        this->unk_1D70 = 0.00999999977648f;
        if ((KREG(64) != 0) || (gSaveContext.owl.unk5 & 0x20) || (D_809E0434 != NULL)) {
            this->unk_1D20 = 0;
            D_809E0430 = KREG(15) + 20;
        } else {
            this->unk_1D20 = 1;
        }
        XREG(41) = KREG(14) + 20;
        this->unk_01AC = 1.0f;
        Actor_SpawnWithParent(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_EN_TANRON5, 0.0f, 1000.0f, 0.0f, 0, 0, 0, 0);
        return;
    }

    if (this->actor.params == 0x64) {
        this->actor.update = func_809DC218;
        this->actor.draw = NULL;
        this->actor.naviEnemyId = 0x2E;
        return;
    }

    if (this->actor.params != 0x23) {
        this->actor.params = 0;
        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_BOSS_02, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0xC8);
        D_809E0424 = this;
        D_809E0428 = (Boss02*)Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_BOSS_02, this->actor.currPosRot.pos.x, this->actor.currPosRot.pos.y, this->actor.currPosRot.pos.z, this->actor.currPosRot.rot.x, this->actor.currPosRot.rot.y, this->actor.currPosRot.rot.z, 0x23);
        D_809E0424->actor.colChkInfo.damageChart = &D_809DF570;
        D_809E0428->actor.colChkInfo.damageChart = &D_809DF550;
        D_809E0424->unk_1674 = D_809E0428;
        D_809E0428->unk_1674 = D_809E0424;
    }

    this->actor.colChkInfo.mass = 0xFE;
    this->actor.colChkInfo.health = 0x14;
    Actor_SetScale(&this->actor, 0.01f);
    SkelAnime_Init(globalCtx, &this->skelAnime, &D_06009B10, &D_06009C78, this->limbDrawTable, this->transitionDrawTable, 13);
    Collision_InitSphereGroup(globalCtx, &this->colliderSphere1, &this->actor, &D_809DF92C, this->colliderSphere1Items);
    Collision_InitSphereGroup(globalCtx, &this->colliderSphere2, &this->actor, &D_809DF984, this->colliderSphere2Items);
    Collision_InitCylinder(globalCtx, &this->colliderCylinder, &this->actor, &D_809DF994);
    
    if (D_809E0434 != 0) {
        func_809DAA74(this, globalCtx);
    } else {
        func_809DAAA8(this, globalCtx);
    }

    for (i = 0; i < 200; i++) {
        this->unk_01BC[i].x = this->actor.currPosRot.pos.x;
        this->unk_01BC[i].y = this->actor.currPosRot.pos.y;
        this->unk_01BC[i].z = this->actor.currPosRot.pos.z;
    }

    this->unk_014C = randZeroOneScaled(1000.0f);
    this->unk_1678 = 0x16;
    Actor_SpawnWithParent(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_BOSS_02, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0x64);
}

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/Boss02_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DAA74.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DAA98.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DAAA8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DAB78.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DBFB4.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DC218.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/Boss02_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DC78C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/Boss02_Draw.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DD0A8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DD0CC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DD2F8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DD934.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DEAC4.asm")
