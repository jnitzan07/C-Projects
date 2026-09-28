#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

double calc_sqrt(int num, int num_digits) {

    int points[num_digits + 2];

    for (int i = 0; i < num_digits; i++) {
        while (points[i] * points[i] < (num % (10 ^ num_digits - i))) {
            points[i] = points[i] + 1;
        }
        printf("%lf, ", points[i]);
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
            parts[count] = i;
            count++;
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

        if (sum == i) {
            printf("\n%d is a perfect number!", i);
        }
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

        if (temp < min) {
            min = temp;
        }
        if (temp > max) {
            max = temp;
        }
    }

    printf("\nMin: %d, Max: %d", min, max);




}

int main() {
    print_fibonacci(16);
    printf("\n");

    max_min(4);
    perfect_number(8128);

    //calc_sqrt(2.0, 1);
}
