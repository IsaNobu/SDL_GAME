compile: build run

build:
	gcc src/main.c -o out/sdl_game.exe -lSDL3 -lSDL_image/SDL_image

run:
	./out/sdl_game.exe