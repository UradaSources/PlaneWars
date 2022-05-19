//#ifndef HEAD_SDL_SIMPLE_WRAP
//#define HEAD_SDL_SIMPLE_WRAP
#include <SDL.h>
#include <SDL_image.h>

#include <string>
#include <stdexcept>

#include "vector2.h"
#include "nonCopyable.h"

class Game : public NonCopyable
{
public:
	static Game& GetInstance();

private:
	SDL_Window* m_windowOrigPtr;
	SDL_Renderer* m_rendererOrigPtr;
	
	Game();
	~Game();

public:
	void setDisplayParam(const std::string& title, Vector2i size);
	void setDisplayParam(const std::string& title, Vector2i size, Vector2i position);

	SDL_Renderer* getRendererOrigPtr();
	SDL_Window* getWindowOrigPtr();
};
