#include "game.h"
#include "game_context.h"
#include "utils/msg.h"
#include <stdio.h>

void draw(GameContext *ctx) {
  XO(ctx->input_buffer);
  fwrite(ctx->input_buffer, sizeof(typeof(*ctx->input_buffer)), luas, stdout);

#ifndef NDEBUG
  printf("--\t%s\ninput User:%c, Current Turn: %s, intChar:%d, move_count: "
         "%d\n-- P1: "
         "%d -- P2: %d\nNULL internal buffer? %s\n",
         what, ctx->last_input_char,
         (ctx->current_turn == PLAYER_1
              ? "HUMAN"
              : (ctx->current_turn == PLAYER_2 ? "AI" : "NONE")),
         ctx->last_input_char - '0', ctx->move_count, ctx->lower_score,
         ctx->higher_score, (getPInternalSt() == NULL) ? "true" : "false");
#endif
}
