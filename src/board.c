#include "game.h"
#include "game_context.h"
#include <stdlib.h>

void XO(GameContext *ctx) {
  U8 *buffer = ctx->input_buffer;
  int *board = ctx->board_bitmask;
  if (buffer == NULL || board == NULL)
    return;
  static const U8 xy[9][2] = {{0, 0}, {1, 0}, {2, 0}, {0, 1}, {1, 1},
                              {2, 1}, {0, 2}, {1, 2}, {2, 2}};
  for (U8 i = 0; i < ctx->boardSize; i++) {
    const U16 shape = board[i];
    if (shape == 0)
      continue;
    U8 offset = ((xy[i][0] << 1) + xy[i][1] * width) << 2;

    if (shape == 1) {
      buffer[0 + offset] = '\\';
      buffer[4 + offset] = '/';
      buffer[width + 2 + offset] = 'X';
      buffer[(width << 1) + offset] = '/';
      buffer[(width << 1) + 4 + offset] = '\\';
    }
    if (shape == 2) {
      buffer[2 + offset] = 'O';
      buffer[width + offset] = 'O';
      buffer[width + 4 + offset] = 'O';
      buffer[(width << 1) + 2 + offset] = 'O';
    }
  }
}

void XORst(GameContext *ctx) {
  U8 *buffer = ctx->input_buffer;
  int *board = ctx->board_bitmask;
  if (buffer == NULL || board == NULL)
    return;
  static const U8 xy[9][2] = {{0, 0}, {1, 0}, {2, 0}, {0, 1}, {1, 1},
                              {2, 1}, {0, 2}, {1, 2}, {2, 2}};
  for (U8 i = 0; i < ctx->boardSize; i++) {
    const U16 shape = board[i];
    if (shape == 0)
      continue;
    U8 offset = ((xy[i][0] << 1) + xy[i][1] * width) << 2;

    if (shape == 1) {
      buffer[0 + offset] = ' ';
      buffer[4 + offset] = ' ';
      buffer[width + 2 + offset] = ' ';
      buffer[(width << 1) + offset] = ' ';
      buffer[(width << 1) + 4 + offset] = ' ';
    }
    if (shape == 2) {
      buffer[2 + offset] = ' ';
      buffer[width + offset] = ' ';
      buffer[width + 4 + offset] = ' ';
      buffer[(width << 1) + 2 + offset] = ' ';
    }
  }
}
