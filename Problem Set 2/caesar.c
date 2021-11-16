#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Check Key
    if (argc == 2)
    {
        int nondigit = 0;
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (argv[1][i] < 48 || argv[1][i] > 57)
            {
                nondigit++;
            }
        }
        if (nondigit == 0)
        {
            //Get Key
            int k = atoi(argv[1]);
            //Prompt user for plaintext
            string plaintext = get_string("plaintext: ");
            //Print out ciphertext
            printf("ciphertext: ");
            for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                if (isupper(plaintext[i]) != 0)
                {
                    char cipher = (char)(((int) plaintext[i] + k - 64) % 26 + 64);
                    printf("%c", cipher);
                }
                else if (islower(plaintext[i]) != 0)
                {
                    char cipher = (char)(((int) plaintext[i] + k - 96) % 26 + 96);
                    printf("%c", cipher);
                }
                else
                {
                    printf("%c", plaintext[i]);
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
}