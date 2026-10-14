#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dice.h"
#include "sic_bo.h"
#include "greatest_common_divisor.h"
#include "prediction.h"

int output_roll_dice(int min, int max, int rolls) {
    srand(time(NULL));

    printf("- Rolling die %d times! -\n", rolls);
    int num_sides = max - min;
    int faces[max - min];

    for (int i = 0; i < max - min; i++) {
        faces[i] = 0;
    }

    roll_dice(min, max, rolls, faces);

    for (int i = 0; i <= num_sides; i++) {
        printf("\nLanded on %d: %d times!", i + min, faces[i]);
    }
}

int game_sic_bo() {
    srand(time(NULL));

    int guess = get_user_input();
    while (guess == -1) {
        printf("\nInvalid guess\n");
        guess = get_user_input();
    }

    int sum_die = add_dice(roll_die(1, 6), roll_die(1, 6), roll_die(1, 6));
    int winner = calculate_winner(guess, sum_die);

    //1: user wins
    //2: dealer wins
    if (winner == 1) {
        printf("\nYou (the user), win!");
    } else {
        printf("\nYou lose! The dealer wins!");
    }


}

int get_greatest_common_divisor(int n1, int n2) {
    int *divisors_1 = malloc(sizeof(int) * 1600);
    int *divisors_2 = malloc(sizeof(int) * 1600);

    get_divisors(n1, divisors_1);
    get_divisors(n2, divisors_2);

    int greatest_divisor = compare_divisors(divisors_1, divisors_2);
    printf("\nThe greatest common divisor of %d and %d is %d!", n1, n2, greatest_divisor);
}

int predict_love_life() {
    int sum = get_bday_sum();
    seed_random(sum);
    int card = gen_card_val();
    check_rules(sum, card);
}

int main() {
    //output_roll_dice(1, 6 , 60000000);
    //int num_games = 3;
    //for (int i = 0; i < num_games; i++) {
    //    game_sic_bo();
    //    printf("\n");
    //}
    //get_greatest_common_divisor(18, 63);
    predict_love_life();
}

