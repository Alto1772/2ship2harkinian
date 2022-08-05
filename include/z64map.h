#ifndef Z64MAP_H
#define Z64MAP_H
#include "ultra64.h"
#include "z64scene.h"
#define FLOOR_INDEX_MAX 4

/* z_scene */
/* z_map_data */

typedef struct {
    /* 0x00 */ TexturePtr lmapTex; //minimap texture
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ s16 unkA;
} T_801BED4C; // size 0x0C?

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 unk7;
    /* 0x08 */ s16 unk8;
} T_801BED88; // size 0x0A

typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    s16 unk8;
} T_801BF170; // size 0x0A, ident to T_801BED88

/* z_map_disp */

typedef struct {
    /* 0x00 */ UNK_TYPE1 unk0[8];
    /* 0x08 */ s32 unk8; // G_IM_SIZ
} T_801BEAE0;

typedef struct {
    /* 0x00 */ MinimapList2* unk0; //unk0 -> sub1 -> s16[5]
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ TexturePtr unk10; // gameplay cur minimap room
    /* 0x14 */ s32 unk14; //unk4 same type as unk14
    /* 0x18 */ TexturePtr unk18;
    /* 0x1C */ s16 unk1C; //same as 0C
    /* 0x1E */ s16 unk1E; //same as 0E
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ TexturePtr unk28; //unk type
    /* 0x2C */ TexturePtr unk2C; //unk type
    /* 0x30 */ s16 unk30; //scene minBounds.x
    /* 0x32 */ s16 unk32; //scene minBounds.z
    /* 0x34 */ s16 unk34; //scene boundsWidth.x
    /* 0x36 */ s16 unk36; //scene boundsWidth.z
    /* 0x38 */ s16 unk38; //scene boundsMidpoint.x
    /* 0x3A */ s16 unk3A; //scene boundsMidpoint.z
    /* 0x3C */ s16* unk3C;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ s16 unk42;
    /* 0x44 */ s16 unk44;
    /* 0x48 */ s16* unk48;
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ char unk4E[0x02];
    /* 0x50 */ s32 unk50; //num chests
    /* 0x54 */ MinimapChest* unk54;
    /* 0x58 */ s16 unk58;
    /* 0x5A */ s16 unk5A;
} T_801BEBB8;

typedef struct {
    /* 0x00 */ s16 unk0; //scene
    /* 0x02 */ s16 unk2;
} T_801BEC5C;

typedef struct {
    /* 0x00 */ s32 unk0[5];
} T_801BEC70;

typedef struct {
    s16 unk0;
    s32 unk4;
    s32 unk8;
} T_801BED24; // size 0x0C

typedef struct {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4[32];
    /* 0x084 */ s32 unk84[32];
    /* 0x104 */ s32 unk104[32];
    /* 0x184 */ s32 unk184;
} T_801F56B0;

/* z_map_data */
TexturePtr func_8010958C(s32);

s32 func_80109714(s32);
s32 func_80109CBC(s32);
s32 func_80109A98(s32);
s32 func_80109AD8(s32);
s32 func_801096D4(s32 arg0);
void func_8010983C(s32 arg0, s32 *arg1);
void func_801097C8(s32 arg0, s32* arg1, s32* arg2);
void func_80109754(s32 arg0, s32 *arg1, s32 *arg2);

void func_80178E3C(u8*, s32, s32, s32);
#endif
