#include <stdio.h>
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void printFibonacciSeries(int n) {
    printf("Fibonacci Series up to %d terms: ", n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int main() {
    int terms;

    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &terms);

    printFibonacciSeries(terms);

    return 0;
}

