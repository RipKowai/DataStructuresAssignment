#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <utility>
#include <ctime>
#include <cstdlib>

#include "Monster.h"
#include "SortingAlgorithms.h"

typedef std:: chrono::microseconds MSEC;
typedef std:: chrono::high_resolution_clock HRC;

float randomFloat(float min, float max)
{
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (max - min));
}

/*int main()
{
    std::fstream file("AssignmentNodes.txt");
    std::string line;
    std::srand(time(0));

#pragma region Monsters

    const int lenght = 5000;
    const int sortTimes = 1000;
    //Monster monsters[lenght]{};
    Monster* monsters = new Monster[lenght];

    auto start = HRC::now();
    for (int i = 0; i < sortTimes; i++) {
        for (int i = 0; i < lenght; i++) {
            monsters[i].attack = rand () % 500;
            monsters[i].health = rand () % 1000;
            monsters[i].dextirity = rand () % 100;
            monsters[i].vision = rand () % 10000;
        }
    
        //BubbleSort(monsters, lenght);//318msec for 10k monsters //300msec after optimization //19677msec for 100k monsters
        //SelectionSort(monsters, lenght);//180msec for 10k monsters //3507msec for 100k monsters
        //InsertionSort(monsters, lenght);//74msec for 10k monsters //2205msec for 100k monsters
        QuickSort(monsters, lenght);//34msec for 100k
    }
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
    for (int i = 0; i < lenght; i++) {
        std::cout << "Monster:" << std::endl;
        std::cout << "Hp:" << monsters[i].health << std::endl;
        std::cout << "Dps:" << monsters[i].attack << std::endl;
        std::cout << "Dex:" << monsters[i].dextirity << std::endl;
        std::cout << "Vision:" << monsters[i].vision << std::endl;
        std::cout << std::endl;
    }
    
    std::cout << "SortedList exec time =" << exec_time.count()/sortTimes <<"misec" << std::endl;
#pragma endregion
    return 0;
}*/

