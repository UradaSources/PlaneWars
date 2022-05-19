#include <SDL.h>

#include <memory>
#include <string>
#include <stdexcept>

#include "game.h"

#include "vector2.h"
#include "sdlWrap.h"
#include "nonCopyable.h"

using SDLTexture = std::shared_ptr<SDL_Texture>;

struct Texture : public NonCopyable
{
public:
	static Texture LoadFromFile(const std::string& filePath);

private:
	Vector2i m_offset;
	Vector2i m_size;

	Texture(const SDLTexture& ptr);
	Texture(const SDLTexture& ptr, Vector2i offset, Vector2i size);

public:
	~Texture() = default;

	void setFilter(SDL_ScaleMode mode);
	SDL_ScaleMode getFilter()const;

	Vector2i getSize()const;
	Vector2i getOrigSize()const;

	SDL_Texture* getOrigPtr();
};
