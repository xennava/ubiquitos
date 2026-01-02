#include "tictactoe.h"
#include "trit.h"
#include "utils.h"
#include <stdint.h>
#include <stdlib.h>

void AIturn(U8 *curXO) {
  if (!getPInternalSt())
    return;
  if (freeCtr > 8 || freeCtr == 0)
    return;
  U8 emptyIndex[9];
  U8 count = 0;
  for (U8 i = 0; i < 9; i++) {
    if (getTrit16(i) == 0)
      emptyIndex[count++] = i;
  }

  if (count == 0)
    return;
  // index -> a random pick of available move
  setTrit16(emptyIndex[(rand() >> 28) % count], *curXO);
  freeCtr++;
  *curXO = 1;
}
