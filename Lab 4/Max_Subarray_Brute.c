#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max_subarray(int arr[],int low, int high);
int random_array(int arr[], int size);
int print_array(int arr[], int size);
int low_index, high_index;

int main(void)
{
    clock_t begin, end;
    double rtime;
    srand(time(NULL));
    int array_size = 10000;
    int arr[array_size];
    random_array(arr, array_size);
    begin = clock();
    int max_sum = max_subarray(arr, 0, array_size - 1);
    end = clock();
    rtime = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
    //print_array(arr, array_size);
    printf("Maximum Subarray Sum: %d\n", max_sum);
    printf("Found at indices [%d, %d]\n", low_index, high_index);
    printf("Time taken by Brute Force Max Subarray: %f ms\n", rtime);
    return 0;
}

int max_subarray(int arr[], int low, int high)
{
    int max_sum = 0;
    for (int i = low; i <= high; i++)
    {
        int current_sum = 0;
        for (int j = i; j <= high; j++)
        {
            current_sum += arr[j];
            if (current_sum > max_sum)
            {
                low_index = i;
                high_index = j;
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}

int random_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % size - (size / 2); 
    }
    return 0;
}

int print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}