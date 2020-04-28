#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // remind the user of correct usage if your program is not executed with exactly one command-line argument
    if (argc < 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    //remember filename
    char *infile = argv[1];

    // *file declare a pointer of type file.
    // This declaration is needed for communication between the file and the program.
    FILE *file = fopen(infile, "r");

    //If the forensic image cannot be opened for reading, your program should inform the user as much
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", infile);
        return 2;
    }

    unsigned char buffer[512]; //512 bytes for a block
    int imagecount = 0; //count number of jpg file
    char filename[8]; // every JPG file requires 7 chars + null terminator = 8
    FILE *img;
    bool open;

    while (fread(buffer, sizeof(char), 512, file))
    {

        if (feof(file))
        {
            break;
        }

        // check if bytes are 0xff 0xd8 0xff 0xe0-0xef
        else if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //create string of ###.jpg for the first image
            if (imagecount == 0)
            {
                sprintf(filename, "%03i.jpg", imagecount);
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
                open = true;
                
            }
            
            // close previouse file if another jpg has been found
            fclose(img);
            sprintf(filename, "%03i.jpg", imagecount);
            img = fopen(filename, "w");
            fwrite(buffer, 512, 1, img);
            open = true;
            imagecount++;
        }
                    
        // continue writing if the file is opening
        else if (open == true)
        {
            fwrite(buffer, 512, 1, img);
        }

    }
    fclose(img);
    fclose(file);
}
