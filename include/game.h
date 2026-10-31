#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "game_context.h"
#include "utils/misc.h"
#include <stdbool.h>
#include <stdint.h>

#define width 22
#define height 11

extern const UF16 luas;

extern void XO(U8 *buffer);
extern void XORst(U8 *buffer);
extern void AIturn(GameContext *ctx);
extern void init(GameContext *ctx);
extern void updateInput(GameContext *ctx);
extern void win(GameContext *ctx);
extern void draw(GameContext *ctx);

#endif
