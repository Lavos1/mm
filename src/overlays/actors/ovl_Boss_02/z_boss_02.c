#include "z_boss_02.h"
#include "overlays/actors/ovl_Door_Warp1/z_door_warp1.h"

#define FLAGS 0x00000035

#define THIS ((Boss02*)thisx)

void Boss02_Init(Actor* thisx, GlobalContext* globalCtx);
void Boss02_Destroy(Boss02* this, GlobalContext* globalCtx);
void Boss02_Update(Boss02* this, GlobalContext* globalCtx);
void Boss02_Draw(Boss02* this, GlobalContext* globalCtx);

void func_809DC78C(Actor* thisx, GlobalContext* globalCtx);
void func_809DD0A8(Actor* thisx, GlobalContext* globalCtx);
void func_809DC218(Actor* thisx, GlobalContext* globalCtx);
void func_809DD0CC(GlobalContext* globalCtx);
void func_809DD2F8(GlobalContext* globalCtx);

void func_809DAA74(Boss02* this, GlobalContext* globalCtx);
void func_809DAAA8(Boss02* this, GlobalContext* globalCtx);
void func_809DEAC4(Boss02* this, GlobalContext* globalCtx);

void func_809DD934(Boss02* this, GlobalContext* globalCtx);
void func_809DAA98(Boss02* this, GlobalContext* globalCtx);
void func_809DAB78(Boss02* this, GlobalContext* globalCtx);






extern SkeletonHeader D_06009B10;
extern AnimationHeader D_06009C78;

extern Gfx D_06000230[];
extern Gfx D_060002E0[];
extern Gfx D_0401A620[];
extern Gfx D_04023348[];
extern Gfx D_04023428[];
extern UNK_TYPE D_06008650;

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

f32 D_809DF5B0 = 1.0f;

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

u8 D_809E0422;
Boss02* D_809E0424;
Boss02* D_809E0428;
Boss02* D_809E042C;
u8 D_809E0430;
DoorWarp1* D_809E0434;
Boss02Effects D_809E0438[150];

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

void func_809DAA74(Boss02 *this, GlobalContext *globalCtx) {
    this->actionFunc = func_809DAA98;
    this->actor.currPosRot.pos.y = -3000.0f;
}

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DAA98.asm")

void func_809DAAA8(Boss02 *this, GlobalContext *globalCtx) {
    this->actionFunc = func_809DAB78;
    SkelAnime_ChangeAnimTransitionRepeat(&this->skelAnime, &D_06009C78, 0.0f);
    if (D_809E042C->unk_1D20 != 0) {
        this->unk_0144 = 10;
    } else {
        this->unk_0144 = 100;
        this->unk_01A8 = 25.0f;
        D_809E042C->unk_1D7E = 100;
        this->actor.currPosRot.pos.x = 0.0f;
        if (D_809E0424 == this) {
            this->actor.currPosRot.pos.z = -1000.0f;
        } else {
            this->actor.currPosRot.pos.z = 1400.0f;
        }
    }
    this->actor.currPosRot.pos.y = -500.0f;
}

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DAB78.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DBFB4.asm")

void func_809DC218(Actor* thisx, GlobalContext *globalCtx) {
    Boss02 *this = THIS;
    s32 pad;
    Vec3f sp24;
    s32 sp20;

    this->unk_014C++;
    if (((this->unk_014C + this->actor.params) & 1) != 0) {
        sp24 = this->actor.currPosRot.pos;
        this->actor.topPosRot.pos = this->actor.currPosRot.pos;
        if (D_809E0422 != 0) {
            sp24.y = 5000.0f;
        } else {
            sp24.y = 2000.0f;
        }

        if ((this->actor.topPosRot.pos.y < func_800C3FA0(&globalCtx->colCtx, &sp20, &sp24, &this->actor)) || (D_809E0422 != 0)) {
            this->actor.flags &= ~1;
        } else {
            this->actor.flags |= 1;
        }
    }
}

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/Boss02_Update.asm")

void func_809DC78C(Actor* thisx, GlobalContext *globalCtx) {
    Boss02 *this = THIS;

    this->unk_01AC = D_809DF5B0;
    globalCtx->kankyoContext.unkEA = 0xD;
    if (D_809E0434 != NULL) {
        this->unk_1D74 = KREG(23) + -15.0f;
        D_801F4E30 = 0;
        globalCtx->kankyoContext.unkC3 = 1;
        globalCtx->unk18874 = 1;
    } else if (D_809E0422 == 0) {
        this->unk_1D74 = 0.0f;
        D_801F4E30 = this->unk_1D7C;
        globalCtx->kankyoContext.unkC3 = 0;
        globalCtx->unk18874 = 2;
    } else {
        this->unk_1D74 = KREG(23) + -15.0f;
        D_801F4E30 = ((KREG(24) * 0.1f) + 1.0f) * this->unk_1D7C;
        globalCtx->kankyoContext.unkC3 = 1;
        globalCtx->unk18874 = 1;
    }

    Math_SmoothScaleMaxS(&this->unk_1D7C, this->unk_1D7E, 1, 3);

    DECR(this->unk_0146);

    if (D_809E0434 == NULL) {
        if (D_809E0430 != 0) {
            D_809E0430--;
            if (D_809E0430 == 0) {
                func_801A89A8(0x801B);
            }
        }
    }

    func_809DD0CC(globalCtx);
    func_809DEAC4(this, globalCtx);
    func_809DD934(this, globalCtx);
}

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/Boss02_Draw.asm")

void func_809DD0A8(Actor* thisx, GlobalContext *globalCtx) {
    func_809DD2F8(globalCtx);
}

void func_809DD0CC(GlobalContext *globalCtx) {
    Boss02Effects* effect = (Boss02Effects*)globalCtx->actorEffects;
    f32 phi_f22;
    s16 i;

    if (D_809E0422 == 0) {
        phi_f22 = 0.0f;
    } else {
        phi_f22 = 3150.0f;
    }

    for (i = 0; i < 150; i++, effect++) {
        if (effect->unk_24) {
            effect->unk_26++;
            effect->unk_00.x += effect->unk_0C.x * D_809DF5B0;
            effect->unk_00.y += effect->unk_0C.y * D_809DF5B0;
            effect->unk_00.z += effect->unk_0C.z * D_809DF5B0;
            effect->unk_0C.y += effect->unk_1C;

            if (effect->unk_24 < 3) {
                Math_SmoothScaleMaxF(&effect->unk_34, effect->unk_38, 0.1f, 0.1f);
                if (effect->unk_24 == 2) {
                    effect->unk_2C -= 0x12;
                } else {
                    effect->unk_2C -= 0xF;
                }
                if (effect->unk_2C <= 0) {
                    effect->unk_24 = 0;
                }
            } else if (effect->unk_24 == 3) {
                effect->unk_2E += 0x1000;
                effect->unk_30 += 0x1500;
                if ((effect->unk_00.y < phi_f22) || (effect->unk_26 >= 0x33)) {
                    effect->unk_24 = 0;
                }
            } else if (effect->unk_24 == 4) {
                Math_SmoothScaleMaxF(&effect->unk_34, 80.0f, 0.2f, 20.0f);
                effect->unk_2C -= 0xF;
                if (effect->unk_2C <= 0) {
                    effect->unk_24 = 0;
                }
            }
        }
    }
}

void func_809DD2F8(GlobalContext *globalCtx) {
    u8 flag = 0;
    Boss02Effects* effect = (Boss02Effects*)globalCtx->actorEffects;
    s16 i;
    s32 phi_a0;

    {
        GraphicsContext* oGfxCtx = globalCtx->state.gfxCtx;

        func_8012C28C(globalCtx->state.gfxCtx);
        func_8012C2DC(globalCtx->state.gfxCtx);
        
        for (i = 0; i < 150; i++, effect++) {
            if (effect->unk_24 == 1) {
                if (!flag) {
                    gSPDisplayList(oGfxCtx->polyXlu.p++, D_06000230);
                    gDPSetEnvColor(oGfxCtx->polyXlu.p++, 185, 140, 70, 128);
                    flag++;
                }

                phi_a0 = effect->unk_2C & 0xFF;
                if (effect->unk_2C >= 0x100) {
                    phi_a0 = 0xFF;
                }

                gDPSetPrimColor(oGfxCtx->polyXlu.p++, 0, 0, 185, 140, 70, phi_a0);
                gSPSegment(oGfxCtx->polyXlu.p++, 0x08, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, effect->unk_26 + (i * 3), (effect->unk_26 + (i * 3)) * 5, 0x20, 0x40, 1, 0, 0, 0x20, 0x20));
                
                SysMatrix_InsertTranslation(effect->unk_00.x, effect->unk_00.y, effect->unk_00.z, 0);
                SysMatrix_NormalizeXYZ(&globalCtx->unk187FC);
                SysMatrix_InsertScale(effect->unk_34 * D_809DF5B0, effect->unk_34 * D_809DF5B0, 1.0f, 1);
                
                gSPMatrix(oGfxCtx->polyXlu.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(oGfxCtx->polyXlu.p++, D_060002E0);
            }
        }

        effect = (Boss02Effects*)globalCtx->actorEffects;
        for (i = 0, flag = 0; i < 150; i++, effect++) {
            if (effect->unk_24 == 3) {
                if (!flag) {
                    gDPSetCombineLERP(oGfxCtx->polyOpa.p++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
                    gDPSetPrimColor(oGfxCtx->polyOpa.p++, 0, 0x01, 100, 100, 120, 255);
                    flag++;
                }
                SysMatrix_InsertTranslation(effect->unk_00.x, effect->unk_00.y, effect->unk_00.z, 0);
                SysMatrix_InsertYRotation_s(effect->unk_30, 1);
                SysMatrix_InsertXRotation_s(effect->unk_2E, 1);
                SysMatrix_InsertScale(effect->unk_34 * D_809DF5B0, effect->unk_34 * D_809DF5B0, effect->unk_34 * D_809DF5B0, 1);
                
                gSPMatrix(oGfxCtx->polyOpa.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(oGfxCtx->polyOpa.p++, D_0401A620);
            }
        }

        effect = (Boss02Effects*)globalCtx->actorEffects;
        for (i = 0, flag = 0; i < 150; i++, effect++) {
            if (effect->unk_24 == 4) {
                if (!flag) { //! @bug - dev forgot to set flag to 1, should only apply to first entry?
                    gSPDisplayList(oGfxCtx->polyXlu.p++, D_04023348);
                    gDPSetEnvColor(oGfxCtx->polyXlu.p++, 255, 0, 0, 128);
                }

                gDPSetPrimColor(oGfxCtx->polyXlu.p++, 0, 0, 255, 255, 200, (u8)effect->unk_2C);

                SysMatrix_InsertTranslation(effect->unk_00.x, effect->unk_00.y, effect->unk_00.z, 0);
                SysMatrix_NormalizeXYZ(&globalCtx->unk187FC);
                SysMatrix_InsertScale(effect->unk_34 * D_809DF5B0, effect->unk_34 * D_809DF5B0, 1.0f, 1);
                
                gSPMatrix(oGfxCtx->polyXlu.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(oGfxCtx->polyXlu.p++, D_04023428);
            }
        }


        effect = (Boss02Effects*)globalCtx->actorEffects;
        flag = 0;
        for (i = 0; i < 150; i++, effect++) {
            if (effect->unk_24 == 2) {
                if (!flag) {
                    gSPDisplayList(oGfxCtx->polyXlu.p++, D_06000230);
                    gDPSetEnvColor(oGfxCtx->polyXlu.p++, 30, 30, 30, 128);
                    flag++;
                }

                gDPSetPrimColor(oGfxCtx->polyXlu.p++, 0, 0, 30, 30, 30, (u8)effect->unk_2C);
                gSPSegment(oGfxCtx->polyXlu.p++, 0x08, Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, effect->unk_26 + (i * 3), (effect->unk_26 + (i * 3)) * 5, 0x20, 0x40, 1, 0, 0, 0x20, 0x20));

                SysMatrix_InsertTranslation(effect->unk_00.x, effect->unk_00.y, effect->unk_00.z, 0);
                SysMatrix_NormalizeXYZ(&globalCtx->unk187FC);
                SysMatrix_InsertScale(effect->unk_34 * D_809DF5B0, effect->unk_34 * D_809DF5B0, 1.0f, 1);
                
                gSPMatrix(oGfxCtx->polyXlu.p++, SysMatrix_AppendStateToPolyOpaDisp(globalCtx->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(oGfxCtx->polyXlu.p++, D_060002E0);
            }
        }
    }
}

GLOBAL_ASM("asm/non_matchings/ovl_Boss_02_0x809DA1D0/func_809DD934.asm")

void func_809DEAC4(Boss02 *this, GlobalContext *globalCtx) {
    ActorPlayer *player = PLAYER;
    Boss02 *sp68;
    Vec3f sp5C;
    f32 sp58 = 0.0f;

    this->unk_1D1C++;
    if (this->unk_0194 == 0) {
        sp68 = D_809E0424;
    } else {
        sp68 = D_809E0428;
    }

    switch (this->unk_1D20) {
        case 0:
            break;

        case 1:
            if ((gSaveContext.perm.weekEventReg[52] & 0x20) || ((KREG(13) + 15) >= this->unk_1D1C)) {
                break;
            }
            func_800EA0D4(globalCtx, &globalCtx->csCtx);
            this->unk_1D22 = func_801694DC(globalCtx);
            func_80169590(globalCtx, 0, 1);
            func_80169590(globalCtx, this->unk_1D22, 7);
            this->unk_1D20 = 2;
            this->unk_1D1C = 0;

        case 2:
            player->base.shape.rot.y = -0x8000;
            player->base.currPosRot.rot.y = player->base.shape.rot.y;
            this->unk_1D24.x = player->base.currPosRot.pos.x - 20.0f;
            this->unk_1D24.y = (func_800B6FC8(player) + player->base.currPosRot.pos.y) - 29.0f;
            this->unk_1D24.z = player->base.currPosRot.pos.z - 50;

            this->unk_1D30.x = player->base.currPosRot.pos.x;
            this->unk_1D30.y = (func_800B6FC8(player) + player->base.currPosRot.pos.y) - 17.0f;
            this->unk_1D30.z = player->base.currPosRot.pos.z;
            if (this->unk_1D1C >= 0x1E) {
                if (this->unk_1D1C == 0x1E) {
                    func_8013EC44(0.0f, 0x32, 0xC8, 1);
                }
                this->unk_0150 += 0x4000;
                sp58 = (Math_Sins(this->unk_0150) * (BREG(19) + 5)) * 0.1f;
                SysMatrix_InsertZRotation_f(Math_Sins(this->unk_1D1C * 12288) * ((KREG(28) * 0.001f) + 0.017f), 0);
                SysMatrix_GetStateTranslationAndScaledY(1.0f, &this->unk_1D3C);
                func_8019F128(0x2150);
            }

            if (this->unk_1D1C == 0x14) {
                this->unk_1D7E = 0x64;
            }
            if (this->unk_1D1C == 0x2D) {
                func_800B7298(globalCtx, &this->actor, 0x15);
                D_809E0430 = KREG(91) + 0x2B;
            }
            if (this->unk_1D1C == 0x55) {
                D_809E0424->unk_0144 = 0xB;
                D_809E0424->unk_014C = 0;
            }
            if (this->unk_1D1C == 0x5C) {
                func_8013EC44(0.0f, 0xFF, 0x1E, 0x64);
            }
            if (this->unk_1D1C == 0x64) {
                func_800B7298(globalCtx, &this->actor, 0x73);
            }
            if (this->unk_1D1C == 0x70) {
                this->unk_1D20 = 0xA;
                this->unk_1D1C = 0;
            }
            break;

        case 10:
            if (this->unk_1D1C < 0x136) {
                this->unk_1D48 = sp68->actor.currPosRot.pos;
                this->unk_1D24.x = (sp68->actor.currPosRot.pos.x * 50.0f) * 0.001f;
                this->unk_1D24.y = (sp68->actor.currPosRot.pos.y * 50.0f) * 0.001f;
                if (this->unk_1D24.y < 100.0f) {
                    this->unk_1D24.y = 100.0f;
                }
                this->unk_1D24.z = (sp68->actor.currPosRot.pos.z * 100) * 0.001f;
            }
            Math_SmoothScaleMaxF(&this->unk_1D30.x, this->unk_1D48.x, 0.1f, 3000.0f);
            Math_SmoothScaleMaxF(&this->unk_1D30.y, this->unk_1D48.y, 0.1f, 3000.0f);
            Math_SmoothScaleMaxF(&this->unk_1D30.z, this->unk_1D48.z, 0.1f, 3000.0f);
            if (this->unk_1D1C == 0x64) {
                D_809E0428->unk_0144 = 0xB;
                D_809E0428->unk_014C = 0;
                this->unk_0194 = 1;
            }
            if (this->unk_1D1C == (KREG(92) + 0x7D)) {
                Actor_TitleCardCreate(globalCtx, &globalCtx->actorCtx.titleCtxt, Lib_PtrSegToVirt(&D_06008650), 0xA0, 0xB4, 0x80, 0x28);
            }
            if (this->unk_1D1C == (BREG(27) + 0x14F)) {
                func_80169AFC(globalCtx, this->unk_1D22, 0);
                this->unk_1D22 = 0;
                func_800EA0EC(globalCtx, &globalCtx->csCtx);
                func_800B7298(globalCtx, &this->actor, 6);
                this->actor.flags |= 1;
                this->unk_1D20 = 0;
                D_809E0424->unk_0144 = D_809E0428->unk_0144 = 3;
                D_809E0424->unk_0146 = D_809E0428->unk_0146 = 0x3C;
                gSaveContext.owl.unk5 |= 0x20;
            }
            break;

        case 100:
            if (ActorCutscene_GetCurrentIndex() == -1) {
                func_800EA0D4(globalCtx, &globalCtx->csCtx);
                this->unk_1D22 = func_801694DC(globalCtx);
                func_80169590(globalCtx, 0, 1);
                func_80169590(globalCtx, this->unk_1D22, 7);
                this->unk_1D20 = 101;
                this->unk_1D1C = 0;
                this->unk_1D5C = 1.0f;
                this->unk_1D30 = sp68->actor.currPosRot.pos;
            } else {
                break;
            }

        case 101:
        case 102:
case_10x:
            if ((this->unk_1D20 == 101) || (this->unk_1D20 == 103)) {
                this->unk_1D48 = sp68->actor.currPosRot.pos;
            } else {
                this->unk_1D48 = sp68->unk_147C[sp68->unk_1678];
            }

            this->unk_1D24.x = player->base.currPosRot.pos.x;
            this->unk_1D24.y = player->base.currPosRot.pos.y + 100.0f;
            if (D_809E0422 == 0) {
                if (this->unk_1D24.y < 100.0f) {
                    this->unk_1D24.y = 100.0f;
                }
            } else if (this->unk_1D24.y < 3160.0f) {
                this->unk_1D24.y = 3160.0f;
            }

            if (this->unk_1D48.y < (100.0f * D_809DF5B0)) {
                this->unk_1D48.y = (100.0f * D_809DF5B0);
            }

            this->unk_1D24.z = player->base.currPosRot.pos.z;
            Math_SmoothScaleMaxF(&this->unk_1D30.x, this->unk_1D48.x, 0.3f, this->unk_1D5C * 500.0f);
            Math_SmoothScaleMaxF(&this->unk_1D30.y, this->unk_1D48.y, 0.3f, this->unk_1D5C * 500.0f);
            Math_SmoothScaleMaxF(&this->unk_1D30.z, this->unk_1D48.z, 0.3f, this->unk_1D5C * 500.0f);
            Math_SmoothScaleMaxF(&this->unk_1D5C, 1.0f, 1.0f, 0.02f);
            break;

        case 103:
            this->unk_0150 += 0x4000;
            sp58 = Math_Sins(this->unk_0150);
            sp58 = (sp58 * this->unk_0146) * 1.5f;
            if (this->unk_1D1C == 0x1E) {
                func_80169AFC(globalCtx, this->unk_1D22, 0);
                this->unk_1D22 = 0;
                func_800EA0EC(globalCtx, &globalCtx->csCtx);
                func_800B7298(globalCtx, &this->actor, 6);
                this->unk_1D20 = 0;
                this->actor.flags |= 1;
                sp68->unk_0144 = 10;
                if ((D_809E0424->unk_0144 >= 10) && (D_809E0428->unk_0144 >= 10)) {
                    f32 phi_f0;

                    this->unk_1D7E = 0;
                    if (D_809E0422 == 0) {
                        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, 0.0f, 30.0f, -150.0f, 0, 1, 0, 0);
                        phi_f0 = 60.0f;
                    } else {
                        Actor_Spawn(&globalCtx->actorCtx, globalCtx, ACTOR_ITEM_B_HEART, 0.0f, 3153.0f, -15.0f, 0, 1, 0, 0x23);
                        phi_f0 = 3155.0f;
                    }
                    D_809E0434 = (DoorWarp1*)Actor_SpawnWithParent(&globalCtx->actorCtx, &this->actor, globalCtx, ACTOR_DOOR_WARP1, 0.0f, phi_f0, 0.0f, 0, 0, 0, 1);
                    
                    if (D_809E0422 == 0) {
                        D_809E0434->unk_203 = 0;
                        D_809E0434->unk_204 = 1.0f;
                    } else {
                        D_809E0434->unk_203 = 1;
                        D_809E0434->unk_204 = 0.1f;
                    }
                }
            }
            goto case_10x;
    }

    if ((this->unk_1D20 != 0) && (this->unk_1D22 != 0)) {
        sp5C = this->unk_1D24;
        sp5C.y += sp58 * D_809DF5B0;
        func_8016981C(globalCtx, this->unk_1D22, &this->unk_1D30, &sp5C, &this->unk_1D3C);
        this->unk_1D44 = this->unk_1D3C = 0.0f;
        this->unk_1D40 = 1.0f;
        ShrinkWindow_SetLetterboxTarget(0x1B);
    }
}
