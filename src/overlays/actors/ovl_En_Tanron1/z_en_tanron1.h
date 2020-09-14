#ifndef Z_EN_TANRON1_H
#define Z_EN_TANRON1_H

#include <global.h>

struct EnTanron1;

typedef struct EnTanron1 {
    /* 0x0000 */ Actor actor;
    /* 0x0144 */ char unk0144[0x4];
    /* 0x0148 */ s16 unk0148;
    /* 0x014C */ char unk014C[0x3220];
} EnTanron1; // size = 0x336C

extern const ActorInit En_Tanron1_InitVars;

#endif // Z_EN_TANRON1_H
