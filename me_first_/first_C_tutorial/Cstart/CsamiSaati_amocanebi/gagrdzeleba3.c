// gagrdzeleba 3 - 2D arrays nested loops

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

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

struct Books {
  char  title[50];
  char  author[50];
  char  subject[100];
  int   book_id;
};

int main()
{

  return 0;
}

/*
ტუკუ ტუკუ
ჩუ ჩუუ
კუ კუუუ
*/
