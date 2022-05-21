#include "game.h"

Game& Game::GetInstace()
{
	static Game instance;
	return instance;
}

Game::Game()
{
	// 初始化
	int initFlag = SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS;
	if (SDL_Init(initFlag)) throw std::runtime_error(SDLErrorInfo());
	
	// 初始化sdl_image
	int imgInitFlag = IMG_INIT_PNG | IMG_INIT_JPG;
	int rtCode = IMG_Init(imgInitFlag);
	if ((rtCode & imgInitFlag) != imgInitFlag)
		throw std::runtime_error(IMGErrorInfo());

	// 获取屏幕信息
	SDL_DisplayMode displayMode;
	if (SDL_GetCurrentDisplayMode(0, &displayMode)) throw std::runtime_error(SDLErrorInfo());

	// 计算窗口位置
	int x, y;
	x = (displayMode.w - DefaultWidth) / 2;
	y = (displayMode.h - DefaultHeight) / 2;

	// 创建窗口和渲染器
	int windowInitFlag = SDL_WINDOW_MOUSE_FOCUS;
	m_window = SDL_CreateWindow(DefaultTitle, x, y, DefaultWidth, DefaultHeight, windowInitFlag);
	if (m_window == nullptr) throw std::runtime_error(SDL_GetError());

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (m_renderer == nullptr) throw std::runtime_error(SDL_GetError());
}

Game::~Game()
{
	// 释放sdl对象
	SDL_DestroyRenderer(this->m_renderer);
	SDL_DestroyWindow(this->m_window);
	
	// 关闭所有子系统
	IMG_Quit();
	SDL_Quit();
}

void Game::setTitle(const char* title)
{
	SDL_SetWindowTitle(this->m_window, title);
}
void Game::setSize(int w, int h)
{
	SDL_SetWindowSize(this->m_window, w, h);
}

void Game::setRenderDrawColor(int r, int g, int b, int a = 255)
{
	SDL_SetRenderDrawColor(this->m_renderer, r, g, b, a);
}

void Game::renderClear()
{
	// 将清屏颜色设置为黑色
	SDL_SetRenderDrawColor(this->m_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(this->m_renderer);	
}
void Game::renderPresent()
{
	// 更新屏幕缓冲
	SDL_RenderPresent(this->m_renderer);
}

void Game::_render(SDL_Texture* texture, const SDL_Rect* src, const SDL_Rect* dest)
{
	if (SDL_RenderCopy(this->m_renderer, texture, src, dest))
		throw std::runtime_error(SDLErrorInfo());
}
