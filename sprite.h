#ifndef HEAD_SPRITE
#define HEAD_SPRITE

#include "nonCopyable.h"
#include "texture.h"

class Sprite : NonCopyable
{
private:
	Texture& m_texture;

	vector2i m_position;
	vector2i m_size;

	SDL_Rect m_dest;

public:
	Sprite(Texture& texture, vector2i position, vector2i size);
	Sprite(Texture& texture);

	~Sprite() = default;

	void draw();

	vector2i getSize()const { return m_size; }
	void setSize(vector2i size) { m_size = size; }

	vector2i getPosition()const { return m_size; }
	void setPosition(vector2i position) { m_position = position; }
};

#endif
