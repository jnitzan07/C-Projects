#include <stdio.h>


int main() {
    char yourname[20];
    char yourschool[50];
    char youranimal[50];
    char yourcolor[50];
    int yourage;

    printf("What is your name?: ");
    scanf("%s", yourname);

    printf("\nWhat is your age?: ");
    scanf("%d", &yourage);

    printf("\nWhat school do you go to?: ");
    scanf("%s", yourschool);

    printf("\nWhat is your favorite color?: ");
    scanf("%s", yourcolor);

    printf("\nWhat is your favorite animal?: ");
    scanf("%s", youranimal);

    printf("\nOnce apon a time, there was a %s named %s. This %s was %d years old, and went to %s. %s learned Programming there, preferred to use a %s colored IDE, and eventually mastering programming. The end.", youranimal, yourname, youranimal, yourage, yourschool, yourname, yourcolor);
    return 0;
}

