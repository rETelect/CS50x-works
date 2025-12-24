
#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            int average = round((red + green + blue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
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
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumRed = 0, sumGreen = 0, sumBlue = 0;
            int counter = 0;

            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    int currentRow = i + r;
                    int currentCol = j + c;

                    if (currentRow >= 0 && currentRow < height && currentCol >= 0 && currentCol < width)
                    {
                        sumRed += copy[currentRow][currentCol].rgbtRed;
                        sumGreen += copy[currentRow][currentCol].rgbtGreen;
                        sumBlue += copy[currentRow][currentCol].rgbtBlue;
                        counter++;
                    }
                }
            }

            image[i][j].rgbtRed = round(sumRed / counter);
            image[i][j].rgbtGreen = round(sumGreen / counter);
            image[i][j].rgbtBlue = round(sumBlue / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Gx_red = 0, Gx_green = 0, Gx_blue = 0;
            float Gy_red = 0, Gy_green = 0, Gy_blue = 0;

            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    int currentRow = i + r;
                    int currentCol = j + c;

                    if (currentRow < 0 || currentRow >= height || currentCol < 0 || currentCol >= width)
                    {
                        continue;
                    }

                    Gx_red += copy[currentRow][currentCol].rgbtRed * Gx[r + 1][c + 1];
                    Gx_green += copy[currentRow][currentCol].rgbtGreen * Gx[r + 1][c + 1];
                    Gx_blue += copy[currentRow][currentCol].rgbtBlue * Gx[r + 1][c + 1];

                    Gy_red += copy[currentRow][currentCol].rgbtRed * Gy[r + 1][c + 1];
                    Gy_green += copy[currentRow][currentCol].rgbtGreen * Gy[r + 1][c + 1];
                    Gy_blue += copy[currentRow][currentCol].rgbtBlue * Gy[r + 1][c + 1];
                }
            }

            int finalRed = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int finalGreen = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int finalBlue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            if (finalRed > 255) finalRed = 255;
            if (finalGreen > 255) finalGreen = 255;
            if (finalBlue > 255) finalBlue = 255;

            image[i][j].rgbtRed = finalRed;
            image[i][j].rgbtGreen = finalGreen;
            image[i][j].rgbtBlue = finalBlue;
        }
    }
    return;
}
