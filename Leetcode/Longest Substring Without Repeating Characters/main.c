#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



static int char_array_contains(char* array, char target, int endpoint) {
    for (int i = 0; i < endpoint; i++) {
        if (target == array[i]) {
            return 1;
        }
    }
    return 0;
}

static int lengthOfLongestSubstring(char* s) {
    int longest = 0;
    int length = 0;

    int count = 0;
    int str_len = strlen(s);


    char *seen_chars = malloc(sizeof(s));

    while (count < str_len - longest) {
        if (char_array_contains(seen_chars, s[count], length)) {
            length = 0;
        } else {
            seen_chars[length] = s[count];
            length++;
            longest = (length > longest) ? length: longest;
        }
        count++;
    }

    free(seen_chars);
    return longest;
}


int main() {

    return 1;
}