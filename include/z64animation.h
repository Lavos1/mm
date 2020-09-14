#ifndef _Z64_ANIMATION_H
#define _Z64_ANIMATION_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>
#include <z64dma.h>
#include <z64math.h>

#define LINK_ANIMETION_OFFSET(addr,offset) (((u32)&_link_animetionSegmentRomStart)+((u32)addr)-((u32)&link_animetion_segment)+((u32)offset))
#define LIMB_DONE 0xFF
#define ANIMATION_ENTRY_MAX 50

#define ANIM_FLAG_UPDATEXZ 0x02
#define ANIM_FLAG_UPDATEY  0x10

struct GlobalContext;
struct Actor;
typedef struct SkelAnime SkelAnime;

typedef struct {
    /* 0x000 */ Vec3s translation;      // Translation relative to parent limb.  root limb is a tranlation for entire model.
    /* 0x006 */ u8 firstChildIndex;     // The first child's index into the limb table.
    /* 0x007 */ u8 nextLimbIndex;       // The parent limb's next limb index into the limb table.
    /* 0x008 */ Gfx* displayLists[1];   // Display lists for the limb. Index 0 is the normal display list, index 1 is the far model display list.
} SkelLimbEntry; // Size = 0xC or 0x10

typedef struct {
    /* 0x000 */ SkelLimbEntry* limbs[1];   // One ore more limbs, index 0 is the root limb.
} Skeleton; // Size >= 4

typedef struct {
    /* 0x000 */ Skeleton* skeletonSeg; // Segment address of SkelLimbIndex.
    /* 0x004 */ u8 limbCount;       // Number of limbs in the model.
    /* 0x005 */ char unk_05[3];     // unknown, maybe padding?
    /* 0x008 */ u8 dListCount;      // Number of display lists in the model.
} SkeletonHeader;  // Size = 0xC

typedef struct {
    s16 frameCount;
    s16 unk_02;
} GenericAnimationHeader;

typedef struct {
    /* 0x000 */ GenericAnimationHeader genericHeader;
    /* 0x004 */ u32 rotationValueSeg; // referenced as tbl
    /* 0x008 */ u32 rotationIndexSeg; // referenced as ref_tbl
    /* 0x00C */ u16 limit;
} AnimationHeader; // size = 0x10

typedef struct {
    GenericAnimationHeader genericHeader;
    u32 animationSegAddress;
} LinkAnimetionEntry;

struct SkelAnime {
    /* 0x00 */ u8 limbCount; // joint_Num
    /* modes 0 and 1 repeat the animation indefinitely
     * modes 2 and 3 play the animaton once then stop
     * modes >= 4 play the animation once, and always start at frame 0.
    */
    /* 0x01 */ u8 mode;
    /* 0x02 */ u8 dListCount;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ Skeleton* skeleton;
    /* 0x08 */
    union {
        AnimationHeader* animCurrentSeg;
        LinkAnimetionEntry* linkAnimetionSeg;
        GenericAnimationHeader* genericSeg;
    };
    /* 0x0C */ f32 initialFrame;
    /* 0x10 */ f32 animFrameCount;
    /* 0x14 */ f32 totalFrames;
    /* 0x18 */ f32 animCurrentFrame;
    /* 0x1C */ f32 animPlaybackSpeed;
    /* 0x20 */ Vec3s* limbDrawTbl; // now_joint
    /* 0x24 */ Vec3s* transitionDrawTbl; // morf_joint
    /* 0x28 */ f32 transCurrentFrame;
    /* 0x2C */ f32 transitionStep;
    /* 0x30 */ s32 (*animUpdate)();
    /* 0x34 */ s8 initFlags;
    /* 0x35 */ u8 flags;
    /* 0x36 */ s16 prevFrameRot;
    /* 0x38 */ Vec3s prevFramePos;
    /* 0x3E */ Vec3s unk_3E;
}; // size = 0x44

typedef s32 (*OverrideLimbDraw)(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList,
             Vec3f* pos, Vec3s* rot, struct Actor* actor);

typedef void (*PostLimbDraw)(struct GlobalContext* globalCtx, s32 limbIndex, Gfx** dList,
                                          Vec3s* rot, struct Actor* actor);

#endif
