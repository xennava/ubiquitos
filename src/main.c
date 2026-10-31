#include "core/input.h"
#include "game.h"
#include "game_context.h"

int main() {

  GameContext ctx = {0};
  ctx.game_running = true;
  ctx.current_turn = 1;
  gameInit(&ctx);
  while (ctx.game_running) {
    gameLoop(&ctx);
    if (ctx.game_running)
      inputHandler();
  }
}
