#pragma once

enum SortType { MS, QS3W, SS};

class Sort
{
public:
	virtual void Sorting(int* Arrptr,int ArrLenght, int &NumComparsions, int & NumSwaps, int & Time ) = 0;
	SortType ST;
};

class MergeSort : public Sort 
{
public:
	void Sorting(int* Arrptr, int ArrLenght, int &NumComparsions, int & NumSwaps, int & Time);
	MergeSort();
private:
	void MaxHeap(int* Arrptr, int ArrLenght, int i, int &NumComparsions, int & NumSwaps);
	void merge_sort(int * AP, int p, int r, int &NumComparsions, int & NumSwaps);
	void merge(int * AP, int p, int q, int r, int &NumComparsions, int & NumSwaps);
};

class QwickSort3Way : public Sort
{
public:
	void Sorting(int* Arrptr, int ArrLenght, int &NumComparsions, int & NumSwaps, int & Time);
	QwickSort3Way();
};

class SelectionSort : public Sort
{
public:
	void Sorting(int* Arrptr, int ArrLenght, int &NumComparsions, int & NumSwaps, int & Time);
	SelectionSort();
};
