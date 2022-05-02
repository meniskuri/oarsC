// writing files

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int parametrebi_Brzanebis(char* brzaneba)
{
  /* ფუნქციის აღწერა:
  აბრუნებს ლოგიკურ ერთიანს თუ ჩარების მასივი შედგება მხოლოდ ციფრებისგან
  თუ არა აბრუნებს ლოგიკურ ნულიანს. ამოწმებს 2.3 ში წერტილ სიმბოლოს.
  არ დაუშვებს ორ წერტილს. წერტილით დაწყებას.
  */

  bool cifria = false; // თუ მასივში ციფრები წერია გათრუვდება
  int len, counter_par = 0, counter_mdzime = 0;

  len = strlen(brzaneba);
  // printf("len = %d \n",len);

  for (int i = 0; i <= len; i++)
  {
    // printf("brzaneba(d)[%d] %d %c \n",i,brzaneba[i],brzaneba[i]);
    // printf("i = %d \n", i);
    if (brzaneba[0] >= 48 && brzaneba[0] <= 57)
    {
      if ((brzaneba[i] >= 48 && brzaneba[i] <= 57 || brzaneba[i] == 46) || brzaneba[i] == 0)
      {
        cifria = true;
      } else
      {
        cifria = false;
        break;
      }
      if (brzaneba[i] == 46)
      {
        // ითვლის წერტილების რაოდენობას 3.3 ერთი წერტილია, 3.3.3 - ორი წერტილია. დაბლ რიცხვების შეყვანისთვის
        counter_mdzime++;
      }

      if (counter_mdzime > 1)
      {
        // printf("counter_mdzime %d \n", counter_mdzime);
        cifria = false;
      }
    }
    counter_par++;
  }
  // printf("counter_par = %d \n",counter_par);
  // printf("cifria = %d \n", cifria);
  return cifria;
}

// ფაილის ზომის გაგება
long int findSize(char file_name[])
{
  // opening the file in read mode
  FILE *fp = fopen(file_name, "r");

  // checking if the file exist or not
  if (fp == NULL) {
    printf("File Not Found!\n");
    return -1;
  }

  fseek(fp, 0L, SEEK_END); // ეს რას ნიშნავს? fseek() <<<<

  // calculating the size of the file
  long int res = ftell(fp); // ftell()

  // closing the file
  fclose(fp);

  return res;
}


int main()
{
  char brzaneba[51];
  gets(brzaneba);

  /* ფაილის ჩაწერა
  - r - read
  - w - write
  - a - append
  */
  FILE *chemiFailisPointeri;
  chemiFailisPointeri = fopen("tavi1.txt","a");

  fprintf(chemiFailisPointeri,"%s",brzaneba);
  fprintf(chemiFailisPointeri,"%s","\n");

  fclose(chemiFailisPointeri);


  // ფაილის შემოწმება და პირველი ამოკითხვა
  if( access("tavi1.txt", F_OK ) == 0 ) { // unistd.h - თუ არსებობს ეს ფაილი
    printf("file exists \n");
    // თუ არსებობს - ნახოს ზომა ფაილის
    char file_name[] = { "tavi1.txt" };
    long int res = findSize(file_name);
    if (res != -1)
    {
      printf("Size of the file is %ld bytes \n", res);
    }
  }


  // ფაილის წაკითხვა
  char line[100]; // აქ შევინახავ წაკითხულ ფაილიდან ინფორმაციას

  chemiFailisPointeri = fopen("tavi1.txt","r");

  fgets(line,100,chemiFailisPointeri); // პირველი ლაინი წაიკითხა
  fgets(line,100,chemiFailisPointeri); // მეორე ლაინი წაიკითხა 

  fclose(chemiFailisPointeri);

  printf("line = %s\n", line);
  return 0;
}

/*
ტუკუ ტუკუ
ჩუ ჩუუ
კუ კუუუ
ცოტა ვბუქსაობ... ))
გააგრძელეო. საღამომდე უნდა ეწვალო.
მერე უნდა ივარჯიშო. მერე ჭამო. და მერე ნახავ...
ან დახატო ან ჯოხები გააკეთო. ან უყურო რამეს. ან წაიკითხო.
ნება შენია. საღამოს. დილას ჩემი. ოკ?
ოკ..
*/
