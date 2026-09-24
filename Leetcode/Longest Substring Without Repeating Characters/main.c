#include <stdio.h>
#include <string.h>

int check_seen(char* seen, char target) {
    if (strchr(seen, target) != NULL) {
        return 1;
    } else {
        return 0;
    }
}

void clear_seen(char* seen, int len) {
    for (int i = 0; i < len; i++) {
        seen[i] = '\0';
    }
}

int lengthOfLongestSubstring(char* s) {
    int length = 0;
    int char_length = strlen(s);

    int longest = 0;

    char seen[char_length] = {};

    int count = 0;

    for (int i = 0; i < char_length; i++) {
        if (check_seen(seen, s[i]) != 1) {
            length++;
            seen[count] = s[i];
            count++;
        } else {
            count = 0;
            length = 0;
            clear_seen(seen, char_length);
        }

        if (length > longest) {
            longest = length;
        }
    }

    return longest;
}

int main() {
    char* s = "Once upon a time";
    int longest = lengthOfLongestSubstring(s);
    printf("The longest substring is: %d", longest);

    return 1;
}