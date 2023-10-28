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



int main()
{
    int kapi = 0;
    char file_name[]  = {"tavi2.txt"};
    double Data[1000],Data2[1000];    // I'm interested in this information
    int rekordi;
    char junk1[80], junk2[80], junk3[80], junk4[80]; // junk variables to avoid first two characters
    int lineNUMBER;
    int jami;

    FILE * file = fopen(file_name, "r"); // open file

    lineNUMBER = findLineNumber(file_name); /* ლაინების რაოდენობა რომ ვიცოდე */

    for(int i = 0; i <= lineNUMBER; i++) // each loop will read new line of file; i<3 for 3 lines in file
    {
      if (i == 0 || i % 6 == 0)
      {
        // sataurs sxva wesit viwer failshi
        fscanf(file, "%s %s %s %s %lf\n", &junk1, &junk2, &junk3,&junk4, &Data[i+1]);
      } else {
        // masivis shevseba sachiro infoti
        fscanf(file, "%s %s %lf\n", &junk1, &junk2, &Data[i+1]);
      }

      // fscanf(file, "%s %s %lf\n", &junk1, &junk2, &Data[i+1]); //store info in Data array
      // printf("data [i+1] = %f; i = %d;i procent gayofa 4 ze = %d;\n", Data[i+1],i,i % 4); // print Data, just to check
    }
    fclose(file);

    printf("//////////////////// \n");
    // data2 masivis shevseba rekordebit da maximumis modzebna
    for(int i = 0; i <= lineNUMBER+1; i++)
    {
      if (i!= 0 && (i % (5)== 0))
      {
        // rekordebs viwer pirveli masividan meoreshi
        Data2[i] = Data[i+kapi];
        printf("aq var kapi = %d\n",kapi);
        kapi++;
      }
      printf("Data2 = %lf; i = %d; Data = %lf\n",Data2[i],i, Data[i]);
    }
    // max number from Data2 masivi
    for (int i = 1; i < lineNUMBER+1; ++i) {

      if (Data2[0] < Data2[i]) {
        Data2[0] = Data2[i];
      }
    }
    int test;
    test = Data2[0];
    printf("Largest element = %d\n", Data2[0]);
    printf("Largest element = %lf\n", test);

    printf("//////////////////// \n");
    printf("data 2 davbechdi ////// \n");
    for(int i = 0; i <= lineNUMBER+1; i++)
    {
      //

    }
}

/*
snake_1_4 shi gadavitano cvlilebebi.
mere am kods mivxedo.
1. shevaqmnevino shemowmeba failis
2. tu aris amoikitxos.gaigos zoma. da chaamatos axali tavi. bolos isev amoikitxos da modzebnos udidesi elementi.
3. tu ar aris sheqmnas da mere amoikitxos.
*/
