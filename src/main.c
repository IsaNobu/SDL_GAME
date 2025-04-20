#define SDL_MAIN_USE_CALLBACKS
#include "entity.h"
#include "player.h"

#define RENDER_ENITITES(enitites, enitity_count, renderer) \
    for (int i = 0; i < enitity_count; i++)                \
    {                                                      \
        entities[i].render(renderer);                      \
    }

#define UPDATE_ENITITES(enitites, enitity_count) \
    for (int i = 0; i < enitity_count; i++)      \
    {                                            \
        entities[i].update();                    \
    }

#define QUIT_ENITITES(enitites, enitity_count) \
    for (int i = 0; i < enitity_count; i++)    \
    {                                          \
        entities[i].quit();                    \
    }

#define HANDLE_EVENTS_ENTITES(enitites, enitity_count, event) \
    for (int i = 0; i < enitity_count; i++)                   \
    {                                                         \
        entities[i].handle_event(event);                      \
    }

SDL_Window *window;
SDL_Renderer *renderer;

Enitity entities[MAX_ENTITIES];
int entity_count = 0;

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    QUIT_ENITITES(entities, entity_count);
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

void update()
{
    UPDATE_ENITITES(entities, entity_count)
}

void render()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    RENDER_ENITITES(entities, entity_count, renderer);

    SDL_RenderPresent(renderer);
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    update();
    render();
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv)
{
    if (!SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Error initializing SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    window = SDL_CreateWindow("SDL3 Game", 800, 600, SDL_WINDOW_RESIZABLE);

    if (!window)
    {
        SDL_Log("Error creating window: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, NULL);

    if (!renderer)
    {
        SDL_Log("Error creating renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // init player and putting it inside the entities array

    entities[entity_count++] = init_player(renderer);

    return SDL_APP_CONTINUE;
}