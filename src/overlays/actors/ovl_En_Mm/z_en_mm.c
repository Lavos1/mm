#include "z_en_mm.h"

#define FLAGS 0x00000010

#define THIS ((EnMm*)thisx)

void EnMm_Init(Actor* thisx, GlobalContext* globalCtx);
void EnMm_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnMm_Update(Actor* thisx, GlobalContext* globalCtx);
void EnMm_Draw(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit En_Mm_InitVars = {
    ACTOR_EN_MM,
    ACTORTYPE_ITEMACTION,
    FLAGS,
    GAMEPLAY_KEEP,
    sizeof(EnMm),
    (ActorFunc)EnMm_Init,
    (ActorFunc)EnMm_Destroy,
    (ActorFunc)EnMm_Update,
    (ActorFunc)EnMm_Draw
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_En_Mm_0x80965BB0/func_80965BB0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Mm_0x80965BB0/func_80965BBC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Mm_0x80965BB0/EnMm_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Mm_0x80965BB0/EnMm_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Mm_0x80965BB0/func_80965D3C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Mm_0x80965BB0/func_80965DB4.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Mm_0x80965BB0/func_8096611C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Mm_0x80965BB0/EnMm_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Mm_0x80965BB0/EnMm_Draw.asm")
