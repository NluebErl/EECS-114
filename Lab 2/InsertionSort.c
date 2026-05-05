#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void InsertionSort(int arr[], int n);
void MergeSort(int arr[], int l, int r);
void Merge(int arr[], int l, int q, int r);
void RandomArray(int arr[], int n);

int main()
{
    int arr[100000];
    RandomArray(arr, 100000);
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Array of size %d before sort: ", n);
    /*for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }*/
    printf("\n");
    clock_t begin, end;
    double time;
    begin = clock();
    //InsertionSort(arr, n);
    MergeSort(arr, 0, n - 1);
    end = clock();
    time = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
    printf("Time taken by Merge Sort: %f ms\n", time);
    /*for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }*/
    printf("\n");
    return 0;
}

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return;
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

void RandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
}
