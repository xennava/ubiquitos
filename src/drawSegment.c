#include "tictactoe.h"
#include "utils.h"
#include <stdio.h>

void drawSegment(U8 *buffer, const U16 luas) {
  XO(buffer);
  fwrite(buffer, sizeof(typeof(*buffer)), luas, stdout);

  printf("--\t%s\ninput User:%c, state: %hhu, atoi:%d, counter: %d\n-- P1: "
         "%d -- P2: %d\n",
         what, chr, state, chr - '0', freeCtr, Pctr & 0b11111111,
         (Pctr >> 8) & 0b11111111);
}
