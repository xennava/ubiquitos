#include <time.h>
void *voidState = NULL;

void *getInternalStatePointer() { return voidState; }
void bindInternalState(void *p) { voidState = p; }
