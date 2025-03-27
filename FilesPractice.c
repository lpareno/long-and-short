#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    int amtLong = 0;
    int amtShort = 0;
    // make sure that the user puts one file to read, and two files to write
    if(argc < 4){
        printf("Error: Need 1 Read File, and 2 Write Files\n");
        exit(1);
    }

    // open files and read/write them
    FILE *in = fopen(argv[1], "r");
    FILE *shortLines = fopen(argv[2], "w");
    FILE *longLines = fopen(argv[3], "w");

    // end program if file can't be read
    if(!in || !shortLines || !longLines){
        printf("Can't open one or more files for reading\n");
        exit(1);
    }

    // print lines with given string
    char line[255];
    while( fgets(line, 255, in) != NULL){

        // short lines are made uppercase and put in short.txt
        if(strlen(line) - 1 < 20){
            for(int i = 0; line[i] != '\0'; i++){
                line[i] = toupper(line[i]);
            }
            fprintf(shortLines, "%s", line);
            amtShort++;
        }
        
        // long lines are made lowercase and put in long.txt
        else{
            for(int i = 0; line[i] != '\0'; i++){
                line[i] = tolower(line[i]);
            }
            fprintf(longLines, "%s", line);
            amtLong++;
        }
    }

    // print results and close files
    printf("\n");
    printf("%d lines written to %s\n", amtShort, argv[2]);
    printf("%d lines written to %s\n", amtLong, argv[3]);
    fclose(in);
    fclose(longLines);
    fclose(shortLines);
}