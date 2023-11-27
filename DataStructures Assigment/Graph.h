#pragma once
#include <list>
#include <vector>

#include "Node.h"
class Graph {
	std::vector<Node*> nodes;

	void pritnDepthFirst(Node* startNode);
};