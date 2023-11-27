#pragma once
#include <iostream>

class Vec2 {
public:
	float x, y;

public:
	Vec2(float x, float y) {
		this->x = x;
		this->y = y;
	}

	Vec2() {
		this->x = 0;
		this->y = 0;
	}

	void Print() {
		std::cout << "(" << x << "," << ")" << std::endl;
	}
};