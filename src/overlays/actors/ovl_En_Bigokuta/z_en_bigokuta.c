#include "z_en_bigokuta.h"

#define FLAGS 0x00000005

#define THIS ((EnBigokuta*)thisx)

void EnBigokuta_Init(Actor* thisx, GlobalContext* globalCtx);
void EnBigokuta_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnBigokuta_Update(Actor* thisx, GlobalContext* globalCtx);
void EnBigokuta_Draw(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit En_Bigokuta_InitVars = {
    ACTOR_EN_BIGOKUTA,
    ACTORTYPE_BOSS,
    FLAGS,
    OBJECT_BIGOKUTA,
    sizeof(EnBigokuta),
    (ActorFunc)EnBigokuta_Init,
    (ActorFunc)EnBigokuta_Destroy,
    (ActorFunc)EnBigokuta_Update,
    (ActorFunc)EnBigokuta_Draw
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/EnBigokuta_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/EnBigokuta_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC28B4.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC299C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC2A1C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC2A7C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC2B4C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC2B98.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC2C30.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC2C84.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC2CE8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC2DAC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC2EBC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC2F20.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC2F64.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC3054.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC30EC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC31EC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC33A4.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC33C0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC3460.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC34A8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC35E8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC3650.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC3930.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC39A0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/EnBigokuta_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC3D48.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/func_80AC4204.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Bigokuta_0x80AC26F0/EnBigokuta_Draw.asm")
