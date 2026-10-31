#include "game.h"
#include "game_context.h"
#include "utils/msg.h"
#include "utils/trit.h"
#include <stdio.h>
#include <time.h>

void updateInput(GameContext *ctx) {
  // Reset input
  if (ctx->last_input_char == 'r') {
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
  // Quit handler
  if (ctx->last_input_char == 'q') {
    printf("Quitted.\n");
    ctx->game_running = false;
    return;
  }
  // User input
  if (ctx->current_turn == PLAYER_1 && ctx->last_input_char >= '0' &&
      ctx->last_input_char <= '9') {
    if (getTrit16(ctx->last_input_char - '1') == 0) {
      setTrit16(ctx->last_input_char - '1', ctx->current_turn);
      ctx->current_turn = PLAYER_2;
      ctx->move_count++;
    }
  }

  // AI input/output handler
  if (ctx->current_turn == PLAYER_2)
    AIturn(ctx);
}
