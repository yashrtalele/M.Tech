#include <sys/types.h>
#include <sys/stat.h>

void main(void) {
    const char *name = "pipe";
    mkfifo(name, 0);
}