#include "z_obj_syokudai.h"

#define FLAGS 0x00000410

#define THIS ((ObjSyokudai*)thisx)

void ObjSyokudai_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjSyokudai_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjSyokudai_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjSyokudai_Draw(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit Obj_Syokudai_InitVars = {
    ACTOR_OBJ_SYOKUDAI,
    ACTORTYPE_PROP,
    FLAGS,
    OBJECT_SYOKUDAI,
    sizeof(ObjSyokudai),
    (ActorFunc)ObjSyokudai_Init,
    (ActorFunc)ObjSyokudai_Destroy,
    (ActorFunc)ObjSyokudai_Update,
    (ActorFunc)ObjSyokudai_Draw
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Syokudai_0x808BC010/ObjSyokudai_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Syokudai_0x808BC010/ObjSyokudai_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Syokudai_0x808BC010/ObjSyokudai_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Syokudai_0x808BC010/ObjSyokudai_Draw.asm")
