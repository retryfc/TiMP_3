#include "stdafx.h"
#include "SortTester.h"
#include <cstdlib>

SortTester::SortTester(int numArrs, int* arrSizes, std::ostream* output)
{
	NumArrs = numArrs;
	ArrSizes = arrSizes;
	Arrs = new int*[numArrs];
	for (int i = 0; i < NumArrs; i++) {
		Arrs[i] = new int[ArrSizes[i]];
	}

	CurrentSort = nullptr;
	Output = output;
}

SortTester::~SortTester()
{
	for (int i = 0; i < NumArrs; i++) {
		delete[] Arrs[i];
	}
	delete[] Arrs;
	delete CurrentSort;
}

void SortTester::GenerateArr(int num, GenerationType  GT) {
	SortType ST = CurrentSort->ST;
	switch (GT)
	{
	case Random:
		for (int i = 0; i < ArrSizes[num]; i++) {
			Arrs[num][i] = rand();
		}
		break;
	case Best:
		switch (ST)
		{
		case MS:
			for (int i = 0; i < ArrSizes[num]; i++) {
				Arrs[num][i] = ArrSizes[num] - i;
			}
			break;
		case QS3W:
		case SS:
			for (int i = 0; i < ArrSizes[num]; i++) {
				Arrs[num][i] = i;
			}
			break;
		default:
			break;
		}
		break;
	case Worst:
		switch (ST)
		{
		case MS:
			for (int i = 0; i < ArrSizes[num]; i++) {
				Arrs[num][i] = i;
			}
			break;
		case QS3W:
			for (int i = 0; i < ArrSizes[num]; i++) {
				Arrs[num][i] = ArrSizes[num] - i;
			}
			break;
		case SS:
			for (int i = 0; i < ArrSizes[num]; i++) {
				if ((double)rand() / RAND_MAX < 0.8) {
					Arrs[num][i] = 1;
				}
				else
				{
					Arrs[num][i] = 2;
				}
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	
	
}

void SortTester::SetSort(Sort* s) {
	delete CurrentSort;
	CurrentSort = s;
}

void SortTester::TestSort() {
	switch (CurrentSort->ST)
	{
	case MS:
		*Output << "Merge sort:" << std::endl;
		break;
	case QS3W:
		*Output << "Qwick sort 3-way:" << std::endl;
		break;
	case SS:
		*Output << "Selection sort:" << std::endl;
		break;
	default:
		break;
	}
	*Output <<"Random: "<< std::endl;
	TestSortWithGT(Random);
	*Output << std::endl << "Best: " << std::endl;
	TestSortWithGT(Best);
	*Output << std::endl << "Worst: " << std::endl;
	TestSortWithGT(Worst);
	*Output << std::endl;

}

void SortTester::TestSortWithGT(GenerationType GT) {
	*Output << "N " << "Comps " << "Swaps " << "Time" << std::endl;
	int numTests = 100;
	if (GT != Random) {
		numTests = 1;
	}
	for (int i = 0; i < NumArrs; i++) {
		double Comps = 0;
		double Swaps = 0;
		double Time = 0;
		for (int j = 0; j < numTests; j++) {
			GenerateArr(i,GT);
			int CurrComps = 0;
			int CurrSwaps = 0;
			int CurrTime = 0;
			CurrentSort->Sorting(Arrs[i], ArrSizes[i], CurrComps, CurrSwaps, CurrTime);
			Comps += CurrComps;
			Swaps += CurrSwaps;
			Time += CurrTime;
		}
		Comps /= numTests;
		Swaps /= numTests;
		Time /= numTests;
		*Output << ArrSizes[i] << " " << Comps << " " << Swaps << " " << Time << " " << std::endl;
	}
}
