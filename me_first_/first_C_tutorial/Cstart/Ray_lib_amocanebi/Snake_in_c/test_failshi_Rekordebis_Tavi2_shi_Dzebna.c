#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findLineNumber(char file_name[])
{
  /* extract character from file and store in chr
  ვიყენებ /n ების დასათვლელად. ლაინების რაოდენობა რომ ვიცოდე
  */
  FILE *fileptr;
  char chr;
  int count_lines = 0; // ლაინების რაოდენობა

  fileptr = fopen(file_name, "r");
  chr = getc(fileptr);
  while (chr != EOF)
  {
    //Count whenever new line is encountered
    if (chr == '\n')
    {
      count_lines = count_lines + 1;
    }
    //take next character from file.
    chr = getc(fileptr);
  }
  fclose(fileptr); //close file.

  printf("failshi lainebis raodenoba = %d\n", count_lines);
  printf("ch = %d\n", chr);

  return count_lines;
}

void main()
{
    char file_name[]  = {"test.txt"};
    double Data[3];    // I'm interested in this information
    char junk1, junk2; // junk variables to avoid first two characters
    int lineNUMBER;
    int jami;

    FILE * file = fopen("test.txt", "r"); // open file

    lineNUMBER = findLineNumber(file_name); /* ლაინების რაოდენობა რომ ვიცოდე */

    for(int i = 0; i < lineNUMBER; i++) // each loop will read new line of file; i<3 for 3 lines in file
    {
        fscanf(file, "%s %s %lf\n", &junk1, &junk2, &Data[i]); //store info in Data array
        printf("%f\n", Data[i]); // print Data, just to check
    }
    fclose(file);

    int Nx; // store data in respective variables
    int Ny;
    double T;

    Nx = Data[0];
    Ny = Data[1];
    T  = Data[2];

    printf("Value of Nx is %d\n", Nx); // Print values to check
    printf("Value of Ny is %d\n", Ny);
    printf("Value of T is %f\n", T);
    fclose(file);

    // თავიდან გავხსნა ფაილი და დავამატო T + rame (lineNUMBER)
}
