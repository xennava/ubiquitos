#ifndef TRIT_H
#define TRIT_H

#include "utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef uint16_t State16[];
typedef uint16_t *pState16;

#define setTrit2Bit16(index, value) SetTrit2Bit16(voidState, index, value)
#define getTrit2Bit16(index) pGetTrit2Bit16(voidState, index)
#define setTrit16(index, value) SetTrit16(voidState, index, value)
#define getTrit16(index) pGetTrit16(voidState, index)
#define rstTrit16 *(ptrTo(voidState, U16)) = 0

static uint64_t POW3[40] = {1,
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

static inline uint16_t GetTritState(uint64_t state, uint8_t index) {
  return ((state / POW3[index]) % 3);
}

static inline void SetTritState(uint64_t *state, uint8_t index, int8_t value) {
  *state += (value - GetTritState(*state, index)) * POW3[index];
}

static inline uint16_t pGetTrit16(uint16_t *state, uint8_t index) {
  return (uint16_t)((*state / POW3[index]) % 3);
}

static inline void SetTrit16(uint16_t *state, uint8_t index, int8_t val) {
  *state += (val - GetTritState(*state, index)) * POW3[index];
}

static inline uint8_t getTrit2Bit(uint64_t state, uint8_t index) {
  return (uint8_t)((state >> (index * 2)) & 0x3ULL);
}

static inline void SetTrit2Bit(uint64_t *state, uint8_t index, int8_t value) {
  uint16_t shift = index * 2;
  // *state &= ~(0x3ULL << shift);
  // *state |= (value << shift);
  *state = (*state & ~(0x3ULL << shift)) | (value << shift);
}

static inline uint16_t pGetTrit2Bit16(uint16_t *state, uint8_t index) {
  return (uint16_t)((*state >> (index * 2)) & 0x3ULL);
}

static inline uint16_t GetTrit2Bit16(uint16_t state, uint8_t index) {
  return (uint16_t)((state >> (index * 2)) & 0x3ULL);
}

static inline void SetTrit2Bit16(uint16_t *state, uint8_t index,
                                 uint8_t value) {
  uint16_t shift = index * 2;
  *state = (*state & ~(0x3ULL << shift)) | ((uint16_t)value << shift);
}

static inline void SetsTrit2Bit16(State16 arr, int n) {
  int i = 0;
  while (i != n) {
    setTrit2Bit16(i, arr[i]);
#ifdef DEBUG
    printf("arr[%d] = %d\n", i, arr[i]);
#endif
    i++;
  }
}

static inline void SetsTrit16(State16 arr) { bindPState(arr); }

#endif
