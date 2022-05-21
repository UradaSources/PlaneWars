#include "game.h"

Game& Game::GetInstace()
{
	static Game instance;
	return instance;
}

Game::Game()
{
	// ��ʼ��
	int initFlag = SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS;
	if (SDL_Init(initFlag)) throw std::runtime_error(SDLErrorInfo());
	
	// ��ʼ��sdl_image
	int imgInitFlag = IMG_INIT_PNG | IMG_INIT_JPG;
	int rtCode = IMG_Init(imgInitFlag);
	if ((rtCode & imgInitFlag) != imgInitFlag)
		throw std::runtime_error(IMGErrorInfo());

	// ��ȡ��Ļ��Ϣ
	SDL_DisplayMode displayMode;
	if (SDL_GetCurrentDisplayMode(0, &displayMode)) throw std::runtime_error(SDLErrorInfo());

	// ���㴰��λ��
	int x, y;
	x = (displayMode.w - DefaultWidth) / 2;
	y = (displayMode.h - DefaultHeight) / 2;

	// �������ں���Ⱦ��
	int windowInitFlag = SDL_WINDOW_MOUSE_FOCUS;
	m_window = SDL_CreateWindow(DefaultTitle, x, y, DefaultWidth, DefaultHeight, windowInitFlag);
	if (m_window == nullptr) throw std::runtime_error(SDL_GetError());

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (m_renderer == nullptr) throw std::runtime_error(SDL_GetError());
}

Game::~Game()
{
	// �ͷ�sdl����
	SDL_DestroyRenderer(this->m_renderer);
	SDL_DestroyWindow(this->m_window);
	
	// �ر�������ϵͳ
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
	// ��������ɫ����Ϊ��ɫ
	SDL_SetRenderDrawColor(this->m_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(this->m_renderer);	
}
void Game::renderPresent()
{
	// ������Ļ����
	SDL_RenderPresent(this->m_renderer);
}

void Game::_render(SDL_Texture* texture, const SDL_Rect* src, const SDL_Rect* dest)
{
	if (SDL_RenderCopy(this->m_renderer, texture, src, dest))
		throw std::runtime_error(SDLErrorInfo());
}
