#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

static int check_seen(char* seen, char target) {
    if (strchr(seen, target) != NULL) {
        return 1;
    } else {
        return 0;
    }
}

static int all_same(char* s, int len) {
    char base = s[0];
    for (int i = 1; i < len; i++) {
        if (base != s[i]) {
            return 0;
        }
    }

    return 1;
}

static void clear_seen(char* seen, int len) {
    for (int i = 0; i < len; i++) {
        seen[i] = '\0';
    }
}

//works for every case where the char array isn't all the same character
static int lengthOfLongestSubstring(char* s) {
    int char_length = strlen(s);
    int count = 0;
    int longest = 0;
    int length = 0;

    if (all_same(s, char_length) == 1) {
        return 1;
    }

    char seen[char_length] = {};

    for (int i = 0; i < char_length; i++) {
        if (check_seen(seen, s[i]) != 1) {
            seen[count] = s[i];
            length++;
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
    char* s = "bbbe";
    int longest = lengthOfLongestSubstring(s);
    printf("The longest substring is: %d", longest);

    return 1;
}