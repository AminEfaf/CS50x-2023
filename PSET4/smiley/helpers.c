#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (image[j][i].rgbtBlue == 0 && image[j][i].rgbtGreen == 0 && image[j][i].rgbtRed == 0)
            {
                image[j][i].rgbtBlue = 34;
                image[j][i].rgbtGreen = 35;
                image[j][i].rgbtRed = 88;
            }
        }
    }
}
