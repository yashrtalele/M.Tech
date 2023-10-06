#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int main() {
    const char *buf = "pipe";
    mknod(buf, S_IFIFO | 0, 0);
}