/*
Building a better calculator and other staff

ჩემით უნდა გავაკეთო ეს კალკულატორი. შვადარო ვიდეოს კალკულატორს. ვნახოთ შეიძლება საღამოს ჩავუჯდე.
ფუნქციები ხომ არ გამოვიყენო? დავწერო მიმატება გამოკლება გაყოფა გამრავლება ფესვი კვადრატი კუბი ფუნქციებად (ორი რიცხვისთვის)
ორი რიცხვის მიღება კლავიატურიდან. ბაგებზე უნდა შევამოწმო. მერე გკითხავს რა გინდა უქნა ამათ. მიუმატო თუ გამოაკლო და
რომელსაც აირჩევ იმ ფუნქციას გამოიყენებ. პრინციპში ყველაფერი არის რაც ვიდეოში გავიარე. გეგმა.
ჯერ მარტივი ვარიანტი გავაკეთოთ6
მერე იყოს ვარიანტი როცა პასუხი გაქვს უკვე და ახალ ოპერაციას უკეთებ და კლავიატურიდან შეგყავს კიდევ რაღაცეები.
ჯერ ორი რიცხვის შეყვანა შეიძლებოდეს და მერე რამდენიც გინდა იმდენის?
1+1+1+1+1+1 = 6 + 1 + 1 + 1 = 9 ს. ესეთი რაღაც რომ დაიწეროს რა :))
ამოცანა ესეც :)
რეილიბით გუის გაკეთება გარშემო. კარგი ამოცანა იქნება. ვინდოუსის ფუნქციების გამოყენებით გუის გაეთება
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

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

double add(double x, double y)
{ // 1
  double c;
  c=x+y;
  printf("\n The sum is = %f \n\n",c);
}

double sub(double d, double e)
{ // 2
  double f;
  f=d-e;
  printf("\n The subtraction is = %f \n\n",f);
}

double mult(double x, double y)
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

double sq(double x, double y)
{ // 5
  double sqr1,sqr2;
  sqr1=x*x;
  sqr2=y*y;
  printf("\n Square of %f is = %f \n",x,sqr1);
  printf("\n Square of %f is = %f \n\n",y,sqr2);
}

double cube(double x, double y)
{ // 6
  double cub1,cub2;
  cub1=x*x*x;
  cub2=y*y*y;
  printf("\n Cube of %f is =%f \n",x,cub1);
  printf("\n Cube of %f is =%f \n\n",y,cub2);
}


int main()
{
  char brzaneba[51];     // gets(brzaneba) კლავიატურიდან შეყვანა სტრინგის
  double ricxvi1;        // brzaneba თუ რიცხვია კალკულატორის პირველი რიცხვი
  double ricxvi2;        // კალკულატორის მეორე რიცხვი
  double pasuxi;         // კალკულატორის პასუხი
  int indikatori;        // 1,2,3, მიმატება გამოკლება კუბი
  double result;         // brzaneba -ს გადაყვანა დაბლში სტრინგიდან strtod
  char value[51];        // brzaneba -ს გადაკოპირება strcpy ით. პირდაპირ brzaneba ც რომ იყოს შეიძლება
  char *eptr;            // ???
  char gamortva[51];     // ვაილ 1 დან გასვლა არ გამოსვლა კითხვა
  int counter_while = 0; // ვაილ 1 ციკლის მთვლელი
  bool ricxvi1Chek;
  bool ricxvi2Chek;

  while(true) // ვაილ 1
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
      printf("შეიყვანეთ 1 თუ გსურთ ricxvi1 da ricxvi2 - ის sum - ის გაგება \n");
      printf("შეიყვანეთ 3 თუ გსურთ ricxvi1 da ricxvi2 - ის cube - ის გაგება \n");
      gets(brzaneba);
      indikatori = atoi(brzaneba);

      switch(indikatori)
      {
        case 1:
        add(ricxvi1, ricxvi2);
        break;

        case 2:
        sub(ricxvi1, ricxvi2);
        break;

        case 3:
        mult(ricxvi1, ricxvi2);
        break;

        case 4:
        div_gayofa(ricxvi1, ricxvi2);
        break;

        case 5:
        sq(ricxvi1, ricxvi2);
        break;

        case 6:
        cube(ricxvi1, ricxvi2);
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


    printf("=================== \n");
    printf("ვაილ ციკლი გაგრძელდეს? (y or n) \n");
    gets(gamortva);
    printf("gamortva = %s \n",gamortva);

    if (gamortva[0] == 121) // ვაილიდან გამოსვლა - დასახვეწია
    {
      continue;
    } else
    {
      printf("break \n");
      break;
    }
    counter_while++;
  }

  return 0;
}


/*
ფუნქციები რაც მგონია რომ დამჭირდება:

1 - strcpy(value, brzaneba);

/*


/*
ბალროგთან ბრძოლა გრძელდება თურმე...
შეეცდება ისეთი რაღაცეები გაკაკეთებინოს რომ ახლობლებთან კონფლიქტი მოგივიდეს
და შენი თავი შენვე დაგამარცხებინოს. ამიტომ ძაან ნაგლი დემონია.
ფრთხილად უნდა იყო და რვეულში ჩაწერილ ალგორითმს მიყვე. და სინდისს.
და ვალი გაქვს კიდევ და უნდა დააბრუნო შრომით. სხვა გზა არ გაქვს. ვაჰ...
და ტირლლის უფლებაც არ გაქვს ეხლა. პირიქით ყველაფერი რაც ბალროგმა გაგაკეთებინა
გამოიყენე გაკვეთილად და მის წინააღმდეგ მიმართე.
მისივე ხრიკები მის წინააღმდეგ.
ანუ შენ უნდა იქცეოდე
სინდისიერად.
გაიღიმე.
ეგრეაო ;)
იესომ..
და ბუდამ...

ისეთი სევდა და შიში მეწვია ძალა წამართვა თითქოს სულ და ხსნას ველი
პატრონუსი უნდა გავუშვა სამივე ჯოხიდან
პატრონუს

არ მიყვარს ესე რომ ვამბოხოლმე მაგრამ შაბათია
და დიდად კი არ მინდა მაგრამ ვასო პაპას
რჩევას ვენდობი და მისტერ რობოტს ვრთავ
ჰეი მისტერ რობორტ :)
ჰაკერობაზე რადგან არის მეშინაია ყურება
ანუ პროგრამირების მეცადინეობის ისე მეშინაია
სერიალის ყურებაზეც უარს ვამბობდი ვაჰ
მშიშარა კაპანა. არადა პროსტა ტვინს სხვა ჰებითები გაქვს
და უნდა შეცვალო რა. უცებ წესიერი კაცი რომ გახდეს ეგრევე ნარკომანი. ეგრე არ იქნება ნელ ნელა მოხდება.
ასევე ნარკომანიც ეგრევე ვერ გახდება წესიერი კაცი. და დრო ჭირდება ნელა ნელა ტუკუ ტუკუს ტყუილად არ
ვიძახი. მოკლედ
კაპანას. წარსულიდან მომავალში ვუგზავნი ამ ნაწერს.

kapan-ჩართე სვანი კაცი-მოხუცი სანტოსი.
არაფერზე არ ვნერვიულობ. ემოციებს ვაკონტროლებ. შიშები ფეხებს ვერ მჭამს სვანი ვარ.
სანტოსობა ასწორებს. :) საქციელებიც ეგეთი უნდა მქონდეს. როცა სვანი ვარ.

რა გამოდის? რომ ისეთი არჩევანი გავაკეთე მეთვითონ.
გავუშვი გვანცაც. ქეთოც. ვიცოდი.
უბრალოდ ისეთი მწარე იყო.
ძლივს გადავიტანე.
არადა ჩემი
თავის
უფლება
ამირჩევია
წინ ბევრი საქმეები მაქვს.
ღმერთო დაგვეხმარე ყველა გაჭირვებულს
ამ მენ. im man. :)))

ანიმ, ვირი ხეზე ავიდაო.
მათე ხეზე აძვრაო. მიშიკუნამ გადაუღოო.
მეორედ მოსვლაა მოკლედ.
*/
