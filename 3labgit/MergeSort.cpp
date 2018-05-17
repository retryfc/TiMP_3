#include "stdafx.h"
#include "sort.h"
#include <ctime>
#include <utility>

MergeSort::MergeSort() {
	ST = MS;
}

void MergeSort :: Sorting(int* Arrptr, int ArrLenght, int &NumComparsions, int &NumSwaps, int &Time) {
    Time = clock();

	merge_sort(Arrptr, 0, ArrLenght - 1, NumComparsions, NumSwaps);

    Time = clock() - Time;
}

void  MergeSort:: merge(int * AP, int p, int q, int r, int &NumComparsions, int &NumSwaps) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int * L; int * R;
	L = new int[n1 + 1];
	R = new int[n2 + 1];
	for (int i = 1; i <= n1; i++) {
		L[i - 1] = AP[p + i - 1];
	}
	for (int j = 1; j <= n2; j++) {
		R[j - 1] = AP[q + j];
	}
	for (int i = 0, j = 0, k = p; k <= r; k++) {
		NumComparsions++;
		if (i<n1 && j<n2) {
			NumComparsions++;
			NumSwaps++;
			if (L[i] <= R[j]) {
				AP[k] = L[i];
				i++;
			}
			else {
				AP[k] = R[j];
				j++;
			}
		}
		else {
			NumComparsions++;
			NumSwaps++;
			if (i < n1) {
				AP[k] = L[i];
				i++;
			}
			else {
				AP[k] = R[j];
				j++;
			}
		}
	}
	delete[] L; delete[] R;
}
void  MergeSort::merge_sort(int * AP, int p, int r, int &NumComparsions, int &NumSwaps) {
	int q;
	NumComparsions++;
	if (p < r) {
		q = (p + r) / 2;
		merge_sort(AP, p, q, NumComparsions, NumSwaps);
		merge_sort(AP, q + 1, r, NumComparsions, NumSwaps);
		merge(AP, p, q, r, NumComparsions, NumSwaps);
	}
}