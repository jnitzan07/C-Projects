#include <stdio.h>

void print_grade_switch(int grade) {
    printf("Grade determined from switch: ");
    switch (grade/10) {
        case 10:
        case 9:
            printf("A");
            break;
        case 8:
            printf("B");
            break;
        case 7:
            printf("C");
            break;
        default:
            printf("F");
            break;
    }
}

void print_grade_nested(int grade) {
    printf("Grade determined from nested loop: ");
    if (grade < 70) {
        printf("F");
    } else if (grade < 80) {
        printf("C");
    } else if (grade < 90) {
        printf("B");
    } else {
        printf("A");
    }
}

int main() {
    int grade;
    printf("Enter the grade (0-100): ");
    scanf("%d", &grade);


    print_grade_switch(grade);
    printf("\n");
    print_grade_nested(grade);

    return 1;
}
