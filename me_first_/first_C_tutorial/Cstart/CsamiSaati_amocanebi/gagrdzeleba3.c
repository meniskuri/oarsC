// gagrdzeleba 3 - struct - ebidan - video განვაგრძო - Struct_totirial შია struct ების მაგალითები
// Buildgin a Guessing Game (loop ებით) ვნახოთ რას აკეთებს და მეთვითნ გავაკეთო

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
  printf("len = %d \n",len);

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


int main()
{
  double secret = 1783;  // გამოსაცნობი რიცხვი
  double mixvedra;       // კლავიატურიდან შეყვანილი რიცხვს სადაც ჩავწე და შევადარებ secret-ს

  char brzaneba[51];     // სტრინგი რომელიც შემყავს კლავიატურიდან ვამოწმებ რიცხვია თუა არა და ვანიჭებ mixvedra-ს
  bool brzanebaChek;     //  თუ ფუნქციამ დააბრუნა 1 ანუ რიცხვი შევიყვანეთ თუარადა დააბრუნებს 0 ს
  char *eptr;            // ??? string pointer რაც გადაყავს დაბლში (მგონი)
  int counter_while = 0; // ვაილის მთვლელი. როცა შეგვყავს რიცხვი. სხვა შემთხვევებს არ ავღრიცხავ
  int counter_main  = 0;

  double sacavi_statistikis[10000];

  printf("================================== \n");
  printf("ვთამაშობთ გამოცნობანას - წინასწარმეტყველების თამაში \n");
  printf("შეყვანილია საიდუმლო secret ცვლადი, რომელიც უნდა გამოვიცნოთ \n");

  while (true)
  {
    printf("================================== \n");
    printf("შეიყვანეთ ნებისმიერი რიცხვი \n");
    gets(brzaneba);
    brzanebaChek = parametrebi_Brzanebis(brzaneba);

    if (brzanebaChek == 1)
    {
      mixvedra = strtod(brzaneba, &eptr);
      printf("mixvedra = %f \n",mixvedra);

      if (mixvedra == secret)
      {
        printf("თამაში დამთვრებულია \n");
        break;
      } else if (mixvedra < secret) {
        printf("========== \n");
        printf("ცივა \n");
      } else {
        printf("========== \n");
        printf("ცხელა \n");
      }
      counter_while++;

    } else
    {
      printf("================================== \n");
      printf("ERROR - შეიყვანეთ რიცხვი \n");
    }
    counter_main++;
    printf("counter_main %d \n", counter_main);
    printf("counter_while = %d \n", counter_while);
    sacavi_statistikis[counter_while] = mixvedra;
    printf("sacavi_statistikis[%d] = %f \n", counter_while, sacavi_statistikis[counter_while]);
    printf("==========++++++++++ \n");
    // printf("strlen(sacavi_statistikis) = %d \n",strlen(sacavi_statistikis));

    for (int i = 1; i < 20; i++)
    {
      printf("sacavi_statistikis[i] %f \n", sacavi_statistikis[i]);
    }

  }
  return 0;
}


/*
არჩილმა დამირეკა და მითხრა რომ ნუ აძინებ ტვინსო
როცა ტვინი არ გყავს დაძინებული მაშინ გამოგივა ყველაფერიო
ნუ გუდავ ტვინსო. ისე როცა არ გყავს გაგაუდული ტვინი.. ტვინი თვითონ ვერ გაჩერდებაო

ვბრაზობ რომ ნელა მივდივარ წინ.
გაიხსენე ლაი. ნელა სიარულით შორს წავა.
ასე რომ იარე თუნდაც ნელა. მაგრამ იარე.
ბოლოს ფოფხვაც რომ მოგწიოს გაიხსენე სიზმარი..
რომ უნდა იარო..
*/
