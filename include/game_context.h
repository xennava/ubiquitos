#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H

#include "utils/misc.h"
#include <stdbool.h>
#include <stdint.h>

#define width 22
#define height 11

typedef struct {
  U8 id;
  U8 score;
  U8 shape;
  bool isAi;
} Player;

/* ---- Main Game Context ---- */
typedef struct {
  /* Input buffer for all processed characters */
  U8 input_buffer[242];
  Player *players;
  /* Bitboard representing X/O positions on the board */
  int *board_bitmask;
  U8 boardSize;

  U8 playerCount;
  /* Whose turn is it? (Player enum) */
  U8 currentPlayerId;

  /* Winner latch to avoid race condition */
  U8 winnerId;
  bool isDraw;

  /* Is the game currently running? */
  bool game_running;
  bool resetPlayGame;

  /* Number of valid moves already processed */
  U8 move_count;
} GameContext;

extern void firstPlayer(GameContext *ctx);
extern void stepPlayer(GameContext *ctx);
#endif /* GAME_CONTEXT_H */
