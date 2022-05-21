#ifndef HEAD_TEXTURE
#define HEAD_TEXTURE

#include <SDL.h>
#include <SDL_image.h>

#include <memory>

#include "game.h"

class Texture
{
private: // 静态函数和数据结构定义
	// sdl对象包装器
	struct wrapper
	{
		SDL_Texture* ptr;

		wrapper(SDL_Texture* ptr) : ptr(ptr) {}
		~wrapper() { SDL_DestroyTexture(this->ptr); }
	};

public:
	// sdl对象的共享指针包装器
	using SDLTexture = std::shared_ptr<wrapper>;

	// 从文件加载纹理
	static Texture LoadFormFile(const char* filePath);

private:
	SDLTexture m_sharedPrt;

	vector2i m_size;
	vector2i m_offset;

	SDL_Rect m_src;

	Texture(SDLTexture sharedPtr, vector2i size, vector2i offset);

public:
	Texture(const Texture&) = default;
	Texture& operator=(const Texture&) = default;

	~Texture() = default;

	void setFilter(SDL_ScaleMode mode);

	vector2i getSize()const { return m_size; }
	vector2i getOffset()const { return m_offset; }

	inline SDL_Rect* _rectPtr() { return &m_src; }
	inline SDL_Texture* _texturePtr() { return m_sharedPrt->ptr; }
};

#endif
