#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int print_multiplication_table() {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < i + 1; j++) {
            int result = i * j;
            printf("%d * %d = %d   ", i, j, result);
        }
        printf("\n");
    }
    return 1;
}

static int guessing_game() {
    bool running = true;
    int num_set;
    int num_guess;

    int chances = 3;
    int guesses = 0;

    int max_num = 10;
    int min_num = 1;

    srand(time(NULL));

    printf("A random integer has been chosen (%d - %d)! You have %d chances remaining to guess it!\n", min_num, max_num, chances - guesses);
    num_set = (rand()) % (max_num - min_num) + min_num;
    while (running) {
        printf("\nGuess the integer: \n");
        scanf("\n%d", &num_guess);

        guesses++;

        if (guesses == chances && num_guess != num_set) {
            printf("\nThe number was %d! You failed to guess it in %d guesses!", num_set, chances);
            return 0;
        }

        if (num_guess < num_set) {
            printf("The number guessed (%d) is less then set integer", num_guess);
        } else if (num_guess > num_set) {
            printf("The number guessed (%d) is greater then set integer", num_guess);
        } else {
            printf("Correct! The number was %d! It took you %d guesses!", num_set, guesses);
            running = false;
        }
    }
    return 0;
}


static double convert_celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0/5.0 + 32);
}

static void celsius_to_fahrenheit(int max) {
    int celsius = 0;

    printf("Celsius    Fahrenheit");
    for (;celsius < max; celsius++) {
        printf("\n %d          %.2f", celsius, convert_celsius_to_fahrenheit(celsius));
    }


}


int main() {
    print_multiplication_table();
    guessing_game();
    celsius_to_fahrenheit(10);
}

