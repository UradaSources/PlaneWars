#include <SDL.h>
#include <SDL_image.h>

#include <cstdio>

#include <memory>

#include "sdlWrap.h"
#include "game.h"

int main(int argc, char** argv)
{
	// initialize SDL video
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("Unable to init SDL: %s\n", SDL_GetError());
		return 1;
	}

	Game& game = Game::GetInstance();
	game.setDisplayParam("main", Vector2i(800, 600));

	using SDLTexture = SDLWrap<SDL_Texture>;

	SDL_Texture* texture = IMG_LoadTexture(game.getRendererOrigPtr(), "test.jpg");
	// SDLTexture t(texture, SDL_DestroyTexture);
	std::shared_ptr<SDLTexture> m = std::make_shared<SDLTexture>(texture, SDL_DestroyTexture);

	SDL_Texture* s = m->get();
	std::printf("%d", s->w);

	SDL_Delay(5000);

	return 0;
}