// laba2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;
int n;

int first, last;
///sortirovka
void quicksort(int *mas, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; ///pervij element
	do
	{
		while (mas[f]<mid) f++;
		while (mas[l]>mid) l--;
		if (f <= l) ///perestanovka
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f<l);
	if (first<l) quicksort(mas, first, l);
	if (f<last) quicksort(mas, f, last);
}

///glavnay 
int _tmain(int argc, _TCHAR* argv[])
{setlocale(LC_ALL, "Rus");
scanf_s("%d", &n);
	int *A = new int[n];
	srand(time(NULL));
	
	for (int i = 0; i<n; i++)
	{
		scanf_s("%d",&A[i]);
	
	}
	first = 0; last = n - 1;
	quicksort(A, first, last);
	cout << endl << "Результирующий массив: ";
	for (int i = 0; i<n; i++) cout << A[i] << " ";
	delete[]A;
	system("pause>>void");
	return 0;
}

