#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm> 
#include <__msvc_chrono.hpp>
using namespace std;


struct Node {
    bool isWall = false;
    Node* parent = nullptr;
    std::vector<Node*> cn;
    int i = -1;
    int j = -1;
};


typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

class Grid {
public:
    static const int SIZE = 20;
    Node* maze[SIZE][SIZE];
    Node* start = nullptr;
    Node* target = nullptr;
    std::vector<Node*> path;
    string mazeFile =
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
        stringstream ss(mazeFile, ios::in);

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                char buffer;
                Node* n = new Node();
                ss >> buffer;
                if (buffer == 'X') {
                    n->isWall = true;
                }
                else if (buffer == 'S') {
                    start = n;
                }
                else if (buffer == 'G') {
                    target = n;
                }
                n->i = i;
                n->j = j;

                maze[i][j] = n;
            }
        }

        //Connect the nodes
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if ((i - 1) >= 0) {
                    maze[i][j]->cn.push_back(maze[i - 1][j]);
                }
                if ((i + 1) <= SIZE - 1) {
                    maze[i][j]->cn.push_back(maze[i + 1][j]);
                }
                if ((j - 1) >= 0) {
                    maze[i][j]->cn.push_back(maze[i][j - 1]);
                }
                if ((j + 1) <= SIZE - 1) {
                    maze[i][j]->cn.push_back(maze[i][j + 1]);
                }
            }
        }
    }

    void displayMaze() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (maze[i][j]->isWall) {
                    cout << "X";
                }
                else if (maze[i][j] == start)
                {
                    cout << "S";
                }
                else if (maze[i][j] == target)
                {
                    cout << "G";
                }
                else {
                    cout << "o";
                }
            }
            cout << endl;
        }
    }

    void breadthFirst() {
        reset();
        auto startTimer = std::chrono::high_resolution_clock::now();
        std::queue<Node*> q;
        q.push(start);
        start->parent = nullptr;

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current == target) {
                reconstructPath(current);
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - startTimer);
                std::cout << duration.count() << " microseconds" << std::endl;
                return;
            }

            for (Node* neighbor : current->cn) {
                if (!neighbor->isWall && neighbor->parent == nullptr && neighbor != start) {
                    neighbor->parent = current;
                    q.push(neighbor);
                }
            }
        }


        cout << "BFS: No path found" << endl;
    }

    void depthFirst() {
        reset();
        auto startTimer = std::chrono::high_resolution_clock::now();
        std::stack<Node*> s;
        s.push(start);
        start->parent = nullptr;

        while (!s.empty()) {
            Node* current = s.top();
            s.pop();
            //cout << "Visiting node at (" << current->i << "," << current->j << ")" << endl;

            if (current == target) {
                reconstructPath(current);
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - startTimer);
                std::cout << duration.count() << " microseconds" << std::endl;
                return;
            }

            for (Node* neighbor : current->cn) {
                if (!neighbor->isWall && neighbor->parent == nullptr && neighbor != start) {
                    neighbor->parent = current;
                    s.push(neighbor);
                }
            }
        }

        cout << "DFS: No path found" << endl;
    }

private:

    void reset() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                maze[i][j]->parent = nullptr;
            }
        }
    }

    void reconstructPath(Node* current) {
        path.clear();
        while (current != nullptr) {
            path.push_back(current);
            current = current->parent;
        }

        // Display the path
        cout << "\nPath Found: " << endl;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (maze[i][j] == start) {
                    cout << "S";
                }
                else if (maze[i][j] == target) {
                    cout << "G";
                }
                else if (maze[i][j]->isWall) {
                    cout << "X";
                }
                else if (contains(path, maze[i][j])) {
                    cout << "*";
                }
                else {
                    cout << "o";
                }
            }
            cout << endl;
        }
    }

    bool contains(const std::vector<Node*>& path, Node* node) {
        return std::find(path.begin(), path.end(), node) != path.end();
    }
};


int main()
{
    Grid g;

    g.displayMaze();

    g.breadthFirst();
    g.depthFirst();

}