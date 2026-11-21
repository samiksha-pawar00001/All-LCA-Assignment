#include <stdio.h>


void swap_numbers(int *num1, int *num2);

int main() {
    int num1, num2;
    printf("Enter First Number : ");
    scanf("%d", &num1);
    printf("Enter Second Number : ");
    scanf("%d", &num2);
    printf("BEFORE SWAP :: num1 =%d  num2=%d\n", num1, num2);
    swap_numbers(&num1, &num2); // call by reference
    printf("AFTER SWAP :: num1 =%d  num2=%d\n", num1, num2);
    return 0;
}

void swap_numbers(int *num1, int *num2) {
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
