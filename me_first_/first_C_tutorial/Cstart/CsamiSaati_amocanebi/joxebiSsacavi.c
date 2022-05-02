/*
- joxebiSsacavi.c
- - ჯადოსნური joxebis საცავის შექმნა ნუმერაციით და ჯადოსნური სიტყვებით (თარიღების მიწერაც მოსულა)
- - - კარები იღება ელფურად მეგობრობით
- - თავიდან არის მოსაფიქრებელი კოდი
- თავდაპირველი იდეები
*/

/*
- ამოხსნა მქონდა მოფიქრებული (გავიხსენო):
- - აა თავდან ამოწმებს არის თუარა ფაილი
- - - თუ არ არის ქმნის (პირველი გაშვება)
- - - - თუ არის
- - - შევა პირველ ფაილს გახსნის ამოიწერს რიცხვს და შეინახავს დახურავს ფაილეს
- - მეორე მასივი შევქმნა სადაც მეორედ გაშვების დროს ჩაიწერება სიტყვებსანახში რაც იწერება ეგ
- და მერე სიტყვებს სანახს გადავაწერ მაგას ბოლოში დამახსოვრებული ციფრის ჩასმა
*/

/*
- მჭირდება ფუნქცია რომელიც 1 ს აბრუნებს როცა რიცხვია შეყვანილი
- მჭირდება ფუნქცია რომელიც 1 ს აბრუნებს როცა სიტყვაა შეყვანილი
- მჭირდება ფუნქცია რომელიც 1 ს აბრუნებს როცა სიმბოლოა შეყვანილი
- - მჭირდება ფუნქცია რომელიც ნახავს სიტყვა სიმბოლოს რიცხვს და ასოს შეამოწმებს შეიცავს თუარა
- - - მჭირდება სტრუქტურა რომელსაც დავბეჭდავ და ჩავწერ ფაილში (სტრუქტურა კითხვარით)
- - - - მჭირდება ისეთი ვაილი რომელიც სტრუქტურის კითხვებს გადაურბენს და სათითაოდ შეგაყვანინებს
- - - - - შემდეგ კი ჩაწერს ფაილში
- - - - სანამ ფაილში ჩაწერს ნახავს არის თუარა ფაილი. თუ არის ნუმერაცია უნდა შეინარჩუნოს
- - - თუარადა უნდა შექმნას ფაილი
- - მელონით გამოსვლა (ან ცალკე ან ძველი მექანიზმი რომელიც გადასაკეთებელი იქნება)
- შეიძლება რამდენიმე განსხვავებული სტრუქტურის შესავსებად იყენებდე (კითხვას უნდა გისვავდეს)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

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
  char brzaneba[51];     // სტრინგი რომელიც შემყავს კლავიატურიდან
  int counter_while = 0;

  printf("Say friend დიდი ასოებით at Elvish (და ვაილიდან გამოხვალ - სამებით - წამებით) \n");

  while (true)
  {
    gets(brzaneba);
    printf("brzaneba (string) = %s\n", brzaneba);
    printf("counter_while = %d\n", counter_while);

    // ვაილიდან გამოსვლა. ავარიული. ასკი 126 - ~ ლევიოსა
    if (brzaneba[counter_while] == 126)
    {
      // break
      printf("break from while! \n");
      break;
    }
    counter_while++;
  }









  // ფაილის შემოწმება და პირველი ამოკითხვა
  if( access("program.txt", F_OK ) == 0 ) { // unistd.h - თუ არსებობს ეს ფაილი

    printf("file exists \n");
    // თუ არსებობს პროგრამა.ტქსტ არსებობს - ნახოს ზომა ფაილის რომ გავიგო counter3 ის შემცვლელი
    char file_name[] = { "program.txt" };
    long int res = findSize(file_name);
    if (res != -1)
    {
      printf("Size of the file is %ld bytes \n", res);
    }
    // gio (3) - 14; giorgi (6) - 17
    // MELON (5) - 9
    // ~ - 3
    // + 3
    // counter3 = filisize - 4
  }

  return 0;
}
