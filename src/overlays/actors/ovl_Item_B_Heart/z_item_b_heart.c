#include "z_item_b_heart.h"

#define FLAGS 0x00000000

#define THIS ((ItemBHeart*)thisx)

void ItemBHeart_Init(Actor* thisx, GlobalContext* globalCtx);
void ItemBHeart_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ItemBHeart_Update(Actor* thisx, GlobalContext* globalCtx);
void ItemBHeart_Draw(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit Item_B_Heart_InitVars = {
    ACTOR_ITEM_B_HEART,
    ACTORTYPE_BOSS,
    FLAGS,
    OBJECT_GI_HEARTS,
    sizeof(ItemBHeart),
    (ActorFunc)ItemBHeart_Init,
    (ActorFunc)ItemBHeart_Destroy,
    (ActorFunc)ItemBHeart_Update,
    (ActorFunc)ItemBHeart_Draw
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_Item_B_Heart_0x808BCDF0/ItemBHeart_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Item_B_Heart_0x808BCDF0/ItemBHeart_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Item_B_Heart_0x808BCDF0/ItemBHeart_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Item_B_Heart_0x808BCDF0/func_808BCF54.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Item_B_Heart_0x808BCDF0/ItemBHeart_Draw.asm")
