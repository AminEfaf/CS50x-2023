#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    unsigned char *temp = malloc(512);

    char *fName = malloc(8);
    int img = 0;

    if (temp == NULL)
    {
        return 1;
    }

    if (file == NULL)
    {
        return 1;
    }

    if (fName == NULL)
    {
        return 1;
    }

    FILE *imgf = NULL;
    while (fread(temp, sizeof(unsigned char), 512, file))
    {
        if ((temp[0] == 0xff) && (temp[1] == 0xd8) && (temp[2] == 0xff) && ((temp[3] & 0xf0) == 0xe0))
        {
            sprintf(fName, "%03i.jpg", img);
            imgf = fopen(fName, "w");
            if (imgf == NULL)
            {
                return 1;
            }
            fwrite(temp, 1, 512, imgf);
            img++;
        }
        else if (img != 0)
        {
            imgf = fopen(fName, "a");
            if (imgf == NULL)
            {
                return 1;
            }
            fwrite(temp, 1, 512, imgf);
        }
        if (imgf != NULL)
        {
            fclose(imgf);
            imgf = NULL;
        }
    }
    free(temp);
    fclose(file);
    free(fName);
}