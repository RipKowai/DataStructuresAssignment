#include <string>
#include <iostream>
#include <fstream>
#include <chrono>

#include "Monster.h"
#include "SortingAlgorithms.h"

typedef std:: chrono::milliseconds MSEC;
typedef std:: chrono::high_resolution_clock HRC;

float randomFloat(float min, float max)
{
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (max - min));
}

int main()
{
    auto start = HRC::now();

    std::fstream file("AssignmentNodes.txt");
    std::string line;
    std::srand(time(0));

#pragma region Monsters

    const int lenght = 10000;
    Monster monsters[lenght]{};

    for (int i = 0; i < lenght; i++) {
        monsters[i].attack = rand () % 500;
        monsters[i].health = rand () % 1000;
        monsters[i].dextirity = rand () % 100;
    }
    
    BubbleSort(monsters, lenght);//318msec for 10k monsters //300msec after optimization 
    //SelectionSort(monsters, lenght);//180msec for 10k monsters
    //InsertionSort(monsters, lenght);//74msec for 10k monsters
    auto end = HRC::now();
    auto exec_time = std::chrono::duration_cast<MSEC>(end - start);
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
        std::cout <<"Monster:" << std::endl;
        std::cout <<"Hp:" << m.health << std::endl;
        std::cout <<"Dps:" << m.attack << std::endl;
        std::cout <<"Dex:" << m.dextirity << std::endl;
    }
    std::cout << "SortedList exec time =" << exec_time.count() <<"msec" << std::endl;
#pragma endregion
    return 0;
}
