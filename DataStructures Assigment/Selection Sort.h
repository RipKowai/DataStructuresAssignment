#pragma once
#include <iostream>
#include "Monster.h"

void selection_sort(int a[], int length) {
    for (int i = 0; i < (length - 1); i++) {
        int minPos = i;
        for (int j = i + 1; j < length; j++) {
            if (a[j] < a[minPos]) {
                minPos = j;
            }
        }
        if (minPos != i) {
            int temp = a[i];
            a[i] = a[minPos];
            a[minPos] = temp;
        }
    }
}