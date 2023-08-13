#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <math.h>
#include <conio.h>

// fuqnciebi
int parametrebi_Brzanebis(char* brzaneba) // დასამთავრებელია. დაამთავრე და მერე მიწერე ლარას
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
    printf("brzaneba(d)[%d] %d %c \n",i,brzaneba[i],brzaneba[i]);
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
  printf("cifria = %d \n", cifria);
  return cifria;
}

double add_mimateba(double x, double y)
{ // 1
  double c;
  c=x+y;
  printf("\n The sum is = %f \n\n",c);
}

double sub_gamokleba(double d, double e)
{ // 2
  double f;
  f=d-e;
  printf("\n The subtraction is = %f \n\n",f);
}

double mult_gamravleba(double x, double y)
{ // 3
  double i;
  i=x*y;
  printf("\n The multiplication is = %f \n\n",i);
}

double div_gayofa(double x, double y)
{ // 4
  double m;
  m=x/y;
  printf("\n Divison is = %.3lf \n\n",m);
}

double sq_kvadrati(double x, double y)
{ // 5
  double sqr1,sqr2;
  sqr1=x*x;
  sqr2=y*y;
  printf("\n Square of %f is = %f \n",x,sqr1);
  printf("\n Square of %f is = %f \n\n",y,sqr2);
}

double cube_kubi(double x, double y)
{ // 6
  double cub1,cub2;
  cub1=x*x*x;
  cub2=y*y*y;
  printf("\n Cube of %f is = %f \n",x,cub1);
  printf("\n Cube of %f is = %f \n\n",y,cub2);
}

double percentage(int x,int y) // ჯერ არ დამიმატებია
{ // 7
  float per1,per2;
  per1=100*x/y;
  per2=100*y/x;
  printf("\n%d is %.3f %c of %d\n",x,per1,37,y);//% sign using ASCII code 37
  printf("\n%d is %.3f %% of %d\n\n",y,per2,x);//% sign by traditional %% code
}



int prizma = 0;
int kutxe  = 3;
char brzaneba[51];
char gamortva[51];
double ricxvi1;
double ricxvi2;
double pasuxi;         // კალკულატორის პასუხი
int indikatori;        // 1,2,3, მიმატება გამოკლება კუბი
double result;         // brzaneba -ს გადაყვანა დაბლში სტრინგიდან strtod
char value[51];        // brzaneba -ს გადაკოპირება strcpy ით. პირდაპირ brzaneba ც რომ იყოს შეიძლება
char *eptr;            // ??? string pointer რაც გადაყავს დაბლში (მგონი)
char gamortva[51];     // ვაილ 1 დან გასვლა არ გამოსვლა კითხვა
int counter_while = 0; // ვაილ 1 ციკლის მთვლელი
bool ricxvi1Chek;
bool ricxvi2Chek;

int main()
{
  printf("drois borbali %d\n",prizma);
  printf("gamarjoba samyaro\n");
  printf("სევდა --> სინათლის სხივი --> სიყვარული ---> infinit 1.8T WW3 - new world (mission)\n");
  for (int i = 0; i <= kutxe; i++)
  {
    //unda davxato samkutxedi
    if (i == 0)
    {
      printf("            /\\\n");
      printf("           /  \\\n");
      printf("სევდა --> /void\\ სიყვარული ---> \n");
      printf("         /______\\\n");
      prizma++;
      printf("drois borbali %d\n",prizma);
    }

    if (i == 1)
    {
      printf("          \\\--------/\n");
      printf("           \\\ time /\n");
      printf("გააკეთე <-  \\\ 18T/ <--- ტკივილი\n");
      printf("   1  ქართა  \\\  /\n");
      printf("     2  ველო  \\\/\n");

      prizma++;
      printf("drois borbali %d\n",prizma);
    }

    if (i == 2)
    {
      printf("        \\\--- /\\ ---/\n");
      printf("         \\\  /  \\  /\n");
      printf("      3   \\\/  4 \\/ ხე - 2 (new brave worl-Nდ)\n");
      printf("          /\\\    /\\\n");
      printf("         /__\\\  /__\\\n");
      printf("             \\\/\n");

      prizma++;
      printf("drois borbali %d\n",prizma);
    }
  printf("შეუსრულებელი მისია - ლევანიკომ მომცა - სიფხიზლის ქვესთი (KA [პი] ოქროს შუალედი +- 1,2,3)\n");
  }

  printf("klaviaturidan sheyvanili brzaneba (sqanf) it an (gets) -it\n");
  gets(brzaneba);
  printf("klaviaturidan sheyvanili brzanebaa %s\n",brzaneba);

  ////////////// კალკულატორი ////////////////
  while (true)
  {
    // გამოსათვლელი რიცხვების შეყვანა სტრინგად
    printf("==================================== \n");
    printf("gets - brzaneba - შეიყვანე რიცხვი 1 - ricxvi1 \n");
    gets(brzaneba);
    ricxvi1Chek = parametrebi_Brzanebis(brzaneba);
    ricxvi1 = strtod(brzaneba, &eptr);
    printf("ricxvi1 = %f\n",ricxvi1);
    printf("ricxvi1Chek = %d\n",ricxvi1Chek);
    printf("============= \n");
    printf("gets - brzaneba - შეიყვანე რიცხვი 2 - ricxvi2 \n");
    gets(brzaneba);
    ricxvi2Chek = parametrebi_Brzanebis(brzaneba);
    ricxvi2 = strtod(brzaneba, &eptr);
    printf("ricxvi2 = %f\n",ricxvi2);
    printf("ricxvi2Chek = %d\n",ricxvi2Chek);

    if (ricxvi1Chek == 1 && ricxvi2Chek == 1) // თუ ricxvi1 და ricxvi2 არიან რიცხვები
    {
      printf("=================== \n");
      printf("შეიყვანეთ 1 თუ გსურთ ricxvi1 da ricxvi2 - ის sum_mimateba - ის გაგება \n");
      printf("შეიყვანეთ 2 თუ გსურთ ricxvi1 da ricxvi2 - ის sub_gamokleba - ის გაგება \n");
      printf("შეიყვანეთ 3 თუ გსურთ ricxvi1 da ricxvi2 - ის mult_gamravleba - ის გაგება \n");
      printf("შეიყვანეთ 4 თუ გსურთ ricxvi1 da ricxvi2 - ის div_gayofa - ის გაგება \n");
      printf("შეიყვანეთ 5 თუ გსურთ ricxvi1 da ricxvi2 - ის sq_kvadrati - ის გაგება \n");
      printf("შეიყვანეთ 6 თუ გსურთ ricxvi1 da ricxvi2 - ის cube - ის გაგება \n");

      gets(brzaneba);
      indikatori = atoi(brzaneba); // სტრინგი გადაყავს ინტში

      switch(indikatori)
      {
        case 1:
        add_mimateba(ricxvi1, ricxvi2);
        break;

        case 2:
        sub_gamokleba(ricxvi1, ricxvi2);
        break;

        case 3:
        mult_gamravleba(ricxvi1, ricxvi2);
        break;

        case 4:
        div_gayofa(ricxvi1, ricxvi2);
        break;

        case 5:
        sq_kvadrati(ricxvi1, ricxvi2);
        break;

        case 6:
        cube_kubi(ricxvi1, ricxvi2);
        break;

        default:
        printf("\n\n შეიყვანეთ რიცხვი მოცემული ცხრილიდან \n");
      }

    } else
    {
      //
      printf("შეიყვანეთ ricxvi1 და ricxvi2 თავიდან \n");
      printf("==================================== \n");
    }

    // უნდა ვთქვა როგორ მინდა ჯერ და მერე გავაკეთო ეგრე
    // y - 121; n - 110
    printf("=================== \n");
    printf("ვაილ ციკლი გაგრძელდეს? (y or n) \n");
    gets(gamortva);
    printf("gamortva = %s \n",gamortva);

    if (gamortva[0] == 121) // ვაილიდან გამოსვლა - დასახვეწია - არ დამიმთავრებია!!!!!!! <<<<<<<<<<<<<<<<
    {
      continue;
    } else if (gamortva[0] == 110)
    {
      printf("break \n");
      break;
    } else
    {
      printf("ვაილი გრძელდება \n");
      continue;
    }

  }

  return 0;
}

/*
უკრაინისთვის ვიბრძვი
ყოველდღიური
მე111111111111
ცა
დინებით
სინდისით
გამოსწორება მჭირდება
ჩემი სირცხვილის

10 დღიანი - სულების სამყაროში გადასვლით -
სადღაც ვარ გზაში. მივხდები როცა ვიქნები ცაში.

ველოს გარემონტება + მანქანის გარემონტება (მისია)
:) დებილო ბეეე )))) მმმმ
ეხლა უცხოური ტექნიკის მასტერკლასებს გადიან მებრძოლები.

3 x ბუქნი 20
3 x აჯიმანია 20
3 x პრესები 20

20 აჯიმანია
ბანაობა

უნდა გავაკეთო ფაილი.
ფაილში უნდა ჩაიწეროს თვითოეული გამოთვლა.
ვინ ჩაატარა. რამდენი რამდენის მიუმატა გამოაკლო.
რა დროს მოხდა ეს. და პასუხი. პროგრამის დასახელება. ჰალო კალკ კაპ. დროის ბორბალი ან რამე ეგეთი.

*/
