#include "stdafx.h"
#include "sort.h"
#include <ctime>
#include <utility>

QwickSort3Way::QwickSort3Way() {
	ST = QS3W;
}

void QwickSort3Way::Sorting(int* Arrptr, int ArrLenght, int &NumComparsions, int & NumSwaps, int & Time) {
    
   Time = clock();
   bool notsorted = true;
   while (notsorted) {
       notsorted = false;
       for (int i = 1; i < ArrLenght-1;i+=2) {
            NumComparsions++;
            if (Arrptr[i] > Arrptr[i+1]) {
                std::swap(Arrptr[i+1],Arrptr[i]);
                notsorted = true;
                NumSwaps++;
            }
       }
       for (int i = 0; i < ArrLenght-1;i+=2) {
            NumComparsions++;
            if (Arrptr[i] > Arrptr[i+1]) {
				std::swap(Arrptr[i + 1], Arrptr[i]);
                notsorted = true;
                NumSwaps++;
            }
       }
   }
    Time = clock() - Time;
}
