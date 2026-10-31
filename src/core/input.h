#include "core/input.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool keys[255];
char _char = 0;

const bool *getKeys() { return keys; }
char getChar() { return _char; }

void inputHandler() {
  memset(keys, 0, 255);

  _char = getchar();
  keys[(int)_char] = true;
  while (isspace(_char)) {
    _char = getchar();
  }
}
