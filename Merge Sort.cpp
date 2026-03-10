

#include <stdio.h>
int count = 0;
void merge(int arr[], int low, int mid, int high) 
{
    int i = low, j = mid + 1, k = 0;
    int temp[100];
    while (i <= mid && j <= high) 
	{
        count++;
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}
void mergeSort(int arr[], int low, int high) 
{
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main() 
{
    int n;
    int arr[100];

    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nTotal iterations (comparisons): %d", count);
    return 0;
}

