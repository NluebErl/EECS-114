#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int arr[], int p, int r);
int Partition(int arr[], int p, int r);
void PrintArray(int arr[], int size);
void RandomArray(int arr[], int size);

int main(void)
{
    time_t begin, end;
    double rtime;
    srand(time(NULL));
    int array_size = 500000;
    int arr[array_size];
    RandomArray(arr, array_size);
    printf("Array before QuickSort:\n");
    //PrintArray(arr, array_size);
    begin = clock();
    QuickSort(arr, 0, array_size - 1);
    end = clock();
    rtime = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
    printf("\nArray after QuickSort:\n");
    //PrintArray(arr, array_size);
    printf("\nArray size of %d\n", array_size);
    printf("Time taken by Quick Sort: %f ms\n", rtime);
    return 0;
}

void QuickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = Partition(arr, p, r);
        QuickSort(arr, p, q - 1);
        QuickSort(arr, q + 1, r);
    }
}

int Partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] >= x)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;

    return i + 1;
}

void RandomArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % size;
    }
}

void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
