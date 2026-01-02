#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;

extern void *voidState;

#define bindPState(x) voidState = x;
#define bindState(state) voidState = &(state)

#define ptrTo(ptr, type) ((type *)ptr)
#define stCastTo(state, type) *((type *)(uintptr_t)state)
#define stResolve(x) _Generic((x), uint8_t *: *(x), default: (x))
#define stCastToU64(state) *((uint64_t *)(state))
#define bitGetVal(index, mask) ((stCastToU64(voidState) >> index) & mask)
#define bitSet8(index, mask, val)                                              \
  *((U8 *)voidState) = (*(U8 *)(voidState) & ~(mask << index)) | (val << index)

#define setLPctr(val) Pctr = (Pctr & ~(255)) | (val)
#define setHPctr(val) Pctr = (Pctr & ~(255 << 8)) | (val) << 8
#define getLPctr (Pctr & 255)
#define getHPctr ((Pctr >> 8) & 255)

inline void *getPInternalSt() { return voidState; }

#endif // !UTILS_H
