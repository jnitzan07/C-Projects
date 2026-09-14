#include <stdio.h>;

static double convert_fahrenheit_to_celsius(double fahrenheit) {
    return ((fahrenheit - 32.0) * 5.0/9.0);
}

static void fahrenheit_to_celsius() {
    double fahrenheit;
    double celsius;

    printf("\nEnter today's temperature in Fahrenheit: ");
    //didn't use scanf_s because scanning a double means there'll be no buff overflow issues
    //and I don't feel like dealing with edge-cases for if a non-numerical value is entered
    scanf("%lf", &fahrenheit);

    celsius = convert_fahrenheit_to_celsius(fahrenheit);

    printf("\nToday's Temperature is %lf degrees in Fahrenheit, which is %lf degrees in Celsius!", fahrenheit, celsius);
}

static void memory_cells() {
    int cell1;
    int cell2;

    printf("\n\n\nEnter the value to store in memory cell 1:");
    scanf("%d", &cell1);
    printf("\nEnter the value to store in memory cell 2:");
    scanf("%d", &cell2);

    int temp_val = cell1;
    cell1 = cell2;
    cell2 = temp_val;

    printf("\nCell 1 was swapped from %d to %d, and Cell 2 was swapped from %d to %d", temp_val, cell1, cell1, cell2);
}


static void random_numbers() {
    int r1;
    int r2;
    int r3;
    printf("\nEnter a random integer less than 100: ");
    scanf("%d", &r1);
    printf("\nEnter a random integer less than 100: ");
    scanf("%d", &r2);
    printf("\nEnter a random integer less than 100: ");
    scanf("%d", &r3);

    int max;

    if (r1 >= r2 && r1 >= r3) {
        max = r1;
    } else if (r2 >= r3) {
        max = r2;
    } else {
        max = r3;
    }

    printf("\n The biggest of the 3 numbers is: %d!", max);
}

int main() {
    //quick note that yes, I know normally these would be in their own file and we'd be including it (#include) and calling it. but that's too much effort.
    fahrenheit_to_celsius();
    memory_cells();
    random_numbers();
    return 0;
}
