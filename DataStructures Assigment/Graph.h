#pragma once
#include <list>
#include <vector>

#include "Node.h"
class Grid
{
public:
    static const int gridSize = 20;
    Node* graph[gridSize][gridSize];
    Node* start = nullptr;
    Node* goal = nullptr;
    std::vector<Node*> path;
    std::string graphNodes =
        "oooooooXooooooXooooo\n"
        "ooooSoooooooooXooooo\n"
        "oooooooXoooooooooooo\n"
        "XXXXXXXXooooooXooooo\n"
        "oooooooXXXXXXXXooooo\n"
        "oooooooXooooooXXXoXX\n"
        "ooooooooooooooXooooo\n"
        "oooooooXooooooXooooo\n"
        "oooooooXoooooooooooo\n"
        "oooooooXXXXXXXXooooo\n"
        "oooooooXooooooXooooo\n"
        "ooooooooooooooXooooo\n"
        "oooooooXoooooooooooo\n"
        "XXoXXXXXooooooXooooo\n"
        "oooooooXXXXXXXXooooo\n"
        "oooooooXooooooXXXXXX\n"
        "ooooooooooooooXooooo\n"
        "oooooooXooooooXooGoo\n"
        "oooooooXoooooooooooo\n"
        "oooooooXooooooXooooo";

    Grid() {
        // Create a stringstream to read the graphFile
        std::stringstream ss(graphNodes, std::ios::in);

        // Loop through each vertex of the graph
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                // Temporary storage for read character from the stringstream
                char tempSt;

                // Read a character from the stringstream into the buffer
                ss >> tempSt;

                // Create a new Node for the current position in the graph
                Node* vertex = new Node();

                if (tempSt == 'X') {
                    vertex->isWall = true;
                }

                else if (tempSt == 'S') {
                    start = vertex;
                }

                else if (tempSt == 'G') {
                    goal = vertex;
                }

                // Set the coordinates of the node
                vertex->i = i;
                vertex->j = j;

                // Add the newly created node to the graph at the current position
                graph[i][j] = vertex;
            }
        }

        //Here we make the nodes have neighbors
        for (int i = 0;i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if ((i - 1) >= 0) {
                    graph[i][j]->nb.push_back(graph[i - 1][j]);
                }

                if ((i + 1) <= gridSize - 1) {
                    graph[i][j]->nb.push_back(graph[i + 1][j]);
                }

                if ((j - 1) <= 0) {
                    graph[i][j]->nb.push_back(graph[i][j - 1]);

                }

                if ((j + 1) <= gridSize - 1) {
                    graph[i][j]->nb.push_back(graph[i][j + 1]);

                }
            }
        }

    }

    void ShowGraph() {
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (graph[i][j]->isWall) {
                    std::cout << "X";
                }
                else if (graph[i][j] == start)
                {
                    std::cout << "S";
                }
                else if (graph[i][j] == goal)
                {
                    std::cout << "G";
                }
                else {
                    std::cout << "o";
                }
            }
            std::cout << std::endl;
        }
    }

private:
    void newPath(Node* current) {
        path.clear();
        while (current != nullptr) {
            path.push_back(current);
            current = current->parent;
        }

        // Display the path
        std::cout << "\nPath Found: " << std::endl;
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (graph[i][j] == start) {
                    std::cout << "S";
                }
                else if (graph[i][j] == goal) {
                    std::cout << "G";
                }
                else if (graph[i][j]->isWall) {
                    std::cout << "X";
                }
                else if (Container(path, graph[i][j])) {
                    std::cout << "*";
                }
                else {
                    std::cout << "o";
                }
            }
            std::cout << std::endl;
        }
    }
    bool Container(const std::vector<Node*>& path, Node* node) {
        return std::find(path.begin(), path.end(), node) != path.end();
    }
};