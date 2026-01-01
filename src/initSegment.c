#include "tictactoe.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

void initSegment(U8 *buffer) {
  memset(buffer, 0, luas);

  for (uint_fast16_t i = 0; i < luas; i += width)
    memcpy(buffer + i, "      |       |      \n", width);

  for (uint_fast16_t i = width * (height / 3); i < luas; i += (width << 2))
    memcpy(buffer + i, "------|-------|------", (sizeof(uint8_t) << 4) + 5);

  bindState(xoState16);
  setLPctr(0);
  setHPctr(0);
  srand(time(NULL));
}
