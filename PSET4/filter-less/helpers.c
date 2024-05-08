#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gray;

    for (int row = 0; row < width; row++)
    {
        for (int column = 0; column < height; column++)
        {
            gray = round((image[row][column].rgbtRed + image[row][column].rgbtGreen + image[row][column].rgbtBlue) / 3.0);

            image[row][column].rgbtRed = gray;
            image[row][column].rgbtGreen = gray;
            image[row][column].rgbtBlue = gray;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            sepiaRed =
                round(.393 * image[row][column].rgbtRed + .769 * image[row][column].rgbtGreen + .189 * image[row][column].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            sepiaGreen =
                round(.349 * image[row][column].rgbtRed + .686 * image[row][column].rgbtGreen + .168 * image[row][column].rgbtBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            sepiaBlue =
                round(.272 * image[row][column].rgbtRed + .534 * image[row][column].rgbtGreen + .131 * image[row][column].rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[row][column].rgbtRed = sepiaRed;
            image[row][column].rgbtGreen = sepiaGreen;
            image[row][column].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE row[width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            row[j] = image[i][j];
        }
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = row[width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = row[width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = row[width - j - 1].rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE second[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            second[i][j] = image[i][j];
        }
    }

    int counter;
    float rSum, gSum, bSum;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            counter = 0;
            rSum = 0;
            gSum = 0;
            bSum = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (!((i + k < 0) || (i + k >= height) || (j + l < 0) || (j + l >= width)))
                    {
                        rSum += second[i + k][j + l].rgbtRed;
                        gSum += second[i + k][j + l].rgbtGreen;
                        bSum += second[i + k][j + l].rgbtBlue;
                        counter += 1;
                    }
                }
            }

            image[i][j].rgbtRed = (int) round(rSum / counter);
            image[i][j].rgbtGreen = (int) round(gSum / counter);
            image[i][j].rgbtBlue = (int) round(bSum / counter);
        }
    }
}
