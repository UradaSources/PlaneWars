//#include "texture.h"
//
//Texture Texture::LoadFromFile(const std::string& filePath)
//{
//	SDL_Renderer* renderer = Game::GetInstance().getRendererOrigPtr();
//
//	// 创建纹理
//	SDL_Texture* texture = IMG_LoadTexture(renderer, filePath.c_str());
//	if (texture == nullptr) throw std::runtime_error(IMG_GetError());
//
//	// 创建智能指针, 托管sdl指针
//	SDLTexture shader(texture, SDL_DestroyTexture);
//
//	return Texture(shader);
//}
//Texture::Texture(const SDLTexture& ptr) :
//	m_ptr(ptr),
//	m_offset(),
//	m_size()
//{
//	int w = ptr->w;
//}
//
//Texture::Texture(const SDLTexture& ptr, Vector2i offset, Vector2i size);
//
//Texture::Texture(Texture& other, Vector2i offset, Vector2i size);
//
//void Texture::setFilter(SDL_ScaleMode mode);
//SDL_ScaleMode Texture::getFilter()const;
//
//Vector2i Texture::getSize()const;
//Vector2i Texture::getOrigSize()const;
//
//SDL_Texture* Texture::getOrigPtr();
