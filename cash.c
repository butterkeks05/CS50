#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Get user's owed change
    float ch;
    do
    {
        ch = get_float("Change owed: ");
    }
    while (ch < 0);
    //Convert dollars to cents
    int change = round(ch * 100);
    //Calculate number of coins
    int n;
    for (n = 0; change >= 1; n++)
    {
        if (change >= 25)
        {
            change = change - 25;
        }
        else if (change >= 10)
        {
            change = change - 10;
        }
        else if (change >= 5)
        {
            change = change - 5;
        }
        else
        {
            change = change - 1;
        }
    }
    //Print number of coins
    printf("%i\n", n);
}