//pointers and dereferencing pointers
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

struct Books {
  char  title[50];
  char  author[50];
  char  subject[100];
  int   book_id;
};

int main()
{
  int asaki      = 30;
  double nishani = 13.5;
  char simbolo   = 'A';

  struct Books Book1;

  char sacavi[3][30] = {
    {"gio"},
    {"neo"},
    {"hoe"},
  };
  printf("sacavi[1] = %s\n",sacavi[1]);
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      printf("sacavi (for - shi) = %s\n",sacavi[i]);
    }
  }

  strcpy(Book1.title, "Sons of Hurin"); // ჯოხების საცავისთვის იდეალურია
  printf("Book 1 title   : %s\n", Book1.title);

  printf("memory Adress of int asaki = %p\n", &asaki); // hexadecimal
  printf("memory Adress of struct Books Book1 = %p\n", &Book1);
  printf("memory Adress of char sacavi = %p\n", &sacavi);
  printf("memory Adress of char sacavi[1] = %p\n", &sacavi[1]);

  // Pointers
  int  var = 20;   /* actual variable declaration */
  int  *ip = &var;        /* pointer variable declaration */
  // ip = &var;       /* store address of var in pointer variable*/

  printf("Address of var variable: %x\n", &var);
  printf("Address of ip variable: %x\n", &ip);
  /* address stored in pointer variable */
  printf("Address stored in ip variable: %x\n", ip);
  /* access the value using the pointer */
  printf("Value of *ip variable: %d\n", *ip);
  printf("Value of *ip (*&var) variable: %d\n", *&var);

  return 0;

}

/*
ლუკამ დამირეკა და შეიძლება ხვალ აბასთუმანში წავიდე
დღეს დამესიზმრა რომ ვიყავი აბასთუმანში. ყველა იყო იკა ანი ბავშვები
თორნე ვერა ბავშვები
თიკუკა ნიკუშა მაშო ელენე
ყველას ვეხუტებოდი.
მერე დამესიზმრა ქეთი. მართვის მოწმობას იღებდა. დამესიზმრა რომ ჩუმად შევხდით
ჩვენს ქუჩაზე. სადღაც სხვანაირი საბურთალო იყო და სხვანაირი პეკინი და სადღაც მანდ.
ხილბოსტნის კაცი იყო და ყიდიდა რაღაცეებს. ქეთი ხატავდა და ისეთი რაღაც უნდა დაეხატა
რაც მე გამახარებდა. მე კიდევ უნდა მემუშავა რომ ქეთის ხატვის ძალა ქონოდა.
არადა ვიცი რომ ხატვა მაგრად ჭირდება. ნუ რათქმაუნდა ვერ მოვითმინე და ყურში ჩავჩურჩულე
ქეთ მართლა აღარ გიყვარვარ? და სანამ რამეს მეტყოდა პასუხის შემეშინდა და გადავაკეთე კითხვა
და არაა არაა მეგობრულ სიყვარულზე გეუბნებოდი :))) ჰოდა შემომხედა და მითხრა დებილი ხარო
მოკლედ ქეთის დაურეკეს მერე იასნია და წასასვლელი იყო. წავიდა. ჰოდა მეც წავედი.
მერე მე კომპიუტერთან ვიჯექი და თითქოს გვერძე მეჯდა მაგრამ ანუ არ იყო გვერძე მაგასთან სხვა სიტოაციები
იჩითებოდა ჩემთან სხვა. ორივე ვჩალიჩობდით რაღაცას კომპიუტერით და ალბათ ვწერდით და მაგიტომ ჩანდა ისე
თითქოს გვერდიგვერდ ვიჯექით.
სამუშაო დღის ბოლოს დამირეკა fula - მ. (დღეს ვფიქრობდი რომ თუ ისევ ნახულობ დემონურ სიზმრებს
შავ გეტოსთან ახლოს თეთრმა ანგელოზებმა მითხრეს და მივხდი რომ მართლა ეგრე მოხდა და ანუ ნუ კი პიზდეცია
მაგრამ fula სთან სზიმრებში რომ კონტაქტი მაქვს ძაან ასწორებს - ფრაქტალური ქრისტე). მოკლედ დღესაც ვნახე რა
სფიქსიც ვნახე. და მერე დიდი კამანდა. და წავედით ერთად ვინტის (მეტამფეტამინი) საჩალიჩოდ. და ვეუბნებოდი ყველაზე
მაგარი გოგო მყავსთქო. ნუ თან მანდ მახსოვდა რომ ჩემი გოგო არ იყავი მაგრამ მაგ სიზმრაში... მოკლედ ნუ რა აზრი აქვს
შენზე ვუყვებოდი ყველაზე მაგარი გოგოათქო.
*/
