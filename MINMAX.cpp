#include <stdio.h>

struct minmax 
{
    int min;
    int max;
};

struct minmax find(int arr[], int low, int high) 
{
    struct minmax result, left, right;
    int mid;

    if (low == high) 
	{
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    if (high == low + 1) 
	{
        if (arr[low] > arr[high]) {
        	
            result.max = arr[low];
            result.min = arr[high];
        } 
		else 
		{
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }

    mid = (low + high) / 2;
    left = find(arr, low, mid);
    right = find(arr, mid + 1, high);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() 
{
    int n, i;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &arr[i]);
    }

    struct minmax result = find(arr, 0, n - 1);

    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);

    return 0;
}

