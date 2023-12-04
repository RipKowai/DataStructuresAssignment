#pragma once
#include "Monster.h"
#pragma region InsertionSort
void InsertionSort(Monster* monsters, int length) {
	for (int i = 0; i < length; i++) {
		int key = monsters[i].dextirity;
		int j = i - 1;
		while (j >= 0 && monsters[j].dextirity > key) {
			monsters[j + 1].dextirity = monsters[j].dextirity;
			j = j - 1;
		}
		monsters[j + 1].dextirity = key;
	}
}

#pragma endregion

#pragma region SelectionSort
void SelectionSort(Monster* monsters, int length) {
    for (int i = 0; i < (length - 1); i++) {
        int minPos = i;
        for (int j = i + 1; j < length; j++) {
            if (monsters[j].attack < monsters[minPos].attack) {
                minPos = j;
            }
        }
        if (minPos != i) {
            std::swap(monsters[i], monsters[minPos]);
        }
    }
}
#pragma endregion

#pragma region BubbleSort
void BubbleSort(Monster* monsters, int length) {
	bool swapped;
	int i = 0;
	do {
		swapped = false;
		for (int j = 0; j < (length - 1); j++) {
			if (monsters[j].health > monsters[j + 1].health) {
				int temp = monsters[j].health;
				monsters[j].health = monsters[j + 1].health;
				monsters[j + 1].health = temp;
				swapped = true;
			}
		}
	} while (swapped);
}
#pragma endregion

#pragma region MergeSort
void MergeSort(Monster* monsters, int length){
	if (length <= 1) return;

	int middle = length / 2;
	void Divide();
	void Conquer();
	void Merge();
}
#pragma endregion

#pragma region QuickSort
void QuickSort(Monster* monsters, int length);

void QuickSortReccursion(Monster* monsters, int low, int high);

int partition(Monster* monsters, int low, int high);

void QuickSort(Monster* monsters, int length) {
	srand(time(NULL));
	QuickSortReccursion(monsters, 0, length - 1);
}

void QuickSortReccursion(Monster* monsters, int low, int high) {
	int pivot = partition(monsters, low, high);

	QuickSortReccursion(monsters, low, pivot - 1);
	QuickSortReccursion(monsters, pivot + 1, high);
}

int partition(Monster* monsters, int low, int high) {
	int pivot = low + (std::rand() % (high - low + 1));
	int pivotValue = monsters[high].vision;
	int i = low;

	if (pivot != high) {
		std::swap(monsters[pivot].vision, monsters[high].vision);
	}

	for (int j = low; j < high; j++) {
		if (monsters[j].vision <= pivotValue) {
			std::swap(monsters[i].vision, monsters[j].vision);
			i++;
		}
	}

	std::swap(monsters[i].vision, monsters[high].vision);
	return i;
}

#pragma endregion
