#ifndef HEAD_WINDOW
#define HEAD_WINDOW

#include <SDL.h>
#include <SDL_image.h>

#include <list>
#include <stdexcept>

#include "functions.h"
#include "vector2.h"
#include "nonCopyable.h"

class Game: NonCopyable
{
public:
	const char* DefaultTitle = "Plane Wars";
	const int DefaultHeight = 600;
	const int DefaultWidth = 800;

	static Game& GetInstace();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	Game();
	~Game();

public:
	void setTitle(const char* title);
	void setSize(int w, int h);

	void setRenderDrawColor(int r, int g, int b, int a = 255);

	void renderClear();
	void renderPresent();

	void _render(SDL_Texture* texture, const SDL_Rect* src, const SDL_Rect* dest);

	inline SDL_Window* _windowPtr() { return this->m_window; }
	inline SDL_Renderer* _rendererPtr() { return this->m_renderer; }
};

#endif
