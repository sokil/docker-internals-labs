/**
 * Presentation:
 * https://www.youtube.com/watch?v=hdVNKmru3LM&feature=youtu.be
 *
 * Capabilities:
 * https://wiki.archlinux.org/index.php/capabilities
 *
 * CGroups:
 * https://en.wikipedia.org/wiki/Cgroups
 *
 * Namespaces:
 * https://en.wikipedia.org/wiki/Linux_namespaces
 *
 * Veth (Virtual Ethernet devices):
 * http://man7.org/linux/man-pages/man4/veth.4.html
 *
 * Aufs (advanced multi-layered unification filesystem):
 * https://en.wikipedia.org/wiki/Aufs
 *
 * Overlay filesystem:
 * https://wiki.archlinux.org/index.php/Overlay_filesystem
 *
 * Unshare:
 * http://man7.org/linux/man-pages/man2/unshare.2.html
 *
 * Chroot:
 */

#include <sched.h>

int main(int argc, char *argv[])
{
    unshare(
        CLONE_NEWIPC |  // IPC namespace
        CLONE_NEWNS |   // mount namespace
        CLONE_NEWNET |  // network namespace
        CLONE_NEWPID |  // PID namespace
        CLONE_NEWUTS |  // UTS namespace
        CLONE_NEWUSER // user namespace
    );

    if (fork()) {
        wait(null);
        return 0;
    }
}
