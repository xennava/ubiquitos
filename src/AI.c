#include "tictactoe.h"
#include "trit.h"
#include "utils.h"
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

  // int rndInt = abs((rand() >> 27) - 7);
  // while (getTrit16(rndInt) != 0) {
  //   rndInt = abs((rand() >> 27) - 7);
  // }

  if (count == 0)
    return;
  U8 rndInt = emptyIndex[rand() % count];
  setTrit16(rndInt, *curXO);
  freeCtr++;
  *curXO = 1;
}
