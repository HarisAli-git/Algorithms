#include <iostream>
#include <cstdlib>
#include <chrono>
#include <time.h>
using namespace std;
const int k = 22;

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

// this function sorts array from left index to 
// to right index which is of size atmost RUN 
void insertionSort(int arr[], int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

/* C program for Merge Sort */
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
// merge function merges the sorted runs 
void merge(int arr[], int l, int m, int r)
{
	// original array is broken in two parts 
	// left and right array 
	int len1 = m - l + 1, len2 = r - m;
	int* left = new int [len1], *right = new int[len2];
	for (int i = 0; i < len1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = arr[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	// after comparing, we merge those two array 
	// in larger sub array 
	while (i < len1 && j < len2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	// copy remaining elements of left, if any 
	while (i < len1)
	{
		arr[k] = left[i];
		k++;
		i++;
	}

	// copy remaining element of right, if any 
	while (j < len2)
	{
		arr[k] = right[j];
		k++;
		j++;
	}
	delete[] left;
	delete[] right;
	left = right = NULL;
}

/* l is for left index and r is right index of the sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

// iterative Modified ot TimSort function to sort the array[0...n-1] 
void Modified_mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		if ((r - l) <= k)
		{
			insertionSort(arr, l, r);
		}
		else
		{
			// Same as (l+r)/2, but avoids overflow for 
			// large l and h 
			int m = l + (r - l) / 2;

			// Sort first and second halves 
			Modified_mergeSort(arr, l, m);
			Modified_mergeSort(arr, m + 1, r);

			merge(arr, l, m, r);
		}
	}
}


void com_random(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int* arr = new int[10000];
	int* n = new int(10000);
	com_random(arr, *n);
	cout << "\ndone\n!";
	auto start = chrono::steady_clock::now();
	
	/* Your code here */
	
	Modified_mergeSort(arr, 0, *n - 1);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "Time taken: " << chrono::duration <double, milli>(diff).count() << " milli seconds" << endl;
	delete[] arr;
	delete n;
	arr = n = NULL;
	system("pause");
	return 0;
}
