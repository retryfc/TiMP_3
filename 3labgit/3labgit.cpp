// Sort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "SortTester.h"
#include "Sort.h"

int main()
{
	int ArrSizes [] = { 1,2,3,4,5,10,15,20,25,30,50,75,100,250,500 };
	std::ofstream Outfile("Output.txt");
	SortTester ST(15, ArrSizes, &Outfile);
	srand(time(NULL));
	
	ST.SetSort(new QwickSort3Way());
	ST.TestSort();

	ST.SetSort(new SelectionSort());
	ST.TestSort();

	ST.SetSort(new MergeSort());
	ST.TestSort();

	Outfile.close();
    return 0;
}

