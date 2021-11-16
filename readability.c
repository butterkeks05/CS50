#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Prompt user for a text
    string text = get_string("Text: ");

    //Count letters
    int letter = count_letters(text);
    //Count words
    int word = count_words(text);
    //Count sentences
    int sentence = count_sentences(text);
    //Calculate L, S, Index
    float index = 0.0588 * (letter * 100) / (float) word - 0.296 * (sentence * 100) / (float) word - 15.8;
    
    //Print Grade
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 16 && index >= 1)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else
    {
        printf("Before Grade 1\n");
    }
}


//Count number of letters
int count_letters(string text)
{
    int letter = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(toupper(text[i])) != 0)
        {
            letter++;
        }
    }
    return letter;
}

//Count number of words
int count_words(string text)
{
    int word = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            word++;
        }
    }
    return word;
}

//Count number of sentences
int count_sentences(string text)
{
    int sentence = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence++;
        }
    }
    return sentence;
}