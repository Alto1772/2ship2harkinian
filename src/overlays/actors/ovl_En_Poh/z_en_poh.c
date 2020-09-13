#include "z_en_poh.h"

#define FLAGS 0x00001205

#define THIS ((EnPoh*)thisx)

void EnPoh_Init(Actor* thisx, GlobalContext* globalCtx);
void EnPoh_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnPoh_Update(Actor* thisx, GlobalContext* globalCtx);
void EnPoh_Draw(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit En_Poh_InitVars = {
    ACTOR_EN_POH,
    ACTORTYPE_ENEMY,
    FLAGS,
    OBJECT_PO,
    sizeof(EnPoh),
    (ActorFunc)EnPoh_Init,
    (ActorFunc)EnPoh_Destroy,
    (ActorFunc)EnPoh_Update,
    (ActorFunc)EnPoh_Draw
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/EnPoh_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/EnPoh_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2C910.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2C9B8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2CA4C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2CAA4.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2CB60.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2CBBC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2CD14.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2CD64.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2CEC8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2CF28.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2CFF8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2D07C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2D0E8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2D140.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2D2C0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2D300.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2D5DC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2D628.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2D694.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2D6EC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2D76C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2D7D4.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2D924.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2D980.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2DAD0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2DB44.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2DC50.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2DD2C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2DDF8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2E0B0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2E180.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2E1D8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2E230.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2E3B0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2E3F8.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2E438.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2E55C.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2E6C0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2E8E0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/EnPoh_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2ED14.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2EDD0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/EnPoh_Draw.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2F328.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Poh_0x80B2C6F0/func_80B2F37C.asm")
