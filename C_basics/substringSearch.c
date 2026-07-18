#include <stdio.h>

int find_substring(const char *haystack, const char *needle) {
    int h_len = 0, n_len = 0;
    while (haystack[h_len] != '\0') h_len++;
    while (needle[n_len] != '\0') n_len++;
    for (int i = 0; i < h_len; i++) {
        char sub[100];
        int index = 0;
        for (int j = i; j < h_len && index < n_len; j++) {
            sub[index++] = haystack[j];
        }
        sub[index] = '\0';
        int match = 1;
        for (int k = 0; k < n_len; k++) {
            if (sub[k] != needle[k]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    return -1;
}

int main() {
    char *haystack = "Embedded Systems";
    char *needle = "bed";

    printf("%d\n", find_substring(haystack, needle));

    return 0;
}
