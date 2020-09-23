#ifndef Z_DOOR_WARP1_H
#define Z_DOOR_WARP1_H

#include <global.h>

struct DoorWarp1;

typedef struct DoorWarp1 {
    /* 0x000 */ Actor actor;
    /* 0x144 */ char unk_144[0xBF];
    /* 0x203 */ u8 unk_203;
    /* 0x204 */ f32 unk_204;
    /* 0x208 */ char unk_208[0x4];
} DoorWarp1; // size = 0x20C

extern const ActorInit Door_Warp1_InitVars;

#endif // Z_DOOR_WARP1_H
