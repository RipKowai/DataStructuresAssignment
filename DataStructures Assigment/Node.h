#pragma once
#include "Vec2.h"

#include <vector>

class Node {
	Vec2 position;
	std::vector<Node>neighbors;
	int id;

	Node(Vec2 position, int id) {
		this->position = position;
		this->id = id;
	}
};