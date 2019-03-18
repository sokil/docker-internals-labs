default: build

build:
	gcc unshare.c -o ./bin/unshare
	gcc connect.c -o ./bin/connect
