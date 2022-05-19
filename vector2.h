#ifndef HEAD_VECTOR
#define HEAD_VECTOR

#include <cmath>
#include <limits>

template <typename T>
struct Vector2
{
public:
	// 无穷大
	static Vector2 Inf()
	{
		constexpr T inf = std::numeric_limits<T>::infinity();
		return Vector2(inf, inf);
	}
	static Vector2 Zero()
	{
		return Vector2(T(), T());
	}

	// 归一化
	static Vector2 Normalized(const Vector2& v)
	{
		T length = v.length();
		T x = v.x != 0 ? v.x / length : 0;
		T y = v.y != 0 ? v.y / length : 0;
		return Vector2(x, y);
	}

	// 线性插值
	static Vector2 Lerp(const Vector2& from, const Vector2& to, T t)
	{
		return from + (to - from) * t;
	}

public:
	T x, y;

	Vector2(T x = 0, T y = 0) :
		x(x), y(y) {};
	Vector2(const Vector2& copy) :
		x(copy.x), y(copy.y) {};

	T length() const
	{
		return std::sqrt(x * x + y * y);
	}
};

template <typename T>
Vector2<T> operator+(Vector2<T> left, Vector2<T> right)
{
	return Vector2<T>(left.x + right.x, left.y + right.y);
}
template <typename T>
Vector2<T> operator-(Vector2<T> left, Vector2<T> right)
{
	return Vector2<T>(left.x - right.x, left.y - right.y);
}
template <typename T>
Vector2<T> operator*(Vector2<T> left, Vector2<T> right)
{
	return Vector2<T>(left.x * right.x, left.y * right.y);
}
template <typename T>
Vector2<T> operator/(Vector2<T> left, Vector2<T> right)
{
	return Vector2<T>(left.x / right.x, left.y / right.y);
}

template <typename T>
Vector2<T> operator+(Vector2<T> left, T right)
{
	return Vector2<T>(left.x + right, left.y + right);
}
template <typename T>
Vector2<T> operator-(Vector2<T> left, T right)
{
	return Vector2<T>(left.x - right, left.y - right);
}
template <typename T>
Vector2<T> operator*(Vector2<T> left, T right)
{
	return Vector2<T>(left.x * right, left.y * right);
}
template <typename T>
Vector2<T> operator/(Vector2<T> left, T right)
{
	return Vector2<T>(left.x / right, left.y / right);
}

template <typename T>
bool operator==(Vector2<T> left, Vector2<T> right)
{
	return left.x == right.x && left.y == right.y;
}

using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;

#endif // HEAD_VECTOR
