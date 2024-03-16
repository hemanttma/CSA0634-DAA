#include <stdio.h>
#include <math.h>

int countDigits(int num) {
    if (num == 0) {
        return 0;
    } else {
        return 1 + countDigits(num / 10);
    }
}

int isArmstrong(int num, int n) {
    if (num == 0) {
        return 0;
    } else {
        return pow(num % 10, n) + isArmstrong(num / 10, n);
    }
}

int main() {
    int number, sum = 0, originalNumber, digits;

    printf("Enter an integer: ");
    scanf("%d", &number);

    originalNumber = number;

    digits = countDigits(number);

    sum = isArmstrong(number, digits);

    if (sum == originalNumber) {
        printf("%d is an Armstrong number.\n", originalNumber);
    } else {
        printf("%d is not an Armstrong number.\n", originalNumber);
    }

    return 0;
}

