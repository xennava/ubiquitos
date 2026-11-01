#include "game_context.h"
#include "utils/msg.h"
#include <stdio.h>
#include <string.h>

typedef enum {
  MATCH_RESULT_PENDING,
  MATCH_RESULT_WIN,
  MATCH_RESULT_DRAW
} MatchResult;

MatchResult matchResult;

bool won = false;
const char *winMessage = "Ada yang menang nih!";
void atWin(GameContext *ctx) {

  U8 winner = ctx->winnerId;
  if (winner > ctx->playerCount) {
    winner = ctx->playerCount;
  }

  snprintf(getWhat(), strlen(winMessage), "%s %d", winMessage, winner);

  ctx->players[winner].score++;
  ctx->winnerId = 0;
}

void winLines(GameContext *ctx, U16 now, U16 n1, U16 n2) {
  if (won)
    return;
  int *board = ctx->board_bitmask;
  if (board == NULL)
    return;
  now = board[now];
  if ((now != 0) && (now == board[n1]) && (now == board[n2])) {
    ctx->winnerId = now - 1; // shape -> id, strange
    matchResult = MATCH_RESULT_WIN;
    return;
  }
}

void manualCombinationalWinLinesCheck(GameContext *ctx) {

  winLines(ctx, 0, 1, 2);
  winLines(ctx, 3, 4, 5);
  winLines(ctx, 6, 7, 8);

  winLines(ctx, 0, 3, 6);
  winLines(ctx, 1, 4, 7);
  winLines(ctx, 2, 5, 8);

  winLines(ctx, 0, 4, 8);
  winLines(ctx, 2, 4, 6);
}

void matchHandler(GameContext *ctx) {
  manualCombinationalWinLinesCheck(ctx);
  if (ctx->move_count >= ctx->boardSize &&
      matchResult == MATCH_RESULT_PENDING) {
    matchResult = MATCH_RESULT_DRAW;
  }

  switch (matchResult) {
  case MATCH_RESULT_PENDING:
    return;
  case MATCH_RESULT_WIN:
    atWin(ctx);
  case MATCH_RESULT_DRAW:
    ctx->resetPlayGame = true;
    break;
  default:
    break;
  }

  matchResult = MATCH_RESULT_PENDING;
}
