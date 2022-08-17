#include "global.h"

void MapDisp_DestroyIMap(PlayState* play);
void MapDisp_InitIMap(PlayState* play);
void func_80103090(MinimapEntry*, s32*, s32*);
void func_80105FE0(PlayState* play, s32 x, s32 z, s32 rot);
void func_80106644(PlayState* play, s32 x, s32 z, s32 rot);
s32 func_801039EC(PlayState* play);
void func_80103A58(PlayState* play, Actor* actor);

void func_80106D5C(PlayState*, s32, s32, s32, s32, f32, s32);
void func_80107B78(PlayState*, s32, s32, s32, s32, f32);
void func_80108124(PlayState*, s32, s32, s32, s32, f32, s32);
void func_80108558(PlayState*, s32, s32, s32, s32, f32, s32);
s32 func_80108A64(PlayState*);
s32 func_80109BA0(s32);
s16 func_80109F78(s32);

void func_80109D40(s32, s32*, s32*, void*);
void func_80109DD8(s32, s32*, s32*);

extern s32          D_801BEAD0[4]; // G_IM_SIZ
extern s32          D_801BEAE0[4]; // siz_LOAD_BLOCK
extern u32          D_801BEAF0[4]; // siz_INCR
extern s32          D_801BEB00[4]; // siz_SHIFT
extern u32          D_801BEB10[4]; // siz_BYTES
extern u32          D_801BEB20[4]; // siz_LINE_BYTES

extern TexturePtr   D_801BEB38;
extern T_801BEBB8   D_801BEBB8;
extern s16          D_801BEBFA; // D_801BEBB8.unk42

extern MinimapList  D_801BEC14; //D_801F5130
extern s32          D_801BEC1C; //current scene's no. of rooms
extern s32          D_801BEC20; //MinimapChest count
extern TransitionActorList  D_801BEC24;
extern Color_RGBA8  D_801BEC2C[12]; // cat colors
extern T_801BEC5C   D_801BEC5C[5];
extern T_801BEC70   D_801BEC70;
extern u16          D_801BEC84[0x10]; //palette 0
extern u16          D_801BECA4[0x10]; //palette 1
extern u16          D_801BECC4[0x10]; //palette 2
extern TexturePtr   D_801BECE4[6];
extern TexturePtr   D_801BED00[9];
extern T_801BED24   D_801BED24[2];

extern MinimapEntry D_801F5130[0x50];
extern MinimapChest D_801F5270[32];
extern TransitionActorEntry D_801F53B0[48];
extern T_801F56B0   D_801F56B0;

extern TexturePtr   D_02002460;
extern TexturePtr   D_02003F20;
extern Gfx          D_0401ED00[];
extern TexturePtr   D_0C000000;

void func_80102E40(s32 arg0, s32 arg1) {
    if (func_80109A98(arg1) != 0) {
        func_80178E3C(SEGMENT_ROM_START(map_i_static), arg1, arg0, func_80109A98(arg1));
    }
}

void func_80102E90(PlayState* play, s16* arg1) {
    *arg1 = -1;
}

void func_80102EA4(PlayState* play, s16* arg1) {

}

void func_80102EB4(u32 param_1) {
    D_801BEBB8.unk20 |= param_1;
}

void func_80102ED0(u32 param_1) {
    D_801BEBB8.unk20 &= ~param_1;
}

s32 func_80102EF0(PlayState* play) {
    MinimapEntry* entry;
    s8 curRoom;

    if (Map_IsInBossArea(play) == true) {
        return true;
    }
    curRoom = play->roomCtx.currRoom.num;
    if (curRoom == -1) {
        return false;
    }
    entry = &D_801BEBB8.unk0->entry[curRoom];
    if (entry->unk0 == 0xFFFF) {
        return false;
    }
    if (func_80109AD8(entry->unk0) == 0x3A) {
        return false;
    }
    return true;
}

f32 func_80102F9C(f32 arg0) {
    s32 i;

    if ((D_801BEBB8.unk48[D_801BEBB8.unk40-1] - 80.0f) < arg0) {
        return D_801BEBB8.unk48[D_801BEBB8.unk40-1];
    }
    for (i = D_801BEBB8.unk40 - 2; i >= 0; i--) {
        if (((D_801BEBB8.unk48[i] - 80.0f) < arg0) && (arg0 < (D_801BEBB8.unk48[i + 1] + 80.0f))) {
            return D_801BEBB8.unk48[i];
        }
    }
    if (arg0 < (D_801BEBB8.unk48[0] + 80.0f)) {
        return D_801BEBB8.unk48[0];
    }
    return 0.0f;
}

void func_80103090(MinimapEntry* arg0, s32* out1, s32* out2){
    func_80109754(arg0->unk0, out1, out2);
}

void func_801030B4(MinimapEntry *arg0, s32 *arg1) {
    func_8010983C(arg0->unk0, arg1);
    if (*arg1 == 0) {
        *arg1 = 0x14;
    }
}

void func_801030F4(MinimapEntry* arg0, s32* arg1, s32* arg2) {
    s32 sp2C;
    s32 sp28;
    s32 temp_v0;
    s32 temp_v0_2;

    if (arg0->unk0 == 0xFFFF) {
        *arg1 = 0;
        *arg2 = 0;
        return;
    }
    func_80103090(arg0, &sp2C, &sp28);
    func_801097C8(arg0->unk0, arg1, arg2);
    if (arg0->unk8 & 1) {
        temp_v0 = sp2C / 2;
        *arg1 = (temp_v0 - *arg1) + temp_v0;
    }
    if (arg0->unk8 & 2) {
        temp_v0_2 = sp28 / 2;
        *arg2 = (temp_v0_2 - *arg2) + temp_v0_2;
    }
}

void func_801098A0(u16, s32*);
s32 func_80109908(u16);

#ifdef NON_MATCHING
// https://decomp.me/scratch/XPZfI
void func_801031D0(PlayState* play, TexturePtr arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5) {
    MinimapEntry* spCC;
    s32 spC8;
    s32 spC4;
    s16 var_a0_4;
    s16 var_a3;
    s32 var_t0;
    s32 var_t1;
    s32 var_v1_4;
    s32 var_v1_5;
    Color_RGBA8 spAC;
    s32 spA8;

    spCC = &D_801BEBB8.unk0->entry[arg4];
    if ((spCC->unk0 != 0xFFFF) && (arg1 != 0)) {
        func_80103090(spCC, &spC8, &spC4);
        OPEN_DISPS(play->state.gfxCtx);
        func_8012C654(play->state.gfxCtx);
        func_801094A0(func_80109908(spCC->unk0), &spAC);
        gDPSetPrimColor(OVERLAY_DISP++, 0, 0, spAC.r, spAC.g, spAC.b, (s32)(play->interfaceCtx.minimapAlpha * arg5 * spAC.a / 255.0f));
        func_801098A0(spCC->unk0, &spA8);
        switch (spA8) {
        case 1:
            gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
            gDPLoadTextureBlock_4b(OVERLAY_DISP++, arg1, G_IM_FMT_IA, spC8, spC4, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK , G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
        case 3:
            gDPSetCombineLERP(OVERLAY_DISP++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
            gDPLoadTextureBlock_4b(OVERLAY_DISP++, arg1, G_IM_FMT_I, spC8, spC4, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK , G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
        default:
        case 0:
            gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
            gDPLoadTextureBlock_4b(OVERLAY_DISP++, arg1, G_IM_FMT_I, spC8, spC4, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK , G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
        }

        var_t1 = (spCC->unk8 & 1) ? (spC8 - 1) << 5 : 0;
        var_t0 = (spCC->unk8 & 2) ? 0 : (spC4 - 1) << 5;

        var_v1_4 = (spCC->unk8 & 1) ? -1 : 1;
        var_a3 = var_v1_4 << 0xA;
        var_v1_5 = (spCC->unk8 & 2) ? 1 : -1;

        if ((spCC->unk8 & 1) != 0) {
            var_a3 = var_a3 & 0xFFFF;
        }
        if ((spCC->unk8 & 2) != 0) {
            var_a0_4 = var_v1_5 << 0xA;
        } else {
            var_a0_4 = (var_v1_5 << 0xA) & 0xFFFF;
        }
        gSPTextureRectangle(OVERLAY_DISP++, arg2 << 2, arg3 << 2, (spC8 + arg2) << 2, (arg3 + spC4) << 2, G_TX_RENDERTILE, var_t1, var_t0, var_a3, var_a0_4);
        CLOSE_DISPS(play->state.gfxCtx);
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_map_disp/func_801031D0.s")
#endif

s32 func_801039EC(PlayState *play) {
    if (play->sceneNum == SCENE_35TAKI) {
        return true;
    }
    return false;
}

s32 func_80103A10(PlayState* play) {
    if ((gSaveContext.save.entranceIndex == 0x6400) && (Cutscene_GetSceneSetupIndex(play) != 0)) {
        return false;
    }
    return true;
}

#define	gDPLoadTextureBlock_TEST(pkt, timg, fmt, siz_LOAD_BLOCK, siz_INCR, siz_SHIFT, siz_BYTES, siz_LINE_BYTES, siz, width, height,		\
		pal, cms, cmt, masks, maskt, shifts, shiftt)		\
_DW({									\
	gDPSetTextureImage(pkt, fmt, siz_LOAD_BLOCK, 1, timg);	\
	gDPSetTile(pkt, fmt, siz_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 	\
		0 , cmt, maskt, shiftt, cms, masks, shifts);		\
	gDPLoadSync(pkt);						\
	gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, 				\
		(((width)*(height) + siz_INCR) >> siz_SHIFT) -1,	\
		CALC_DXT(width, siz_BYTES)); 				\
	gDPPipeSync(pkt);						\
	gDPSetTile(pkt, fmt, siz,					\
		(((width) * siz_LINE_BYTES)+7)>>3, 0,			\
		G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks,	\
		shifts);						\
	gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0,			\
		((width)-1) << G_TEXTURE_IMAGE_FRAC,			\
		((height)-1) << G_TEXTURE_IMAGE_FRAC);			\
})

#ifdef NON_MATCHING
// https://decomp.me/scratch/TR5Jq
void func_80103A58(PlayState *play, Actor *actor) {
    MinimapEntry *spDC;
    s32 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    s32 spC8;
    s32 spC4;
    f32 spC0;
    u32 pad;
    s32 var_v0;
    Player *spB4;
    u32 pad2;
    s32 spAC;
    //GraphicsContext *spA8;
    
    spDC = &D_801BEBB8.unk0->entry[D_801BEBB8.curRoom];
    spB4 = GET_PLAYER(play);
    if (spDC->unk0 != 0xFFFF) {
        func_801030F4(spDC, &spD0, &spCC);
        func_80103090(spDC, &spC8, &spC4);
        var_v0 = D_801BEBB8.unk0->unk4;
        if (D_801BEBB8.unk0->unk4 == 0) {
            var_v0 = 0x14;
        } else if (D_801BEBB8.unk0->unk4 == -1) {
            func_801030B4(spDC, &spAC);
            var_v0 = spAC;
        }
        spC0 = 1.0f / (f32) var_v0;
        if (func_801039EC(play) == 0) {
            spD8 = (s32) ((actor->world.pos.x - (f32) spDC->unk2) * spC0) + D_801BEBB8.unk8 + D_801BEBB8.unkC - D_801BEBB8.unk8 + spD0;
            spD4 = (s32) ((actor->world.pos.z - (f32) spDC->unk6) * spC0) + D_801BEBB8.unkA + D_801BEBB8.unkE - D_801BEBB8.unkA + spCC;
        } else {
            spD8 = - (s32) ((actor->world.pos.x - (f32) spDC->unk2) * spC0) + D_801BEBB8.unk8  + D_801BEBB8.unkC - D_801BEBB8.unk8 + spD0;
            spD4 = - (s32) ((actor->world.pos.z - (f32) spDC->unk6) * spC0) + D_801BEBB8.unkA  + D_801BEBB8.unkE - D_801BEBB8.unkA + spCC;
        }
        if ((spD8 > 0) && (spD8 < 0x3FF) && (spD4 > 0) && (spD4 < 0x3FF)) {
            OPEN_DISPS(play->state.gfxCtx);
            if ((actor->category == ACTORCAT_PLAYER) && (actor->flags & 0x80000000)) {
                s16 spA2;
                func_8012C8D4(play->state.gfxCtx); 
                gSPMatrix(OVERLAY_DISP++, &gIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
                gDPSetEnvColor(OVERLAY_DISP++, 0, 0, 0, play->interfaceCtx.minimapAlpha);
                gDPSetCombineMode(OVERLAY_DISP++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
                gDPSetRenderMode(OVERLAY_DISP++, G_RM_AA_DEC_LINE, G_RM_NOOP2);

                Matrix_Translate((f32) spD8 - 160.0f, 120.0f - (f32) spD4, 0.0f, MTXMODE_NEW);
                Matrix_RotateXFApply(-1.6f);
                spA2 = (s32) (0x7FFF - actor->focus.rot.y) / 1024;
                if (func_801039EC(play) != 0) {
                    spA2 += 0x7FFF;
                }
                Matrix_RotateYF((f32) spA2 / 10.0f, MTXMODE_APPLY);
                Matrix_Scale(0.4f, 0.4f, 0.4f, MTXMODE_APPLY);
                gSPMatrix(OVERLAY_DISP++, Matrix_NewMtx(play->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 200, 255, 0, play->interfaceCtx.minimapAlpha);
                gSPDisplayList(OVERLAY_DISP++, &D_0401ED00);
                return;
            }
            if (actor->id == ACTOR_EN_BOX) {
                if (!Flags_GetTreasure(play, actor->params & 0x1F)) {
                    if (func_80102F9C(spB4->actor.world.pos.y) == func_80102F9C(actor->world.pos.y)) {
                        func_8012C654(play->state.gfxCtx);
                        gDPPipeSync(OVERLAY_DISP++);
                        gDPSetTextureLUT(OVERLAY_DISP++, G_TT_NONE);
                        gDPSetPrimColor(OVERLAY_DISP++, 0, 0, 255, 255, 255, play->interfaceCtx.minimapAlpha);
                        gDPSetEnvColor(OVERLAY_DISP++, 0, 0, 0, play->interfaceCtx.minimapAlpha);
                        gDPPipeSync(OVERLAY_DISP++);

                        gDPLoadTextureBlock_TEST(OVERLAY_DISP++, &D_02003F20, G_IM_FMT_RGBA,
                         D_801BEAE0[2], D_801BEAF0[2], D_801BEB00[2], D_801BEB10[2], D_801BEB20[2], D_801BEAD0[2], 8, 8, 0,
                        G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMASK,
                        G_TX_NOMASK,
                        G_TX_NOLOD,
                        G_TX_NOLOD);

                        // gDPSetTextureImage(OVERLAY_DISP++, G_IM_FMT_RGBA, D_801BEAE0.unk8, 1, &D_02003F20);
                        // gDPSetTile(OVERLAY_DISP++, G_IM_FMT_RGBA, D_801BEAE0.unk8, 0, 0x0000, G_TX_LOADTILE, 0,
                        //     G_TX_NOMIRROR | G_TX_WRAP, // cmt
                        //     G_TX_NOMASK, //maskt
                        //     G_TX_NOLOD, //shiftt
                        //     G_TX_NOMIRROR | G_TX_WRAP, //cms
                        //     G_TX_NOMASK, //masks
                        //     G_TX_NOLOD); //shifts
                        // gDPLoadSync(OVERLAY_DISP++);
                        // gDPLoadBlock(OVERLAY_DISP++, G_TX_LOADTILE, 0, 0,
                        //  ((D_801BEAF8 + 0x40) >> D_801BEB08) - 1,
                        //        (((D_801BEB18 * 8 >> 3 == 0)? 1 : D_801BEB18) + 0x7FF) 
                        //     /   ((D_801BEB18 * 8 >> 3 == 0)? 1 : D_801BEB18));
                        // gDPPipeSync(OVERLAY_DISP++);                        
                        // gDPSetTile(OVERLAY_DISP++, G_IM_FMT_RGBA, D_801BEAD8,
                        //   ((D_801BEB28 * 8) + 7) >> 3, 0x0000, G_TX_RENDERTILE, 0,
                        //     G_TX_NOMIRROR | G_TX_WRAP, // cmt
                        //     G_TX_NOMASK,
                        //     G_TX_NOLOD, 
                        //     G_TX_NOMIRROR | G_TX_WRAP, 
                        //     G_TX_NOMASK, 
                        //     G_TX_NOLOD);
                        // gDPSetTileSize(OVERLAY_DISP++, G_TX_RENDERTILE, 0, 0, 0x001C, 0x001C);
                        gSPTextureRectangle(OVERLAY_DISP++, (spD8 - 4) << 2, (spD4 - 4) << 2, (spD8 + 4) << 2, (spD4 + 4) << 2, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                        return;
                    }
                }
            }
            func_8012C654(play->state.gfxCtx);
            gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
            if (actor->flags & 0x80000000) {
                gDPSetPrimColor(OVERLAY_DISP++, 0, 0, D_801BEC2C[actor->category].r, D_801BEC2C[actor->category].g, D_801BEC2C[actor->category].b, play->interfaceCtx.minimapAlpha);
                gSPTextureRectangle(OVERLAY_DISP++, (spD8 - 1) << 2, (spD4 - 1) << 2, (spD8 + 1) << 2, (spD4 + 1) << 2, G_TX_RENDERTILE, 0, 0, 0x0001, 0x0001);
            }
            CLOSE_DISPS(play->state.gfxCtx);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_map_disp/func_80103A58.s")
#endif

void func_8010439C(PlayState *play) {
    ActorContext *actorCtx;
    s32 i;

    if (play->roomCtx.currRoom.num != -1) {
        OPEN_DISPS(play->state.gfxCtx);
        gDPLoadTextureBlock_4b(OVERLAY_DISP++, &D_801BEB38, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        actorCtx = &play->actorCtx;
        for (i = 0; i < ACTORCAT_MAX; i++) {
            Actor *actor = actorCtx->actorLists[i].first;
            if (actor != NULL) {
                do {
                    if (
                        (actor->update != NULL) 
                        && (actor->init == NULL) 
                        && (Object_IsLoaded(&play->objectCtx, actor->objBankIndex))
                        && ((actor->id == ACTOR_EN_BOX) || (i == ACTORCAT_PLAYER) || (actor->flags & ACTOR_FLAG_80000000))
                        && ((D_801BEBB8.curRoom == actor->room) || (actor->room == -1))) {
                        func_80103A58(play, actor);
                    }
                    actor = actor->next;
                } while (actor != NULL);
            }
        }
        CLOSE_DISPS(play->state.gfxCtx);
    }
}

void func_801045AC(PlayState* play, Actor* actor) {
    MinimapEntry* sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    Player* player;
    f32 sp5C;
    f32 temp_fv1;
    s32 var_v1;
    f32 sp50;
    
    player = GET_PLAYER(play);
    temp_fv1 = fabsf(player->actor.world.pos.y - actor->world.pos.y);
    sp50 = 1.0f -  (1 / 350.0f) * temp_fv1;
    if (sp50 < 0) {
        sp50 = 0.0f;
    }
    sp7C = &D_801BEBB8.unk0->entry[D_801BEBB8.curRoom];
    if (sp7C->unk0 != 0xFFFF) {
        func_801030F4(sp7C, &sp70, &sp6C);
        func_80103090(sp7C, &sp68, &sp64);
        
        var_v1 = D_801BEBB8.unk0->unk4;
        if (D_801BEBB8.unk0->unk4 == 0) {
            var_v1 = 0x14;
        } else if (D_801BEBB8.unk0->unk4 == -1) {
            s32 sp4C;
            func_801030B4(sp7C, &sp4C);
            var_v1 = sp4C;
        }
        sp5C = 1.0f / var_v1;
        if (func_801039EC(play) == 0) {
            sp78 = (((s32) ((actor->world.pos.x - sp7C->unk2) * sp5C) + D_801BEBB8.unk8 + D_801BEBB8.unkC) - D_801BEBB8.unk8) + sp70;
            sp74 = (((s32) ((actor->world.pos.z - sp7C->unk6) * sp5C) + D_801BEBB8.unkA + D_801BEBB8.unkE) - D_801BEBB8.unkA) + sp6C;
        } else {
            sp78 = (((D_801BEBB8.unk8 - (s32) ((actor->world.pos.x - sp7C->unk2) * sp5C)) + D_801BEBB8.unkC) - D_801BEBB8.unk8) + sp70;
            sp74 = (((D_801BEBB8.unkA - (s32) ((actor->world.pos.z - sp7C->unk6) * sp5C)) + D_801BEBB8.unkE) - D_801BEBB8.unkA) + sp6C;
        }
        if ((sp78 > 0) && (sp78 < 0x3FF) && (sp74 > 0) && (sp74 < 0x3FF) ) {
            OPEN_DISPS(play->state.gfxCtx);
            func_8012C654(play->state.gfxCtx);
            gDPSetCombineMode(OVERLAY_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
            
            if ((actor->category == 0xA) && (func_80103A10(play) != 0)) {
                s32 pad;
                gDPSetPrimColor(OVERLAY_DISP++, 0, 0, D_801BEC2C[actor->category].r, D_801BEC2C[actor->category].g, D_801BEC2C[actor->category].b, (s32)((D_801BEC2C[actor->category].a * (1.0f - D_801BEBB8.unk24 * 0.05f) * sp50 * play->interfaceCtx.minimapAlpha) / 255.0f));

                var_v1 = D_801BEBB8.unk0->unk4;
                if (D_801BEBB8.unk0->unk4 == 0) {
                    var_v1 = 0x14;
                } else if (D_801BEBB8.unk0->unk4 == -1) {
                    s32 sp34;
                    func_801030B4(sp7C, &sp34);
                    var_v1 = sp34;
                }
                if (var_v1 <= 50) {
                    gSPTextureRectangle(OVERLAY_DISP++, (sp78 - 2) << 2, (sp74 - 2) << 2, (sp78 + 2) << 2, (sp74 + 2) << 2, G_TX_RENDERTILE, 0, 0, 0x0001, 0x0001);
                } else {
                    gSPTextureRectangle(OVERLAY_DISP++, (sp78 - 1) << 2, (sp74 - 1) << 2, (sp78 + 1) << 2, (sp74 + 1) << 2, G_TX_RENDERTILE, 0, 0, 0x0001, 0x0001);
                }
            }
            CLOSE_DISPS(play->state.gfxCtx);
        }
    }
}

void func_80104AE8(PlayState *play) {
    s32 i;
    Actor* actor;

    if (play->roomCtx.currRoom.num != -1) {
        OPEN_DISPS(play->state.gfxCtx);
        gDPLoadTextureBlock_4b(OVERLAY_DISP++, &D_801BEB38, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        actor = play->actorCtx.actorLists[ACTORCAT_DOOR].first;
        if (actor != NULL) {
            do {
                if (
                    (actor->update != NULL) 
                    && (actor->init == NULL) 
                    && Object_IsLoaded(&play->objectCtx, actor->objBankIndex)
                    && ((D_801BEBB8.curRoom == actor->room) || (actor->room == -1))) {
                    func_801045AC(play, actor);
                }
                actor = actor->next;
            } while (actor != NULL);
        }
        CLOSE_DISPS(play->state.gfxCtx);
    }
}

//Possible fakematch
//https://decomp.me/scratch/kvGBZ
void func_80104C80(PlayState* play) {
    s32 objBankIndex;

    objBankIndex = Object_GetIndex(&play->objectCtx, GAMEPLAY_DANGEON_KEEP);
    if (objBankIndex < 0) {
        D_801BEBB8.unk20 |= 1;
    }
    else 
    {
    do { } while (!Object_IsLoaded(&play->objectCtx, objBankIndex));
    }
    if (&play->objectCtx) {}
}

//init
void MapDisp_Init(PlayState* play) {
    s32 i;

    D_801BEBB8.unk0 = NULL;
    D_801BEBB8.curRoom = -1;
    D_801BEBB8.unk8 = 0xD2;
    D_801BEBB8.unkA = 0x8C;
    D_801BEBB8.unkC = 0xD2;
    D_801BEBB8.unkE = 0x8C;
    D_801BEBB8.unk10 = NULL;
    D_801BEBB8.prevRoom = -1;
    D_801BEBB8.unk18 = NULL;
    D_801BEBB8.unk1C = 0;
    D_801BEBB8.unk1E = 0;
    D_801BEBB8.unk20 = 0;
    D_801BEBB8.unk24 = 0;
    
    if (!Map_IsInBossArea(play)) {
        D_801BEC1C = play->numRooms;
    }
    D_801BEBB8.unk28 = THA_AllocEndAlign16(&play->state.heap, 0x4000);
    D_801BEBB8.unk2C = THA_AllocEndAlign16(&play->state.heap, 0x4000);
    func_80104C80(play);
    if (!Map_IsInBossArea(play)) {
        D_801BEBB8.unk30 = 0;
        D_801BEBB8.unk32 = 0;
        D_801BEBB8.unk34 = 0x64;
        D_801BEBB8.unk36 = 0x64;
        D_801BEBB8.unk38 = (s16) (s32) ((f32) D_801BEBB8.unk30 + ((f32) D_801BEBB8.unk34 * 0.5f));
        D_801BEBB8.unk3A = (s16) (s32) ((f32) D_801BEBB8.unk32 + ((f32) D_801BEBB8.unk36 * 0.5f));
    }
    D_801BEBB8.unk3C = THA_AllocEndAlign16(&play->state.heap, D_801BEC1C * sizeof(s16));

    for (i = 0; i < D_801BEC1C; i++) {
        func_80102E90(play, &D_801BEBB8.unk3C[i]);
    }
    D_801BEBB8.unk48 = THA_AllocEndAlign16(&play->state.heap, 32 * sizeof(s16));
    
    for (i = 0; i < 32; i++)
    {
        D_801BEBB8.unk48[i] = -0x7FFF;
    }
    MapDisp_InitIMap(play);
    D_801BEBB8.unk58 = 0;
    D_801BEBB8.unk5A = 0;
    if (Map_IsInBossArea(play) != 0) {
        func_8010549C(play, NULL);
        func_8010565C(play, 0, NULL);
    }
}

void func_80104F34(PlayState* play) {
    s32 i1;
    s32 i2;
    s32 i3;
    s32 i4;

    for (i1 = 0; i1 < 32; i1++){
        D_801BEBB8.unk48[i1] = -0x7FFF;
    }
    for (i2 = 0; i2 < D_801BEC1C; i2++) {
        MinimapEntry* mapEntry1 = &D_801BEBB8.unk0->entry[i2];
        
        if (mapEntry1->unk0 == 0xFFFF) {
            continue;
        }
        for (i1 = 0; i1 < 32; i1++) {
            if (D_801BEBB8.unk48[i1] == -0x7FFF) {
                D_801BEBB8.unk48[i1] = mapEntry1->unk4;
                break;
            } else if(fabsf((f32) D_801BEBB8.unk48[i1] - (f32) mapEntry1->unk4) < 5.0f) {
                break;
            }
        }
    }
    for (i2 = 0; i2 < D_801BEC1C; i2++) {
        if (D_801BEBB8.unk48[i2] == -0x7FFF) {
            break;
        } 
        for (i3 = i2+1; i3 < D_801BEC1C; i3++) {
            if (D_801BEBB8.unk48[i3] == -0x7FFF) {
                break;
            }
            if (D_801BEBB8.unk48[i3] < D_801BEBB8.unk48[i2]) {
                s16 temp_t3 = D_801BEBB8.unk48[i2];
                
                D_801BEBB8.unk48[i2] = D_801BEBB8.unk48[i3];
                D_801BEBB8.unk48[i3] = temp_t3;
            }
        }
    }
    for (i2 = 0; i2 < D_801BEC1C; i2++) {
        MinimapEntry* mapEntry2 = &D_801BEBB8.unk0->entry[i2];
        
        D_801BEBB8.unk3C[i2] = -1;

        for (i4 = 0; i4 < D_801BEC1C; i4++) {
            if (D_801BEBB8.unk48[i4] != -0x7FFF) {
                if (fabsf((f32) D_801BEBB8.unk48[i4] - (f32) mapEntry2->unk4) < 5.0f) {
                    D_801BEBB8.unk3C[i2] = i4;
                    break;
                }
            }
        }
    }
    D_801BEBB8.unk40 = 0;
    for (i2 = 0; i2 < D_801BEC1C; i2++) {
        if (D_801BEBB8.unk48[i2] != -0x7FFF) {
            D_801BEBB8.unk40++;
        }
    }
    D_801BEBB8.unk44 = 0;
    for (i2 = 0; i2 < 5; i2++) {
        if (play->sceneNum == D_801BEC5C[i2].unk0) {
            D_801BEBB8.unk44 = D_801BEC5C[i2].unk2;
        }
    }
}

s32 func_80105294(void) {
    T_801BEC70 sp4 = D_801BEC70;
    
    if ((D_801BEBB8.unk0 == NULL) || (D_801BEBB8.unk58 < 0) || (D_801BEBB8.unk58 >= 5) || (D_801BEC1C == 0)) {
        return 0x7B;
    }
    return sp4.unk0[D_801BEBB8.unk58];
}

s16 func_80105318(void) {
    return D_801BEBB8.unk58;
}

// TransitionActor params test
s32 func_80105328(s32 params) {
    if (((((u16)params) >> 7) & 7) == 5) {
        return 1;
    }
    return 0;
}

void func_8010534C(PlayState* play) {
    TransitionActorList* transitionActors; 
    TransitionActorEntry* var_s0;
    s32 var_v0;
    s32 var_s2;

    transitionActors = &D_801BEC24;

    for (var_s2 = 0; var_s2 < transitionActors->count; var_s2++) {
        if (func_80105328(D_801F53B0[var_s2].params) != 0) {
            if (ABS_ALT(D_801F53B0[var_s2].id) != 0x18) {
                for (var_v0 = 0; var_v0 < D_801BEBB8.unk40; var_v0++) {
                    s32 temp = (D_801BEBB8.unk48[var_v0] - 5); // needed for matching
                    if (
                        ( (var_v0 == D_801BEBB8.unk40 - 1) && (D_801F53B0[var_s2].pos.y >= (D_801BEBB8.unk48[var_v0] - 5)) ) 
                    || (
                        (var_v0 != D_801BEBB8.unk40 - 1) &&
                        (D_801F53B0[var_s2].pos.y >= (D_801BEBB8.unk48[var_v0] - 5)) &&
                        (D_801F53B0[var_s2].pos.y < (D_801BEBB8.unk48[var_v0+1] - 5))
                    )) {
                        D_801BEBB8.unk58 = var_v0;
                        return;
                    }
                }
            }
        }
    }
    D_801BEBB8.unk58 = 0;
}

#ifdef NON_MATCHING
void func_8010549C(PlayState* globalCtx, void* segmentAddress) {
    MinimapEntry* var_v1;
    MinimapList* temp_v0;
    s32 i;

    if (Map_IsInBossArea(globalCtx) == 0) {
        D_801BEC1C = globalCtx->numRooms;
        temp_v0 = Lib_SegmentedToVirtual(segmentAddress);
        D_801BEC14 = *temp_v0;
        var_v1 = Lib_SegmentedToVirtual(temp_v0->entry);

        for (i = 0; i < D_801BEC1C; i++)
        {
            D_801F5130[i] = var_v1[i];
        }
        
        D_801BEC14.entry = D_801F5130;
        if (globalCtx->colCtx.colHeader != NULL) {
            D_801BEBB8.unk30 = globalCtx->colCtx.colHeader->minBounds.x;
            D_801BEBB8.unk32 = globalCtx->colCtx.colHeader->minBounds.z;
            D_801BEBB8.unk34 = globalCtx->colCtx.colHeader->maxBounds.x - globalCtx->colCtx.colHeader->minBounds.x;
            D_801BEBB8.unk36 = globalCtx->colCtx.colHeader->maxBounds.z - globalCtx->colCtx.colHeader->minBounds.z;
            D_801BEBB8.unk38 = (s16) (D_801BEBB8.unk30 + (D_801BEBB8.unk34 * 0.5f));
            D_801BEBB8.unk3A = (s16) (D_801BEBB8.unk32 + (D_801BEBB8.unk36 * 0.5f));
        }
    }
    D_801BEBB8.unk0 = &D_801BEC14;
    func_80104F34(globalCtx);
    func_8010534C(globalCtx);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_map_disp/func_8010549C.s")
#endif

void func_8010565C(PlayState* play, s32 num, void* segmentAddress) {
    MinimapChest* var_v1;
    s32 var_a3;

    if (Map_IsInBossArea(play) == 0) {
        var_v1 = Lib_SegmentedToVirtual(segmentAddress);
        for (var_a3 = 0; var_a3 < num; var_v1++, var_a3++) {
            D_801F5270[var_a3] = *var_v1;
        }
        D_801BEC20 = num;
    }
    D_801BEBB8.unk54 = D_801F5270;
    D_801BEBB8.unk50 = D_801BEC20;
}

void func_80105818(PlayState* play, s32 num, TransitionActorEntry* transitionActorList) {
    s32 i;

    if (Map_IsInBossArea(play) == 0) {
        D_801BEC24.count = num;
        for (i = 0; i < num; i++)
        {
            D_801F53B0[i] = transitionActorList[i];
        }
        D_801BEC24.list = D_801F53B0;
    }
}

void MapDisp_Destroy(PlayState* play) {
    s32 i;

    D_801BEBB8.unk0 = NULL;
    D_801BEBB8.curRoom = -1;
    D_801BEBB8.unkC = 0xD2;
    D_801BEBB8.unkE = 0x8C;
    D_801BEBB8.unk10 = NULL;
    D_801BEBB8.prevRoom = -1;
    D_801BEBB8.unk18 = NULL;
    D_801BEBB8.unk1C = 0;
    D_801BEBB8.unk1E = 0;
    D_801BEBB8.unk20 = 0;
    D_801BEBB8.unk24 = 0;
    D_801BEBB8.unk28 = NULL;
    D_801BEBB8.unk2C = NULL;
    
    for (i = 0; i < D_801BEC1C; i++) {
        func_80102EA4(play, &D_801BEBB8.unk3C[i]);
    }

    D_801BEBB8.unk3C = NULL;
    D_801BEBB8.unk40 = 0;
    D_801BEBB8.unk42 = 0;
    D_801BEBB8.unk44 = 0;
    D_801BEBB8.unk4C = 0;
    D_801BEBB8.unk48 = NULL;
    D_801BEBB8.unk50 = 0;
    D_801BEBB8.unk54 = NULL;
    MapDisp_DestroyIMap(play);
    D_801BEBB8.unk5A = 0;
}


void func_80105B34(PlayState* play) {
    s16 temp_a0;
    s16 temp_a0_2;
    s16 temp_v1;
    s16 temp_v1_2;
    s32 temp_v0;

    if ((D_801BEBB8.unk0 != NULL) && (D_801BEC1C != 0)) {
        D_801BEBFA = 8 - play->pauseCtx.unk_256;
        if (D_801BEBB8.prevRoom != -1) {
            temp_v0 = D_801BEBB8.unk24;
            if (temp_v0 > 0) {
                temp_v1 = D_801BEBB8.unk8;
                temp_a0 = D_801BEBB8.unkC;
                if (temp_v1 != temp_a0) {
                    D_801BEBB8.unkC = (s16) (s32) (((f32) (temp_v1 - temp_a0) / (f32) temp_v0) + (f32) temp_a0);
                }
                temp_v1_2 = D_801BEBB8.unkA;
                temp_a0_2 = D_801BEBB8.unkE;
                if (temp_v1_2 != temp_a0_2) {
                    D_801BEBB8.unkE = (s16) (s32) (((f32) (temp_v1_2 - temp_a0_2) / (f32) temp_v0) + (f32) temp_a0_2);
                }
                D_801BEBB8.unk24 = temp_v0 - 1;
                return;
            }
            D_801BEBB8.prevRoom = -1;
            D_801BEBB8.unk24 = 0;
            D_801BEBB8.unkC = D_801BEBB8.unk8;
            D_801BEBB8.unkE = D_801BEBB8.unkA;
            return;
        }
        D_801BEBB8.unk24 = 0;
    }
}

#ifdef NON_MATCHING
//https://decomp.me/scratch/oK0wd
void func_80105C40(s16 arg0) {
    MinimapEntry* temp_s0;
    MinimapEntry* sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 var_v0;
    s32 pad;
    s32 sp2C;

    if ((D_801BEBB8.unk0 != NULL) && (D_801BEC1C != 0) && (arg0 != -1)) {
        temp_s0 = &D_801BEBB8.unk0->entry[arg0];
     if ( ( temp_s0->unk0 < 5) || (( temp_s0->unk0 >= 0x100) && ( temp_s0->unk0 < 0x162)) ||  temp_s0->unk0 == 0xFFFF) {
        
        D_801BEBB8.prevRoom = D_801BEBB8.curRoom;
        D_801BEBB8.curRoom = arg0;
        D_801BEBB8.unk24 = 0x14;

        D_801BEBB8.unk18 = D_801BEBB8.unk10;
        sp54 = D_801BEBB8.unk8;
        sp50 = D_801BEBB8.unkA;

        temp_s0 = &D_801BEBB8.unk0->entry[D_801BEBB8.curRoom];

        if (temp_s0->unk0 == 0xFFFF) {
            D_801BEBB8.unk1E = 0;
            D_801BEBB8.unk8 = 0xD2;
            D_801BEBB8.unkA = 0x8C;
            D_801BEBB8.unkC = 0xD2;
            D_801BEBB8.unkE = 0x8C;
            D_801BEBB8.unk10 = NULL;
            D_801BEBB8.unk1C = D_801BEBB8.unk1E;
            return;
        }
        func_801030F4(temp_s0, &sp44, &sp40);
        func_80103090(temp_s0, &sp4C, &sp48);
        D_801BEBB8.unk8 = 0x127 - sp4C;
        D_801BEBB8.unkA = 0xDC - sp48;
        if (D_801BEBB8.prevRoom != -1) {
            sp58 = &D_801BEBB8.unk0->entry[D_801BEBB8.prevRoom];
            if (sp58->unk0 == 0xFFFF) {
                D_801BEBB8.unk1E = 0;
                D_801BEBB8.unk10 = NULL;
                D_801BEBB8.unk1C = D_801BEBB8.unk1E;
                D_801BEBB8.unkC = D_801BEBB8.unk8;
                D_801BEBB8.unkE = D_801BEBB8.unkA;
                return;
            }
            func_801030F4(sp58, &sp3C, &sp38);
            //temp_a0 = ;
            var_v0 = D_801BEBB8.unk0->unk4;
            if (D_801BEBB8.unk0->unk4 == 0) {
                var_v0 = 0x14;
            } else if (D_801BEBB8.unk0->unk4 == -1) {
                func_801030B4(temp_s0, &sp2C);
                var_v0 = sp2C;
            }
            //temp_fv0 = ;
            D_801BEBB8.unk1C = (s16) (s32) (((f32) sp44 + (((f32) sp58->unk2 - (f32) temp_s0->unk2) * (1.0f / var_v0))) - (f32) sp3C);
            D_801BEBB8.unk1E = (s16) (s32) (((f32) sp40 + (((f32) sp58->unk6 - (f32) temp_s0->unk6) * (1.0f / var_v0))) - (f32) sp38);
            D_801BEBB8.unkC = sp54 - D_801BEBB8.unk1C;
            D_801BEBB8.unkE = sp50 - D_801BEBB8.unk1E;
        }
        else {
            D_801BEBB8.unk1C = D_801BEBB8.unk1E = 0;
            D_801BEBB8.unkC = D_801BEBB8.unk8;
            D_801BEBB8.unkE = D_801BEBB8.unkA;
        }
        D_801BEBB8.unk10 = NULL;
        
        switch (func_80109714(temp_s0->unk0)) {
        case 0: 
            D_801BEBB8.unk10 = func_8010958C(temp_s0->unk0);
            return;
        case 1:
            if (D_801BEBB8.unk18 == D_801BEBB8.unk28) {
                D_801BEBB8.unk10 = D_801BEBB8.unk2C;
            } else {
                D_801BEBB8.unk10 = D_801BEBB8.unk28;
            }
            if (func_801096D4(temp_s0->unk0) != 0) {
                func_80178E3C(SEGMENT_ROM_START(map_grand_static),
                temp_s0->unk0 - 0x100,
                (s32) D_801BEBB8.unk10,
                func_801096D4(temp_s0->unk0));
            }
            break;
        }
    }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_map_disp/func_80105C40.s")
#endif

#ifdef NON_MATCHING
//https://decomp.me/scratch/WiRnZ
void func_80105FE0(PlayState* play, s32 x, s32 z, s32 rot) {
    MinimapEntry* sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 var_v0;
    f32 sp4C;
    s32 sp48;

    sp6C = &D_801BEBB8.unk0->entry[D_801BEBB8.curRoom];
    if (sp6C->unk0 != 0xFFFF) {
        func_801030F4(sp6C, &sp60, &sp5C);
        func_80103090(sp6C, &sp58, &sp54);
        var_v0 = D_801BEBB8.unk0->unk4;
        if (D_801BEBB8.unk0->unk4 == 0) {
            var_v0 = 0x14;
        } else if (D_801BEBB8.unk0->unk4 == -1) {
            func_801030B4(sp6C, &sp48);
            var_v0 = sp48;
        }
        sp4C = (1.0f / var_v0);
        if (func_801039EC(play) == 0) {
            sp68 = (s32) ((x - (f32)sp6C->unk2) * sp4C) + D_801BEBB8.unk8 + (D_801BEBB8.unkC - D_801BEBB8.unk8) + sp60;
            sp64 = (s32) ((z - (f32)sp6C->unk6) * sp4C) + D_801BEBB8.unkA + (D_801BEBB8.unkE - D_801BEBB8.unkA) + sp5C;
        } else {
            sp68 =  - (s32) ((x - (f32)sp6C->unk2) * sp4C) + D_801BEBB8.unk8 + (D_801BEBB8.unkC - D_801BEBB8.unk8) + sp60;
            sp64 =  - (s32) ((z - (f32)sp6C->unk6) * sp4C) + D_801BEBB8.unkA + (D_801BEBB8.unkE - D_801BEBB8.unkA) + sp5C;
        }
        if ((sp68 > 0) && (sp68 < 0x3FF) && (sp64 > 0) && (sp64 < 0x3FF)) {
            OPEN_DISPS(play->state.gfxCtx);
            func_8012C8D4(play->state.gfxCtx);
            gSPMatrix(OVERLAY_DISP++, &gIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPSetCombineLERP(OVERLAY_DISP++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
            gDPSetEnvColor(OVERLAY_DISP++, 0, 0, 0, 255);
            gDPSetCombineMode(OVERLAY_DISP++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
            gDPSetRenderMode(OVERLAY_DISP++, G_RM_AA_DEC_LINE, G_RM_NOOP2);
            Matrix_Translate((f32) sp68 - 160.0f, 120.0f - (f32) sp64, 0.0f, MTXMODE_NEW);
            Matrix_RotateXFApply(-1.6f);
            if (func_801039EC(play) != 0) {
                rot += 0x7FFF;
            }
            Matrix_RotateYF(rot / 10.0f, MTXMODE_APPLY);
            Matrix_Scale(0.4f, 0.4f, 0.4f, MTXMODE_APPLY);
            gSPMatrix(OVERLAY_DISP++, Matrix_NewMtx(play->state.gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPSetPrimColor(OVERLAY_DISP++, 0, 0xFF, 200, 0, 0, play->interfaceCtx.minimapAlpha);
            gSPDisplayList(OVERLAY_DISP++, D_0401ED00);
            CLOSE_DISPS(play->state.gfxCtx);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_map_disp/func_80105FE0.s")
#endif

s32 func_80106408(PlayState* play) {
    if ((gSaveContext.save.entranceIndex == 0x6400) && (Cutscene_GetSceneSetupIndex(play) != 0)) {
        return true;
    }
    return false;
}

s32 func_80106450(PlayState* play) {
    if (((func_8010A0A4(play) == 0) && (Inventory_IsMapVisible(play->sceneNum) != 0)) 
    || ((func_8010A0A4(play) != 0) && CHECK_DUNGEON_ITEM(2, gSaveContext.mapIndex)  )) {
        return true;
    }
    return false;
}

s32 func_801064CC(PlayState* play) {
    if (((play->csCtx.state != 0) && (func_80106408(play) == 0)) || (D_801BEBB8.unk20 & 2) || (Map_IsInBossArea(play) != 0)) {
        return true;
    }
    return false;
}

s32 func_80106530(PlayState* play) {
    if ((func_801064CC(play) == true) || !func_80106450(play)) {
        return true;
    }
    return false;
}

s32 func_8010657C(s32 arg0, s32 arg1) {
    MinimapEntry* temp_v1;
    s16* temp1; // Can be removed, but adds readability

    if ((arg0 == -1) || (arg1 == -1)) {
        return 0;
    }
    temp_v1 = &D_801BEBB8.unk0->entry[arg0];
    temp1 = D_801BEBB8.unk3C;
    if ((temp1[arg0] <= temp1[arg1]) && (temp1[arg1] <= (temp1[arg0] + ((temp_v1->unk8 >> 2) & 7)))) {
        return 1;
    } 
    temp_v1 = &D_801BEBB8.unk0->entry[arg1];
    if ((temp1[arg1] <= temp1[arg0]) && (temp1[arg0] <= (temp1[arg1] + ((temp_v1->unk8 >> 2) & 7)) )) {
        return 1;
    }
    return 0;
}

#ifdef NON_MATCHING
void func_80106644(PlayState *play, s32 x, s32 z, s32 rot) {
    s32 pad[2];
    
    if ((D_801BEBB8.unk0 != 0) && ((s32) play->pauseCtx.state < 4) && (XREG(95) == 0) && (play->interfaceCtx.minimapAlpha != 0)) {
        //sp2C = ;// + 0x10000;
        if ((func_801064CC(play) == 0) && (D_801BEC1C != 0)) {
            if (func_80106450(play) != 0) {
                func_801031D0(play, D_801BEBB8.unk10, D_801BEBB8.unkC, D_801BEBB8.unkE, D_801BEBB8.curRoom, 1.0f - ((f32) D_801BEBB8.unk24 * 0.05f));
                if ((D_801BEBB8.curRoom != D_801BEBB8.prevRoom) && (func_8010657C(D_801BEBB8.curRoom, D_801BEBB8.prevRoom) != 0)) {
                    func_801031D0(play, D_801BEBB8.unk18, D_801BEBB8.unkC + D_801BEBB8.unk1C, D_801BEBB8.unkE + D_801BEBB8.unk1E, D_801BEBB8.prevRoom, (f32) D_801BEBB8.unk24 * 0.05f);
                }
                func_80104AE8(play);
            }
            if (((func_8010A0A4(play) == 0) || (gSaveContext.save.inventory.dungeonItems[gSaveContext.mapIndex] & gBitFlags[1]) )
                 && ((func_8010A0A4(play) != 0) || Inventory_IsMapVisible(play->sceneNum))) {
                if (play->interfaceCtx.unk_280 == 0) {
                    func_80105FE0(play, x, z, rot);
                }
                func_8010439C(play);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_map_disp/func_80106644.s")
#endif

void MapDisp_ResetIMap(void) {
    s32 i;

    D_801F56B0.rooms = 0;
    for (i = 0; i < 32; i++)
    {
        D_801F56B0.unk4[i] = 0;
        D_801F56B0.unk84[i] = NULL;
        D_801F56B0.unk104[i] = NULL;
    }

    D_801F56B0.unk184 = 0;
    D_801BEBB8.unk20 &= ~1;
}

void MapDisp_InitIMap(PlayState* play) {
    MapDisp_ResetIMap();
}

void MapDisp_DestroyIMap(PlayState* play) {
    MapDisp_ResetIMap();
}

#ifdef NON_MATCHING
//alloc pause screen dungeon map
void* func_801068FC(PlayState* play, void* heap) {
    void* heapNext; //sp3C
    s32 temp_s2;
    s32 temp_v0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s4;
    MinimapEntry* entry;
    s32 var_s3;

    heapNext = heap;
    if ((D_801BEBB8.unk0 == NULL) || (D_801BEC1C == 0)) {
        return heapNext;
    }
    D_801F56B0.rooms = 0;

    //loop for number of rooms
    for (var_s4 = 0; var_s4 < D_801BEC1C; var_s4++) {
        var_s2 = 0;
        entry = &D_801BEBB8.unk0->entry[var_s4];
        if (entry->unk0 == 0xFFFF) {
            continue;
        } else {
            temp_v0 = func_80109BA0(entry->unk0);
            if (temp_v0 == -1) {
                continue;
            } else {
                for (var_s1 = 0; var_s1 < D_801F56B0.rooms; var_s1++) {
                    if (temp_v0 == D_801F56B0.unk4[var_s1]) {
                        var_s2 = 1;
                        break;
                    }
                }
                if (var_s2 == 0) {
                    D_801F56B0.unk4[D_801F56B0.rooms] = temp_v0;
                    D_801F56B0.rooms += 1;
                }
            }
        }
    }

    D_801F56B0.unk84[0] = heap;
    for (var_s1 = 0; var_s1 < D_801F56B0.rooms; var_s1++) {
        temp_s2 = D_801F56B0.unk4[var_s1];
        func_80102E40(D_801F56B0.unk84[var_s1], temp_s2);
        if (var_s1 + 1 < D_801F56B0.rooms) {
            D_801F56B0.unk84[var_s1 + 1] = ALIGN16((intptr_t)D_801F56B0.unk84[var_s1] + MapData_GetIMapSize(temp_s2));
        } else {
            heapNext = (intptr_t)D_801F56B0.unk84[var_s1] + MapData_GetIMapSize(temp_s2); 
        }
    }
    for (var_s4 = 0; var_s4 < D_801BEC1C; var_s4++) {
        entry = &D_801BEBB8.unk0->entry[var_s4];
        if (entry->unk0 == 0xFFFF) {
            D_801F56B0.unk104[var_s4] = NULL;
        } else {
            var_s3 = false;
            temp_v0 = func_80109BA0(entry->unk0);
            for (var_s1 = 0; var_s1 < D_801F56B0.rooms; var_s1++) {
                if (temp_v0 == D_801F56B0.unk4[var_s1]) {
                    var_s3 = true;
                    break;
                }
            }
            D_801F56B0.unk104[var_s4] = (!var_s3) ? NULL : D_801F56B0.unk84[var_s1];
        }
    }
    return heapNext;
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_map_disp/func_801068FC.s")
#endif

s32 func_80106BEC(s32 arg0, f32 arg1) {
    if (arg0 == 0) {
        if ((D_801BEBB8.unk48[0] <= arg1) && ((D_801BEBB8.unk40 == 1) || (arg1 < D_801BEBB8.unk48[1]))) {
            return 1;
        }
    }
    else if (arg0 >= (D_801BEBB8.unk40 - 1)) {
        if (D_801BEBB8.unk48[D_801BEBB8.unk40-1] <= arg1) {
            return 1;
        }
    }
    else if ((D_801BEBB8.unk48[arg0] <= arg1) && (arg1 < D_801BEBB8.unk48[arg0+1])) {
        return 1;
    }
    return 0;
}

s32 func_80106D08(s32 sceneNum) {
    switch (sceneNum) {
    case SCENE_MITURIN_BS:
        return SCENE_MITURIN;
    case SCENE_HAKUGIN_BS:
        return SCENE_HAKUGIN;
    case SCENE_SEA_BS:
        return SCENE_SEA;
    case SCENE_INISIE_BS:
        return SCENE_INISIE_N;
    default:
        return sceneNum;
    }
}

#define COLOR16(r, g, b, a) (s16) \
    ( ((s32) (((r) * 31.0f) / 255.0f) << 11) \
    | ((s32) (((g) * 31.0f) / 255.0f) << 6) \
    | ((s32) (((b) * 31.0f) / 255.0f) << 1) \
    | (a)) \

#ifdef NON_MATCHING
// https://decomp.me/scratch/3cGkW
void func_80106D5C(PlayState* play, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6) {
    s32 var_a0;
    s32 var_a1_2;
    s32 var_a1_4;
    s32 var_a1_5;
    s32 var_v1;
    s32 var_s2;
    TexturePtr temp_s1;
    s32 temp1;
    s32 temp2;

    temp1 = ((D_801F56B0.unk184 * -120.0f / 40.0f) + 200.0f) * 31.0f / 255.0f;
    temp2 = ((D_801F56B0.unk184 * 115.0f / 40.0f) + 140.0f) * 31.0f / 255.0f;

    D_801BECC4[1] = (temp1 << 6) | (temp2 << 1) | 1; //COLOR16(0, ((D_801F5834 * -120.0f) / 40.0f) + 200.0f, ((D_801F5834 * 115.0f) / 40.0f) + 140.0f, 1);
    //  (
    //     0 << 11
    //     | ((s32) (((((D_801F5834 * -120.0f) / 40.0f) + 200.0f) * 31.0f) / 255.0f) << 6) 
    //     | ((s32) (((((D_801F5834 * 115.0f) / 40.0f) + 140.0f) * 31.0f) / 255.0f) << 1)
    //     | 1);
    if (CHECK_DUNGEON_ITEM(2, arg6)) {//*(gBitFlags + 8) & gSaveContext.save.inventory.dungeonItems[arg6]) {
        //15, 15, F (172, 172, 123)
        D_801BEC84[0xF] = COLOR16(176, 176, 128, 1); //0xAD5F;
        D_801BECA4[0xF] = COLOR16(176, 176, 128, 1);
        D_801BECC4[0xF] = COLOR16(176, 176, 128, 1);
    } else {
        D_801BEC84[0xF] = 0;
        D_801BECA4[0xF] = 0;
        D_801BECC4[0xF] = 0;
    }

    OPEN_DISPS(play->state.gfxCtx);
    //temp_a0 = play->state.gfxCtx;
    //sp48 = arg6 + &gSaveContext;
    func_8012C628(play->state.gfxCtx);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, play->pauseCtx.alpha);
    gDPLoadTLUT_pal16(POLY_OPA_DISP++, 0, D_801BEC84);
    gDPLoadTLUT_pal16(POLY_OPA_DISP++, 1, D_801BECA4);
    gDPLoadTLUT_pal16(POLY_OPA_DISP++, 2, D_801BECC4);
    gDPSetTextureLUT(POLY_OPA_DISP++, G_TT_RGBA16);

    for (var_s2 = 0; var_s2 < D_801BEC1C; var_s2++) {
        s32 sp118;
        s32 sp114;
        s32 sp110;
        s32 sp10C;
        MinimapEntry* sp108;
        s32 pad104;
        s32 sp100;
        s32 spFC;
        s32 spF8;
        s32 spF4;
        s32 spF0;
        s32 spEC;
        s32 spE8;
        s32 padE4;
        s32 padE0;
    
        sp108 = &D_801BEBB8.unk0->entry[var_s2];
        if ((sp108->unk0 != 0xFFFF) && (sp108->unk0 < 0x162)) {
            if ((D_801BEBB8.unk42 >= D_801BEBB8.unk3C[var_s2]) 
            && ((D_801BEBB8.unk3C[var_s2] + ((sp108->unk8 >> 2) & 7)) >= D_801BEBB8.unk42)) {
                temp_s1 = D_801F56B0.unk104[var_s2];
                if (temp_s1 != NULL) {
                    spE8 = func_80109BA0(sp108->unk0);
                    if (spE8 == -1) {
                        continue;
                    } else {
                        //sp3C = play + 0x18000;
                        func_80109D40(spE8, &sp118, &sp114, sp108);
                        func_80109DD8(spE8, &sp110, &sp10C);
                        if (sp108->unk8 & 1) {
                            sp110 = (sp118 / 2 - sp110) + sp118 / 2;
                            sp100 = (sp118 - 1) << 5;
                            spF8 = 0xFC00;
                        } else {
                            sp100 = 0;
                            spF8 = 0x400;
                        }
                        if (sp108->unk8 & 2) {
                            sp10C = (sp114 / 2 - sp10C) + sp114 / 2;
                            spFC = (sp114 - 1) << 5;
                            spF4 = 0xFC00;
                        } else {
                            spFC = 0;
                            spF4 = 0x400;
                        }
                        spF0 = ((sp108->unk2 - (f32) D_801BEBB8.unk38) * arg5 - sp110) + ((arg3 / 2) + arg1);
                        spEC = ((sp108->unk6 - (f32) D_801BEBB8.unk3A) * arg5 - sp10C) + ((arg4 / 2) + arg2);

                        if (var_s2 == play->roomCtx.currRoom.num) {
                            if (Map_IsInBossArea(play) != 0) {
                                gDPLoadTextureBlock_4b(POLY_OPA_DISP++, temp_s1, G_IM_FMT_CI, sp118, sp114, 1, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK , G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                            } else {
                                gDPLoadTextureBlock_4b(POLY_OPA_DISP++, temp_s1, G_IM_FMT_CI, sp118, sp114, 2, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK , G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                            }
                        } else if (gSaveContext.save.permanentSceneFlags[Play_GetOriginalSceneNumber(func_80106D08(play->sceneNum))].rooms & (1 << var_s2)) {
                            gDPLoadTextureBlock_4b(POLY_OPA_DISP++, temp_s1, G_IM_FMT_CI, sp118, sp114, 1, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK , G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                        } else if (CHECK_DUNGEON_ITEM(2, arg6)) { //*(gBitFlags + 8) & gSaveContext.save.inventory.dungeonItems[arg6]) {
                            gDPLoadTextureBlock_4b(POLY_OPA_DISP++, temp_s1, G_IM_FMT_CI, sp118, sp114, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK , G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                        }
                        else {
                            continue;
                        }
                        gSPTextureRectangle(POLY_OPA_DISP++, (spF0 << 2), (spEC << 2), (spF0 + sp118) << 2, (spEC + sp114) << 2, 0, sp100, spFC, spF8, spF4);
                        gDPPipeSync(POLY_OPA_DISP++);
                    }
                }
            }
        }
    }
    gDPSetTextureLUT(POLY_OPA_DISP++, G_TT_NONE);
    CLOSE_DISPS(play->state.gfxCtx);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_map_disp/func_80106D5C.s")
#endif

#ifdef NON_MATCHING
// https://decomp.me/scratch/dKnQx
void func_80107B78(PlayState* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5) {
    s32 sp3C;
    MinimapEntry* sp38;
    GraphicsContext* temp_s1;
    MinimapChest* var_s0;
    s32 temp_ft0;
    s32 temp_ft0_2;
    s32 var_s3;
    s32 var_v1;
    s32 var_v1_2;

    //temp_t0 = ;
    if (D_801BEBB8.unk54 != NULL) {
        // temp_s1 = arg0->state.gfxCtx;
        OPEN_DISPS(arg0->state.gfxCtx);
        // temp_v1 = temp_s1->polyOpa.p;
        // temp_s1->polyOpa.p = temp_v1 + 8;
        // temp_v1->words.w1 = 0x00000000;
        // temp_v1->words.w0 = 0xE7000000;

        // temp_v1_2 = temp_s1->polyOpa.p;
        // temp_s1->polyOpa.p = temp_v1_2 + 8;
        // temp_v1_2->words.w1 = 0x00000000;
        // temp_v1_2->words.w0 = 0xE3001001;

        // temp_v1_3 = temp_s1->polyOpa.p;
        // temp_s1->polyOpa.p = temp_v1_3 + 8;
        // temp_v1_3->words.w0 = 0xFA000000;
        // temp_v1_3->words.w1 = (arg0->pauseCtx.alpha & 0xFF) | ~0xFF;

        // temp_v1_4 = temp_s1->polyOpa.p;
        // temp_s1->polyOpa.p = temp_v1_4 + 8;
        // temp_v1_4->words.w1 = 0x000000FF;
        // temp_v1_4->words.w0 = 0xFB000000;

        // temp_v1_5 = temp_s1->polyOpa.p;
        // temp_s1->polyOpa.p = temp_v1_5 + 8;
        // temp_v1_5->words.w1 = 0x00000000;
        // temp_v1_5->words.w0 = 0xE7000000;

        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetTextureLUT(POLY_OPA_DISP++, G_TT_NONE);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, arg0->pauseCtx.alpha);
        gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
        gDPPipeSync(POLY_OPA_DISP++);

        // temp_v1_6 = temp_s1->polyOpa.p;
        // temp_s1->polyOpa.p = temp_v1_6 + 8;
        // temp_v1_6->words.w1 = (u32) &D_02003F20;
        // temp_v1_6->words.w0 = ((D_801BEAE0.unk8 & 3) << 0x13) | 0xFD000000;

        // temp_v1_7 = temp_s1->polyOpa.p;
        // temp_s1->polyOpa.p = temp_v1_7 + 8;
        // var_a0 = 0x7FF;
        // temp_v1_7->words.w1 = 0x07000000;
        // temp_v1_7->words.w0 = ((D_801BEAE0.unk8 & 3) << 0x13) | 0xF5000000;

        // temp_v1_8 = temp_s1->polyOpa.p;
        // temp_s1->polyOpa.p = temp_v1_8 + 8;
        // temp_v1_8->words.w1 = 0x00000000;
        // temp_v1_8->words.w0 = 0xE6000000;

        // temp_a1 = temp_s1->polyOpa.p;
        // temp_s1->polyOpa.p = temp_a1 + 8;
        // temp_a1->words.w0 = 0xF3000000;
        // temp_v0 = ((u32) (D_801BEAF8 + 0x40) >> D_801BEB08) - 1;
        // if (temp_v0 < 0x7FFU) {
        //     var_a0 = temp_v0;
        // }
        // temp_v1_9 = (u32) (D_801BEB18 * 8) >> 3;
        // var_a2 = temp_v1_9;
        // if (temp_v1_9 == 0) {
        //     var_a2 = 1;
        // }
        // if (temp_v1_9 == 0) {
        //     var_v0 = 1;
        // } else {
        //     var_v0 = temp_v1_9;
        // }
        // temp_a1->words.w1 = (((u32) (var_a2 + 0x7FF) / var_v0) & 0xFFF) | 0x07000000U | ((var_a0 & 0xFFF) << 0xC);

        // temp_v1_10 = temp_s1->polyOpa.p;
        // temp_s1->polyOpa.p = temp_v1_10 + 8;
        // temp_v1_10->words.w1 = 0x00000000;
        // temp_v1_10->words.w0 = 0xE7000000;

        // temp_v1_11 = temp_s1->polyOpa.p;
        // temp_s1->polyOpa.p = temp_v1_11 + 8;
        // temp_v1_11->words.w0 = ((((u32) ((D_801BEB28 * 8) + 7) >> 3) & 0x1FF) << 9) | 0xF5000000 | ((D_801BEAD8 & 3) << 0x13);
        // temp_v1_11->words.w1 = 0x00000000;

        // temp_v1_12 = temp_s1->polyOpa.p;
        // temp_s1->polyOpa.p = temp_v1_12 + 8;
        // temp_v1_12->words.w0 = 0xF2000000;
        // temp_v1_12->words.w1 = 0x0001C01C;

// gDPSetTextureImage(POLY_OPA_DISP++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 1, 0x02003F20);
// gDPSetTile(POLY_OPA_DISP++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
// gDPLoadSync(POLY_OPA_DISP++);
// gDPLoadBlock(POLY_OPA_DISP++, G_TX_LOADTILE, 0, 0, 0, 0);
// gDPPipeSync(POLY_OPA_DISP++);
// gDPSetTile(POLY_OPA_DISP++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
// gDPSetTileSize(POLY_OPA_DISP++, G_TX_RENDERTILE, 0, 0, 0x001C, 0x001C);

        gDPLoadTextureBlock_TEST(OVERLAY_DISP++, &D_02003F20, G_IM_FMT_RGBA,
            D_801BEAE0[2], D_801BEAF0[2], D_801BEB00[2], D_801BEB10[2], D_801BEB20[2], D_801BEAD0[2], 8, 8, 0,
        G_TX_NOMIRROR | G_TX_WRAP,
        G_TX_NOMIRROR | G_TX_WRAP,
        G_TX_NOMASK,
        G_TX_NOMASK,
        G_TX_NOLOD,
        G_TX_NOLOD);

        var_s3 = 0;
        var_s0 = D_801BEBB8.unk54;
        //if (D_801BEBB8.unk50 > 0) {
        for (var_s3 = 0; var_s3 < D_801BEBB8.unk50; var_s3++) {
                sp3C = var_s0[var_s3].unk0;
                sp38 = &D_801BEBB8.unk0->entry[sp3C];
                switch (arg0->sceneNum) {
                case SCENE_MITURIN_BS:
                    var_v1_2 = gSaveContext.cycleSceneFlags[SCENE_MITURIN].chest & (1 << var_s0[var_s3].unk2);
                    break;
                case SCENE_HAKUGIN_BS:
                    var_v1_2 = gSaveContext.cycleSceneFlags[SCENE_HAKUGIN].chest & (1 << var_s0[var_s3].unk2);
                    break;
                case SCENE_SEA_BS:
                    var_v1_2 = gSaveContext.cycleSceneFlags[SCENE_SEA].chest & (1 << var_s0[var_s3].unk2);
                    break;
                case SCENE_INISIE_BS:
                    var_v1_2 = gSaveContext.cycleSceneFlags[SCENE_INISIE_N].chest & (1 << var_s0[var_s3].unk2);
                    break;
                default:
                    var_v1_2 = Flags_GetTreasure(arg0, (s32) var_s0[var_s3].unk2);
                    break;
                }
                if (( D_801BEBB8.unk42 < D_801BEBB8.unk3C[sp3C]) || ((D_801BEBB8.unk3C[sp3C] + ((sp38->unk8 >> 2) & 7)) < (s32) D_801BEBB8.unk42) || (var_v1_2 != 0)) {
                    continue;
                } else if (func_80106BEC((s32) D_801BEBB8.unk42, (f32) var_s0[var_s3].unk6) == 0) {
                    continue;
                } else {
                    temp_ft0 = (s32) (((((f32) var_s0[var_s3].unk4 - (f32) D_801BEBB8.unk38) * arg5) - (f32) 4) + (f32) ((arg3 / 2) + arg1));
                    temp_ft0_2 = (s32) (((((f32) var_s0[var_s3].unk8 - (f32) D_801BEBB8.unk3A) * arg5) - (f32) 4) + (f32) ((arg4 / 2) + arg2));
                    // temp_v1_13 = temp_s1->polyOpa.p;
                    // temp_s1->polyOpa.p = temp_v1_13 + 8;
                    // temp_v1_13->words.w1 = (((temp_ft0 * 4) & 0xFFF) << 0xC) | ((temp_ft0_2 * 4) & 0xFFF);
                    // temp_v1_13->words.w0 = ((((temp_ft0 + 8) * 4) & 0xFFF) << 0xC) | 0xE4000000 | (((temp_ft0_2 + 8) * 4) & 0xFFF);
                    // temp_v1_14 = temp_s1->polyOpa.p;
                    // temp_s1->polyOpa.p = temp_v1_14 + 8;
                    // temp_v1_14->words.w1 = 0;
                    // temp_v1_14->words.w0 = 0xE1000000;
                    // temp_v1_15 = temp_s1->polyOpa.p;
                    // temp_s1->polyOpa.p = temp_v1_15 + 8;
                    // temp_v1_15->words.w1 = 0x04000400;
                    // temp_v1_15->words.w0 = 0xF1000000;

                    gSPTextureRectangle(POLY_OPA_DISP++, temp_ft0 << 2, temp_ft0_2 << 2, (temp_ft0 + 8) << 2, (temp_ft0_2 + 8) << 2, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                }
        }
        CLOSE_DISPS(arg0->state.gfxCtx);
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_map_disp/func_80107B78.s")
#endif

void func_80108124(PlayState* play, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6) {
    PauseContext* pauseCtx = &play->pauseCtx;
    TransitionActorList* transitionActors = &D_801BEC24;
    TransitionActorEntry* var_s1;
    s32 tempX;
    s32 tempY;
    s32 i;
    s8 roomA;
    s8 roomB;

    if (transitionActors->count != 0) {
        OPEN_DISPS(play->state.gfxCtx);
        gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPLoadTextureBlock_4b(POLY_OPA_DISP++, &D_801BEB38, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        for (i = 0; i < transitionActors->count; i++) {
            if (func_80106BEC(D_801BEBB8.unk42, D_801F53B0[i].pos.y)) {
                if ((ABS_ALT(D_801F53B0[i].id) != ACTOR_EN_HOLL) 
                && (func_80105328(D_801F53B0[i].params) == 0)){ 
                    roomA = D_801F53B0[i].sides[0].room;
                    roomB = D_801F53B0[i].sides[1].room;
                if (CHECK_DUNGEON_ITEM(2, gSaveContext.mapIndex)
                    || (roomA < 0) 
                    || (gSaveContext.save.permanentSceneFlags[Play_GetOriginalSceneNumber(func_80106D08(play->sceneNum))].rooms & (1 << roomA)) 
                    || (roomB < 0) 
                    || (gSaveContext.save.permanentSceneFlags[Play_GetOriginalSceneNumber(func_80106D08(play->sceneNum))].rooms & (1 << roomB))) {
                    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
                    
                    tempX = ((f32) D_801F53B0[i].pos.x - D_801BEBB8.unk38) * arg5 +  ((arg3 / 2) + arg1);
                    tempY = ((f32) D_801F53B0[i].pos.z - D_801BEBB8.unk3A) * arg5 +  ((arg4 / 2) + arg2);
                    gSPTextureRectangle(POLY_OPA_DISP++, ((tempX - 1) << 2), ((tempY - 1) << 2), ((tempX + 1) << 2), ((tempY + 1) << 2), G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                }
            }
            }
        }
        CLOSE_DISPS(play->state.gfxCtx);
    }
}

#ifdef NON_MATCHING
// https://decomp.me/scratch/nHYgx
void func_80108558(PlayState* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6) {
    TransitionActorList* sp30;
    //TransitionActorEntry* var_s0;
    s32 temp_ft0;
    s32 temp_ft0_2;
    s32 var_s2;

    sp30 = &D_801BEC24;
    OPEN_DISPS(arg0->state.gfxCtx);
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetTextureLUT(POLY_OPA_DISP++, G_TT_NONE);
    gDPSetRenderMode(POLY_OPA_DISP++, G_RM_AA_DEC_LINE, G_RM_NOOP2);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, arg0->pauseCtx.alpha);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gDPPipeSync(POLY_OPA_DISP++);
    if (CHECK_DUNGEON_ITEM(1, arg6)) {
        gDPLoadTextureBlock_TEST(POLY_OPA_DISP++, &D_02002460, G_IM_FMT_IA,
         D_801BEAE0[1], D_801BEAF0[1], D_801BEB00[1], D_801BEB10[1],D_801BEB20[1], D_801BEAD0[1], 8, 8, 0,
        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,G_TX_NOMASK,G_TX_NOLOD, G_TX_NOLOD);
        for (var_s2 = 0; var_s2 < sp30->count; var_s2++) {
                if ((func_80105328((s32) D_801F53B0[var_s2].params) != 0) && (func_80106BEC((s32) D_801BEBB8.unk42, (f32) D_801F53B0[var_s2].pos.y) != 0)) {
                    if (ABS_ALT(D_801F53B0[var_s2].id) != ACTOR_EN_HOLL) {
                        temp_ft0 = ((((f32) D_801F53B0[var_s2].pos.x -  D_801BEBB8.unk38) * arg5) - 4) + ((arg3 / 2) + arg1);
                        temp_ft0_2 = ((((f32) D_801F53B0[var_s2].pos.z - D_801BEBB8.unk3A) * arg5) - 4) + ((arg4 / 2) + arg2);
                        gSPTextureRectangle(POLY_OPA_DISP++, temp_ft0 << 2, temp_ft0_2 << 2, (temp_ft0 + 8) << 2, (temp_ft0_2 + 8) << 2, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                    }
                }
        }
    }
    CLOSE_DISPS(arg0->state.gfxCtx);
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_map_disp/func_80108558.s")
#endif

TexturePtr func_80108A10(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 8)) {
        return D_801BECE4[arg0];
    }
    if ((arg0 >= -8) && (arg0 < 0)) {
        return D_801BED00[-arg0];
    }
    return &D_0C000000;
}

s32 func_80108A64(PlayState* play) {
    PauseContext* pauseCtx = &play->pauseCtx;

    if (pauseCtx->pageIndex != 1) {
        return 1;
    }
    if ((pauseCtx->state == 7) || (( pauseCtx->state >= 8) && (pauseCtx->state < 0x13))) {
        return 1;
    }
    if ((pauseCtx->state != 6) || (pauseCtx->unk_200 != 0)) {
        return 1;
    }
    if (pauseCtx->alpha == 0) {
        return 1;
    }
    return 0;
}

//https://decomp.me/scratch/4gO7Z
void func_80108AF8(PlayState* play) {
    PauseContext* pauseCtx = &play->pauseCtx;
    s32 temp_a0_2;
    s32 temp_a2_2;
    s16 a3;
    s16 a2;
    s32 pad;
    s32 var_s1;
    s32 spB4 = 0;

    if ((D_801BEBB8.unk0 != NULL) && (D_801BEC1C != 0) && (func_80108A64(play) == 0)) {
        if (Map_IsInBossArea(play) != 0) {
            switch (play->sceneNum) {
            case SCENE_MITURIN_BS:
                spB4 = 0;
                break;
            case SCENE_HAKUGIN_BS:
                spB4 = 1;
                break;
            case SCENE_SEA_BS:
                spB4 = 2;
                break;
            case SCENE_INISIE_BS:
                spB4 = 3;
                break;
            }
        } else {
            spB4 = gSaveContext.mapIndex;
        }
        OPEN_DISPS(play->state.gfxCtx);
        func_8012C628(play->state.gfxCtx);
        gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 200, pauseCtx->alpha);

        for (var_s1 = 0; var_s1 < D_801BEBB8.unk40; var_s1++) {
                if ((gSaveContext.save.permanentSceneFlags[Play_GetOriginalSceneNumber(func_80106D08(play->sceneNum))].unk_14 & gBitFlags[4 - var_s1])
                     ||  CHECK_DUNGEON_ITEM2(2, spB4)) { 
                    gDPLoadTextureBlock(POLY_OPA_DISP++, func_80108A10(D_801BEBB8.unk44 + var_s1), G_IM_FMT_IA, G_IM_SIZ_8b,
                     24, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                    gSPTextureRectangle(POLY_OPA_DISP++, 0x0144, (125 - var_s1 * 15) << 2, 0x01A4, ((125 - var_s1 * 15) + 16) << 2, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
                }
        }
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 150, 150, 255, pauseCtx->alpha);
        gDPLoadTextureBlock(POLY_OPA_DISP++, func_80108A10((D_801BEBB8.unk44 - pauseCtx->unk_256) + 8), G_IM_FMT_IA, G_IM_SIZ_8b, 24, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        
        a3 = 80;
        a2 = 106;
        temp_a0_2 = (5 + (pauseCtx->unk_256 * 0xF));
        temp_a2_2 = temp_a0_2 + 0x10;
        if ((pauseCtx->unk_258 == 0) && (pauseCtx->unk_242[1] == 0)) {
            a2++;
            a3--;
            temp_a2_2 += 4;
            temp_a0_2 -= 4;
            gSPTextureRectangle(POLY_OPA_DISP++, a3 << 2, (temp_a0_2) << 2, a2 << 2, (temp_a2_2) << 2, G_TX_RENDERTILE, 0, 0, 0x036E, 0x02AA);
        } else {
            gSPTextureRectangle(POLY_OPA_DISP++, (a3 + 1) << 2, temp_a0_2 << 2, (a2 - 1) << 2, temp_a2_2 << 2, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        }
        func_8012C8AC(play->state.gfxCtx);
        CLOSE_DISPS(play->state.gfxCtx);
    }
}

s32 func_801090B0(s32 arg0) {
    if ((D_801BEBB8.unk0 == NULL) || (D_801BEC1C == 0)) {
        return false;
    }
    if ((arg0 < 0) || (arg0 >= 6)) {
        return false;
    }
    if (D_801BEBB8.unk48[arg0] != -0x7FFF) {
        return true;
    }
    return false;
}

s32 func_80109124(s16 arg0) {
    s32 i;

    if ((D_801BEBB8.unk0 == NULL) || (D_801BEC1C == 0)) {
        return -1;
    }
    if (D_801BEBB8.unk40 < 2) {
        return 0;
    }
    if ((D_801BEBB8.unk48[1] - 5) >= arg0) {
        return 0;
    }
    for (i = 1; i < D_801BEBB8.unk40; i++) {
        if (((D_801BEBB8.unk48[i] - 5) < arg0) && ((D_801BEBB8.unk48[i + 1] - 5) >= arg0)) {
            return i;
        }
    }
    return D_801BEBB8.unk40 - 1;
}

#ifdef NON_MATCHING
void func_801091F0(PlayState* play) {
    s32 var_t2;
    u16 temp_a0;
    s16 sp44;
    s32 sp40;
    s32 sp3C;
    s32 var_v0;
    s32 temp_v0_2;

    sp44 = 0;
    sp40 = 0;
    sp3C = 0;
    if (func_80108A64(play) == 0) {
        if (Map_IsInBossArea(play) != 0) {
            switch (play->sceneNum) {
            case SCENE_MITURIN_BS:
                sp44 = 0;
                break;
            case SCENE_HAKUGIN_BS:
                sp44 = 1;
                break;
            case SCENE_SEA_BS:
                sp44 = 2;
                break;
            case SCENE_INISIE_BS:
                sp44 = 3;
                break;
            }
        } else {
            sp44 = gSaveContext.mapIndex;
        }
        temp_a0 = D_801BEBB8.unk0->entry->unk0;
        if ((temp_a0 != 0xFFFF) && (temp_a0 < 0x162)) {
            temp_v0_2 = func_80109BA0(temp_a0);
            if (temp_v0_2 != -1) {
                var_t2 = func_80109F78(temp_v0_2);
                if (var_t2 == 0) {
                    var_t2 = 0x50;
                }
                for (var_v0 = 0; var_v0 < 2; var_v0++){
                    if (play->sceneNum == D_801BED24[var_v0].unk0) {
                        sp40 = D_801BED24[var_v0].unk4;
                        sp3C = D_801BED24[var_v0].unk8;
                    }
                }
                
                func_80106D5C(play, sp40 + 0x90, sp3C + 0x55, 0x78, 0x64, 1.0f / var_t2, sp44);
                func_80108124(play, sp40 + 0x90, sp3C + 0x55, 0x78, 0x64, 1.0f / var_t2, sp44);
                func_80108558(play, sp40 + 0x90, sp3C + 0x55, 0x78, 0x64, 1.0f / var_t2, sp44);
                if (CHECK_DUNGEON_ITEM(1, sp44)) {
                    func_80107B78(play, sp40 + 0x90, sp3C + 0x55, 0x78, 0x64, 1.0f / var_t2);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/non_matchings/code/z_map_disp/func_801091F0.s")
#endif

void func_80109428(PlayState* play) {
    D_801BEBB8.unk4C++;
    if (!(D_801BEBB8.unk20 & 1)) {
        D_801F56B0.unk184++;
        if (D_801F56B0.unk184 > 40) {
            D_801BEBB8.unk20 |= 1;
        }
    } else {
        D_801F56B0.unk184--;
        if (D_801F56B0.unk184 < 0) {
            D_801BEBB8.unk20 &= ~1;
        }
    }
}
