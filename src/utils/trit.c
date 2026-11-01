#include "utils/trit.h"
#include "utils/misc.h"

static const U64 POW3[40] = {1,
                             3,
                             9,
                             27,
                             81,
                             243,
                             729,
                             2187,
                             6561,
                             19683,
                             59049,
                             177147,
                             531441,
                             1594323,
                             4782969,
                             4782969,
                             14348907,
                             43046721,
                             129140163,
                             387420489,
                             1162261467,
                             3486784401,
                             10460353203,
                             31381059609,
                             94143178827,
                             282429536481,
                             847288609443,
                             2541865828329,
                             7625597484987,
                             22876792454961,
                             68630377364883,
                             205891132094649,
                             617673396283947,
                             1853020188851841,
                             5559060566555523,
                             16677181699666569,
                             50031545098999707,
                             150094635296999121,
                             450283905890997363,
                             1350851717672992089};
U16 GetTritState(U64 state, U8 index) { return ((state / POW3[index]) % 3); }

void SetTritState(U64 *state, U8 index, Int8 value) {
  *state += (value - GetTritState(*state, index)) * POW3[index];
}

U16 pGetTrit16(U16 *state, U8 index) {
  return (U16)((*state / POW3[index]) % 3);
}

void SetTrit16(U16 *state, U8 index, Int8 val) {
  *state += (val - GetTritState(*state, index)) * POW3[index];
}

U8 getTrit2Bit(U64 state, U16 index) {
  return (U16)((state >> (index * 2)) & 0x3ULL);
}

void SetTrit2Bit(U64 *state, U8 index, Int8 value) {
  U16 shift = index * 2;
  // *state &= ~(0x3ULL << shift);
  // *state |= (value << shift);
  *state = (*state & ~(0x3ULL << shift)) | (value << shift);
}

U16 pGetTrit2Bit16(U16 *state, U8 index) {
  return (U16)((*state >> (index * 2)) & 0x3ULL);
}

U16 GetTrit2Bit16(U16 state, U8 index) {
  return (U16)((state >> (index * 2)) & 0x3ULL);
}

void SetTrit2Bit16(U16 *state, U8 index, U8 value) {
  U16 shift = index * 2;
  *state = (*state & ~(0x3ULL << shift)) | ((U16)value << shift);
}

// void SetsTrit16(State16 arr) { printf("size: %lu", sizeof(typeof(arr))); }
