/**
 * Presentation:
 * https://www.youtube.com/watch?v=hdVNKmru3LM&feature=youtu.be
 *
 * Privileges and access restrictions:
 * Capabilities: https://wiki.archlinux.org/index.php/capabilities
 * Chroot: http://man7.org/linux/man-pages/man2/chroot.2.html
 * 
 * Resource limiting:
 * CGroups: https://en.wikipedia.org/wiki/Cgroups
 *
 * Process isolation:
 * Namespaces: https://en.wikipedia.org/wiki/Linux_namespaces
 * Unshare: http://man7.org/linux/man-pages/man2/unshare.2.html
 * Veth (Virtual Ethernet devices): http://man7.org/linux/man-pages/man4/veth.4.html
 *
 * File systems:
 * Aufs (advanced multi-layered unification filesystem): https://en.wikipedia.org/wiki/Aufs
 * Overlay filesystem: https://wiki.archlinux.org/index.php/Overlay_filesystem
 * Mount: http://man7.org/linux/man-pages/man2/mount.2.html
 * Umount: http://man7.org/linux/man-pages/man2/umount.2.html
 */

#define _GNU_SOURCE
#include <sched.h>      // unshaer
#include <unistd.h>     // fork
#include <sys/wait.h>   // wait
#include <sys/mount.h>  // mount
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int unshared = unshare(
      CLONE_NEWIPC |  // IPC namespace
      CLONE_NEWNS |   // mount namespace
      CLONE_NEWNET |  // network namespace
      CLONE_NEWPID |  // PID namespace
      CLONE_NEWUTS |  // UTS namespace
      CLONE_NEWUSER // user namespace
    );

    if (unshared == -1) {
      exit(EXIT_FAILURE);
    }

    // fork process
    if (fork()) {
      wait(NULL);
      exit(EXIT_SUCCESS);
    }

    // re-mount /proc
    umount("/proc");
    mount(
      "proc",   // source
      "/proc",  //  target
      "proc",   // filesystem type
      0,        // mount flags
      0         // string of comma-separated options understood by filesystem
    );

    // exec program
    execvp(argv[optind], &argv[optind]);
}
