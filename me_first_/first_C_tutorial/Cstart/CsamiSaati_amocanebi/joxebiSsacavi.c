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

/*
- ვორდ ფაილის გახსნა
- - ტექსტის ჩამატება
- - - ფოტოების ჩამატება
- - დროის ჩამატება
- ვნახოთ
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

/* გლობალური ცვლადები */

/* ფაილში ლაინების რაოდენობის გაგება */
int findLineNumber(char file_name[])
{
  /* extract character from file and store in chr
  ვიყენებ /n ების დასათვლელად. ლაინების რაოდენობა რომ ვიცოდე
  */
  FILE *fileptr;
  char chr;
  int count_lines = 0; // ლაინების რაოდენობა

  fileptr = fopen(file_name, "r");
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

  printf("failshi lainebis raodenoba = %d\n", count_lines);

  return count_lines;
}

/* ფაილის ზომის გაგება */
long int findSize(char file_name[])
{
  // opening the file in read mode
  FILE *fp = fopen(file_name, "r");
  // checking if the file exist or not
  if (fp == NULL) {
    printf("File Not Found!\n");
    return -1;
  }
  // calculating the size of the file
  fseek(fp, 0L, SEEK_END); // ეს რას ნიშნავს? fseek() <<<<
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

void printMagicWandsInfo (struct MagicWands wand, char file_name[], int counter_while)
{
  printf("wand title  : %s\n", wand.title);
  printf("wand author : %s\n", wand.author);
  printf("wand owner  : %s\n", wand.owner);
  printf("wand soul   : %s\n", wand.soul);
  printf("wand id     : %d\n", wand.wand_id);

  /* ფაილის შექმნა და ჩაწერა */
  FILE *chemiFailisPointeri;
  chemiFailisPointeri = fopen(file_name,"a");

  if (counter_while == 0)
  {
    fprintf(chemiFailisPointeri,"%s","//////////////////////\n");
  }

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
  fprintf(chemiFailisPointeri,"%s","//////////////////////\n");

  fclose(chemiFailisPointeri);
}


int main()
{
  char brzaneba[51];                   /* სტრინგი რომელიც შემყავს კლავიატურიდან */
  char file_name[]  = {"tavi1.txt"};  /* ფაილი რომელზეც ვმუშაობ - ვწერ ჯოხების ინფოს */
  int counter_while = 0;               /* ვაილ ციკლი რამდენჯერ გაეშვა */
  int lineNUMBER;                      /* სამუშაო tavi1.txt ფაილში ლაინების რაოდენობა*/

  struct MagicWands wand1;             /* Declare wand1 as Magicwands struct */
  FILE *chemiFailisPointeri;


  /* ფაილის შემოწმება და პირველი ამოკითხვა */
  if( access(file_name, F_OK ) == 0 )
  {
    printf("file exists \n");
    lineNUMBER = findLineNumber(file_name); /* ლაინების რაოდენობა რომ ვიცოდე */

    long int res = findSize(file_name);
    if (res != -1)
    {
      printf("Size of the file is %ld bytes \n", res);
    }
  }


  printf("ჯადოსნური ჯოხების საცავი \n");
  printf("Say friend დიდი ასოებით at Elvish (და ვაილიდან გამოხვალ - სამებით - წამებით) \n");

  while (true)
  {
    printf("enter wand.title \n");
    gets(brzaneba);

    strcpy(wand1.title, brzaneba);
    printf("enter wand.author \n");
    gets(brzaneba);

    strcpy(wand1.author, brzaneba);
    printf("enter wand.owner \n");
    gets(brzaneba);

    strcpy(wand1.owner, brzaneba);
    printf("enter wand.soul \n");
    gets(brzaneba);

    strcpy(wand1.soul, brzaneba);
    wand1.wand_id = counter_while; // <<<<<<<<<<<<<<<<<<<<<< შესაცვლელია <<<<<<<<<<<<<<<

    /* print MagicWands info and write to file (ფაილის შექმნა და ჩაწერა) */
    printMagicWandsInfo(wand1, file_name, counter_while);

    /* ვაილიდან გამოსვლა */
    printf("=================== \n");
    printf("ვაილ ციკლი გაგრძელდეს? (y or n) \n");
    gets(brzaneba);

    if (brzaneba[0] == 110)
    {
      printf("break \n");
      break;
    } else
    {
      printf("ვაილი გრძელდება \n");
      // continue;
    }

    printf("aq rato ar movida? \n");

    // წაკითხვა ფაილის
    char line[100]; // აქ შევინახავ წაკითხულ ფაილიდან ინფორმაციას
    chemiFailisPointeri = fopen("tavi1.txt","r");

    fgets(line,100,chemiFailisPointeri); // პირველი ლაინი წაიკითხა
    fgets(line,100,chemiFailisPointeri); // მეორე ლაინი წაიკითხა

    fclose(chemiFailisPointeri);

    printf("line = %s\n", line);

    printf("counter_while = %d\n", counter_while);
    counter_while++;
  }

  return 0;
}

/*
- ჯოხების და მათი პატრონების ცხრილი v1
- - ქლაუდე უნდა იდოს და ინტერნეტ სამყაროში შეუგნებლად რევოლუციას მოახდენენ
- - - ზაფხულში რევოლუცია - მატრიცა რევოლუცია - მალე თვითმფრინავი ჩამოვარდება
- - ჩონჩხების გუნდი იხოდება
- აზერ საიდიდან მოდიან
*/

/*
- ემოციებმა წამიღო
-- ლარაზე ვიეჭვიანე
--- თან გამიხარდა თან გამიტყდა
-- უცნაურია, არადა...
- ვნახოთ
*/
