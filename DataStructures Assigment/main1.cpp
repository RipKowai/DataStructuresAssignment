#include <string>
#include <iostream>
#include <fstream>

#include "Monster.h"
#include "Selection Sort.h"

float randomFloat(float min, float max)
{
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (max - min));
}
void selection_sort(int a[], int length);


int main()
{
    std::fstream file("AssignmentNodes.txt");
    std::string line;
    std::srand(time(0));

#pragma region Monsters


    Monster monsters[10]{};

    for (int i = 0; i < 10; i++) {
        monsters[i].attack = rand () % 250;
        monsters[i].health = rand () % 1000;
    }
#pragma endregion

#pragma region SelectionSort
    //void selection_sort(Monster monsters[]);
    int a[] = { 6, 5, 3, 2, 1, 4 };
    int length = 6;
#pragma endregion


#pragma region Graph


    if (file.is_open()) {
        while (getline(file, line))
        {
            std::cout << line << std::endl;
        }
        file.close();
    }

    std::cout << "KISS MY ASS!!!\n";
#pragma endregion

#pragma region WriteOut
  
    for (Monster& m : monsters) {
        std::cout << "Monster:" << std::endl;
        std::cout <<"Dph:" << m.attack << std::endl;
        std::cout <<"Health:" << m.health << std::endl;
    }
    selection_sort(a, length);

    for (int i = 0; i < length; i++) {
        std::cout << "[" << i << "]" << a[i] << std::endl;
    }
#pragma endregion
    return 0;
}
