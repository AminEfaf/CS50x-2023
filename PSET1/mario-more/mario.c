#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int height;
    do
    {
        height = get_int("Please enter the height: ");
    }
    while (height > 8 || height < 1);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (height - (i + 1)); j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
            if (k == i)
            {
                printf("  ");
                for (int l = 0; l <= i; l++)
                {
                    printf("#");
                }
            }
        }
        printf("\n");
    }
}
