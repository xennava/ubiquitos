#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "utils.h"
#include <stdbool.h>
#include <stdint.h>

#define width 22
#define height 11

extern bool run;
extern char chr;
static const uint_fast16_t luas = width * height;

extern char what[];
extern uint16_t Pctr;
extern uint8_t freeCtr;
extern uint16_t xoState16;
extern uint8_t state, winner;

extern void XO(U8 *buffer);
extern void XORst(U8 *buffer);
extern void AIturn(U8 *curXO);
extern void initSegment(U8 *buffer);
extern void updateInput(char chr, U8 *buffer);
extern void winSegment(U8 *buffer);
extern void drawSegment(U8 *buffer, U16 luas);

#endif
