/*
- testi snake_1_4 ისთვის
- - ფაილში სადაც ინახება რეკორდების ბაზა უნდა შევიდეს და მოდძებნოს ის ადგილები სადაც რეკორდები წერია/
- - - უნდა შექმნას სხვა მასივი და მასში ჩაწეროს
- - შემდეგ კიდევ ბოლო პოზიციაზე დაწეროს რეკორდის რიცხვი
- კარგი იქნება (თუ დაწერს რეკორდს და მიყწერს ნუმბერ აიდის და სახელს ვისი გაკეთებული იყო რეკორდი)
- - (ჩაწერის ფუნქცია აღსადგენი მექნება მერე)

... ES KODI KARGAD GAVARCHIO T S
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

/* ფაილში კონკრეტული სახელების მოძებნა რეკორდების სიისთვის ფუნქცია */
int findRecordsINFile(char file_name[])
{
  // ფუნქციის აღწერა





}




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
  printf("ch = %c\n", chr);
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

/* ფაილის ზომის გაგება */
long int findSize(char file_name[])
{
  // opening the file in read mode
  FILE *fp = fopen(file_name, "r");
  // checking if the file exist or not
  if (fp == NULL) {
    printf("File Not Found!\n");
    return -1;
  }
  // calculating the size of the file
  fseek(fp, 0L, SEEK_END); // ეს რას ნიშნავს? fseek() <<<<
  long int res = ftell(fp); // ftell()
  // closing the file
  fclose(fp);

  return res;
}




int main()
{
  char brzaneba[51];                   /* სტრინგი რომელიც შემყავს კლავიატურიდან */
  char file_name[]  = {"tavi2.txt"};   /* ფაილი რომელზეც ვმუშაობ - ვწერ ჯოხების ინფოს */
  int lineNUMBER;                      /* სამუშაო tavi1.txt ფაილში ლაინების რაოდენობა */
  int result;                          /* მელონ ის შესამოწმებლადს result = strcmp(str1, str2);*/
  char str1[] = {"MELON"};

  /* ფაილის შემოწმება და პირველი ამოკითხვა */
  if( access(file_name, F_OK ) == 0 )
  {
    printf("file exists \n");
    lineNUMBER = findLineNumber(file_name); /* ლაინების რაოდენობა რომ ვიცოდე */
    printf("lineNUMBER = %d\n", lineNUMBER);
    long int res = findSize(file_name);
    if (res != -1)
    {
      printf("Size of the file is %ld bytes \n", res);
    }
  } else {
    printf("ფაილი არ არსებობს \n");
    // lineNUMBER = findLineNumber(file_name); /* ლაინების რაოდენობა რომ ვიცოდე */
    // printf("lineNUMBER = %d\n", lineNUMBER);
  }

  printf("test for snake_1_4 \n");

  return 0;
}
