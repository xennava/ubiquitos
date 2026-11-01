#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "game_context.h"
#include "utils/misc.h"
#include <stdbool.h>
#include <stdint.h>

extern const UF16 luas;

extern void XO(GameContext *ctx);
extern void XORst(GameContext *ctx);
extern void AITurn(GameContext *ctx);
extern void matchHandler(GameContext *ctx);

extern void gameInit(GameContext *ctx);
extern void gameLoop(GameContext *ctx);
extern void endGame(GameContext *ctx);

#endif
