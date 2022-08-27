#pragma once

struct FVector2 {
	float x;
	float y;

	friend bool operator==(const FVector2& v1, const FVector2& v2);
};

inline bool operator==(const FVector2& v1, const FVector2& v2) {
	if (v1.x == v2.x && v1.y == v2.y) {
		return true;
	}
	return false;
}