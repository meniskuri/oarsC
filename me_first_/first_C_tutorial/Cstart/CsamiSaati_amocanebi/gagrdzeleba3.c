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

// გლობალური ცვლადები
#define MAX_LENGTH 100  // სტრინგების მასივის შესაქმნელად სიგრძე
#define NUM_STRINGS 100 // რამდენი სტრინგ ელემენტის შენახვა შეუძლია 2დ ერრეის

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

void civa_cxela_funqcia(double sacavi_statistikis[], int mtvleli, char sacavi_civa_cxela[][MAX_LENGTH], double secret)
{
  /*
  ფუნქცია. რომელსაც მივაწვდი სტატისტიკის მასივს
  გამოითვლის ჰოთ მინს და ქოლდ მაქს და დამიბეჭდვას
  მგონი არ იქნება რთული. მთავარია თქვა რა გინდა.
  ასევე ვაწვდი ცივა ცხელას მასივს საბეჭდად.
  */
  double coldMAX, hotMIN;
  double chemMAX, chemMIN;

  double sacavi_shida_stat_qveda[1000]; // საცავი ქვედა არეალში მოხვედრილი რიცხვებისთვის
  int k = 0; // ინდექსების მთვლელი ქვედა არეალისთვის
  double sacavi_shida_stat_zeda[1000]; // საცავი ზედა არეალში მოხვედრილი რიცხვებისთვის
  int p = 0; // ინდექსების მთვლელი ზედა არეალისთვის

  printf("საცნობი: %f - %s \n", sacavi_statistikis[mtvleli-1], sacavi_civa_cxela[mtvleli-1]);

  chemMAX = chemMIN = sacavi_statistikis[0];

  for (int i = 0; i < mtvleli; i++)
  {
    // მინ მაქს ის გამოთვლა მასივში
    if (chemMIN > sacavi_statistikis[i])
    chemMIN = sacavi_statistikis[i];
    if (chemMAX < sacavi_statistikis[i])
    chemMAX = sacavi_statistikis[i];

    // ქვედა მასივის შექმნა რომელსიც უნდა გამოვითვალო მინ მაქსი ასევე
    if (sacavi_statistikis[i] < secret)
    {
      sacavi_shida_stat_qveda[k] = sacavi_statistikis[i];
      // printf("sacavi_shida_stat_qveda[%d] = %f \n", k, sacavi_shida_stat_qveda[k]);
      k++;
    }
    // ქვედა მასივის შექმნა რომელსიც უნდა გამოვითვალო მინ მაქსი ასევე
    if (sacavi_statistikis[i] > secret)
    {
      sacavi_shida_stat_zeda[p] = sacavi_statistikis[i];
      // printf("sacavi_shida_stat_zeda[%d] = %f \n", p, sacavi_shida_stat_zeda[p]);
      p++;
    }

    // მაქს ქვედა არეალისთვის
    coldMAX = sacavi_shida_stat_qveda[0];
    for (int i = 0; i < k; i++)
    {
      if (coldMAX < sacavi_shida_stat_qveda[i])
      coldMAX = sacavi_shida_stat_qveda[i];
    }
    // მინ ზედა არეალისთვის
    hotMIN = sacavi_shida_stat_zeda[0];
    for (int i = 0; i < p; i++)
    {
      if (hotMIN > sacavi_shida_stat_zeda[i])
      hotMIN = sacavi_shida_stat_zeda[i];
    }
  }

  printf("(Man array) Minimum of array is : %f \n",chemMIN);
  printf("(Man array) Maximum of array is : %f \n",chemMAX);

  printf("(coldMAX) Maximum low diapason of array is : %f \n",coldMAX);
  printf("(hotMIN) Minumum hight diapason of array is : %f \n",hotMIN);
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

  double sacavi_statistikis[1000];                        // ვინახავ შეყვანილ რიცხვებს
  char sacavi_civa_cxela[NUM_STRINGS][MAX_LENGTH] = {""}; // ყოველ შეყვანილ რიცხვზე ვიწერ ცივია თუ ცხელია

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
      // printf("mixvedra = %f \n",mixvedra);

      if (mixvedra == secret)
      {
        printf("თამაში დამთვრებულია \n");
        break;
      } else if (mixvedra < secret) {
        strcpy(sacavi_civa_cxela[counter_while ],"cold");
      } else {
        strcpy(sacavi_civa_cxela[counter_while],"hot");
      }
      sacavi_statistikis[counter_while] = mixvedra;
      counter_while++;
    } else
    {
      printf("================================== \n");
      printf("ERROR - შეიყვანეთ რიცხვი \n");
    }
    counter_main++;

    printf("counter_main %d \n", counter_main);
    printf("counter_while = %d \n", counter_while);

    printf("========== \n");
    civa_cxela_funqcia(sacavi_statistikis, counter_while, sacavi_civa_cxela, secret);
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
