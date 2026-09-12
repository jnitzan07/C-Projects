#include <stdio.h>
#include <stdbool.h>

#define MAX_ROWS 3
#define MAX_COLS 3

char board[MAX_ROWS][MAX_COLS];
int rows, cols;

static void print_board() {
    for (int i = 0; i < rows; i++) {
        printf("\n|");
        for (int j = 0; j < cols; j++) {
            printf("%c |", board[i][j]);
        }
    }
}

static void initialize_board() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = ' ';
        }
    }
}

int main() {
    rows = 3;
    cols = 3;

    initialize_board();
    print_board();

    int turn = 0;
    int user_col;
    int user_row;

    bool running = true;

    while (running) {
        printf("\nEnter the column number (the x-axis) (1-3): ");
        scanf("%d", &user_col);
        printf("\nEnter the row number (the y-axis) (1-3): ");
        scanf("%d", &user_row);

        if (turn % 2 == 0) {
            board[user_row - 1][user_col - 1] = 'O';
        } else {
            board[user_row - 1][user_col - 1] = 'X';
        }

        turn++;
        print_board();
    }
    return 0;
}