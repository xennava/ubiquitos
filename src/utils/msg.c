#include "utils/msg.h"
#include <string.h>

char what[100];

char *getWhat() { return what; }
void setMsg(const char *message) { strcpy(getWhat(), message); }
