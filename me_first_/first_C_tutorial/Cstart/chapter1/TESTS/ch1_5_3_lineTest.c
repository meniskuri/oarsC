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
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> // << შემოწმების დროს რაღაც ფუნქციისთვის მჭირდება

// globals
int cointer_numeracia;

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

  // შეიძლება ზუსტად ეს გამომადგეს. ყოველ შემდეგ გაშვებაზე
  // ტესტებია გასაკეთბელი
  // მასივების პარაგრაფი სანახავი
  // მგონი გამოვა (ცდა უნდა)
  // ჯერ ანუ მეორე მასივის (ტვინ მასივის) - იდეა ვცადო <<<<<<<<<<<<<<<<<<<<<<<<<<< აქ ვარ <<<<<<<<<<<<<<<<<<<
  int sityvebSanaxi2[2][300]; // მეორედ გაშვების დროს აქ ჩავწერ სიტყვებს ... შემდეგ გაშვებებზე მერე ვიფიქროთ


  // ნახვა ფაილი მართლა არსებობს თუარა
  // თუ არსებობს. რა ქნას? ვთქვათ ყოველ გაშვებაზე შლიდეს და ახლიდან ქმნიდეს ფაილს.
  // თუ არ არსებობს. რა ქნას? შექმნას და ჩაწეროს ასოები (სიტყვები).
  // ფაილებთან მუშაობა გასაუმჯობესებელი იქნება და უფრო ლამაზად მოვიფიქრო სიტყვების სანახი

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
    sityvebSanaxi[0][counter3] = c;  // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< masivis shevseba
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
  // TODO
  // - მასივში ჩაწერილში სიტყვების ძებნა (ვთქვათ) <<
  // - საცავის გაკეთება <<
  // - ამოკითხვა და დაბეჭდვა საცავიდან <<
  // - ნუმერაცია წაკითხვა ამოკითხვა (საცავში შენახვა - საცავიდან ამოკითხვა მიმატება თავიდან ჩაწერა)
  // - დამავიწყდა აქ რა უნდა დამეწერა (დასატენია ლეპტოპი)

  // - საცავის რეზერვირების იდეა? ან ჯერ უბრალოდ რიცხვი დაემატოს რამდენჯერ იწერება. ფაილიდან ამოკითხვა გასაკეთებელია
  // - პარაგრაფის გადახედვა

  printf("counter3 (sul ramdeni asoa) = %d\n", counter3);
  printf("nl (number of entered words) = %d\n", nl);
  printf("slesh_counter = %d\n", slesh_counter);
  printf("n_counter = %d\n", n_counter);

  // ვაილმა რა სიტყვაც დამიბრუნა იმას ვბეჭდავ
  for (int i = 0; i <= counter3; i = i + 1)
  {
    printf("sityvebSanaxi (vailma daabruna - d )= %d sityvebSanaxi2 (c) = %c \n",sityvebSanaxi[0][i],sityvebSanaxi2[0][i]);
  }

  // <<<<<<<<<<<<< აქ ვარ <<<<<<<<<<<<<< მაღაზიიდან რომ მოხვლ ნახე <<<<<<<<<<<<<<<<<<<<<<<<<<<<
  // ფაილის მთვლელის გაკეთება . 300 მასივია
  // გადაირბენს ნახავს სად მთავრდება ამოიწერს მაგას შეინახავს.
  // მერე ამოკითხვისასაც გადაირბენს მთლიან მასივზე ვთქვათ სადაც დამთავრდება იქ ამოაგდებს ფორს ოკ ;)
  // ერთ შემთხვევაში ნუმერაციას ამოიღებს ამოკითხვისას მიღებული ქაუნთერით
  // მერე ჩაწერისას ჩაწერს counter3 ში რაც იქნება იმით + წინა ამოღებული რიცხვი
  //
  int failis_end_test;
  failis_end_test = 0;

  /*
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
  კოდი გასაწმენდია
  */


  /*
  აქ იფი იქნები
  შეამოწმებს არის ფაილი თუ არა
  და ორ გზას შემოგთავაზებს მოვლენების განვითარების
  მგონი კარგი იქნება ფუქნციების გამოყენებას თუ ვისწავლი
  მაღაზიაში გასვლა საჭიროა :))
  მოვალ და გავაგრძელებ
  იფ იფ ))

  ამოკითხვის დროსაც ქაუნთრების პრობლემა მაქვს
  ისე უნდა გავაკეთო ქაუნთერები რომ არ მერეოდეს
  ერთმანეთში
  გავასწორებ
  საათ
  ქაუნთერებს
  ყველას საჭირო დროზე ფორებში
  */

  if( access("program.txt", F_OK ) == 0 ) { // unistd.h - თუ არსებობს ეს ფაილი

    printf("file exists \n");

    // ფაილის წაკითხვა (ნუმერაცია)
    // აქედამ უნდა ამოვიწერო ბოლო ციფრი
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
      // როცა ბოლოზე მივა ამოიკითხოს როგორც d იფ იქნება დასაწერი იეე )) პაპიროზი მოვწიოთ
      if (i == counter3 + 1)
      {
        fscanf(failponteramokitxvis,"%d", &sityvebSanaxi[0][i]);
        printf("i = counter3 + 1 \n");
        printf("sityvebSanaxi (წაკითხვის დროს - d)= %d sityvebSanaxi2 (d) = %d \n",sityvebSanaxi[0][i],sityvebSanaxi2[0][i]);
      } else {
        fscanf(failponteramokitxvis,"%c", &sityvebSanaxi[0][i]); // ამოკითხვა (ჩემი ბოლო ციფრი ამოიკითხა ჩარად და არა ინტად)
        printf("sityvebSanaxi (წაკითხვის დროს - c)= %c sityvebSanaxi2 (c) = %c \n",sityvebSanaxi[0][i],sityvebSanaxi2[0][i]);
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
    printf("mtvleli_1_sanaxi_amokitxva1 = %d\n", mtvleli_1_sanaxi_amokitxva1);
    printf("mtvleli_2_sanaxi_amokitxva2 = %d\n", mtvleli_2_sanaxi_amokitxva2);
    printf("######### \n");

    int cointer_numeracia;
    cointer_numeracia = sityvebSanaxi[0][counter3 + 1] + 1;
    printf("TEST cointer_numeracia (zrda - c) %c\n", cointer_numeracia);
    printf("TEST cointer_numeracia (amokitxvis dros - c) %c\n",sityvebSanaxi[0][counter3 + 1]);
    printf("TEST cointer_numeracia (zrda - d) %d\n", cointer_numeracia);
    printf("TEST cointer_numeracia (amokitxvis dros - d) %d\n",sityvebSanaxi[0][counter3 + 1]);

    fclose(failponteramokitxvis); // არსებული ფაილის ამოკითხვის დამთავრება


    // წაკითხვის შემდეგ რაც ჩაიწერა sityvebSanaxi ში
    for (int i = 0; i <= counter3 + 5; i = i + 1)
    {
      printf("sityvebSanaxi (wakitxvis mere rac gaxda)= %c\n",sityvebSanaxi[0][i]);
    }


    // აქამდე ვარ მოსული. ქვემოთ უნდა გავარკვიო. შეიძლება აქ
    // იყოს თუ ქვემოთ გახსნა ჩაწერა თავიდან უნდა დავწერო ან აფენდი
    // ზემოთ ფაილი რომ გავხენით cointer_numeracia შეივსო გახსნილი ფაილიდან მიღებული ინფორმაციით
    // ეს ბლოკი სხვაგან უნდა გადავდო
    // ქვემოთ

    // >>>>>>>>>> აქ ვარ >>>>>>>>>>>>>>>
    // sityvebSanaxi2 - ით ვაკეთებ ჩაწერას
    // და ისე დაემატოთ ერთმანეთს (for ებით გადარბენის დროს counter3 ს სავარაუდოდ
    // შესამოწმებელია sityvebSanaxi ის 2 ის ბოლო რიცხვები ცალცალკე

    // ეშლება ამ ორ მასივში ნუმერაციის მოძებნა) ანუ კიდევ ერთი ქაუნთერი იქნება გასაკეთბელი
    // ეს ორი მასივი დავბეჭდო ორივე (გვერდიგვერდ)
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
    printf("TEST cointer_numeracia !!!!!!!!!! %c\n",cointer_numeracia); // <<< ra xdeba? integers ar vsvav masivshi?
    sityvebSanaxi2[0][counter3 + 1] = cointer_numeracia;
    fprintf(fptr_me,"%d",sityvebSanaxi2[0][counter3 + 1]);
    printf("#### meored gashveba ### \n");
    printf("sityvebSanaxi2[0][counter3 + 1]) c ti = %c\n", sityvebSanaxi2[0][counter3 + 1]);
    printf("sityvebSanaxi2[0][counter3 + 1]) d ti = %d\n", sityvebSanaxi2[0][counter3 + 1]);
    printf("#### \n");

    sityvebSanaxi2[0][counter3 + 2] = 33;
    fprintf(fptr_me,"%c",sityvebSanaxi2[0][counter3 + 2]);

    fclose(fptr_me); // ვა გავიჭდე ზემოთ რაღაც ავრიე დროში

  } else {
    // file doesn't exist
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




  /*
  რისი გაკეთება მინდა?
  მოსაფიქრებელი მაქვს
  აუ მაგრად ჩემშია
  შიმშილი
  ვნახო
  იქნებ
  რამე გამოვიდეს

  აა ნუმერაცია უნდა გავაკეთო
  მაგრამ რაღაც პრობლემა შეგვექმნა
  და მაგაზე უნდა დავფიქრდე
  */

  /*
  // ფაილებთან მუშაობა. შემოწმება. წაკითხვა. შექმნა. ახლის. ჩაწერა.
  // ფაილის წაკითხვა (ნუმერაცია)
  char nums[100]; // ეს არ მჭირდება მგონი, მაგრამ იყოს
  FILE *failponteramokitxvis;

  if ((failponteramokitxvis = fopen("program.txt","r")) == NULL)
  {
    printf("Error! opening file");

    // Program exits if the file pointer returns NULL.
    exit(1);
  }

  for (int i = 0; i <= counter3 + 1; i = i + 1)
  {
    //
    fscanf(failponteramokitxvis,"%c", &sityvebSanaxi[0][i]); // ამოკითხვა
    printf("sityvebiSsanaxi (amokitxva) =%c\n", sityvebSanaxi[0][i]);

  } // აქედან უნდა გავაგრძელო შესრულება ყველაფერს რიგ რიგობით მივყვე იასნო აქ ვარ <<<<<<<<<<<

  // ნიუ ბიგინინგ :)))
  // ....
  // .. მოვალ მალე
  int cointer_numeracia;
  cointer_numeracia = sityvebSanaxi[0][counter3 + 1] + 1; // ეს გადასატანი იქნებიან
  printf("cointer_numeracia (amokitxvis dros) %c\n",cointer_numeracia);

  fclose(failponteramokitxvis);

  // დავბეჭდო მთელი მატრიცა
  // მოსაფიქრებელია მეორედ გაშვების დროს რას აკეთებდეს. ალბათ გადაწეროს თავიდან ახალი შეყვანილი სიტყვა?
  // ჯერ დავბეჭდოთ მთლიანი მასივი


  /*
  // ფაილის თავიდან გახსნა და ჩაწერა cointer_numeracia = cointer_numeracia + 1
  // მერე მატრიცის შექმნაზე ფიქრი
  // აქ პრობლემა მაქვს
  FILE *fptr2;
  // აქ ვიწყებ ჩაწერას ბოლო ციფრის

  fptr2 = fopen("program.txt","w"); // << w არის გახსნა და გადაწერა. ეს უნდა შევცვალო

  if (fptr2 == NULL) // ამოქმებ არის თუარა ფაილი
  {
    printf("Error!");
    exit(1);
  }

  // ჩავწერო + 1 (ვნახოთ)
  fprintf(fptr2,"%d",cointer_numeracia); // <<< გადასატანი იქნება. ეხლა ეს ამოვიკითხო და სადმე ცვლადში ჩავწერო
  printf("#### \n");
  printf("cointer_numeracia = %d\n", cointer_numeracia);
  printf("sityvebSanaxi[0][counter3 + 1]) = %d\n", sityvebSanaxi[0][counter3 + 1]);
  printf("#### \n");

  fclose(fptr2); // ვა გავიჭდე ზემოთ რაღაც ავრიე დროში
  */

  // gets(brzaneba); // <<< ბრძანების მიცემა კლავიატურიდან <<<<<<<<<<<<<<<<<<<<< გამოვიყენო

  return 0;
}




























/*
ვაილიდან გამოსვლაა გასაკეთებელი (ზედა პრობლემა შეიძლება მოაგვაროს)
ძირს ცენზურა
თავისუფლება
გასაღებია
სიყვარული
ერთგულება
მეგობრის
პატივისცემა
მშობლის

პრობლემები. მამენტ მე მეყლევება, მაგრამ როცა ვოლდემორი
ჩაძვრება მანდ და თავის ბინძურ ჩრდილებს გაუშვებს
მერე შეიძლება გაპრობლემდეს მართლა
მაგრამ ჩვენ მაგისთვის არ ვართ?
რომ ჰორკრუქსები
გავანადგუროთ?
აბა რა ))

შვილი რომ მყავდეს გამოვყლევდები ისე გამიხარდება :))
რაც დასათმობი იყო. ყველაფერი დავთმე.
იმენა ნახტომში ვარ.
მი ვენ დე :)
იესოს

ნარკომანის ფარდა მცილდება. უფრო ნათლად ვხედავ რა როგორ.
შეფასებების სიტემა ცოტა სხვანაირი მაქვს. მამენტ სიზმარია ეს.
უბრალოდ სხვების შეხედულებას უფრო კარგად ვხედავ.
სხვისი გადმოსახედიდან. ვინც არ იყო ისე გასული.
როგორც მე. იმას უფრო ტკივა? არ ვიცი.
უბრალოდ აზრები და მისიები.
გადაწყვეტილებები.
მე ვაფშე.
გასული
ვიყავი
ეე
ე

ღმერთს და სამყაროს ვერ მოატყუებ
თქვი მეგობარი. მელონ.
მეგობარი
მეგობრობა
წმინდაა
ყოველთვის

ჯოკრები დავყარეთ ტელეგრამში
ან ნიჟე იქმნება ან
წაგვიყვანენ
მაგრამ მე ნიჟე
ანუ ან ნიჟე იქნება ან მოგვჯოკრავენ
ნიჟე ნიჟეა რავი
დათმობა
მე
ამინ

ღამე ჩაჯდომებიც უნდა დავამუღამო
უეჭველი. საინტერესო გამოვა.
მოკლედ ნუ ნერვიულობ ეხლა ამას უფრო აპროგრამებ
ჰოდა ყველაფერი ოკ
იქმნებაო
იესომ

კონცენტრაცია.
მონდომებაა რა მაინც.
მინდა სწავლა
მინდა სწავლა
ღმერთო დამეხმარე
მინდა
სწავლა
გთხოვ დამეხმარე თავო ჩემო ))
ჯორჯ კაპან ეგოს დონეზე გთხოვთ დამეხმაროთ
კაი ტვინი ნუ მოტყანი გეხმარებით ბლიად :D ))
mpirdebi?
კი ))

პირობა პირობაა ბრატ.
სიტყვაა ნათქვამი
მოგთხოვო
იესომ

ჯორჯმა
მეც მოგთხოვო უპასუხა )))

ნანა შენც გპირდები ცუდი ბიჭი აღარ ვიქნები
მაგრამ ცუდი ბიჭის როლით შემიძლია
ქაჯებს შევუძვრე გულში
და სიყვარული
ჩავუდო

გპირდები ნანა
შენი წმინდანობა მაიძულებს მაგას
რომ დაგპირდე
მადლობა ყურადღებისთვის

მე ბერი ასტრონომი ჯორჯი
ქუჩაში მეძახიან კაპანას
შამანები მგელს
სახლში ბუშტუკას ))

შენ რას დამიძახებ?

უცხო დარაბებში ნუ ეძებ სიყვარულს
გახსოვდეს ეგ
თუ სიყვარულს ეძებ
უნდა
დარჩე მარტო
გრიზლი (მწვანე ოჯახი)

რა გეგონა არებად
გაგცემენ პასუხებს
გამოცდა
სიტყვა ნათქვამია
შესრულება
ჭირდება
იესომ
კაიო ))
ჯორჯმა აუ რეებს მაკეთებინებო )))

კაი დაწყნარდი და
იმეცადინე
ბლიად

ზედმეტი მოგდისო
ტოჟე მნე ხრისწიანკა ბლიად
არადა ლოცვების დროს მაგრად იდებს თავს ალბათ
მაგრამ
შიში
ურწმუნოება
მესმის
ყველაფერი
მეც კი გავბრაზდი
რატო?
ამპარტავნება ოღონდ იმის რომ აპარტავნება რატო აქვს ეგრე რომ დამელაპარაკათქო
სიმართლეს უნდა ჩავხედოთ თვალებში
ნანა დამეხმარება
უკვე დამეხმარება
მახვედრებს
ნანა ბოდიში
გიყენებ ხანდახან (ინტელექტუალურად ემოციურად)
ქუჩებში მხვდება წარწერები სულ (ნანა ღვინო ანუ სასწაულს მოახდენს ნანა

realურად
შეხედე სიზმრებს
რეალობას ზიმრისეულად
და
ეგაა რა

შეიძლება არის რაღაც
რასაც ვერ ვხდები კიდევ
მიხვები
დონთ ვორი
ბი ხეფი
სამთაიმს ჯასთ
ბი ))
ფუტკარი
ჰაჰაჰა კაია

მივხდი. შაჰაბასი ვიყავი.
აღარ მინდა შაჰაბასობა
თავისუფლება
გიორგი მინდა ვიყო
გიორგი ბრწყინვალე
იბადება
ვორიორი
არა მონობას
არა ძალადობას
არა ძმა ძმის კვლას
თავისუფლება ქეთოს
და მეც
ილოსაც
და ყველას

ღმერთო დაგვილაგე გზები
დაგვეხმარე
განთავისუფლებაში

არა მონობას
არანაირს

წინასწარმეტყველება ახდება (სვანი)

ჯოხების ოსტატი
ხოდზეა
ოლ ი ვანდერ
ჩემშია

მარიამის პირობა
როგორც ყოველთვის შედარების პრობლემა მაქვს :))

ქართველებო
კატანებო

დევით კოპერფილდი
ილუზიების წიგნის
წაკითხვა
*/
