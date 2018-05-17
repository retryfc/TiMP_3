#include "stdafx.h"
#include "sort.h"
#include <ctime>
#include <utility>

SelectionSort::SelectionSort() {
	ST = SS;
}

void SelectionSort::Sorting(int* Arrptr, int ArrLenght, int &NumComparsions, int & NumSwaps, int & Time) {

    Time = clock();
    for (int i =0; i < ArrLenght-1; i++){
        int el = i;

        for (int j = i + 1; j < ArrLenght ; j++) {
            NumComparsions++;
            if (Arrptr[j]<Arrptr[el]) {
                el = j;
            }

        }
        NumComparsions++;
        if (el !=i) {
            std::swap (Arrptr[i],Arrptr[el]);
            NumSwaps++;
        }
    }
    Time = clock() - Time;
}

