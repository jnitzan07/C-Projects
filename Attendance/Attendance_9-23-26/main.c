#include <stdio.h>


int main() {
    int num_stars = 5;
    int num_rows = 5;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_stars; j++) {
            printf("*");
        }
        printf("\n");
    }
}