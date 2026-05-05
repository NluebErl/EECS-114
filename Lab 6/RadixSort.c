#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RadixSort(int arr[], int d);
void PrintArray(int arr[], int size);
void RandomArray(int arr[], int size);
int FindMax(int arr[], int size);
void CountingSort(int arr[], int B[], int k, int size);

int main(void)
{
    time_t begin, end;
    double rtime;
    srand(time(NULL));
    int array_size = 500000;
    int arr[array_size];
    RandomArray(arr, array_size);
    printf("Array Before Radix Sort:\n");
    //PrintArray(arr, array_size);
    begin = clock();
    RadixSort(arr, array_size);
    end = clock();
    rtime = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
    printf("\nArray After Radix Sort:\n");
    //PrintArray(arr, array_size);
    printf("\nArray size of %d\n", array_size);
    printf("Time taken by Radix Sort: %f ms\n", rtime);
    
    return 0;
}

void RadixSort(int arr[], int d)
{
    int B[d];
    int max = FindMax(arr, d);
    // Do Counting Sort for every digit. Divide by 10 each time to get next digit
    for (int i = 1; (max / i) > 0; i *= 10)
    {
        CountingSort(arr, B, i, d);
    }
}

void CountingSort(int arr[], int B[], int k, int size)
{
    // Hardcode array C of size 10 since we are only dealing with digits 0-9.
    // Divide by k to get the number we are currently sorting by and then mod to get the digit.
    int C[10] = {0};
    for (int i = 0; i < size; i++)
    {
        C[(arr[i] / k) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        C[i] += C[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        B[C[(arr[i] / k) % 10] - 1] = arr[i];
        C[(arr[i] / k) % 10] -= 1;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = B[i];
    }
}

int FindMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void RandomArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % size;
    }
}
