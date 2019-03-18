#define _GNU_SOURCE
#include <sched.h>      // unshaer
#include <unistd.h>     // fork
#include <sys/wait.h>   // wait
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int pid = atoi(argv[1]);

    // connect to proc namespace
    char pathbuf[100];

    snprintf(pathbuf, 100, "/proc/%d/ns/net", pid);
    setns(open(pathbuf, O_RDONLY), 0);

    snprintf(pathbuf, 100, "/proc/%d/ns/ipc", pid);
    setns(open(pathbuf, O_RDONLY), 0);

    snprintf(pathbuf, 100, "/proc/%d/ns/uts", pid);
    setns(open(pathbuf, O_RDONLY), 0);

    snprintf(pathbuf, 100, "/proc/%d/ns/pid", pid);
    setns(open(pathbuf, O_RDONLY), 0);

    snprintf(pathbuf, 100, "/proc/%d/ns/mnt", pid);
    setns(open(pathbuf, O_RDONLY), 0);

    // fork process
    if (fork()) {
      wait(NULL);
      exit(EXIT_SUCCESS);
    }

    // exec program
    execl(argv[2], argv[2], NULL);
}
