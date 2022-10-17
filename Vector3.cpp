#include "Vector3.h"
#include <cmath>

Vector3::Vector3() {

}

Vector3::Vector3(float x, float y, float z) :x(x), y(y), z(z) {

}

float Vector3::length() const {
	return sqrtf(x * x + y * y + z * z);
}

Vector3& Vector3::normalize() {
	float len = length();
	if (len != 0)
	{
		return *this /= len;
	}
	return *this;
}

Vector3 Vector3::cross(const Vector3& v) const
{
	Vector3 vec3;
	vec3.x = y * v.z - z * v.y;
	vec3.y = z * v.x - x * v.z;
	vec3.z = x * v.y - y * v.x;

	return vec3;
}

float Vector3::dot(const Vector3& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::operator+()const
{
	return *this;
}

Vector3 Vector3::operator-()const
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator*(const Vector3& v)
{
	x* v.x;
	y* v.y;
	z* v.z;

	return *this;
}

Vector3& Vector3::operator+=(const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}

Vector3& Vector3::operator-=(const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}

Vector3& Vector3::operator*=(const Vector3& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;

	return *this;
}

Vector3& Vector3::operator/=(const Vector3& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;

	return *this;
}

Vector3& Vector3::operator*=(float s)
{
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

Vector3& Vector3::operator/=(float s)
{
	x /= s;
	y /= s;
	z /= s;
	return *this;
}

//Vector3クラスに属さない関数群
// 二項演算子
const Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
	Vector3 temp(v1);
	return temp += v2;
}

const Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
	Vector3 temp(v1);
	return temp -= v2;
}

const Vector3 operator*(const Vector3& v, float s)
{
	Vector3 temp(v);
	return temp *= s;
}

const Vector3 operator*(float s, const Vector3& v)
{
	return v * s;
}

const Vector3 operator/(const Vector3& v, float s)
{
	Vector3 temp(v);
	return temp /= s;
}

float dot(const Vector3& v, const Vector3& v2)
{
	return v.x * v2.x + v.y * v2.y + v.z * v2.z;
}

float Degree2Radian(float degree)
{
	return degree * PI / 180;
}

float Radian2Degree(float radian)
{
	return radian * 180 / PI;
}

int Sign(int value)
{
	if (value > 0)
	{
		return 1;
	}
	else if (value < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

float Sign(float value)
{
	if (value > 0.0f)
	{
		return 1.0f;
	}
	else if (value < 0.0f)
	{
		return -1.0f;
	}
	else
	{
		return 0.0f;
	}
}

float Clamp(float value, float max, float min)
{
	// 値が最大値を上回っていたら最大値を返す
	if (value >= max) return max;

	// 値が最小値を下回っていたら最小値を返す
	if (value <= min) return min;

	// どちらにも当てはまらなかったら値をそのまま返す
	return value;
}