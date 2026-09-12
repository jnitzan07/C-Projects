#include <stdio.h>
#include <string.h>

int main() {
    char resp[100];
    printf(":) \nHello Professor Li, how are you doing today? (good/bad?): ");
    scanf("%s", resp);

    if (strcmp(resp, "good") == 0) {
        printf("That's great to hear!.\n");
    } else {
        printf("I'm sorry to hear that. \n");
    }

    printf("  ........  \n .        . \n.  0    0  .\n . \\____/ .\n  ........    \n");
    return 0;
}