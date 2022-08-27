#pragma once

struct Vector2 {
	int x;
	int y;
	bool operator==(const Vector2& v2) {
		if (x == v2.x && y == v2.y) {
			return true;
		}
		return false;
	}
	friend bool operator==(const Vector2& v1, const Vector2& v2);
};

inline bool operator==(const Vector2& v1, const Vector2& v2) {
	if (v1.x == v2.x && v1.y == v2.y) {
		return true;
	}
	return false;
}