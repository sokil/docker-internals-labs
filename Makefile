default: build

build:
	if [ ! -d ./bin ]; then mkdir ./bin; fi
	gcc run.c -o ./bin/run
	gcc exec.c -o ./bin/exec
