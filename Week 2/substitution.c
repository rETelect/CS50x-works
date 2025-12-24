#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];


    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }


    for (int i = 0; i < 26; i++)
    {

        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }


        for (int j = i + 1; j < 26; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }


    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char current_char = plaintext[i];

        if (isupper(current_char))
        {

            int index = current_char - 'A';

            printf("%c", toupper(key[index]));
        }
        else if (islower(current_char))
        {

            int index = current_char - 'a';

            printf("%c", tolower(key[index]));
        }
        else
        {

            printf("%c", current_char);
        }
    }

    printf("\n");
    return 0; 
}
