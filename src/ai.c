#include "game.h"
#include "game_context.h"
#include "utils/misc.h"
#include <stdint.h>
#include <stdlib.h>

void AITurn(GameContext *ctx) {
  U8 boardSize = ctx->boardSize;
  if (ctx->move_count > 8 || ctx->move_count == 0 ||
      ctx->players[ctx->currentPlayerId].isAi == false)
    return;

  // get the latest list
  U8 emptyIndex[boardSize];
  U8 count = 0;
  for (U8 i = 0; i < boardSize; i++) {
    if (ctx->board_bitmask[i] == 0)
      emptyIndex[count++] = i;
  }

  if (count == 0)
    return;
  // index -> a random pick of available move
  ctx->board_bitmask[emptyIndex[(rand() >> 28) % count]] =
      ctx->players[ctx->currentPlayerId].shape;
  ctx->move_count++;
  stepPlayer(ctx);
}
