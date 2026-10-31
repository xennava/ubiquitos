#include "game.h"
#include "game_context.h"
#include <ctype.h>
#include <stdio.h>

int main() {

  GameContext ctx = {0};
  ctx.game_running = true;
  ctx.current_turn = 1;
  init(&ctx);
  while (ctx.game_running) {

    draw(&ctx);

    ctx.last_input_char = getchar();
    while (isspace(ctx.last_input_char)) {
      ctx.last_input_char = getchar();
    }

    updateInput(&ctx);
    win(&ctx);
  }
}
