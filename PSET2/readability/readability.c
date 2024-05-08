#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // getting input from user
    string text = get_string("Please enter the text: ");

    float wordCount = 1, sentenceCount = 0, lettweCount = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        // Counting the words
        if (text[i] == 32)
        {
            wordCount++;
        }
        // Counting the sentences
        if (text[i] == 46 || text[i] == 63 || text[i] == 33)
        {
            sentenceCount++;
        }
        // Counting the letters
        if ((text[i] <= 90 && text[i] >= 65) || (text[i] <= 122 && text[i] >= 97))
        {
            lettweCount++;
        }
    }

    // Calculating the index wuth formula
    int index = round(0.0588 * (100 * (lettweCount / wordCount)) - 0.296 * (100 * (sentenceCount / wordCount)) - 15.8);

    // Output
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}