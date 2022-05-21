#include <stdexcept>

#include "functions.h"

#include "texture.h"

Texture Texture::LoadFormFile(const char* filePath)
{
	SDL_Renderer* renderer = Game::GetInstace()._rendererPtr();
	SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);

	// 获取纹理的尺寸
	int w, h;
	if (SDL_QueryTexture(texture, nullptr, nullptr, &w, &h))
		throw std::runtime_error(SDLErrorInfo());

	// 创建并返回纹理对象
	auto sharedPtr = std::make_shared<wrapper>(texture);
	return Texture(sharedPtr, vector2i(w, h), vector2i(0, 0));
}

Texture::Texture(SDLTexture sharedPtr, vector2i size, vector2i offset) :
	m_sharedPrt(sharedPtr),
	m_size(size),
	m_offset(offset),
	m_src{ m_offset.x, m_offset.y, m_size.x, m_size.y } {};

void Texture::setFilter(SDL_ScaleMode mode)
{
	if (SDL_SetTextureScaleMode(m_sharedPrt->ptr, mode))
		throw std::runtime_error(ErrorInfo("invaild texture ptr"));
}