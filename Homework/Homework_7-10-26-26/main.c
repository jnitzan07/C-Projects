#include <stdio.h>

long long reverse_num(long long num, long long rev) {
    if (num == 0) return rev;
    return reverse_num(num / 10, rev * 10 + num % 10);
}

int calc_gcd(int a, int b) {
    if (b == 0) return a;
    return calc_gcd(b, a % b);
}

void to_binary(int n) {
    if (n == 0) return;
    to_binary(n / 2);
    printf("%d", n % 2);
}

void reverse_num_input() {
    long long n;
    printf("\nEnter a number: ");
    scanf("%lld", &n);

    if (n < 0)
        printf("Reversed: -%lld\n", reverse_num(-n, 0));
    else
        printf("Reversed: %lld\n", reverse_num(n, 0));
}

void gcd_dialog() {
    int a, b;
    printf("\nEnter two numbers: ");
    scanf("%d %d", &a, &b);

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    printf("GCD of %d and %d is %d\n", a, b, calc_gcd(a, b));
}

void to_binary_dialog() {
    int n;
    printf("\nEnter a number: ");
    scanf("%d", &n);

    printf("Binary: ");
    if (n == 0)
        printf("0");
    else if (n < 0) {
        printf("-");
        to_binary(-n);
    } else
        to_binary(n);
    printf("\n");
}

int main() {
    gcd_dialog();
    reverse_num_input();
    to_binary_dialog();
    return 0;
}