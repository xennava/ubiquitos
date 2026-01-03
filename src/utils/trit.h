#ifndef TRIT_H
#define TRIT_H
#include "misc.h"

typedef U16 State16[];
typedef U16 *pState16;

#define setTrit2Bit16(index, value) SetTrit2Bit16(voidState, index, value)
#define getTrit2Bit16(index) pGetTrit2Bit16(voidState, index)
#define setTrit16(index, value) SetTrit16(voidState, index, value)
#define getTrit16(index) pGetTrit16(voidState, index)
#define rstTrit16 *(ptrTo(voidState, U16)) = 0

extern U16 GetTritState(U64 state, U8 index);
extern void SetTritState(U64 *state, U8 index, Int8 value);
extern U16 pGetTrit16(U16 *state, U8 index);
extern void SetTrit16(U16 *state, U8 index, Int8 val);
extern U8 getTrit2Bit(U64 state, U16 index);
extern void SetTrit2Bit(U64 *state, U8 index, Int8 value);
extern U16 pGetTrit2Bit16(U16 *state, U8 index);
extern U16 GetTrit2Bit16(U16 state, U8 index);
extern void SetTrit2Bit16(U16 *state, U8 index, U8 value);
extern void SetsTrit2Bit16(State16 arr, int n);
extern void SetsTrit16(State16 arr);
#endif // !TRIT_H
