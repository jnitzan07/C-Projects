#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool running = true;
    int num_set;
    int num_guess;

    printf("Enter an integer to guess: \n");
    scanf_s("%d", &num_set);
    while (running) {
        printf("\nGuess the integer: \n");
        scanf("\n%d", &num_guess);

        if (num_guess < num_set) {
            printf("The number guessed (%d) is less then set integer", num_guess);
        } else if (num_guess > num_set) {
            printf("The number guessed (%d) is greater then set integer", num_guess);
        } else {
            printf("Correct! The number was %d!", num_set);
            running = false;
        }
    }
    return 0;
}