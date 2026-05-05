#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void HeapSort(int arr[], int n);
void BuildMaxHeap(int arr[], int n);
void MaxHeapify(int arr[], int index, int n);
void PrintArray(int arr[], int n);
void RandomArray(int arr[], int n);

int main(void)
{
    time_t begin, end;
    double rtime;
    srand(time(NULL));
    int array_size = 500000;
    int arr[array_size];
    RandomArray(arr, array_size);
    begin = clock();
    HeapSort(arr, array_size);
    end = clock();
    rtime = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
    //PrintArray(arr, array_size);
    printf("Array size of %d\n", array_size);
    printf("Time taken by Heap Sort: %f ms\n", rtime);

}

void HeapSort(int arr[], int n)
{
    BuildMaxHeap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        MaxHeapify(arr, 0, i);
    }
}

void BuildMaxHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        MaxHeapify(arr, i, n);
    }
}

void MaxHeapify(int arr[], int i, int n)
{
    int L, R, largest;
    L = 2 * i + 1;      // Left child index
    R = 2 * i + 2;      // Right child index
    largest = i;
    if (L < n && arr[L] > arr[i])
    {
        largest = L;
    }
    if (R < n && arr[R] > arr[largest])
    {
        largest = R;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        MaxHeapify(arr, largest, n);
    }
}

void RandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % n);
    }
}


void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}