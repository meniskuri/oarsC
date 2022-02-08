/*
- TESTInG chapter 1.5.3 Line counting
- Count lines in input
TODO:
 - ვაილიდან გამოსვლა დასაწერია. მელონზე
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


main()
{
  // ცვლადები
  int nl, c, counter, counter2;
  counter2 = 0; // საერთოდ ვაილში რამდენჯერ შევიდა, ანუ სულ რამდენი სიტყვაა
  counter  = 0; // თვითოეულ სიტყვაში ასოებს ითვლის
  nl       = 0; // სიტყვების რაოდენობა

  // ბულ იან ეგოები მერევა. მაგრამ აზრი არ აქვს მაგას ეხლა
  bool Me     = false; // 77
  bool Erti   = false; // 69
  bool Leo    = false; // 76
  bool Oniani = false; // 79
  bool N_vi   = false; // 78

  // 2D array
  int sityvebSanaxi[2][300];


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
      printf("   movida sleshi \n");
    }

    if (c == 110)
    {
      // "n" ების მთვლელი. სიტყვაში თუ n მოვიდა
      printf("   movida n \n");
    }

    if (c == '\n')
    {
      // "\n" ების მთვლელი. სიტყვების მთვლელი.
      // printf("end of getchar. enter new word: \n");
      ++nl;
    }

    if (c == 10)
    {
      // სიტყვაში სიმბოლოების მთველი
      counter = 0;
    } else {
      // წერა. სიტყვების ასკი კოდების
      // printf("counter = %d\n", counter);
      printf("ascii of c words = %d\n", c);
      printf("counter = %d\n", counter);
    }

    // მასივში ჩაწერა. სიტყვის |სიტყვა|counter| es sanaxavia kidev
    sityvebSanaxi[0][counter2] = c;

    ++counter;
    ++counter2; // საერთოდ ვაილში რამდენჯერ შევიდა, ანუ სულ რამდენი სიტყვაა
  }

  // სტატუსები
  printf("counter2 = %d\n", counter2);
  printf("nl (number of entered words) = %d\n", nl);

  /*
  რა დედის ტყვნა უნდა ამას ეხლა?
  მგონი cntr c თი ვრთავ პროგრამას მაგიტომ ემართება ესეთი რაღაც (შესამოწმებელია)
  */

  for (int i = 0; i <= 10; i = i + 1)
  {
    //printf("asoebi - %d\n",sityvebSanaxi[0][i]);
    printf("shemovedi aq\n");
  }
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
ქეთ
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
*/