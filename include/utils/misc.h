#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef int8_t Int8;
typedef int16_t Int16;
typedef uint_fast16_t UF16;

extern void *getInternalStatePointer();
extern void bindInternalState(void *p);

#define bindState(state) bindInternalState(&(state))

#define ptrTo(ptr, type) ((type *)ptr)
#define stCastTo(state, type) *((type *)(uintptr_t)state)
#define stResolve(x) _Generic((x), U8 *: *(x), default: (x))
#define stCastToU64(state) *((U64 *)(state))
#define bitGetVal(index, mask) ((stCastToU64(voidState) >> index) & mask)
#define bitSet8(index, mask, val)                                              \
  *((U8 *)voidState) = (*(U8 *)(voidState) & ~(mask << index)) | (val << index)

#endif // !UTILS_H
