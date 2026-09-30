#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

double calc_sqrt(double num, bool do_print) {
    //newton's method

    if (num <= 0) {return 0;}

    double x0 = 1.0;
    double tolerance = 1e-14;

    int iterations = 0;
    int max_iterations = 1000;
    while (iterations < max_iterations) {
        double xn = 0.5 * (x0 + num / x0);

        double diff = (xn - x0);
        if (diff < 0) {diff = -diff;}

        if (diff < tolerance * xn) {
            if (do_print) printf("\nThe square root of %lf is approximately %lf.", num, xn);
            return xn;
        }
        x0 = xn;
        iterations++;
    }

    return 0;
}

int print_fibonacci(int amount) {
    int last_int = 0;
    int current_int = 1;

    int temp;

    for (int i = 0; i < amount; i++) {
        printf("%d   ", current_int);
        temp = last_int;
        last_int = current_int;
        current_int += temp;
    }

    return 1;
}

int calc_divisors(int num, int* divisors) {
    int count = 0;

    for (int i = 1; i <= num/2; i++) {
        if (num % i == 0) {
            divisors[count++] = i;
        }
    }

    divisors[count] = -1;

    return 1;
}

int calc_sum(int* divisors) {
    int sum = 0;
    int count = 0;
    while (divisors[count] != -1) {
        sum += divisors[count];
        count++;
    }

    return sum;
}

int perfect_number(int bounds) {
    int *divisors = malloc(1600 * sizeof(int));
    if (divisors == NULL) {
        printf("\n###Out of Memory###");
        return 0;
    }

    for (int i = 2; i <= bounds; i++) {
        calc_divisors(i, divisors);
        int sum = calc_sum(divisors);

        if (sum == i) printf("\n%d is a perfect number!", i);
    }

    free(divisors);
    return 1;
}

int max_min(int num_amount) {
    int min = INT_MAX;
    int max = INT_MIN;
    int temp;

    for (int i = 0; i < num_amount; i++) {
        printf("Enter number %d: ", i + 1);

        scanf("%d", &temp);

        if (temp < min) min = temp;
        if (temp > max) max = temp;
    }

    printf("Min: %d, Max: %d", min, max);
    return 1;
}

int calc_primes(int bounds) {
    if (bounds < 2) {bounds = 2;}
    int size = (int) (1.26 * bounds/log(bounds)) + 1;
    int *primes = malloc(size *sizeof(int));
    if (primes == NULL) {
        printf("\n###Out of Memory###");
        return -1;
    }

    int prime_count = 0;
    primes[prime_count++] = 2;

    for (int i = 3; i <= bounds; i += 2) {
        int count = 0;

        bool is_prime = true;
        while (is_prime && count < prime_count && primes[count] * primes[count] <= i) {
            if (i % primes[count] == 0) {is_prime = false;}
            count++;
        }

        if (!is_prime) continue;

        primes[prime_count++] = i;
    }

    for (int i = 0; i < prime_count; i++) {
        printf("\n%d is a prime number!", primes[i]);
    }

    free(primes);
    return 1;
}

int main(void) {
    //P1
    printf("Printing the fibonacci sequence (16 dig):");
    print_fibonacci(16);
    printf("\n");

    //P2
    int inputted_numbers_amount = 4;
    printf("Find the max and minimum of %d inputted numbers:", inputted_numbers_amount);
    printf("\n");
    max_min(inputted_numbers_amount);

    //P3
    int perfect_bounds = 20000;
    printf("\n\nFinding all perfect numbers <= %d: ", perfect_bounds);
    perfect_number(perfect_bounds);

    //P4
    int prime_bounds = 25;
    printf("\n\nFinding all prime numbers <= %d: ", prime_bounds);
    calc_primes(prime_bounds);

    //P5
    double sqrt_double = 5.532;
    printf("\n\nFinding the sqrt of a double (%lf): ", sqrt_double);
    calc_sqrt(sqrt_double, true);
}
