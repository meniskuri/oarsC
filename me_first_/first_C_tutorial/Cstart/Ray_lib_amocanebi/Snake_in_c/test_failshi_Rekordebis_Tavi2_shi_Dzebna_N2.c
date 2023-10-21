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
    double Data[1000];    // I'm interested in this information
    char junk1, junk2, junk3; // junk variables to avoid first two characters
    int lineNUMBER;
    int jami;

    FILE * file = fopen(file_name, "r"); // open file

    lineNUMBER = findLineNumber(file_name); /* ლაინების რაოდენობა რომ ვიცოდე */

    for(int i = 0; i <= lineNUMBER; i++) // each loop will read new line of file; i<3 for 3 lines in file
    {
        //
        /*if (lineNUMBER % 2 == 0 && lineNUMBER != 0){
        fscanf(file, "%s %s %lf\n", &junk1, &junk2, &Data[i]); //store info in Data array
        printf("%f\n", Data[i]); // print Data, just to check
      }*/
      fscanf(file, "%s %s %s %lf\n", &junk1, &junk2, &junk3, &Data[i]); //store info in Data array
      printf("data [i] = %f; i = %d;i procent gayofa 5 ze = %d;\n", Data[i],i,i % 5); // print Data, just to check
    }
    fclose(file);

    // თავიდან გავხსნა ფაილი და დავამატო T + rame (lineNUMBER)
    file = fopen("test.txt", "a"); // open file ჩაწერისთვის (პის ვუმატებ ყოველ მეორეს)
    for(int i = 0; i <= lineNUMBER; i++)
    {
      //
      printf("dawere data i %f\n",Data[i]);
      if (i % 2 == 0){
        //
        // fscanf(file, "%s %s %lf\n", &junk1, &junk2, &Data[i]);
        printf("dawere data %f\n",Data[i]);
      }

    }
    fclose(file);

}

/*
exla gavxsna chemi faili da amovikitxo rekordebi sanam ar damtavrdeba failis gaxsna nu sxva testi davwero?
Tu aq? es kai testia meroe testi xom ar shevqmna? sheidzleba. chai dalie moifiqre

*/
