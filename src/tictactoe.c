#include "tictactoe.h"
#include <ctype.h>
#include <stdio.h>

bool run = true;
char chr;
uint8_t buffer[242];

int main() {

  initSegment(buffer);

  while (run) {

    drawSegment(buffer, luas);

    chr = getchar();
    while (isspace(chr)) {
      chr = getchar();
    }

    updateInput(chr, buffer);
    winSegment(buffer);
  }
}
