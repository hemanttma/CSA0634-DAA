#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    double ratioA = (double)(((struct Item *)a)->value) / ((struct Item *)a)->weight;
    double ratioB = (double)(((struct Item *)b)->value) / ((struct Item *)b)->weight;

    if (ratioA > ratioB)
        return -1;
    else if (ratioA < ratioB)
        return 1;
    else
        return 0;
}


double fractionalKnapsack(int W, struct Item arr[], int n) {

    qsort(arr, n, sizeof(arr[0]), compare);

    int currentWeight = 0; 
    double finalValue = 0.0; 

    for (int i = 0; i < n; i++) {

        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
        
            int remainingWeight = W - currentWeight;
            finalValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
            break; 
        }
    }

    return finalValue;
}

int main() {
    int W = 50;
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    double maxValue = fractionalKnapsack(W, arr, n);

    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}

