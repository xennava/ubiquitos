#pragma once

extern char *getWhat();

/* helper macro */
#define setMsgArgs(fmt, ...) snprintf(what, sizeof(what), fmt, ##__VA_ARGS__)
extern void setMsg(const char *message);
