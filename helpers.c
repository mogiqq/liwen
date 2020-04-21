#include "helpers.h"
#include <math.h>

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
    int blurRed, blurBlue, blurGreen;
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
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    RGBTRIPLE temp[height][width];

    for  (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxRed = 0;
            int gxBlue = 0;
            int gxGreen = 0;
            int gyRed = 0;
            int gyBlue = 0;
            int gyGreen = 0;

            for (int x = 0; x < 3; x++)
            {
                if (i + x - 1 < 0 || i + x - 1 > height - 1)
                {
                    image[i][j].rgbtRed = 0;
                    image[i][j].rgbtBlue = 0;
                    image[i][j].rgbtGreen = 0;
                }
                for (int y = 0; y < 3; y++)
                {
                    if (j + y - 1 < 0 || j + y - 1> width - 1)
                    {
                        image[i][j].rgbtRed = 0;
                        image[i][j].rgbtBlue = 0;
                        image[i][j].rgbtGreen = 0;
                    }

                    gxRed += gx[x][y] * image[x][y].rgbtRed;
                    gxBlue += gx[x][y] * image[x][y].rgbtBlue;
                    gxGreen += gx[x][y] * image[x][y].rgbtGreen;
                    gyRed += gy[x][y] * image[x][y].rgbtRed;
                    gyBlue += gy[x][y] * image[x][y].rgbtBlue;
                    gyGreen += gy[x][y] * image[x][y].rgbtGreen;
                }
            }
            temp[i][j].rgbtRed = round((float)sqrt((gxRed * gxRed) + (gyRed * gyRed)));
            temp[i][j].rgbtBlue = round((float)sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue)));
            temp[i][j].rgbtGreen = round((float)sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen)));

            if (temp[i][j].rgbtRed > 255)
            {
                temp[i][j].rgbtRed = 255;
            }

            if (temp[i][j].rgbtBlue > 255)
            {
                temp[i][j].rgbtBlue = 255;
            }

            if (temp[i][j].rgbtGreen > 255)
            {
                temp[i][j].rgbtGreen = 255;
            }
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