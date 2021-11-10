#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user for height
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    
    for (int i = 0; i < h; i++)
    {
        // Print spaces
        for (int j = 0; j < h - i - 1; j++)
        {
            printf(" ");
        }
        //Print hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}
