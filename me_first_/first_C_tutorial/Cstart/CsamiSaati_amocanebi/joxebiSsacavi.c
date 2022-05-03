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
#include <string.h>

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

struct MagicWands {
  char  title[50];
  char  author[50];
  char  owner[100];
  char  soul[100];
  int   wand_id;
};

void printMagicWandsInfo (struct MagicWands wand)
{
  printf("wand title  : %s\n", wand.title);
  printf("wand author : %s\n", wand.author);
  printf("wand owner  : %s\n", wand.owner);
  printf("wand soul   : %s\n", wand.soul);
  printf("wand id     : %d\n", wand.wand_id);

  // chawera failshi
  FILE *chemiFailisPointeri;
  chemiFailisPointeri = fopen("tavi1.txt","a");

  fprintf(chemiFailisPointeri,"%s","wand.title:");
  fprintf(chemiFailisPointeri,"%s",wand.title);
  fprintf(chemiFailisPointeri,"%s","\n");
  fprintf(chemiFailisPointeri,"%s","wand.author:");
  fprintf(chemiFailisPointeri,"%s",wand.author);
  fprintf(chemiFailisPointeri,"%s","\n");
  fprintf(chemiFailisPointeri,"%s","wand.owner:");
  fprintf(chemiFailisPointeri,"%s",wand.owner);
  fprintf(chemiFailisPointeri,"%s","\n");
  fprintf(chemiFailisPointeri,"%s","wand.soul:");
  fprintf(chemiFailisPointeri,"%s",wand.soul);
  fprintf(chemiFailisPointeri,"%s","\n");
  fprintf(chemiFailisPointeri,"%s","wand.wand_id:");
  fprintf(chemiFailisPointeri,"%d",wand.wand_id);
  fprintf(chemiFailisPointeri,"%s","\n");

  fclose(chemiFailisPointeri);

}
// ფაილიდან ამოკითხვა და ნუმერაციის გაკეთება სწორად

int main()
{
  char brzaneba[51];     // სტრინგი რომელიც შემყავს კლავიატურიდან
  int counter_while = 0;
  int count_lines = 0;

  struct MagicWands wand1;        /* Declare Book1 of type Book */

  printf("Say friend დიდი ასოებით at Elvish (და ვაილიდან გამოხვალ - სამებით - წამებით) \n");

  while (true)
  {
    printf("enter wand.title \n");
    gets(brzaneba);
    printf("brzaneba (string) = %s\n", brzaneba);
    strcpy(wand1.title, brzaneba);

    printf("enter wand.author \n");
    gets(brzaneba);
    printf("brzaneba (string) = %s\n", brzaneba);
    strcpy(wand1.author, brzaneba);

    printf("enter wand.owner \n");
    gets(brzaneba);
    printf("brzaneba (string) = %s\n", brzaneba);
    strcpy(wand1.owner, brzaneba);

    printf("enter wand.soul \n");
    gets(brzaneba);
    printf("brzaneba (string) = %s\n", brzaneba);
    strcpy(wand1.soul, brzaneba);
    wand1.wand_id = counter_while;

    /* print MagicWands info and write to file*/
    printMagicWandsInfo(wand1);



    FILE *fileptr;
    char chr;
    fileptr = fopen("tavi1.txt", "r");
   //extract character from file and store in chr
    chr = getc(fileptr);
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
    printf("failshi lainebis raodenoba = %d\n",count_lines);




    // ვაილიდან გამოსვლა. ავარიული. ასკი 126 - ~ ლევიოსა
    if (brzaneba[counter_while] == 126)
    {
      // break
      printf("break from while! \n");
      break;
    }

    printf("counter_while = %d\n", counter_while);
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
