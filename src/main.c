#include "core/input.h"
#include "game.h"
#include "game_context.h"
#include <stdlib.h>

int main() {

  GameContext ctx = {0};
  ctx.game_running = true;
  ctx.playerCount = 2; // 2 players
  ctx.boardSize = 9;
  ctx.players = (Player *)malloc(sizeof(Player) * ctx.playerCount);

  ctx.players[0] = (Player){0, 0, 1, 0};
  ctx.players[1] = (Player){1, 0, 2, 1};

  ctx.board_bitmask = (int *)calloc(9, sizeof(int));

  ctx.currentPlayerId = 0;
  ctx.move_count = 0;

  gameInit(&ctx);
  while (ctx.game_running) {
    gameLoop(&ctx);
    if (ctx.game_running)
      inputHandler();
  }

  endGame(&ctx);
}
