#include <cs50.h>
#include <stdio.h>

int main(void)
{
    while (1)
    {
        // Prompt for start size
        int startSize;

        startSize = get_int("Please enter the start size: ");

        if (startSize >= 9)
        {
            while (1)
            {
                // Prompt for end size
                int endSize;

                endSize = get_int("Please enter the end size: ");

                if (endSize >= startSize)
                {
                    // Calculate number of years until we reach threshold
                    int years = 0;
                    while (startSize < endSize)
                    {
                        startSize = startSize + ((startSize / 3) - (startSize / 4));
                        years++;
                    }

                    // Print number of years
                    printf("Years: %i\n", years);
                    break;
                }
            };
            break;
        }
    };
}