#include <stdio.h>
#include <limits.h>


double calc_sqrt(double num, bool do_print) {
    //newton's method
    double x0 = 1.0;
    double tolerance = 1e-20;

    int iterations = 0;
    int max_iterations = 1000;
    while (iterations - max_iterations) {
        double xn = 0.5 * (x0 + num / x0);

        int sign = (xn - x0 < 0) ? -1: 1;
        if (sign * (xn - x0) < tolerance) {
            if (do_print) printf("\nThe square root of %lf is approximately %lf.", num, xn);
            return xn;
        }
        x0 = xn;
        iterations++;
    }
}

int print_fibonacci(int amount) {
    int last_int = 0;
    int current_int = 1;

    int temp;

    printf("- ");
    for (int i = 0; i < amount; i++) {
        printf("%d - ", current_int);
        temp = last_int;
        last_int = current_int;
        current_int += temp;
    }

    return 1;
}

int calc_parts(int num, int* parts) {
    int count = 0;

    for (int i = 1; i <= num/2; i++) {
        if (num % i == 0) {
            parts[count++] = i;
        }
    }
    parts[count] = -1;

    return 1;
}

int calc_sum(int* parts) {
    int sum = 0;
    int count = 0;
    while (parts[count] != -1) {
        sum += parts[count];
        count++;
    }

    return sum;
}

int perfect_number(int bounds) {
    for (int i = 2; i <= bounds; i++) {
        int parts[99] = {0};
        calc_parts(i, parts);
        int sum = calc_sum(parts);

        if (sum == i) printf("\n%d is a perfect number!", i);
    }

    return 1;
}

int max_min(int num_amount) {
    int min = INT_MAX;
    int max = INT_MIN;
    int temp;

    for (int i = 0; i < num_amount; i++) {
        printf("\nEnter number %d: ", i + 1);

        scanf("%d", &temp);

        if (temp < min) min = temp;
        if (temp > max) max = temp;
    }

    printf("\nMin: %d, Max: %d", min, max);
    return 1;
}

int calc_primes(int bounds) {

    int primes[99] = {INT_MAX};
    int prime_count = 0;
    primes[prime_count++] = 2;

    for (int i = 3; i <= bounds; i++) {
        int count = 0;

        bool is_prime = true;
        while (is_prime && primes[count] <= calc_sqrt(i, false) && primes[count] != 0) {
            if (i % primes[count] == 0) is_prime = false;
            count++;
        }

        if (!is_prime) continue;

        primes[prime_count++] = i;
    }

    for (int i = 0; i < prime_count; i++) {
        printf("\n%d is a prime number!", primes[i]);
    }

    return 1;
}

int main() {
    //P1
    print_fibonacci(16);
    printf("\n");

    //P2
    max_min(4);

    //P3
    perfect_number(8128);

    //P4
    calc_primes(19);

    //P5
    calc_sqrt(5.000, true);
}
