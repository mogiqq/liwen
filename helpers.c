#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width-1-j];
            image[i][width-1-j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int blurRed;
    int blurBlue;
    int blurGreen;
    float counter;
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blurRed = 0;
            blurBlue = 0;
            blurGreen = 0;
            counter = 0.0;

            for (int n = -1; n < 2; n++)
            {
                if (i + n < 0 || i + n > height - 1)
                {
                    continue;
                }

                for (int m = -1; m < 2; m++)
                {
                    if (j + m < 0 || j + m > width - 1)
                    {
                        continue;
                    }

                    blurRed += image[i + n][j + m].rgbtRed;
                    blurBlue += image[i + n][j + m].rgbtBlue;
                    blurGreen += image[i + n][j + m].rgbtGreen;
                    counter++;
                }

            }

            temp[i][j].rgbtRed = round(blurRed / counter);
            temp[i][j].rgbtBlue = round(blurBlue / counter);
            temp[i][j].rgbtGreen = round(blurGreen / counter);

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
