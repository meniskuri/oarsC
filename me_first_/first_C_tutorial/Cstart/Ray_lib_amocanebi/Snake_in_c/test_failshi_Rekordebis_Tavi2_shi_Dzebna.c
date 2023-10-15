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

    for(int i = 0; i <= lineNUMBER; i++) // each loop will read new line of file; i<3 for 3 lines in file
    {
        //
        /*if (lineNUMBER % 2 == 0 && lineNUMBER != 0){
        fscanf(file, "%s %s %lf\n", &junk1, &junk2, &Data[i]); //store info in Data array
        printf("%f\n", Data[i]); // print Data, just to check
      }*/
      fscanf(file, "%s %s %lf\n", &junk1, &junk2, &Data[i]); //store info in Data array
      printf("data [i] = %f; i = %d;i % 2 = %d;\n", Data[i],i,i % 2); // print Data, just to check
    }
    fclose(file);

    int GIO; // store data in respective variables
    int VASO;
    double TATA;
    double KETO;

    GIO = Data[0];
    VASO = Data[1];
    TATA = Data[2];
    KETO = Data[3];

    printf("Value of GIO is %d\n", GIO); // Print values to check
    printf("Value of VASO is %d\n", VASO);
    printf("Value of TATA is %f\n", TATA);
    printf("Value of KETO is %f\n", KETO);
    fclose(file);

    // თავიდან გავხსნა ფაილი და დავამატო T + rame (lineNUMBER)
}
