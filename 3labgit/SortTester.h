#pragma once
#include "Sort.h"
#include <iostream>

enum GenerationType{Random, Best, Worst};

class SortTester
{
public:
	SortTester(int NumArrs, int* ArrSizes, std::ostream* output);
	~SortTester();
	
	void SetSort(Sort* s);
	void TestSort();
private:
	int NumArrs;
	int* ArrSizes;
	int** Arrs;
	Sort* CurrentSort;
	std::ostream* Output;
	void GenerateArr(int num, GenerationType GT);
	void TestSortWithGT(GenerationType GT);
};