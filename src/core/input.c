#include "core/input.h"
#include <ctype.h>
#include <stdio.h>

char _char = 0;

char getChar() { return _char; }

void inputHandler() {

  _char = getchar();
  while (isspace(_char)) {
    _char = getchar();
  }
}
