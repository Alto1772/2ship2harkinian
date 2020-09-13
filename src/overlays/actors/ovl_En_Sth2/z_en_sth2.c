#include "z_en_sth2.h"

#define FLAGS 0x00000009

#define THIS ((EnSth2*)thisx)

void EnSth2_Init(Actor* thisx, GlobalContext* globalCtx);
void EnSth2_Destroy(Actor* thisx, GlobalContext* globalCtx);
void EnSth2_Update(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit En_Sth2_InitVars = {
    ACTOR_EN_STH2,
    ACTORTYPE_NPC,
    FLAGS,
    GAMEPLAY_KEEP,
    sizeof(EnSth2),
    (ActorFunc)EnSth2_Init,
    (ActorFunc)EnSth2_Destroy,
    (ActorFunc)EnSth2_Update,
    (ActorFunc)NULL
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_En_Sth2_0x80BF74E0/EnSth2_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Sth2_0x80BF74E0/EnSth2_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Sth2_0x80BF74E0/func_80BF75A0.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Sth2_0x80BF74E0/EnSth2_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Sth2_0x80BF74E0/func_80BF7688.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Sth2_0x80BF74E0/func_80BF76AC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Sth2_0x80BF74E0/func_80BF77AC.asm")

GLOBAL_ASM("asm/non_matchings/ovl_En_Sth2_0x80BF74E0/func_80BF7814.asm")
