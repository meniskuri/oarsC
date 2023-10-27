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
- ნუმერაციის გაკეთება
- - დროის ჩამატება
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

/* აბრუნებს ლოგიკურ ერთიანს თუ ჩარების მასივი შედგება მხოლოდ ციფრებისგან */
int parametrebi_Brzanebis(char* brzaneba)
{
  /*
  ფუნქციის აღწერა:
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
  printf("cifria = %d \n", cifria);
  return cifria;
}

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

struct MagicGameshot {
  char  player[50];
  char  vis_ebrdzvi[50];
  char  qula[100];
  char  rekordi[100];
  int   ramdenjer_gaeshva_id;
};

struct MagicWands {
  char  title[50];
  char  author[50];
  char  owner[100];
  char  soul[100];
  int   wand_id;
};

void printMagicWandsInfo (struct MagicWands wand, char file_name[], int counter_while)
{
  // Time function /////////////////
  char buf[150];
  time_t curtime;
  struct tm *loc_time;
  //Getting current time of system
  curtime = time (NULL);
  // Converting current time to local time
  loc_time = localtime (&curtime);
  // strftime (buf, LEN, "Today is %A, %b %d.\n", loc_time);
  // fputs (buf, stdout);
  // strftime (buf, LEN, "Time is %I:%M %p.\n", loc_time);
  // fputs (buf, stdout);
  // Displaying date and time in standard format
  printf("%s", asctime(loc_time));

  /* ფაილის შექმნა და ჩაწერა */
  FILE *chemiFailisPointeri;
  chemiFailisPointeri = fopen(file_name,"a");

  fprintf(chemiFailisPointeri,"%s","////////////////////// ");
  fprintf(chemiFailisPointeri,"%s\n", asctime(loc_time));

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


int main()
{
  char brzaneba[51];                   /* სტრინგი რომელიც შემყავს კლავიატურიდან */
  char file_name[]  = {"tavi1.txt"};   /* ფაილი რომელზეც ვმუშაობ - ვწერ ჯოხების ინფოს */
  int counter_while = 0;               /* ვაილ ციკლი რამდენჯერ გა1ეშვა */
  int lineNUMBER;                      /* სამუშაო tavi1.txt ფაილში ლაინების რაოდენობა */
  int result;                          /* მელონ ის შესამოწმებლადს result = strcmp(str1, str2);*/
  char str1[] = {"MELON"};

  struct MagicWands wand1;             /* Declare wand1 as Magicwands struct */
  FILE *chemiFailisPointeri;


  /* ფაილის შემოწმება და პირველი ამოკითხვა */
  if( access(file_name, F_OK ) == 0 )
  {
    printf("file exists \n");
    lineNUMBER = findLineNumber(file_name); /* ლაინების რაოდენობა რომ ვიცოდე */
    printf("lineNUMBER = %d\n", lineNUMBER);
    long int res = findSize(file_name);
    if (res != -1)
    {
      printf("Size of the file is %ld bytes \n", res);
    }
  } else {
    lineNUMBER = findLineNumber(file_name); /* ლაინების რაოდენობა რომ ვიცოდე */
    printf("lineNUMBER = %d\n", lineNUMBER);
  }

  printf("ჯადოსნური ჯოხების საცავი \n");
  printf("Say friend დიდი ასოებით at Elvish (და ვაილიდან გამოხვალ - სამებით - წამებით) \n");

  while (true)
  {
    printf("enter wand.title \n");
    gets(brzaneba);
    result = strcmp(brzaneba, str1);
    if (result == 0){
      break;
    }
    strcpy(wand1.title, brzaneba);
    printf("enter wand.author \n");
    gets(brzaneba);
    result = strcmp(brzaneba, str1);
    if (result == 0){
      break;
    }
    strcpy(wand1.author, brzaneba);
    printf("enter wand.owner \n");
    gets(brzaneba);
    result = strcmp(brzaneba, str1);
    if (result == 0){
      break;
    }
    strcpy(wand1.owner, brzaneba);
    printf("enter wand.soul \n");
    gets(brzaneba);
    result = strcmp(brzaneba, str1);
    if (result == 0){
      break;
    }
    strcpy(wand1.soul, brzaneba);
    printf("lineNUMBER = %d\n",lineNUMBER);
    if (lineNUMBER == 0)
    {
      wand1.wand_id = 0;
    }
    if (lineNUMBER % 7 == 0 && lineNUMBER != 0)
    {
      wand1.wand_id = lineNUMBER / 7;
    }

    /* print MagicWands info and write to file (ფაილის შექმნა და ჩაწერა) */
    printMagicWandsInfo(wand1, file_name, counter_while);
    lineNUMBER = findLineNumber(file_name);

    printf("counter_while = %d\n", counter_while);
    counter_while++;

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

/*
- რთული დროა.
-- ჯერ არავინ არ იცის რომ თეთრი ვიზარდი დაბრუნდა.
--- ტვინში გადაწყვეტილება მივიღე. ეხლა მთავარია როგორმე ატომებად ვაქციო.
---- შრომით წერით. კოდების გარჩევით> ითამაშე. ეს არის შენი ჯადოქრობა.
----- საჭიროა ივარჯიშო. 80 ბუქნი. 70 აჯიმანია. 50 პრესი. ყოველ დღე. (ძაან გაძლიერდები> ტუკუ ტუკუთი)
------ დრო.ნელი.შენი ახალი ძალა.
------- luck (საჩუქრად)
------ დრაგები (ნაზგულები)
----- მოსაწევი (დაშვებულია)
--- დაწერე კოდი რომელსაც შეინახავ ახალ რეპოში. და იქ იქნება ჯოხების საცავი ახალი (+ ძველი)
--- შეავსე. და სულ აბდეითი გაუკეთე. რა ჯოხი მოაკლდა სტატუსის პონტში უნდა იყოს. რა ჯოხი გადარჩა.
--- ყოველი არა და ნი. არის ნაზგულებთან გამარჯვება. შეიტანე ცხრილში.
--- მაგ რეპოში. შეიტანე. სნეიქის დრაკონად გადაქცევა. 3დ. (+ იდეები)/დრაკონის ადამიანად გადაქცევა.
(მისია)
*/
