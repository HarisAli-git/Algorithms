//#include <iostream>
//#include <stdlib.h>
//#include <cstdlib>
//#include <stdio.h> 
//#include <time.h>
//#include <chrono>
//#include <algorithm>
//using namespace std;
//
///* C++ implementation of QuickSort2 */
//
//// A utility function to swap two elements 
//void swap(int* a, int* b)
//{
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//
///* This function takes average of random numbers as pivot, places
//the pivot element at its correct position in sorted
//array, and places all smaller (smaller than pivot)
//to left of pivot and all greater elements to right
//of pivot */
//int partition2(int arr[], int low, int high)
//{
//	// Generate a random number in between 
//	// low .. high 
//	srand(time(NULL));
//	int *r11 = new int(), *r12 = new int(), *r13 = new int(), *median = new int();
//	*r11 = rand() % (high);
//	*r12 = rand() % (high);
//	*r13 = rand() % (high);
//	*median = (*r11 + *r12 + *r13) / 2;
//	int pivot = arr[*median]; // pivot
//	delete r11;
//	delete r12;
//	delete r13;
//	delete median;
//	r11 = r12 = r13 = median = NULL;
//	int i = (low - 1); // Index of smaller element 
//
//	for (int j = low; j <= high - 1; j++)
//	{
//		// If current element is smaller than the pivot 
//		if (arr[j] < pivot)
//		{
//			i++; // increment index of smaller element 
//			swap(&arr[i], &arr[j]);
//		}
//	}
//	swap(&arr[i + 1], &arr[high]);
//	return (i + 1);
//}
//
///* The main function that implements QuickSort
//arr[] --> Array to be sorted,
//low --> Starting index,
//high --> Ending index */
//void quickSort2(int arr[], int low, int high)
//{
//	if (low < high)
//	{
//		/* pi is partitioning index, arr[p] is now
//		at right place */
//		int pi = partition2(arr, low, high);
//
//		// Separately sort elements before 
//		// partition and after partition 
//		quickSort2(arr, low, pi - 1);
//		quickSort2(arr, pi + 1, high);
//	}
//}
//
//
///* C++ implementation of last index QuickSort */
//
///* This function takes last element as pivot, places
//the pivot element at its correct position in sorted
//array, and places all smaller (smaller than pivot)
//to left of pivot and all greater elements to right
//of pivot */
//int partition(int arr[], int low, int high)
//{
//	int pivot = arr[high]; // pivot 
//	int i = (low - 1); // Index of smaller element 
//
//	for (int j = low; j <= high - 1; j++)
//	{
//		// If current element is smaller than the pivot 
//		if (arr[j] < pivot)
//		{
//			i++; // increment index of smaller element 
//			swap(&arr[i], &arr[j]);
//		}
//	}
//	swap(&arr[i + 1], &arr[high]);
//	return (i + 1);
//}
//
///* The main function that implements QuickSort
//arr[] --> Array to be sorted,
//low --> Starting index,
//high --> Ending index */
//void quickSort(int arr[], int low, int high)
//{
//	if (low < high)
//	{
//		/* pi is partitioning index, arr[p] is now
//		at right place */
//		int pi = partition(arr, low, high);
//
//		// Separately sort elements before 
//		// partition and after partition 
//		quickSort(arr, low, pi - 1);
//		quickSort(arr, pi + 1, high);
//	}
//}
//
//// C++ program for insertion sort 
//
///* Function to sort an array using insertion sort*/
//void insertionSort(int arr[], int n)
//{
//	int i, key, j;
//	for (i = 1; i < n; i++)
//	{
//		key = arr[i];
//		j = i - 1;
//
//		/* Move elements of arr[0..i-1], that are
//		greater than key, to one position ahead
//		of their current position */
//		while (j >= 0 && arr[j] > key)
//		{
//			arr[j + 1] = arr[j];
//			j = j - 1;
//		}
//		arr[j + 1] = key;
//	}
//}
//
///* C program for Merge Sort */
//// Merges two subarrays of arr[]. 
//// First subarray is arr[l..m] 
//// Second subarray is arr[m+1..r] 
//void merge(int arr[], int l, int m, int r)
//{
//	int i, j, k;
//	int n1 = m - l + 1;
//	int n2 = r - m;
//
//	/* create temp arrays */
//	int *L = new int[n1], *R = new int[n2];
//
//	/* Copy data to temp arrays L[] and R[] */
//	for (i = 0; i < n1; i++)
//		L[i] = arr[l + i];
//	for (j = 0; j < n2; j++)
//		R[j] = arr[m + 1 + j];
//
//	/* Merge the temp arrays back into arr[l..r]*/
//	i = 0; // Initial index of first subarray 
//	j = 0; // Initial index of second subarray 
//	k = l; // Initial index of merged subarray 
//	while (i < n1 && j < n2)
//	{
//		if (L[i] <= R[j])
//		{
//			arr[k] = L[i];
//			i++;
//		}
//		else
//		{
//			arr[k] = R[j];
//			j++;
//		}
//		k++;
//	}
//
//	/* Copy the remaining elements of L[], if there
//	are any */
//	while (i < n1)
//	{
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//
//	/* Copy the remaining elements of R[], if there
//	are any */
//	while (j < n2)
//	{
//		arr[k] = R[j];
//		j++;
//		k++;
//	}
//	delete[] L;
//	delete[] R;
//	L = R = NULL;
//}
//
///* l is for left index and r is right index of the
//sub-array of arr to be sorted */
//void mergeSort(int arr[], int l, int r)
//{
//	if (l < r)
//	{
//		// Same as (l+r)/2, but avoids overflow for 
//		// large l and h 
//		int m = l + (r - l) / 2;
//
//		// Sort first and second halves 
//		mergeSort(arr, l, m);
//		mergeSort(arr, m + 1, r);
//
//		merge(arr, l, m, r);
//	}
//}
//
//// To heapify a subtree rooted with node i which is 
//// an index in arr[]. n is size of heap 
//void heapify(int arr[], int n, int i)
//{
//	int largest = i; // Initialize largest as root 
//	int l = 2 * i + 1; // left = 2*i + 1 
//	int r = 2 * i + 2; // right = 2*i + 2 
//
//					   // If left child is larger than root 
//	if (l < n && arr[l] > arr[largest])
//		largest = l;
//
//	// If right child is larger than largest so far 
//	if (r < n && arr[r] > arr[largest])
//		largest = r;
//
//	// If largest is not root 
//	if (largest != i)
//	{
//		swap(arr[i], arr[largest]);
//
//		// Recursively heapify the affected sub-tree 
//		heapify(arr, n, largest);
//	}
//}
//
//// main function to do heap sort 
//void heapSort(int arr[], int n)
//{
//	// Build heap (rearrange array) 
//	for (int i = n / 2 - 1; i >= 0; i--)
//		heapify(arr, n, i);
//
//	// One by one extract an element from heap 
//	for (int i = n - 1; i>0; i--)
//	{
//		// Move current root to end 
//		swap(arr[0], arr[i]);
//
//		// call max heapify on the reduced heap 
//		heapify(arr, i, 0);
//	}
//}
//
///* UTILITY FUNCTIONS */
///* Function to print an array */
//void printArray(int A[], int size)
//{
//	int i;
//	for (i = 0; i < size; i++)
//		printf("%d ", A[i]);
//	printf("\n");
//}
//
//void reverse_sorted(int* arr, int n)
//{
//	for (int i = n - 1, j = 0; i >= 0; i--)
//	{
//		arr[j++] = i;
//	}
//}
//
//void sorted(int* arr, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = i;
//	}
//}
//
//void almost_sorted(int* arr, int n)
//{
//	int an = n*0.9;
//	sorted(arr, an);
//	for (int i = an; i < n; i++)
//	{
//		arr[i] = rand();
//	}
//}
//
//void complete_random(int* arr, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = rand();
//	}
//}
//
//void main()
//{
//	int* arr = new int[10000];
//	int* n = new int(10000);
//	reverse_sorted(arr, *n);
//	//almost_sorted(arr, *n);
//	//sorted(arr, *n);
//	//complete_random(arr, *n);
//	cout << "\ndone\n";
//	auto start = chrono::steady_clock::now();
//	/* Do your stuff here */
//	//insertionSort(arr, *n);
//	//mergeSort(arr, 0, *n - 1);
//	//quickSort(arr, 0, *n - 1);
//	quickSort2(arr, 0, *n - 1);
//	//heapSort(arr, *n);
//	auto end = chrono::steady_clock::now();
//	auto diff = end - start;
//	cout << "Time taken: " << chrono::duration <double, milli>(diff).count() << " milli seconds" << endl;
//	delete[] arr;
//	delete n;
//	arr = NULL;
//	n = NULL;
//	system("pause");
//}