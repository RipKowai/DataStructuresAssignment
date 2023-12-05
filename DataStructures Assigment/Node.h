#pragma once
#include "Vec2.h"

#include <vector>

struct Node {
    bool isWall = false;
    Node* parent = nullptr;
    std::vector<Node*> nb;//stands for neighbor
    int i = -1;
    int j = -1;
};