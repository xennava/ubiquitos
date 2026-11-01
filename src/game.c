#include "game.h"
#include "game_context.h"
#include "utils/misc.h"
#include "utils/msg.h"
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

  srand(time(NULL));
}

void draw(GameContext *ctx) {
  XO(ctx);
  fwrite(ctx->input_buffer, sizeof(typeof(*ctx->input_buffer)), luas, stdout);

#ifndef NDEBUG
  printf("--\t%s\ninput User:%c, Current Turn: %s, intChar:%d, move_count: "
         "%d\n-- P1: "
         "%d -- P2: %d\n",
         getWhat(), getChar(),
         (ctx->currentPlayerId == 0
              ? "HUMAN"
              : (ctx->currentPlayerId == 1 ? "AI" : "NONE")),
         getChar() - '0', ctx->move_count, ctx->players[0].score,
         ctx->players[1].score);
#endif
}

void resetPlayGameHandler(GameContext *ctx) {
  if (ctx->resetPlayGame == false)
    return;
  XORst(ctx);
  firstPlayer(ctx);
  memset(ctx->board_bitmask, 0, sizeof(int) * ctx->boardSize);
  ctx->move_count = 0;
  ctx->resetPlayGame = false;
}

bool playerChoosed = false;
void playerInput(GameContext *ctx) {
  // Quit handler
  if (getChar() == 'q') {
    printf("Quitted.\n");
    ctx->game_running = false;
    return;
  }
  // Reset input
  if (getChar() == 'r') {
    // reset buffer and UI.
    if (ctx->move_count == 0) {
      setMsg("Main dulu..");
      firstPlayer(ctx);
      return;
    }
    ctx->resetPlayGame = true;
  }
  // User input
  U8 n = getChar() - '1';
  int *board = ctx->board_bitmask;
  if (board)
    if (n >= 0 && n <= 9) {
      if (board[n] == 0) {
        board[n] = ctx->players[ctx->currentPlayerId].shape;
        ctx->move_count++;

        stepPlayer(ctx);
        playerChoosed = true;
      }
    }
}

void gameLoop(GameContext *ctx) {

  playerInput(ctx);

  if (ctx->players && playerChoosed)
    AITurn(ctx);

  if (playerChoosed)
    playerChoosed = false;

  matchHandler(ctx);

  resetPlayGameHandler(ctx);

  draw(ctx);
}

void endGame(GameContext *ctx) {
  free(ctx->players);
  ctx->players = NULL;
  free(ctx->board_bitmask);
  ctx->players = NULL;
}

void firstPlayer(GameContext *ctx) {
  if (ctx == NULL) {
    return;
  }
  ctx->currentPlayerId = 0;
}
void stepPlayer(GameContext *ctx) {
  if (ctx == NULL)
    return;
  ctx->currentPlayerId++;
  if (ctx->currentPlayerId >= ctx->playerCount)
    ctx->currentPlayerId = 0;
}
