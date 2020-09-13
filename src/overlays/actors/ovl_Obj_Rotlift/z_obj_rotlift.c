#include "z_obj_rotlift.h"

#define FLAGS 0x00000000

#define THIS ((ObjRotlift*)thisx)

void ObjRotlift_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjRotlift_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjRotlift_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjRotlift_Draw(Actor* thisx, GlobalContext* globalCtx);

/*
const ActorInit Obj_Rotlift_InitVars = {
    ACTOR_OBJ_ROTLIFT,
    ACTORTYPE_BG,
    FLAGS,
    OBJECT_ROTLIFT,
    sizeof(ObjRotlift),
    (ActorFunc)ObjRotlift_Init,
    (ActorFunc)ObjRotlift_Destroy,
    (ActorFunc)ObjRotlift_Update,
    (ActorFunc)ObjRotlift_Draw
};
*/

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Rotlift_0x80B95E20/func_80B95E20.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Rotlift_0x80B95E20/ObjRotlift_Init.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Rotlift_0x80B95E20/ObjRotlift_Destroy.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Rotlift_0x80B95E20/ObjRotlift_Update.asm")

GLOBAL_ASM("asm/non_matchings/ovl_Obj_Rotlift_0x80B95E20/ObjRotlift_Draw.asm")
