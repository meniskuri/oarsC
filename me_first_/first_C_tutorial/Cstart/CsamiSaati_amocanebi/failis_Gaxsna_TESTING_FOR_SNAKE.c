/*
--- failis gaxsna
---- shignit chawera
----- snake V1-4 shi chamateba
---- mere gamortva da egetebi amokitxva shemowmebada ase shemdeg
----- ert ganzomilebiani matrica minda
davtesto es kodic 
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define SNAKE_LENGTH   1000000
int vailis_raodenoba[SNAKE_LENGTH];
int counter = 0;

/* ფაილში ლაინების რაოდენობის გაგება */
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

  printf("failshi lainebis raodenoba 11 = %d\n", count_lines);
  printf("ch = %d\n", chr);

  return count_lines;
}


int main()
{
  //
  char brzaneba[51];                   /* სტრინგი რომელიც შემყავს კლავიატურიდან */
  char file_name[]  = {"tavi2.txt"};   /* ფაილი რომელზეც ვმუშაობ - ვწერ ჯოხების ინფოს */

  // failis amokitxva da rammdenjer moxda amokitxva magis ricxvad chasma
  // mere struqturis saxit dayalibeba rac minda da egre chawera
  // gets it chavwero rame
  findLineNumber;

  while(true)
  {
    //
    vailis_raodenoba[counter] = counter + counter*13;


    /* ვაილიდან გამოსვლა */
    printf("=================== \n");
    printf("ვაილ ციკლი გაგრძელდეს? (y or n) \n");
    gets(brzaneba);

    if (brzaneba[0] == 110)
    {
      printf("break \n");
      break;
    } else
    {
      printf("ვაილი გრძელდება \n");
      // continue;
    }

    FILE *chemiFailisPointeri;
    chemiFailisPointeri = fopen(file_name,"a");

    fprintf(chemiFailisPointeri,"%s","////////////////////// \n");
    fprintf(chemiFailisPointeri,"%d",vailis_raodenoba[counter]);
    fprintf(chemiFailisPointeri,"%s","\n");
    fprintf(chemiFailisPointeri,"%d",counter);
    fprintf(chemiFailisPointeri,"%s","\n");
    fprintf(chemiFailisPointeri,"%s",brzaneba);
    fclose(chemiFailisPointeri);

    counter++;
  }


return 0;
}
