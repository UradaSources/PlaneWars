#include "game.h"
#include "sprite.h"

Sprite::Sprite(Texture& texture, vector2i position, vector2i size) :
	m_texture(texture),
	m_position(position),
	m_size(size),
	m_dest{ m_position.x, m_position.y, m_size.x, m_size.y } {}

Sprite::Sprite(Texture& texture) :
	Sprite(texture, vector2i::Zero(), texture.getSize()) {}

void Sprite::draw()
{
	SDL_Renderer* renderer = Game::GetInstace()._rendererPtr();
	SDL_Texture* texture = this->m_texture._texturePtr();

	SDL_Rect* src = this->m_texture._rectPtr();

	SDL_RenderCopy(renderer, texture, src, &this->m_dest);
}