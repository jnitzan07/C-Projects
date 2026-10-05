#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int char_array_contains(char* array, char target, int endpoint) {
    for (int i = 0; i < endpoint; i++) {
        if (target == array[i]) {
            return i;
        }
    }
    return -1;
}

static int lengthOfLongestSubstring(char* s) {
    int longest = 0;
    int length = 0;

    int count = 0;
    int str_len = strlen(s);


    char *seen_chars = malloc(256);
    int total_check = 0;

    while (count < str_len) {
        int check = char_array_contains(seen_chars, s[count], length);
        if (check != -1) {
            longest = (length > longest) ? length: longest;
            total_check += check + 1;
            length = 0;
            count = total_check;
            if (str_len - total_check <= longest) {
                break;
            }
        } else {
            seen_chars[length] = s[count];
            length++;
            count++;
        }
    }

    longest = (length > longest) ? length: longest;
    free(seen_chars);
    return longest;
}



int main() {
    char* tests[] = {"sVRDmevU5"};
    int tests_length = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < tests_length; i++) {
        printf("\n%s, %d", tests[i], lengthOfLongestSubstring(tests[i]));
    }
    return 1;
}