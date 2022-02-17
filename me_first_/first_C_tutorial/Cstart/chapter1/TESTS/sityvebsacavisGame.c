/*
- sityvebsacaviGame.c
- - ჯადოსნური სიტყვების საცავის შექმნა ნუმერაციით და ჯადოსნური სიტყვებით (თარიღების მიწერაც მოსულა)
- - - კარები იღება ელფურად მეგობრობით
- - თავიდან არის მოსაფიქრებელი კოდი
- თავდაპირველი იდეები
- ვნახავთ
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> // << შემოწმების დროს რაღაც ფუნქციისთვის მჭირდება

// globals
int cointer_numeracia;

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

main()
{
  // ცვლადები - გასაწმენდია
  int nl, counter, counter2, c;

  counter2      = 0;    // სულ რამდენი ასოა
  counter       = 0;    // სიტყვებში ასოების რაოდენობა
  nl            = 0;    // სიტყვების რაოდენობა

  // ბულ იან ეგოები მერევა. მაგრამ აზრი არ აქვს მაგას
  bool Me       = false; // 77
  bool Erti     = false; // 69
  bool Leo      = false; // 76
  bool Oniani   = false; // 79
  bool N_vi     = false; // 78

  bool erti     = false;
  bool ori      = false;
  bool sami     = false;
  bool otxi     = false;
  bool xuti     = false;

  bool amogdeba = false; // არ ვიყენებ

  // 2D array
  int sityvebSanaxi[3][300];

  /*
  ამოხსნა მქონდა მოფიქრებული (გავიხსენო):
  აა თავდან ამოწმებს არის თუარა ფაილი
  თუ არ არის ქმნის (პირველი გაშვება)
  თუ არის
  შევა პირველ ფაილს გახსნის ამოიწერს რიცხვს და შეინახავს დახურავს ფაილეს
  მეორე მასივი შევქმნა სადაც მეორედ გაშვების დროს ჩაიწერება სიტყვებსანახში რაც იწერება ეგ
  და მერე სიტყვებს სანახს გადავაწერ მაგას ბოლოში დამახსოვრებული ციფრის ჩასმა
  */

  // სტარტ
  printf("program will calculate slesh ns \n");
  printf("Say friend დიდი ასოებით at Elvish (და ვაილიდან გამოხვალ - სამებით - წამებით) \n");
  printf("enter word (getchar): \n");

  while ((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      // "\n" ების მთვლელი. სიტყვების მთვლელი.
      ++nl;
    }

    // ვაილიდან გამოსვლა. ავარიული. ასკი 126 - ~ ლევიოსა
    if (c == 126)
    {
      // break
      printf("break from while! \n");
      break;
    }

    // მასივში ჩაწერა. სიტყვის |სიტყვა|counter| es sanaxavia kidev
    sityvebSanaxi[0][counter2] = c; // masivis shevseba
    sityvebSanaxi[1][counter2] = c; // tvin მასივი

    printf("c = %c\n",c);

    for (int j = 0; j <= counter2; j = j + 1)
    {
      if (sityvebSanaxi[0][j] == 77)
      {
        Me = true;
        // printf("Me (TEST)\n");
      }

      if (sityvebSanaxi[0][j] == 69 && Me == true)
      {
        Erti = true;
        // printf("Me Erti (TEST)\n");
      }

      if (sityvebSanaxi[0][j] == 76 && Me == true && Erti == true)
      {
        Leo = true;
        // printf("Me Erti Leo (TEST)\n");
      }

      if (sityvebSanaxi[0][j] == 79 && Me == true && Erti == true && Leo == true)
      {
        Oniani = true;
        // printf("Me Erti Leo Oniani (TEST)\n");
      }

      if (sityvebSanaxi[0][j] == 78 && Me == true && Erti == true && Leo == true && Oniani == true)
      {
        N_vi = true;
        // printf("Me Erti Leo Oniani N_vi var (TEST)\n");
      }
    }

    // ქაუნთერი მუშაობს. უბრალოდ მაგდროს ხუთია შემდეგ ვაილში ჩავარდნის დროს გაიზდება +1 ით მეტი თუ არის ზედმეტი ასო
    if (Me == true && Erti == true && Leo == true && Oniani == true && N_vi == true && counter == 5)
    {
      for (int j = counter2 - 5; j <= counter2; j = j + 1)
      {
        printf("sityvebSanaxi = %c\n",sityvebSanaxi[0][j]);

        if (sityvebSanaxi[0][j - 5] == 77)
        {
          erti = true;
          printf("M >>>> \n");
        }
        if (sityvebSanaxi[0][j - 4] == 69)
        {
          ori = true;
          printf("E >>>> \n");
        }
        if (sityvebSanaxi[0][j - 3] == 76)
        {
          sami = true;
          printf("L >>>> \n");
        }
        if (sityvebSanaxi[0][j - 2] == 79)
        {
          otxi = true;
          printf("O >>>> \n");
        }
        if (sityvebSanaxi[0][j - 1] == 78)
        {
          xuti = true;
          printf("N >>>> \n");
        }
      }

      if (erti == true && ori == true && sami == true && otxi == true && xuti == true)
      {
        printf("melon it gamosvla \n");
        break;
      }

      printf("counter2 = %d\n", counter2);
      printf("break \n");
    }

    ++counter;  // თვითოეულ სიტყვაში სიმბოლოების მთველი
    ++counter2; // სულ რამდენი ასოა

    if (c == 10)
    {
      // თვითოეულ სიტყვაში სიმბოლოების მთველი
      counter = 0;
    }
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





/*
##################### jadosnuri ჯოხების საცავი ###############
სიტყვად საცავში შეინახება ჯადოქრების მათი ჯოხების და მანტიების სახელები

ლიზა(კინგ) - მწვანე - ლომი
ლაი        - იისფერი - ირემი
კოროშინაძე  - იასამნისფერი - დრაკონი
მარიკა      - წითელფერადი - მანტიკორა
ქეთო       - აქვს რუსული მანტია - უნიქორნი

გვანცა       - მწვანე          - კატა
თათია       - ლურჯი          - კატა
თამთა       - მუქი იასამნისფერი - მელა

ბორჯომი    - ცისარტყელა - ჯოკერი
კესო        - ფერადი - კატა
კესი        - წმინდა ჯოკერი
ერეკლე     - ჯოკერი

სვანი   - იასამნისფერი - ჯადოქარი ტოპე კომეტა
სალომე - ვარდისფერყველაფერი - ადამიანი
შინერა  - სტაფილოსფერი - ნადირი
მარიამი - შავიოქროსფერი - ლომი
ლოსი   - ის ჯოხი არა ჭირდება ბრატ ))
ვასო პაპა - წითელი
ოთარა   - მეთვითნ მოვუფიქრო

მარიამ ჯენის - ვკითხო - და გული?  (მავიწყდება ყველაფერი იმენა რა)
ლიზა ჯორჯ  - ?
მარიამ პატარა - წითელი?

ყაფლანა  - შავი - მანტიკორა

მარგარიტა - წითელი - დრაკონი

beren - მწვანე წითელი ყველა ფერი მკვდარი ცოცხალი ანიმაგი - დრაკონი
თუ დუ:
 - მაღაზიაში წასვლა
 - მოსაწევის მოწევა წასვლამდე

 - რა ვიყიდო?
 - -

 - კოდირების გაგრძელება


 - - - ხვალ
 - - ჯოხების დამზადება
 - - - შესაძლოა თბილისში წასვლა
*/
