# Research of process containerisation

## Unshare example

```
# In one terminal:
$ ./bin/run /bin/bash

# In other terminal
$ ps aux | grep ./bin/run
sokil      42346  0.0  0.0   2640   940 pts/7    S    18:45   0:00 ./bin/run /bin/bash

$ pstree -p 42346
run(42346)───bash(42347)

$ ./bin/exec 42347 /bin/bash
```

## Useful links

* https://linuxcontainers.org/
