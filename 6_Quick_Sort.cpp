
//QuickSort Deterministic

#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i
		= (low
		- 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}


//QuickSort Non-Deterministic

#include <cstdlib>
#include <iostream>
using namespace std;

// This function takes last element as
// pivot, places the pivot element at
// its correct position in sorted
// array, and places all smaller
// (smaller than pivot) to left of pivot
// and all greater elements to right
int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low - 1, j = high + 1;

	while (true) {

		// Find leftmost element greater than
		// or equal to pivot
		do {
			i++;
		} while (arr[i] < pivot);

		// Find rightmost element smaller than
		// or equal to pivot
		do {
			j--;
		} while (arr[j] > pivot);

		// If two pointers met
		if (i >= j)
			return j;

		swap(arr[i], arr[j]);
	}
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
// In Hoare partition the low element is selected
// as first pivot
int partition_r(int arr[], int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);

	swap(arr[random], arr[low]);

	return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition_r(arr, low, high);

		quickSort(arr, low, pi);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

