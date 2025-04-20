#include "player.h"

static SDL_Texture *player_texture;

static SDL_FRect spirit_portion = {17, 16, 15, 17};

typedef struct
{
    float x, y;

} Position;

Position position = {0, 0};

static void quit()
{
}

static void handle_event()
{
}

static void update()
{
    const _Bool *keyboard_state = SDL_GetKeyboardState(NULL);

    if (keyboard_state[SDL_SCANCODE_W])
    {
        position.y -= 1;
    }
    if (keyboard_state[SDL_SCANCODE_S])
    {
        position.y += 1;
    }
    if (keyboard_state[SDL_SCANCODE_A])
    {
        position.x -= 1;
    }
    if (keyboard_state[SDL_SCANCODE_D])
    {
        position.x += 1;
    }
}

static void render(SDL_Renderer *renderer)
{
    SDL_FRect player_postion = {position.x, position.y, 15, 17};

    // Draw Character
    SDL_SetTextureScaleMode(player_texture, SDL_SCALEMODE_NEAREST);
    SDL_RenderTexture(renderer, player_texture, &spirit_portion, &player_postion);
}

Entity init_player(SDL_Renderer *renderer)
{
    const char path[] = "./assets/Char_Sprites/char_spritesheet.png";
    player_texture = IMG_LoadTexture(renderer, path);

    Entity player = {.quit = quit, .handle_event = handle_event, .update = update, .render = render};
    return player;
}