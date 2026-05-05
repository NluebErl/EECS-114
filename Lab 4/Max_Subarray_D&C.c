#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

int max_subarray(int arr[], int low, int high);
int find_crossing_subarray(int arr[], int low, int mid, int high);
int random_array(int arr[], int size);
int print_array(int arr[], int size);
int low_index, high_index;
int MAX_VAL = 1000;
int MIN_VAL = -1000;

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
    printf("Time taken by Divide and Conquer Max Subarray: %f ms\n", rtime);

    return 0;
}

int max_subarray(int arr[], int low, int high)
{
    int max_sum;
    if (high == low)
    {
        low_index = low;
        high_index = high;
        return arr[low];
    }
    else
    {
        int mid = (low + high) / 2;
        int left_low, left_high, left_sum;
        int right_low, right_high, right_sum;
        int cross_low, cross_high, cross_sum;
        left_sum = max_subarray(arr, low, mid);
        left_low = low_index;
        left_high = high_index;
        right_sum = max_subarray(arr, mid + 1, high);
        right_low = low_index;
        right_high = high_index;
        cross_sum = find_crossing_subarray(arr, low, mid, high);
        cross_low = low_index;
        cross_high = high_index;
        if (left_sum >= right_sum && left_sum >= cross_sum)
        {
            low_index = left_low;
            high_index = left_high;
            return left_sum;
        }
        else if (right_sum >= left_sum && right_sum >= cross_sum)
        {
            low_index = right_low;
            high_index = right_high;
            return right_sum;
        }
        else
        {
            low_index = cross_low;
            high_index = cross_high;
            return cross_sum;
        }
    }
}

int find_crossing_subarray(int arr[], int low, int mid, int high)
{
    int left_sum, right_sum;
    left_sum = right_sum = INT_MIN;
    int sum = 0;
    int max_left, max_right;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for (int j = mid + 1; j <= high; j++)
    {
        sum += arr[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }
    low_index = max_left;
    high_index = max_right;
    return left_sum + right_sum;
}

int random_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % MAX_VAL) + MIN_VAL / 2; 
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