#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!((argv[1][i] <= 90 && argv[1][i] >= 65) || (argv[1][i] <= 122 && argv[1][i] >= 97)))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        for (int j = 0; j < strlen(argv[1]); j++)
        {
            if ((toupper(argv[1][i]) == toupper(argv[1][j])) && (i != j))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    string message = get_string("plaintext:  ");

    char final;

    printf("ciphertext: ");

    for (int i = 0; i < strlen(message); i++)
    {

        if (((message[i] <= 90 && message[i] >= 65) || (message[i] <= 122 && message[i] >= 97)) && (isupper(message[i])))
        {
            final = toupper(argv[1][message[i] - 65]);
        }
        else if (((message[i] <= 90 && message[i] >= 65) || (message[i] <= 122 && message[i] >= 97)) && (islower(message[i])))
        {
            final = tolower(argv[1][message[i] - 97]);
        }
        else
        {
            final = message[i];
        }

        printf("%c", final);
    }
    printf("\n");
    return 0;
}
