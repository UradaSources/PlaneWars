#include "game.h"

const int DefaultWindowWidth = 800;
const int DefaultWindowHeight = 600;

Game& Game::GetInstance()
{
	static Game _instance;
	return _instance;
}

Game::Game():
	m_windowOrigPtr(nullptr),
	m_rendererOrigPtr(nullptr)
{
	int flag = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
	int errorCode = SDL_CreateWindowAndRenderer(
		DefaultWindowWidth, DefaultWindowHeight,
		flag,
		&this->m_windowOrigPtr, &this->m_rendererOrigPtr
	);

	if (errorCode) throw std::runtime_error(SDL_GetError());
}

Game::~Game()
{
	SDL_DestroyRenderer(this->m_rendererOrigPtr);
	SDL_DestroyWindow(this->m_windowOrigPtr);
}

void Game::setDisplayParam(const std::string& title, Vector2i size)
{
	SDL_DisplayMode dm;
	if (SDL_GetDesktopDisplayMode(0, &dm)) throw std::runtime_error(SDL_GetError());

	Vector2i position((dm.w - size.x) / 2, (dm.h - size.y) / 2);

	this->setDisplayParam(title, size, position);
}
void Game::setDisplayParam(const std::string& title, Vector2i size, Vector2i position)
{
	SDL_SetWindowTitle(m_windowOrigPtr, title.c_str());
	SDL_SetWindowSize(m_windowOrigPtr, size.x, size.y);

	SDL_SetWindowPosition(m_windowOrigPtr, position.x, position.y);
}

SDL_Renderer* Game::getRendererOrigPtr()
{
	return m_rendererOrigPtr;
}
SDL_Window* Game::getWindowOrigPtr()
{
	return m_windowOrigPtr;
}
