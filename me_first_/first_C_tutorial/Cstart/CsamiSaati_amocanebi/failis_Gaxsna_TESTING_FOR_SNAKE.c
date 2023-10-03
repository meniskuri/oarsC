/*
--- failis gaxsna
---- shignit chawera
----- snake V1-4 shi chamateba
---- mere gamortva da egetebi amokitxva shemowmebada ase shemdeg
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


//
int main()
{
  //
  char brzaneba[51];                   /* სტრინგი რომელიც შემყავს კლავიატურიდან */
  char file_name[]  = {"tavi2.txt"};   /* ფაილი რომელზეც ვმუშაობ - ვწერ ჯოხების ინფოს */

  /* ფაილის შექმნა და ჩაწერა */
  FILE *chemiFailisPointeri;
  chemiFailisPointeri = fopen(file_name,"a");

  fprintf(chemiFailisPointeri,"%s","////////////////////// \n");

  fclose(chemiFailisPointeri);

return 0;
}
