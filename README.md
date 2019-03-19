# Research of process containerisation

## Unshare example

```
# In one terminal:
$ ./bin/unshare /bin/bash

# In other terminal
$ ps aux | grep unshared
sokil    21143  0.0  0.0   4308   676 pts/5    S    23:34   0:00 ./bin/unshare /bin/bash

$ pstree -p 21143
unshare(21143)───bash(21144)

$ ./bin/connect 21144 /bin/bash
```

# Useful links

* https://linuxcontainers.org/
