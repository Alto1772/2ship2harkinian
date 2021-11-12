#ifndef _OS_H_
#define _OS_H_

#include "libc/stdlib.h"
#include "ultra64/thread.h"
#include "ultra64/message.h"

#define OS_READ     0
#define OS_WRITE    1

/*
 * I/O message types
 */
#define OS_MESG_TYPE_BASE        10
#define OS_MESG_TYPE_LOOPBACK    (OS_MESG_TYPE_BASE+0)
#define OS_MESG_TYPE_DMAREAD     (OS_MESG_TYPE_BASE+1)
#define OS_MESG_TYPE_DMAWRITE    (OS_MESG_TYPE_BASE+2)
#define OS_MESG_TYPE_VRETRACE    (OS_MESG_TYPE_BASE+3)
#define OS_MESG_TYPE_COUNTER     (OS_MESG_TYPE_BASE+4)
#define OS_MESG_TYPE_EDMAREAD    (OS_MESG_TYPE_BASE+5)
#define OS_MESG_TYPE_EDMAWRITE   (OS_MESG_TYPE_BASE+6)

/*
 * I/O message priority
 */
#define OS_MESG_PRI_NORMAL    0
#define OS_MESG_PRI_HIGH      1


typedef u32 OSIntMask;

typedef u32 OSPageMask;

typedef struct {
    /* 0x00 */ u32 errStatus;
    /* 0x04 */ void* dramAddr;
    /* 0x08 */ void* C2Addr;
    /* 0x0C */ u32 sectorSize;
    /* 0x10 */ u32 C1ErrNum;
    /* 0x14 */ u32 C1ErrSector[4];
} __OSBlockInfo; // size = 0x24


typedef struct {
    /* 0x00 */ u32 cmdType;
    /* 0x04 */ u16 transferMode;
    /* 0x06 */ u16 blockNum;
    /* 0x08 */ s32 sectorNum;
    /* 0x0C */ u32 devAddr;
    /* 0x10 */ u32 bmCtlShadow;
    /* 0x14 */ u32 seqCtlShadow;
    /* 0x18 */ __OSBlockInfo block[2];
} __OSTranxInfo; // size = 0x60


typedef struct OSPiHandle_s {
    /* 0x00 */ struct OSPiHandle_s* next;
    /* 0x04 */ u8 type;
    /* 0x05 */ u8 latency;
    /* 0x06 */ u8 pageSize;
    /* 0x07 */ u8 relDuration;
    /* 0x08 */ u8 pulse;
    /* 0x09 */ u8 domain;
    /* 0x0C */ u32 baseAddress;
    /* 0x10 */ u32 speed;
    /* 0x14 */ __OSTranxInfo transferInfo;
} OSPiHandle; // size = 0x74


typedef struct {
    /* 0x0 */ u8 type;
    /* 0x4 */ u32 address;
} OSPiInfo; // size = 0x8


typedef struct {
    /* 0x0 */ u16 type;
    /* 0x2 */ u8 pri;
    /* 0x3 */ u8 status;
    /* 0x4 */ OSMesgQueue* retQueue;
} OSIoMesgHdr; // size = 0x8


typedef struct {
    /* 0x00 */ OSIoMesgHdr hdr;
    /* 0x08 */ void* dramAddr;
    /* 0x0C */ u32 devAddr;
    /* 0x10 */ size_t size;
    /* 0x14 */ OSPiHandle* piHandle;
} OSIoMesg; // size = 0x88


typedef struct {
    /* 0x00 */ s32 active; // u32 maybe? need to check
    /* 0x04 */ OSThread* thread;
    /* 0x08 */ OSMesgQueue* cmdQueue;
    /* 0x0C */ OSMesgQueue* evtQueue;
    /* 0x10 */ OSMesgQueue* acsQueue;
    /* 0x14 */ s32 (*piDmaCallback)(s32, u32, void*, size_t);
    /* 0x18 */ s32 (*epiDmaCallback)(OSPiHandle*, s32, u32, void*, size_t);
} OSDevMgr; // size = 0x1C

typedef u64 OSTime;

typedef struct OSTimer_s {
    /* 0x00 */ struct OSTimer_s* next;
    /* 0x04 */ struct OSTimer_s* prev;
    /* 0x08 */ OSTime interval;
    /* 0x10 */ OSTime value;
    /* 0x18 */ OSMesgQueue* mq;
    /* 0x1C */ OSMesg msg;
} OSTimer; // size = 0x20

typedef struct {
    /* 0x0 */ u16 type;
    /* 0x2 */ u8 status;
    /* 0x3 */ u8 errno;
} OSContStatus; // size = 0x4


typedef struct {
    /* 0x0 */ u16 button;
    /* 0x2 */ s8 stick_x;
    /* 0x3 */ s8 stick_y;
    /* 0x4 */ u8 errno;
} OSContPad; // size = 0x6


typedef struct {
    /* 0x00 */ void* address;
    /* 0x04 */ u8 databuffer[32];
    /* 0x24 */ u8 addressCrc;
    /* 0x25 */ u8 dataCrc;
    /* 0x26 */ u8 errno;
} OSContRamIo; // size = 0x28

typedef struct {
    /* 0x0 */ u16* histo_base;
    /* 0x4 */ u32 histo_size;
    /* 0x8 */ u32* text_start;
    /* 0xC */ u32* text_end;
} OSProf; // size = 0x10

typedef enum {
    /* 0  */ VOICE_WORD_ID_HOURS,
    /* 1  */ VOICE_WORD_ID_CHEESE,
    /* 2  */ VOICE_WORD_ID_WAKE_UP,
    /* 3  */ VOICE_WORD_ID_SIT,
    /* 4  */ VOICE_WORD_ID_MILK,
    /* 5  */ VOICE_WORD_ID_HIYA,
    /* 6  */ VOICE_WORD_ID_MAX,
    /* -1 */ VOICE_WORD_ID_NONE = 0xFFFF
} OSVoiceWordId;

#define VOICE_STATUS_READY 0 /* stop/end */
#define VOICE_STATUS_START 1 /* Voice Undetected (no voice input) */
#define VOICE_STATUS_CANCEL 3 /* Cancel (cancel extraneous noise) */
#define VOICE_STATUS_BUSY 5 /* Detected/Detecting (voice being input, recognition processing under way) */
#define VOICE_STATUS_END 7 /* End recognition processing (enable execution of Get Recognition Results command) */

#define VOICE_WARN_TOO_SMALL 0x400 /* Voice level is too low (100 < Voice Level < 150) */
#define VOICE_WARN_TOO_LARGE 0x800 /* Voice level is too high (Voice Level > 3500) */
#define VOICE_WARN_NOT_FIT 0x4000 /* No words match recognition word (No. 1 Candidate Distance Value > 1600) */
#define VOICE_WARN_TOO_NOISY 0x8000 /* Too much ambient noise (Relative Voice Level =< 400) */

typedef struct {
    /* 0x0 */ OSMesgQueue* mq;
    /* 0x4 */ s32 port; /* Controller port */
    /* 0x8 */ s32 mode;
    /* 0xC */ u8 status;
} OSVoiceHandle; // size = 0x10

typedef struct {
    /* 0x00 */ u16 warning;     /* Warning */
    /* 0x02 */ u16 answerNum;  /* Candidate number (0~5) */
    /* 0x04 */ u16 voiceLevel; /* Voice input level */
    /* 0x06 */ u16 voiceRelLevel;   /* Relative voice level "voice_sn" */
    /* 0x08 */ u16 voiceTime;  /* Voice input time */
    /* 0x0A */ u16 answer[5];   /* Candidate word number */
    /* 0x14 */ u16 distance[5]; /* Distance value */
} OSVoiceData; // size = 0x20

typedef struct {
    /* 0x000 */ u16 words[20][15]; // 20 words, each with up to 15 syllables
    /* 0x258 */ u8 numWords;
} OSVoiceDictionary; // size = 0x25C

typedef struct {
    /* 0x00 */ OSVoiceDictionary* dict;
    /* 0x04 */ s8 mode;
    /* 0x08 */ OSVoiceData* data;
    /* 0x0C */ u16 distance;
    /* 0x0E */ u16 answerNum;
    /* 0x10 */ u16 warning;
    /* 0x12 */ u16 voiceLevel;
    /* 0x14 */ u16 voiceRelLevel;
} OSVoiceUnk; // size = 0x18

#endif
