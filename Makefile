compile: build run

build:
	gcc ./src/main.c ./src/player.c -o out/sdl_game.exe -Llib -lSDL3 -lSDL3_image

run:
	./out/sdl_game.exe