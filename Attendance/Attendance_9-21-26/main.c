#include <stdio.h>


int main() {
    printf("Enter a number: ");

    int num;
    int sum = 1;
    scanf("%d", &num);

    printf("\n%d! = 1", num);
    for (int i = 2; i <= num; i++) {
        printf(" * %d", i);
        sum *= i;
    }
    printf(" = %d", sum);

}