#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "game_context.h"
#include "utils/misc.h"
#include <stdbool.h>
#include <stdint.h>

extern const UF16 luas;

extern void XO(U8 *buffer);
extern void XORst(U8 *buffer);
extern void win(GameContext *ctx);
extern void AIturn(GameContext *ctx);
extern void gameInit(GameContext *ctx);
extern void gameLoop(GameContext *ctx);
// extern void draw(GameContext *ctx);
// extern void gameInput(GameContext *ctx);
// extern void win(GameContext *ctx);

#endif
