/*
    Filename:                       readabilty.c
    Dependencies:                   See the include.
    Author:                         Vinicius Baradel.
    github:                         https://github.com/Eusouovinii .
    Date :                          21/10/2023.

    File description:               Using the Coleman-Liau index, the following software classifies a text into education levels (Grades).

    IMPORTANT: This software may not work very well when using very small text.
    Change History
    1.0 21/10/2033 First Version
*/

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Pre-declarations of the functions.

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    // Average letters/sentences for each 100 words.

    float L = (count_letters(text) / (float) count_words(text)) * 100;
    float S = (count_sentences(text) / (float) count_words(text)) * 100;

    // Coleman-Liau Index.
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    if (index > 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
}

// Count the number of letters in the text.

int count_letters(string text)
{
    int countl = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalnum(text[i]))
        {
            countl++;
        }
    }
    return countl;
}

// Count the number of words in the text.

int count_words(string text)
{
    int countw = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]) && ((isalnum(text[i-1]) || ispunct(text[i-1])) && ((isalnum(text[i+1]) || ispunct(text[i+1])))))
        {
            countw++;
        }
    }
    return countw;
}

// Count the number of sentences in the text.

int count_sentences(string text)
{
    int counts = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || ((text[i]) == '?'))
        {
            counts++;
        }
    }
    return counts;
}
