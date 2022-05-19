#ifndef HEAD_NON_COPYABLE
#define HEAD_NON_COPYABLE

class NonCopyable
{
private:
	NonCopyable(const NonCopyable&) {};
	NonCopyable& operator=(const NonCopyable&) {};

public:
	NonCopyable() = default;
	~NonCopyable() = default;
};

#endif
