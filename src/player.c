#include "player.h"

static SDL_Texture *player_texture;

static SDL_FRect spirit_portion = {17, 16, 15, 17};
static SDL_FRect player_postion = {250, 250, 15, 17};

static void quit()
{
}

static void handle_event()
{
}

static void update()
{
}

static void render(SDL_Renderer *renderer)
{
    // Draw Character
    SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);
    SDL_RenderTexture(renderer, player_texture, &spirit_portion, &player_postion);
}

Enitity init_player(SDL_Renderer *renderer)
{
    const char path[] = "./assets/Char_Sprites/char_spritesheet.png";
    player_texture = IMG_LoadTexture(renderer, path);

    Enitity player = {.quit = quit, .handle_event = handle_event, .update = update, .render = render};
    return player;
}