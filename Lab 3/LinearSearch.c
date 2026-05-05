#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int LinearSearch(int arr[], int size, int target);
void RandomArray(int arr[], int n);
void Merge(int arr[], int l, int q, int r);
void MergeSort(int arr[], int l, int r);

int main(void)
{
    int size = 5;
    int arr[size];
    RandomArray(arr, size);
    MergeSort(arr, 0, size - 1); // Sort Array
    printf("Sorted Array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
   int target = 2; // Choose a target that is in the array
   printf("Searching for target: %d\n", target);
    clock_t begin, end;
    double time;
    begin = clock();
    int result = LinearSearch(arr, size, target);
    end = clock();
    time = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
    if (result != -1)
    {
        printf("Element found at index: %d\n", result);
    }
    else
    {
        printf("Element not found in the array.\n");
    }
    printf("Element in array spot arr[%d] = %d\n", result, arr[result]);
    printf("Time taken by Linear Search: %f ms\n", time);
    return 0;
}


int LinearSearch(int arr[], int size, int target) 
{
    for (int i = 0; i < size; i ++)
    {
        if (arr[i] == target)
        {
            return i;   // Return the index if the target is found
        }
    }
    return -1;  // Return if the target is not found
}

void RandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n; // Random numbers between 0 and n
    }
}

void Merge(int arr[], int l, int q, int r)
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

void MergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int q = (l + r) / 2;
        MergeSort(arr, l, q);
        MergeSort(arr, q + 1, r);
        Merge(arr, l, q, r);
    }
}
