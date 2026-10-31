#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H

#include <stdbool.h>
#include <stdint.h>

#define width 22
#define height 11

/* ---- Type aliases for clarity ---- */
typedef uint8_t U8;
typedef uint16_t U16;

/* ---- Player / Turn enum ---- */
typedef enum {
  PLAYER_NONE = 0, /* no player / empty state */
  PLAYER_1 = 1,    /* human player */
  PLAYER_2 = 2     /* AI player */
} Player;

/* ---- Main Game Context ---- */
typedef struct {
  /* Is the game currently running? */
  bool game_running;

  /* Input buffer for all processed characters */
  U8 input_buffer[242];

  /* Whose turn is it? (Player enum) */
  Player current_turn;

  /* Winner latch to avoid race condition */
  Player winner_player;

  /* Number of valid moves already processed */
  U8 move_count;

  /* Player scores (bit-packed if needed):
   * Lower 8 bits  -> player 1  (human)
   * Higher 8 bits -> player 2  (AI)
   */
  U8 lower_score;
  U8 higher_score;

  /* Bitboard representing X/O positions on the board */
  U16 board_bitmask;

} GameContext;

#endif /* GAME_CONTEXT_H */
