#include <stdio.h>

double n_power(double input, int power) {
    double temp = input;
    for (; power > 0; power--) {
        input *= temp;
    }

    return input;
}

int main() {
    double in;
    int power;
    
    printf("Enter a double: ");
    scanf("%lf", &in);
    printf("Enter a power (int): ");
    scanf("%d", &power);

    double result = n_power(in, power);
    printf("%lf to the %dth power is %lf!", in, power, result);
}