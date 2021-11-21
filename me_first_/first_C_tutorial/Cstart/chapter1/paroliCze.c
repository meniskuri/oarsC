/*
############################################################################
Passwords must contain:
 - a minimum of 1 lower case letter [a-z] - ASCII ()
 - a minimum of 1 upper case letter [A-Z] - ASCII ()
 - a minimum of 1 numeric character [0-9] - ASCII ()
 - a minimum of 1 special character: ~`!@#$%^&*()-_+={}[]|\;:"<>,./? - ASCII ()
 - Passwords must be at least 6 characters in length, but can be much longer
############################################################################
*/

// TODO: კოდის გალამაზება. ფაილში ჩაწერა (ვაკეთებ)
// სამი მცდელობა განმეორებითზე თუარადა თავიდან (done)
// სისტემის დროის გაგება და ფაილში ჩაწერა (done)
// GUI (რეილიბით შესაძლოა გამოვიდეს)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LEN 150 // const int LEN = 150;

int counterPassword = 0;
int counter         = 0;
int counter2        = 0; // მეორე ვაილში. პაროლის გადამოწმებაზე სამი შემთხვევისთვის <<<
int counterertebi   = 0;

char brzaneba[20];           //
char paroliganmeorebiti[20]; // size ით შეიძლება ამათი გაკეთება
char parolifailshi[20];      // აქ ჩავწერ პაროლს და ფაილში ჩავწერ

bool amomgdebaPirveliNulis = false; // პაროლის დამთავრების პირობა
bool pirobadidi            = false;
bool pirobapatara          = false;
bool pirobacifri           = false;
bool pirobasigrze          = false;
bool pirobasimbolo         = false;
bool ganmeorebiti          = false;
bool amomgdebisaboloo      = false;
bool amogdeba_meorevaili   = false; // შეიძლება არ დამჭირდეს

// file Handling // declare a pointer of type file
FILE *pointeraFailis;


int main()
{
  // ფაილ ჰენდლინგ ///////////////////////////////////////////////
  pointeraFailis = fopen("parolebisSacavi.txt","w");

  // ჩაწერა

  if(pointeraFailis == NULL) //
  {
    printf("Error!");
    exit(1); // wtf
  }

  printf("Enter passwprd for file Write TESTING : ");
  gets(parolifailshi);

  fgets(parolifailshi,"%d",num); // ჩაწერა
  fclose(fptr);
  // არ არის დასრულებული. ცოტა უნდა დავისვენო :))

  // ფაილის დახურვა
  fclose(pointeraFailis);


  // დავბეჭდო საჭირო ინფორმაციები
  printf("\n");


  //////////////////////////////////////////////////////////////////
  while(true) // პირველი ვაილი
  {
    printf("########################### (პაროლის დაგენერირება) \n");
    printf("Passwords must contain:                             \n");
    printf(" - a minimum of 1 lower case letter [a-z]           \n");
    printf(" - a minimum of 1 upper case letter [A-Z]           \n");
    printf(" - a minimum of 1 numeric character [0-9]           \n");
    printf(" - a minimum of 1 special character                 \n");
    printf(" - Passwords must be at least 6 characters in length, but can be much longer\n");

    printf("Enter password (თქვი cntrl C და გამოდი): \n");

    gets(brzaneba);
    counterPassword = 0;

    printf("Password is %s\n", brzaneba);
    for (int i = 0; i <= sizeof(brzaneba); i++)
    {
      // პაროლის დამუშავება
      // პაროლის დაბეჭდვა/მთვლელის (counter) დაბეჭდვა
      // printf("ვბეჭდავ პაროლს %c, ვბეჭდავ მთვლელს (counter) %d\n",brzaneba[i],counter);
      // პაროლის რიცხვის მთველი და პირობა რომელიც შეამოწმებს რომ 6 ზე ნაკლები არ შეიძლება
      // თუ პაროლი 0 ის ტოლი არ არის. მაშინ/დავითვალოთ რამდენი სიმბოლოსგან შედგება
      if (brzaneba[i] != 0 && amomgdebaPirveliNulis == false)
      {
        counterPassword ++;
        // printf("პაროლის სიგრზე (counterPassword) is %d\n",counterPassword);

        if (counterPassword >= 6)
        {
          pirobasigrze = true;
        }

      } else if (brzaneba[i] == 0 && amomgdebaPirveliNulis == false) {
        // როცა მასივში იპოვა ნული
        // printf(" \n");
        // printf("ნულშიჩავერთე\n");
        amomgdebaPirveliNulis = true;
      }

      // upper case letter(s) [A-Z] 65-90
      if (brzaneba[i] >= 65 && brzaneba[i] <= 90 && amomgdebaPirveliNulis == false) // სიმბოლოების შედარება. მათი ასკი კოდები. :)
      {
        pirobadidi = true;
      }

      // lower case letter(s) [a-z] 97-122
      if (brzaneba[i] >= 97 && brzaneba[i] <= 122 && amomgdebaPirveliNulis == false) // სიმბოლოების შედარება. მათი ასკი კოდები. :)
      {
        pirobapatara = true;
      }

      // a minimum of 1 numeric character [0-9] - 48-57
      if (brzaneba[i] >= 48 && brzaneba[i] <= 57 && amomgdebaPirveliNulis == false) // სიმბოლოების შედარება. მათი ასკი კოდები. :)
      {
        pirobacifri = true;
      }

      // a minimum of 1 special character: ~`!@#$%^&*()-_+={}[]|\;:"<>,./? 58-64 32-47 91-96 123-126 (32 Space)
      if (((brzaneba[i] >= 58 && brzaneba[i] <= 64) || (brzaneba[i] >= 32 && brzaneba[i] <= 47) || (brzaneba[i] >= 91 && brzaneba[i] <= 96) || (brzaneba[i] >= 123 && brzaneba[i] <= 126))
       && amomgdebaPirveliNulis == false) // სიმბოლოების შედარება. მათი ასკი კოდები. :)
      {
        pirobasimbolo = true;
      }

    } // ფორის დამთავრება

    printf(" \n");
    printf("პირობების შემოწმება: \n");
    printf(" \n");
    printf("Upper case letter [A-Z]: %d\n",pirobadidi);
    printf("Lower case letter [a-z]: %d\n",pirobapatara);
    printf("Numeric character [0-9]: %d\n",pirobacifri);
    printf("Special character: %d\n",pirobasimbolo);
    printf("Passwords must be at least 6 characters in length: %d\n",pirobasigrze);

    /////////////////////////////////////////////////////////////////////
    // time output //////////////////////////////////////////////////////
    char buf[LEN];
    time_t curtime;
    struct tm *loc_time;

    //Getting current time of system
    curtime = time (NULL);

    // Converting current time to local time
    loc_time = localtime (&curtime);

    // Displaying date and time in standard format
    // printf("%s", asctime (loc_time));

    // strftime (buf, LEN, "Today is %A, %b %d.\n", loc_time);
    // fputs (buf, stdout);
    // strftime (buf, LEN, "Time is %I:%M %p.\n", loc_time);
    // fputs (buf, stdout);
    /////////////////////////////////////////////////////////////////////

    if (pirobadidi && pirobapatara && pirobacifri && pirobasimbolo && pirobasigrze)
    {
      printf(" \n");
      printf("პირობები შესრულდა, შეიყვანეთ განმეორებით პაროლი\n");

      while(true)
      {
        printf(" \n");
        printf("Enter password for validation (თქვი cntrl C და გამოდი): \n");
        gets(paroliganmeorebiti);
        printf(" \n");

        for (int j = 0; j <= sizeof(brzaneba); j++)
        {
          // პაროლების შედარების ბეჭდვა
          // printf("paroliganmeorebiti %d parolimtavari %d\n", paroliganmeorebiti[j],brzaneba[j]);

          if (brzaneba[j] != 0 && (brzaneba[j] == paroliganmeorebiti[j]))
          {
            // printf("1 \n");
            ganmeorebiti = true;
            counterertebi++;
          } else {
            // printf("0 \n");
            // პირობა რომ თუ ბოლო ნულია მაგ შემთხვევაში განმეორებითი არ გააფალსოს counterPassword
            if (counterPassword == counterertebi)
            {
              ganmeorebiti = true;
            } else {
              ganmeorebiti = false;
            }

            break; // განმეორებითი პაროლის შეყვანის დროს თუ არ მოხდა დამთხვევა ამოაგდებს ფორს
          }

        } // შიდა ფორის დასასრული

        counter2++; //

        if (ganmeorebiti == true)
        {
          //
          printf("You have strong password \n");

          amomgdebisaboloo = true;

          break; // ამოაგდებს მეორე ვაილს

        } else if (ganmeorebiti == false && counter2 <= 2) {
          //
          printf("Try again. you have left %d try \n", 3 - counter2);
        } else {
          // თუ სამჯერ ვერ შეიყვანე. პირველ ვაილში გადაგაგდოს
          printf("თავიდან შეიყვანეთ მთავარი პაროლი \n");
          amogdeba_meorevaili = true; // ჯერ არ ვიყენებ <<<<<<<<<<<<
          break; //
        }

      } // შიდა ვაილის დასასრული
    } // შიდა იფის დასასრული

    // Displaying date and time in standard format
    printf("%s", asctime (loc_time));

    if (amomgdebisaboloo == true) break;

    counter++; // რამდენჯერ მოხდა პაროლის შეყვანა

    amomgdebaPirveliNulis = false; // ფორის დამთავრების მერე. ახალი პაროლი შეგყავს. საჭიროა ამის გაფალსება.
    pirobadidi            = false;
    pirobapatara          = false;
    pirobacifri           = false;
    pirobasimbolo         = false;
    pirobasigrze          = false;
  } // ვაილის დამთავრება

  printf("THE END \n"); // შეიცვლება ადგილი

  // ი/ო //




  return 0;
}
