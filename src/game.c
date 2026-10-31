#include "game.h"
#include "game_context.h"
#include "utils/misc.h"
#include "utils/msg.h"
#include "utils/trit.h"
#include <core/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const UF16 luas = width * height;

void gameInit(GameContext *ctx) {
  memset(ctx->input_buffer, 0, luas);

  for (UF16 i = 0; i < luas; i += width)
    memcpy(ctx->input_buffer + i, "      |       |      \n", width);

  for (UF16 i = width * (height / 3); i < luas; i += (width << 2))
    memcpy(ctx->input_buffer + i, "------|-------|------",
           (sizeof(U8) << 4) + 5);

  bindState(ctx->board_bitmask);
  srand(time(NULL));
}

void draw(GameContext *ctx) {
  XO(ctx->input_buffer);
  fwrite(ctx->input_buffer, sizeof(typeof(*ctx->input_buffer)), luas, stdout);

#ifndef NDEBUG
  printf("--\t%s\ninput User:%c, Current Turn: %s, intChar:%d, move_count: "
         "%d\n-- P1: "
         "%d -- P2: %d\nNULL internal buffer? %s\n",
         getWhat(), ctx->last_input_char,
         (ctx->current_turn == PLAYER_1
              ? "HUMAN"
              : (ctx->current_turn == PLAYER_2 ? "AI" : "NONE")),
         ctx->last_input_char - '0', ctx->move_count, ctx->lower_score,
         ctx->higher_score,
         (getInternalStatePointer() == NULL) ? "true" : "false");
#endif
}

void gameInput(GameContext *ctx) {
  // Quit handler
  if (getKeys()['q']) {
    printf("Quitted.\n");
    ctx->game_running = false;
    return;
  }
  // Reset input
  if (getKeys()['r']) {
    // reset buffer and UI.
    if (getInternalStatePointer() == NULL || ctx->move_count == 0) {
      setMsg("Hey, main dulu!");
      ctx->current_turn = PLAYER_1;
      return;
    }
    XORst(ctx->input_buffer);
    printf("The void first: %d\n", *((U16 *)getInternalStatePointer()));
    rstTrit16;
    printf("The void latter: %d\n", *((U16 *)getInternalStatePointer()));
    ctx->current_turn = PLAYER_1;
    ctx->move_count = 0;
    setMsg("Emdam");
  }
  // User input
  if (ctx->current_turn == PLAYER_1 && getChar() >= '0' && getChar() <= '9') {
    if (getTrit16(getChar() - '1') == 0) {
      setTrit16(getChar() - '1', ctx->current_turn);
      ctx->current_turn = PLAYER_2;
      ctx->move_count++;
    }
  }
  // AI input/output handler
  if (ctx->current_turn == PLAYER_2)
    AIturn(ctx);
}

void gameLoop(GameContext *ctx) {
  gameInput(ctx);
  win(ctx);

  draw(ctx);
}
