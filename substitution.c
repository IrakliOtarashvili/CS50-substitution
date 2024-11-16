#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int len, len1, len2, enc;

bool correct_key(string s);

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Usage: ./substitution key\n"); // CHECKS IF IT TAKES ONLY ONE ARGUMENT
        return 1;
    }

    len1 = strlen(argv[1]);

    if (!correct_key(argv[1])) {
        return 1;  // exit the program if the key is invalid
    }


    for (int i = 0; i < len1; i++) { // CHECKS IF THERE ARE DUPLICATE VALUES
    char upper = toupper(argv[1][i]);
    // iterate trough all 26 letters
        for (int j = i + 1; j < len1; j++) {
            if (argv[1][i] == argv[1][j]) {
            printf("error\n");
            return 1;
            }
        }
    }

    string plain_text = get_string("plaintext: ");
    len2 = strlen(plain_text);

    printf("ciphertext: ");

        // encryption logic
    for (int i = 0; i < len2; i++) {
        if(isalpha(plain_text[i])) {

           if(islower(plain_text[i])) {

                enc = plain_text[i] - 97;
                printf("%c", tolower(argv[1][enc]));

           } else if (isupper(plain_text[i])) {

                enc = plain_text[i] - 65;
                printf("%c", toupper(argv[1][enc]));
           }
        } else {
            printf("%c", plain_text[i]);
        }
    }
    printf("\n");
    return 0;
}



bool correct_key(string s) { // CHECKS  - KEY IS NOT NUMBER
    int i = 0;
    len = strlen(s);

    while (s[i] != '\0') {
        if(!isalpha(s[i])) {
            printf("Usage: ./substitution key\n");
            return false;
        } else if (len != 26) {
        printf("Key must contain 26 characters.\n"); // ERRORS WHEN PROVIDED LESS OR MORE THEN 26 ARGUMENTS
        return false;
        }
        i++;
    }
    return true;
}
