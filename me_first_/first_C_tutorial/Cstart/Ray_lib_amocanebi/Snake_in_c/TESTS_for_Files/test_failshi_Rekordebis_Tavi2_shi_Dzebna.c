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
    int kapi;
    char file_name[]  = {"test.txt"};
    char file_name2[]  = {"test2.txt"};
    double Data[1000];    // I'm interested in this information
    char junk1, junk2, junk3; // junk variables to avoid first two characters
    int lineNUMBER;
    int jami;

    FILE * file = fopen(file_name, "r"); // open file

    lineNUMBER = findLineNumber(file_name); /* ლაინების რაოდენობა რომ ვიცოდე */

    for(int i = 0; i <= lineNUMBER+1; i++) // each loop will read new line of file; i<3 for 3 lines in file
    {
      fscanf(file, "%s %s %s %lf\n", &junk1, &junk2,&junk3, &Data[i+1]); //store info in Data array
      printf("data [i+1] = %f; i = %d;i procent gayofa 6 ze = %d;\n", Data[i],i,i % 6); // print Data, just to check
    }

    for(int i = 0; i <= lineNUMBER; i++) // each loop will read new line of file; i<3 for 3 lines in file
    {
      printf("data [i+1] = %f;\n", Data[i+1]); // print Data, just to check
    }

    fclose(file);


    // თავიდან გავხსნა ფაილი და დავამატო T + rame (lineNUMBER)
    file = fopen("test.txt", "r"); // open file ჩაწერისთვის (პის ვუმატებ ყოველ მეორეს)
    for(int i = 0; i <= lineNUMBER+1; i++)
    {
      //
      if (i % 5 == 0){
        //
        printf("lineNUMBER %d\n",lineNUMBER);
        printf("dawere yoveli mexute %f\n",Data[i+1]);
        fprintf(file,"%d",Data[i+1]);
        kapi = i+1;
      }

    }
    printf("i (kapi)= %d\n",kapi);
    fclose(file);

}

/*
exla gavxsna chemi faili da amovikitxo rekordebi sanam ar damtavrdeba failis gaxsna nu sxva testi davwero?
Tu aq? es kai testia meroe testi xom ar shevqmna? sheidzleba. chai dalie moifiqre
unda gavaketo amokitxvis programa

*/
