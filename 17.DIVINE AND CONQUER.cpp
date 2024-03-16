#include <stdio.h>

void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    int mid, max1, max2, min1, min2;

    if (low == high) {
        *max = arr[low];
        *min = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    mid = (low + high) / 2;

    findMaxMin(arr, low, mid, &max1, &min1);
    findMaxMin(arr, mid + 1, high, &max2, &min2);

    if (max1 > max2)
        *max = max1;
    else
        *max = max2;

    if (min1 < min2)
        *min = min1;
    else
        *min = min2;
}

int main() {
    int arr[100]; 
    int size;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &size);

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int max, min;
    findMaxMin(arr, 0, size - 1, &max, &min);

    printf("Maximum value in the list: %d\n", max);
    printf("Minimum value in the list: %d\n", min);

    return 0;
}

