#include <cstdio>
#include <memory>

#include <SDL.h>
#include <SDL_image.h>

#include <stdexcept>

#include "sprite.h"

int main(int argc, char** argv)
{
	try
	{
		// 获取即初始化
		Game& game = Game::GetInstace();

		Texture texture = Texture::LoadFormFile("box.png");
		texture.setFilter(SDL_ScaleMode::SDL_ScaleModeNearest);

		Sprite sprite(texture);

		//SDL_Rect src;
		//src.x = 0;
		//src.y = 0;

		//src.w = 36;
		//src.h = 36;

		//SDL_Rect dest;
		//dest.x = 100;
		//dest.y = 100;

		//dest.w = 200;
		//dest.h = 200;

		bool quit = false;
		SDL_Event e;

		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (e.type == SDL_KEYDOWN)
				{

				}
			}

			game.renderClear();

			sprite.draw();

			game.renderPresent();

			//SDL_RenderCopy(game._rendererPtr(), texture._texturePtr(), &src, &dest);

			//SDL_SetRenderDrawColor(game._rendererPtr(), 1, 1, 1, 1);
			//SDL_RenderPresent(game._rendererPtr());
		}

		return 0;
	}
	catch (std::exception& exp)
	{
		std::printf("%s", exp.what());
		return -1;
	}
}