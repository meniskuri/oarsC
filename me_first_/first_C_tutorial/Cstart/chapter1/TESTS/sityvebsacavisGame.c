/*
- sityvebsacaviGame.c
- - ჯადოსნური სიტყვების საცავის შექმნა ნუმერაციით და ჯადოსნური სიტყვებით (თარიღების მიწერაც მოსულა)
- - - კარები იღება ელფურად მეგობრობით
- - თავიდან არის მოსაფიქრებელი კოდი
- თავდაპირველი იდეები
- ვნახავთ
*/
/*
- TESTInG chapter 1.5.3 Line counting
- Count lines in input

TODO:
- TESTING + 1.5.4 Word Counting
- სიტყვების საცავში სიტყვების რაოდენობის მოძებნა  <<<<
- - ორი სლეში თუ იქნება რომ იცნოს (ვნახოთ)
- - შა :)) 256 :))
- - საცავის შექმნა    <<<<
- - - fileHand.c fileRead.c failisZoma.c (სანახავია)

- პოინტერები
- - დავწყნარდე და კოდს გადავხედო

- ღამე დავაპროგრამო ეს კიდევ :)
დეზ ნოუთს უნდა ვუყურო
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
  // ცვლადები
  int nl, counter, counter2, counter3, counter4, slesh_counter, n_counter, c;
  n_counter     = 0;
  slesh_counter = 0;

  counter4      = 0;
  counter3      = 0;    // საერთოდ რამდენი ასოა
  counter2      = 0;    // საერთოდ ვაილში რამდენჯერ შევიდა, ანუ სულ რამდენი სიტყვაა
  counter       = 0;    // თვითოეულ სიტყვაში ასოებს ითვლის
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

  bool amogdeba = false;

  // 2D array
  int sityvebSanaxi[2][300];
  int sityvebSanaxi2[2][300]; // მეორედ გაშვების დროს აქ ჩავწერ სიტყვებს ... შემდეგ გაშვებებზე მერე ვიფიქროთ

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
    // რამდენი ასოც არის სიტყვაში. იმდენჯერ + 1 (+ გეთჩარის დამთავრება) შემოვდივარ ვაილში
    if (c == 92)
    {
      // "\" ების მთვლელი. სიტყვაში თუ სლეში მოვიდა
      // printf("   movida sleshi \n");
      ++slesh_counter;
    }

    if (c == 110)
    {
      // "n" ების მთვლელი. სიტყვაში თუ n მოვიდა
      // printf("   movida n \n");
      ++n_counter;
    }

    if (c == '\n')
    {
      // "\n" ების მთვლელი. სიტყვების მთვლელი.
      // printf("end of getchar. enter new word: \n");
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
    sityvebSanaxi[0][counter3]  = c;  // masivis shevseba
    sityvebSanaxi2[0][counter3] = c; // tvin მასივი
    printf("c = %c\n",c);

    for (int j = 0; j <= counter3; j = j + 1)
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
      for (int j = counter3 - 5; j <= counter3; j = j + 1)
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
        // ბრეიქამდე. იქნებ აქედან ჩავსვა ფაილის დასრულებამდე ! << ეს ჩავსვა

        break;
      }

      printf("counter3 = %d\n", counter3);
      printf("break \n");
    }

    ++counter;

    ++counter2; // საერთოდ ვაილში რამდენჯერ შევიდა, ანუ counter3
    ++counter3; // სულ რამდენი ასოა

    if (c == 10)
    {
      // თვითოეულ სიტყვაში სიმბოლოების მთველი
      counter = 0;
    }
  }


  // სტატუსები
  printf("############################################################### \n");
  printf("######################## outputs ############################## \n");

  printf("counter3 (sul ramdeni asoa) = %d\n", counter3);
  printf("nl (number of entered words) = %d\n", nl);
  printf("slesh_counter = %d\n", slesh_counter);
  printf("n_counter = %d\n", n_counter);

  // ვაილმა რა სიტყვაც დამიბრუნა იმას ვბეჭდავ
  for (int i = 0; i <= counter3 + 5; i = i + 1)
  {
    printf("sityvebSanaxi (vailma daabruna - d )= %d sityvebSanaxi2 (c) = %c \n",sityvebSanaxi[0][i],sityvebSanaxi2[0][i]);
  }

  int failis_end_test;
  failis_end_test = 0;

  /*
  // ამოწმებს რაღაცეებს იყოს შეიძლება დამჭირდეს გადასატანად ან გადასაკეთებლად
  for (int i = 0; i <= 30; i = i + 1)
  {
  // მთელი მასივის გადარბენა (30 მდე - ისე მთელი მასივი 300 იანია)
  printf("sityvebSanaxi (გადარბენა წაკითხვამდე - d)= %d sityvebSanaxi2 (c) = %c \n",sityvebSanaxi[0][i],sityvebSanaxi2[0][i]);
  // ვიპოვო და დავბეჭდო ფაილის დასასრული და დავაბრეიქო მანდ ფორ ციკლი
  // ასკი სიმბოლოების კოდს შევადარო
  if (sityvebSanaxi[0][i] <= 255 && sityvebSanaxi[0][i] >= 0)
  {
  // piroba + mtvleli
  failis_end_test++;

} else {
// print mtvleli; print break; break from for
printf("failis_end_test = %d\n", failis_end_test);
printf("break from for (enf if file) \n");
break;
}
}
*/





/*
counter 3 სადაც შემეძლება შევცვალო (დროში პირველ მეორე მესამე გაშვებებზე ირევა მგონი)
კოდი გასაწმენდია
(გაიწმინდოს ეკლესია)
:))))))))))))))))))))))
ვა ეს ქაუნთერები ზოგ ადგილას უკან მექნება დასაბრუნებელი
და ფაილის ზრდა მუშაობს
დიდი ფაილიდან
პატარაზე თუ გადახტი ირევა
(ფაილის ზომის მიხედვით ძველი ფაილი ხომ დიდი იყო ახალი პატარაა და ვერ პოულობს დასამატებელ რიცხვს)
*/





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



  // ფაილის წაკითხვა (ნუმერაცია)
  char nums[100]; // ეს არ მჭირდება მგონი, მაგრამ იყოს
  FILE *failponteramokitxvis;

  if ((failponteramokitxvis = fopen("program.txt","r")) == NULL)
  {
    printf("Error! opening file");

    // Program exits if the file pointer returns NULL.
    exit(1);
  }

  printf("###################################### \n");
  printf("amokitxvisas ra xdeba \n");

  int mtvleli_1_sanaxi_amokitxva1, mtvleli_2_sanaxi_amokitxva2;
  mtvleli_2_sanaxi_amokitxva2 = 0;
  mtvleli_1_sanaxi_amokitxva1 = 0;

  for (int i = 0; i <= 30; i = i + 1) // ამოკითხვისას სად წერია რიცხვი
  {
    /*
    აქ არის პრობლემა ფაილის ზომით როცა ვიღებ რიცხვს როცა ფაილი პატარავდება ეგ მეთოდი
    აღარ მუშაობს
    სხვა პირობაა გასაწერი
    ბოლოს საჭირო იქნება რეფრაქტორიზაცია კოდის ))) თუ რაც ქვია
    */

    // როცა ბოლოზე მივა ამოიკითხოს როგორც d იფ იქნება დასაწერი იეე )) პაპიროზი მოვწიოთ
    if (i == res - 4) // res - 4 // aq maqvs problema. failis zomis gamgebi mchirdeba
    { // მივხდი პრობლემას
      fscanf(failponteramokitxvis,"%d", &sityvebSanaxi[0][i]);
      printf("i = counter3 + 1 \n");
      printf("sityvebSanaxi (წაკითხვის დროს - d)= %d sityvebSanaxi2 (d) = %d \n",sityvebSanaxi[0][i],sityvebSanaxi2[0][i]);
    } else {
      fscanf(failponteramokitxvis,"%c", &sityvebSanaxi[0][i]); // ამოკითხვა (ჩემი ბოლო ციფრი ამოიკითხა ჩარად და არა ინტად)
      printf("sityvebSanaxi (წაკითხვის დროს - c)= %c sityvebSanaxi2 (d) = %c \n",sityvebSanaxi[0][i],sityvebSanaxi2[0][i]);
    }

    // mtvlelebi 1 (dzveli); mtvleli2 (axali sityva)
    if (sityvebSanaxi[0][i] <= 255 && sityvebSanaxi[0][i] >= 0)
    {
      // piroba + mtvleli
      mtvleli_1_sanaxi_amokitxva1++;
    }

    if (sityvebSanaxi2[0][i] <= 255 && sityvebSanaxi2[0][i] >= 0)
    {
      // piroba + mtvleli
      // printf("TEST ABA !!!!! \n");
      // printf("sityvebSanaxi2[0][i] %d %c\n",sityvebSanaxi2[0][i],sityvebSanaxi2[0][i]);
      mtvleli_2_sanaxi_amokitxva2++;
    }
  }
  // statusebi
  printf("ricxvi aris %d\n",sityvebSanaxi[0][mtvleli_1_sanaxi_amokitxva1-1]); // <<<<<<<<<<<<<< yess
  printf("mtvleli_1_sanaxi_amokitxva1 = %d\n", mtvleli_1_sanaxi_amokitxva1);
  printf("mtvleli_2_sanaxi_amokitxva2 = %d\n", mtvleli_2_sanaxi_amokitxva2);
  printf("######### \n");
  // აქ რაღაცეები გასასწორებელია. კოდი გასაწმენდია !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  int cointer_numeracia;
  cointer_numeracia = sityvebSanaxi[0][mtvleli_1_sanaxi_amokitxva1 - 1] + 1;
  printf("TEST cointer_numeracia (zrda - d) %d\n", cointer_numeracia);
  printf("TEST cointer_numeracia (amokitxvis dros - d) %d\n",sityvebSanaxi[0][mtvleli_1_sanaxi_amokitxva1 - 1]);

  fclose(failponteramokitxvis); // არსებული ფაილის ამოკითხვის დამთავრება


  // წაკითხვის შემდეგ რაც ჩაიწერა sityvebSanaxi ში
  for (int i = 0; i <= mtvleli_1_sanaxi_amokitxva1 + 5; i = i + 1)
  {
    printf("sityvebSanaxi (wakitxvis mere rac gaxda)= %c\n",sityvebSanaxi[0][i]);
    //
    if (i == mtvleli_1_sanaxi_amokitxva1 - 1)
    {
      //
      printf("sityvebSanaxi (wakitxvis mere rac gaxda)= %d\n",sityvebSanaxi[0][i]);
    }

  }

  // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  // მეორედ ჩაწერა
  FILE *fptr_me;

  printf("file doesnt exist (tavidan - chawera ricxvis ganaxleba - mushaobs tolebistvis only) \n");
  printf("vqmnit fails \n");
  fptr_me = fopen("program.txt","w");

  if (fptr_me == NULL) // ამოქმებს არის თუარა ფაილი
  {
    printf("Error!");
    exit(1);
  }

  // chavwero da davbechdo masivshi chawerili sityvebi1
  // ვა სიტყვებსაც მინდა ცვლიდე და მაგას რატომ არ აკეთებს ვერ ვხდები
  for (int i = 0; i <= counter3; i = i + 1)
  {
    printf("sityvebSanaxi2 (meored chaweris dros ra weria aq? )= %c\n",sityvebSanaxi2[0][i]);
    fprintf(fptr_me,"%c",sityvebSanaxi2[0][i]); // ჩაწერა
  }

  // ნუმერაციის გაკეთება
  // int cointer_numeracia; // global ურად უნდა გამოვაცხადო
  printf("TEST cointer_numeracia !!!!!!!!!! %d\n",cointer_numeracia); // <<< ra xdeba? integers ar vsvav masivshi?
  sityvebSanaxi2[0][counter3 + 1] = cointer_numeracia; // <<<<< aq var
  fprintf(fptr_me,"%d",sityvebSanaxi2[0][counter3 + 1]);
  printf("#### meored gashveba ### \n");
  printf("sityvebSanaxi2[0][mtvleli_1_sanaxi_amokitxva1 - 1]) c ti = %c\n", sityvebSanaxi2[0][counter3 + 1]);
  printf("sityvebSanaxi2[0][mtvleli_1_sanaxi_amokitxva1 - 1]) d ti = %d\n", sityvebSanaxi2[0][counter3 + 1]);
  printf("#### \n");

  sityvebSanaxi2[0][mtvleli_1_sanaxi_amokitxva1] = 33;
  fprintf(fptr_me,"%c",sityvebSanaxi2[0][mtvleli_1_sanaxi_amokitxva1]);

  fclose(fptr_me); // ვა გავიჭდე ზემოთ რაღაც ავრიე დროში

} else {

  // file doesn't exist. სულ პირველი გაშვება
  FILE *fptr;

  printf("file doesnt exist \n");
  printf("vqmnit fails \n");
  fptr = fopen("program.txt","w");

  if (fptr == NULL) // ამოქმებს არის თუარა ფაილი
  {
    printf("Error!");
    exit(1);
  }

  // davbechdo masivshi chawerili sityvebi
  for (int i = 0; i <= counter3; i = i + 1)
  {
    // printf("sityvebSanaxi = %c\n",sityvebSanaxi[0][i]);
    fprintf(fptr,"%c",sityvebSanaxi[0][i]); // ჩაწერა
  }

  // ნუმერაციის გაკეთება
  // int cointer_numeracia; // global ურად უნდა გამოვაცხადო
  sityvebSanaxi[0][counter3 + 1] = 1;
  fprintf(fptr,"%d",sityvebSanaxi[0][counter3 + 1]); // <<< გადასატანი იქნება. ეხლა ეს ამოვიკითხო და სადმე ცვლადში ჩავწერო
  printf("#### pirveli gashveba ### \n");
  printf("sityvebSanaxi[0][counter3 + 1]) = %d\n", sityvebSanaxi[0][counter3 + 1]);
  printf("#### \n");

  // ფაილის დასასრულში ვსვავ ! სიმბოლოს 33
  sityvebSanaxi[0][counter3 + 2] = 33;
  fprintf(fptr,"%c",sityvebSanaxi[0][counter3 + 2]);

  // მთელი მასივის დაბეჭდვა (გასაკეთებელია - პირველი გაშვების დროს შევამოწმებ რა იწერება ბოლოში)
  // ბეჭდვას ვაკეთებ ბოლოსას d თი და ჩასმას??? d თი ვაკეთებ (ჯერ ვფოკუსირდე მხოლოდ პირველ გაშვებაზე)
  for (int i = 0; i <= counter3 + 3; i = i + 1)
  {
    printf("sityvebSanaxi (pirveli gashvebis mteli masivis bechdva)= %d\n",sityvebSanaxi[0][i]);
  }


  fclose(fptr); // ვა გავიჭდე ზემოთ რაღაც ავრიე დროში
}

// gets(brzaneba); // <<< ბრძანების მიცემა კლავიატურიდან <<<<<<<<<<<<<<<<<<<<< გამოვიყენო

return 0;
}

/*
##################### jadosnuri ჯოხები ###############
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
ტანჯულა - მწვანე წითელი ყველა ფერი მკვდარი ცოცხალი ანიმაგი - დრაკონი
*/
