#include <math.h>
#include <stdio.h>
#include <string.h>


/*
 * Calculator:
 * Ask a user to input two numbers and an operation (int input 1-4) -> (+ - * /)
 * print out the result.
 * Ex: print out 10 – 6 =4
 *
 * req: use if-else, and switch case
 */
static int calculator() {
    //print asking for the user to input the first number
    //scan to get said number get_input()
    //print asking for second number
    //scan; get_input()

    //ask for the user to enter a integer (1-4) referencing to +, -, *, and /
    //while we're at it let's add more cases like sqrt, power, abs, floor, ceiling

    //set a char to be the respective operator

    //switch for the cases

    int operation;
    printf(
        "\nOperations:\n1. +\n2. -\n3. *\n4. /\n5. %%\n6. ^ \n7. sqrt\n8. abs\n9. floor\n10. ceiling\nChoose one of the above operations: ");
    scanf("%d", &operation);

    double n1, n2 = 0;

    printf("\nEnter the first number (a): "); //if it's a mod or abs operation, take an int input
    if (operation == 5 || operation == 8) {
        scanf("%d", &n1);
    } else {
        scanf("%lf", &n1);
    }

    if (operation < 7) {
        printf("\nEnter the second number (b): ");
        //using ternary here to avoid nested if's
        (operation == 5 || operation == 8) ? scanf("%d", &n2) : scanf("%lf", &n2);
        //if it's a mod or abs operation, take an int input
    }

    char operation_name[20];
    double result;

    switch (operation) {
        case 1:
            strcpy(operation_name, "+");
            result = n1 + n2;
            break;
        case 2:
            strcpy(operation_name, "-");
            result = n1 - n2;
            break;
        case 3:
            strcpy(operation_name, "*");
            result = n1 * n2;
            break;
        case 4:
            strcpy(operation_name, "/");
            result = n1 / n2;
            break;
        case 5:
            strcpy(operation_name, "%");
            result = (int) n1 % (int) n2;
            break;
        case 6:
            strcpy(operation_name, "^");
            result = pow(n1, n2);
            break;
        case 7:
            strcpy(operation_name, "sqrt");
            result = sqrt(n1);
            break;
        case 8:
            strcpy(operation_name, "abs");
            result = abs((int) n1);
            break;
        case 9:
            strcpy(operation_name, "floor");
            result = floor(n1);
            break;
        case 10:
            strcpy(operation_name, "ceiling");
            result = ceil(n1);
            break;
        default:
            result = 0;
            break;
    }

    printf("\n\n%lf %s %lf = %lf\n", n1, operation_name, n2, result);

    return 1;
}


/*
 * Multiples of Four:
 * Find all the numbers in 100 that are multiples of 4
 * Use while loop with condition counter <= 100 or whatever
 */
static int multiples_of_four() {
    //counter = 1;
    //while counter <= 100
    //  if counter % 4 is 0: print counter
    //  counter++

    int counter = 1;
    while (counter <= 100) {
        if (counter % 4 == 0) {
            printf("%d ", counter);
        }
        counter++;
    }
    return 1;
}


/*
 * Biggest User Input:
 * Find biggest user input
 * Use specific value to signify end of user input (ex: -1)
 */
static int biggest_user_input(int *user_input) {
    //biggest = -1
    //count = 0
    //while user_input[count] is not -1
    //  biggest = (user_input[count] > biggest) ? user_input[count]: biggest
    //  count++
    //print biggest

    int biggest = -1;
    int count = 0;
    while (user_input[count] != -1) {
        biggest = user_input[count] > biggest ? user_input[count] : biggest;
        count++;
    }

    printf("\nThe biggest number is: %d", biggest);

    return 1;
}


int main() {
    //could use const or constexpr here but there's no real point as this isn't some project where we need to make sure it's never changed
    int user_input[99] = {
        1, 2, 3, 4, 6, 5, -1, 8 //-1 breaks it off early, the 8 is just there to make sure 8 isn't checked by the function (so it all works correctly)
    };

    calculator();
    multiples_of_four();
    biggest_user_input(user_input);
    return 1;
}
