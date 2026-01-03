#pragma once

#include <string.h>
char what[100];
/* helper macro */
#define setMsgArgs(fmt, ...) snprintf(what, sizeof(what), fmt, ##__VA_ARGS__)
void setMsg(const char *message) { strcpy(what, message); }
