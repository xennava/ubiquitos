#include "game.h"
#include "utils/trit.h"
#include <time.h>

void XO(U8 *buffer) {

  if (buffer == NULL || getPInternalSt() == NULL)
    return;
  static const U8 xy[9][2] = {{0, 0}, {1, 0}, {2, 0}, {0, 1}, {1, 1},
                              {2, 1}, {0, 2}, {1, 2}, {2, 2}};
  for (U8 i = 0; i < 9; i++) {
    const U16 gTrit = getTrit16(i);
    if (gTrit == 0)
      continue;
    // printf("i:%d, xoState: %d\n", i, gTrit);
    // 0 1 2 3 4 5 6 7 8
    // 0 1 10 11 100 101 110 111 1000
    U8 offset = ((xy[i][0] << 1) + xy[i][1] * width) << 2;

    if (gTrit == 1) {
      buffer[0 + offset] = '\\';
      buffer[4 + offset] = '/';
      buffer[width + 2 + offset] = 'X';
      buffer[(width << 1) + offset] = '/';
      buffer[(width << 1) + 4 + offset] = '\\';
    }
    if (gTrit == 2) {
      buffer[2 + offset] = 'O';
      buffer[width + offset] = 'O';
      buffer[width + 4 + offset] = 'O';
      buffer[(width << 1) + 2 + offset] = 'O';
    }
  }
}

void XORst(U8 *buffer) {
  if (buffer == NULL || getPInternalSt() == NULL)
    return;
  static const U8 xy[9][2] = {{0, 0}, {1, 0}, {2, 0}, {0, 1}, {1, 1},
                              {2, 1}, {0, 2}, {1, 2}, {2, 2}};
  for (U8 i = 0; i < 9; i++) {
    const U16 gTrit = getTrit16(i);
    if (gTrit == 0)
      continue;
    U8 offset = ((xy[i][0] << 1) + xy[i][1] * width) << 2;

    if (gTrit == 1) {
      buffer[0 + offset] = ' ';
      buffer[4 + offset] = ' ';
      buffer[width + 2 + offset] = ' ';
      buffer[(width << 1) + offset] = ' ';
      buffer[(width << 1) + 4 + offset] = ' ';
    }
    if (gTrit == 2) {
      buffer[2 + offset] = ' ';
      buffer[width + offset] = ' ';
      buffer[width + 4 + offset] = ' ';
      buffer[(width << 1) + 2 + offset] = ' ';
    }
  }
}
