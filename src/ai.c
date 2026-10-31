#include "game.h"
#include "game_context.h"
#include "utils/misc.h"
#include "utils/trit.h"
#include <stdint.h>
#include <stdlib.h>

#define invalidMove ctx->move_count > 8 || ctx->move_count == 0

void AIturn(GameContext *ctx) {
  if (!getInternalStatePointer())
    return;
  if (invalidMove)
    return;

  // get the latest list
  U8 emptyIndex[9];
  U8 count = 0;
  for (U8 i = 0; i < 9; i++) {
    if (getTrit16(i) == 0)
      emptyIndex[count++] = i;
  }

  if (count == 0)
    return;
  // index -> a random pick of available move
  setTrit16(emptyIndex[(rand() >> 28) % count], ctx->current_turn);
  ctx->move_count++;
  ctx->current_turn = PLAYER_1;
}
