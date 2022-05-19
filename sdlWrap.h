#ifndef HEAD_SDL_WRAP
#define HEAD_SDL_WRAP

#include "nonCopyable.h"

template<typename T>
class SDLWrap : public NonCopyable
{
public:
	typedef void (*Dest)(T*);

private:
	T* m_ptr;
	Dest m_dest;

public:
	SDLWrap(T* ptr, Dest dest) : m_ptr(ptr), m_dest(dest) {};
	~SDLWrap() { Dest(dest); }

	T* get()
	{
		return m_ptr;
	}
};

#endif // !HEAD_SDL_WRAP
