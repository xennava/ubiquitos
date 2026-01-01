#include "tictactoe.h"
#include "trit.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

void updateInput(const char chr, U8 *buffer) {
  if (chr == 'r') {
    // reset buffer and UI.
    if (getPInternalSt() == NULL || freeCtr == 0) {
      strcpy(what, "Hey, main dulu!");
      state = 1;
      return;
    }
    XORst(buffer);
    printf("The void first: %d\n", *((U16 *)voidState));
    rstTrit16;
    printf("The void latter: %d\n", *((U16 *)voidState));
    state = 1;
    freeCtr = 0;
    strcpy(what, "Emdam");
  }
  if (chr == 'q') {
    printf("Quitted.\n");
    run = false;
    return;
  }

  if (state == 1 && chr >= '0' && chr <= '9') {
    if (getTrit16(chr - '1') == 0) {
      setTrit16(chr - '1', state);
      state = 2;
      freeCtr++;
    }
  }
  if (state == 2)
    AIturn(&state);
}
