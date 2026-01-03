#include "game.h"
#include "game_context.h"
#include "utils/misc.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

const UF16 luas = width * height;

void init(GameContext *ctx) {
  memset(ctx->input_buffer, 0, luas);

  for (UF16 i = 0; i < luas; i += width)
    memcpy(ctx->input_buffer + i, "      |       |      \n", width);

  for (UF16 i = width * (height / 3); i < luas; i += (width << 2))
    memcpy(ctx->input_buffer + i, "------|-------|------",
           (sizeof(U8) << 4) + 5);

  bindState(ctx->board_bitmask);
  srand(time(NULL));
}
