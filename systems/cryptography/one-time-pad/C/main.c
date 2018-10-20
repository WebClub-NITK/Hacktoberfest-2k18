#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define NDEBUG

const size_t LINE_LENGTH = 1024;
const char ALPHABET_LENGTH = 26;

bool validate (char * string) {
    for (; *string != '\0' && *string != '\n'; string++) {
        char c = *string;
        if (c < 'a' || c > 'z') {
            return false;
        }
    }

    if (*string == '\0') {
        return false;
    }
    return true;
}

void encrypt (char * string, char * key) {
    assert (strlen (key) >= strlen (string));
    assert (validate(key));
    assert (validate(string));

    for (; *string != '\n'; string++, key++) {
        char index = (*string - 'a') + (*key - 'a');
        *string = index % ALPHABET_LENGTH + 'a';
    }
}

void decrypt (char * string, char * key) {
    assert (strlen (key) >= strlen (string));
    assert (validate(key));
    assert (validate(string));

    for (; *string != '\n'; string++, key++) {
        char index = (*string - 'a') + (ALPHABET_LENGTH - (*key - 'a'));
        *string = index % ALPHABET_LENGTH + 'a';
    }
}

int main (void) {
    char string[LINE_LENGTH];
    char key[LINE_LENGTH];

    fgets (string, LINE_LENGTH - 1, stdin);
    fgets (key, LINE_LENGTH - 1, stdin);

    if (!validate(key) || !validate(string)) {
        fprintf (stderr, "Key and string must only contain lowercase letters, and end with a newline.\n");
        return 1;
    }

    if (strlen (key) < strlen(string)) {
        fprintf (stderr, "Key must be at least as long as the string to be encoded\n");
        return 1;
    }

    encrypt (string, key);
    printf ("%s", string);

    /* decrypt (string, key); */
    /* printf ("%s", string); */

    return 0;
}
