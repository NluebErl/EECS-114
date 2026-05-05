#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int BinarySearch(int arr[], int target, int low, int high);
void RandomArray(int arr[], int n);
void Merge(int arr[], int l, int q, int r);
void MergeSort(int arr[], int l, int r);

int main(void)
{
    clock_t begin, end;
    double rtime;
    begin = clock();
    int size = 100000;
    int arr[size];
    srand(time(NULL));
    RandomArray(arr, size);
    MergeSort(arr, 0, size - 1); // Sort Array
    printf("Sorted Array: \n");
    /*for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }*/
    printf("\n");
    int target = 67; // Choose a target that is guaranteed to be in the array
    printf("Searching for target: %d\n", target);
    
    int result = BinarySearch(arr, target, 0, size - 1);
    end = clock();
    rtime = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
    if (result != -1)   // Target found
    {
        printf("Element found at index: %d\n", result);
    }
    else    // Target not found
    {
        printf("Element not found in the array.\n");
    }
    printf("Element in array spot arr[%d] = %d\n", result, arr[result]);
    printf("Time taken by Binary Search: %f ms\n", time);
    return 0;
}

int BinarySearch(int arr[], int target, int low, int high)
{
    if (low > high) // Add base case if there are no elements left to search
    {
        return -1; 
    }
    int middle = low + (high - low) / 2;
    if (target == arr[middle])  // Target found
    {
        return middle;
    }
    else if (target < arr[middle])  // Search in the left half for target
    {
        return BinarySearch(arr, target, low, middle - 1); // Recursively search left half
    }
    else
    {
        return BinarySearch(arr, target, middle + 1, high); // Recursively search right half
    }
}

void RandomArray(int arr[], int n) // Create a random array of size n
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n; // Random numbers between 0 and n - 1
    }
}

void Merge(int arr[], int l, int q, int r) // Merge two halves of an array from MergeSort
{
    int n1 = q - l + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[q + j + 1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    for (int k = l; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int arr[], int l, int r) // Sort an array using MergeSort
{
    if (l < r)
    {
        int q = (l + r) / 2;
        MergeSort(arr, l, q);
        MergeSort(arr, q + 1, r);
        Merge(arr, l, q, r);
    }
}
