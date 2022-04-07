// gagrdzeLeba - სინდისის აღდგენა (სინდისით იარე - ეგ გიშველის - და ნუ - გეშინია)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <conio.h> // <<< ra bibliotekaa?

double sameba(double ricxvi)
{
  // კუბში აყვანა
  double pasuxi = ricxvi * ricxvi * ricxvi;
  return pasuxi;
}

void gamarjoba()
{
  // პროსტა ფუნქცია
  printf("funqcia gamarjobashi var - gamarjoba\n");
}

void gagimarjos(char name[]) // შემიძლია ბევრი პარამეტერი დავამატო
{
  // პaრამეტრიანი ფუნქცია
  printf("gagimarjos - პასუხი გაგცა ტელეპორტირებულმა %s ამ\n",name);
}


int main() // main და main(void) ს შორის რა განსხვავებაა უნდა გავიგო მერე (ალბათ ამ კურსში იქნება)
{
  /* variables */
  char brzaneba[100];
  char name[33];
  const int NUMB = 5;

  int numb = 41;

  printf("ნამბერ %d ყლეები \n", numb);
  numb = 5;

  printf("ნამბერ %d ესენიც ყლეები, ზატო რუსებისკენ არ არიან \n", numb);
  printf("გაიმარჯვებენ %d \n", NUMB);
  printf("გაიმარჯვებენ %d \n", NUMB);
  printf("So\'S - ღმერთის დახმარებაა საჭირო და ჩვენი ხელის განძრევა \n");
  printf("%f \n", pow(2, 3));   // pow()   - ხარისხში აყვანა
  printf("%f \n", ceil(45.6));  // ceil()  - დამრგალება ზემოთ
  printf("%f \n", floor(45.6)); // floor() - ქვემოთ დამრგვალება


  /* Getting users input */
  gets(brzaneba);
  printf("gets(brzaneba) კლავიატურიდან შეყვანილი ბრძანება (სტრინგად) %s \n",brzaneba);

  // scanf() - რატომღაც არ მომწონდა. სლეშებს ვერ ამუღამებს "გიორგი კაპანაძე" და აღიქვავს მარტო "გიორგი" -ს )) სირობა მოკლედ
  printf("scanf() ბრძანებით შეყვანა ტექსტის \n");
  scanf("%s",&brzaneba); // ამპერსანტი უნდა თუარა ხზ. უნდა ალბათ
  printf("brzaneba = %s \n",brzaneba);


  /* Building a basic calculator - dzaan advili varianti */
  printf("///////////////////////////// \n");
  printf("Building a basic calculator - ადვილი ვარიანტი - ტუტორიალს გავდივარ უბრალოდ :)) \n");

  int ricxvi1,ricxvi2;

  printf("Enter ricxvi1 \n");
  scanf("%d",&ricxvi1); // რა მოხდება?
  printf("Enter ricxvi2 \n");
  scanf("%d",&ricxvi2); // რა მოხდება?
  printf("შეკრების ოპერაცია + \n");
  printf("Ans =  %d\n",ricxvi1 + ricxvi2);
  printf("bagebi აქვს - მერე გაასწორე. რიცხვს რომ ცნობდეს და თუ რამე სტრინგი ჩაწერე თავიდან შეგაყვანინოს \n");


  /* Building a Mad Lib Game - ar vici ra aris magram mgoni gameiketebia :)) */
  printf("///////////////////////////// \n");
  printf("Building a Mad Lib Game \n");
  char sad[100];
  char vin[100];
  char rogori[100];
  char ranairi[100];
  char gamortva;

  while(true)
  {
    printf(" \n");
    printf("while ში ვარ შემოსული - y ან n გამოგიყვანს ვაილიდან (იქნება კითხვა)\n");
    printf(" \n");

    printf("sad? adgili \n");
    scanf("%s", sad);
    printf("vin? saxeli \n");
    scanf("%s", vin);
    printf("rogori? tma \n");
    scanf("%s", rogori);
    printf("ranairi? shegrdzneba \n");
    scanf("%s", ranairi);
    // scanf("%s%s", ranairi,ranairi2); // ორი სიტყვის შეყვანა ერთად სლეშის შემდეგ გიორგი კაპანაძე ვთქვათ :)

    printf(" \n");
    printf("%s cudi amindia \n", sad);
    printf("%s tmaa %s \n", vin, rogori);
    printf("giorgis elis shexvedra %s \n", ranairi);
    printf("ჩვევაში უნდა გადაგივიდეს კოდირება - ჰeბით \n");
    printf(" \n");

    printf("გინდა თამაშის გაგრძელება? (y or n) \n");
    scanf(" %c", &gamortva);
    printf("gamortva = %c \n",gamortva);

    if (gamortva == 121) // შეიძლება ასკიი თ უნდა შევადარო
    {
      printf("aq var \n");
      continue;
    } else
    {
      printf("break shi var \n");
      break;
    }
    // while it davatrialo da sanam ar vetyvi shemyavdes da shemyavdes am debili tamashistvis sityvebi1
    // aseve bagebi iqneba tu ricxvebs sheviyvan sityvebis magivrad. magram mkidia exla
  }


  /* Arrays in C */
  int masiviRicxvebis[] = {1,2,3,4,5,6,7,8,9,0};
  // This program will create different sequence of
  // random numbers on every program run
  // Use current time as seed for random generator
  srand(time(0));
  for(int i = 0; i<4; i++)
  printf(" %d \n", rand());
  masiviRicxvebis[3] = rand();
  printf("masivi[3] = %d \n", masiviRicxvebis[3]);


  /* Functions */
  gamarjoba();
  gagimarjos(vin);

  /* Return statements fro funqciotns */
  printf("sameba = %f", sameba(masiviRicxvebis[3]));

  return 0;
}









































// (- ორი მთავარი ლოცვა -)
// ნუგეშის მცემელის ლოცვა
// მამაო ჩვენო
// ბევრი იკითხეთო. ცოდნა. შრომა.
// უმანკოს შეცდენა ადვილია და ღმერთი წყალობს :))) უმანკოს
// სინდისი გააღვიძე.
// სხვას ისეთი რამე არ გაუკეთო, რაც შენ რომ გაგიკეთონ გეწყინება.
// სამი გამოცდა. უფალი ჩავიდა ჯოჯოხეთში და სულები ამოიყვანა. ანუ ქვა მერე გადახტომა.ჯოჯოხეთში ჩავარდნა.
// და იქ ეშმკას არ უნდა ეთაყვანო
// სიკვდილი ანუ. 930 წლის ადამი ამოიყვანა. ევაც ტიროდა. ევას სიცოცხლე - ქვია სხვანაირად.
// აmპარტავნება. სიზმარმაცე. გარყვნილება. (დემონები)
// მიშას სიტყვები: არ უნდა მისცე ხელმწიფება ოლიგარქებს. :))))
//
// შრომა შრომა და შრომა. ბებო მიყვება თინას ამბავს.
// მარტო როცა დაგტოვებენ, რწმენა მაშინ უნდა შეინარჩუნო. :))
// ყოველწუთას გამოცდაა გვაქვს. უნდა ჩავაბაროთ ყოველ წუთს. არასდროს არ მორჩება ეს. ვაჰ.
// აინშტაინმა თქვა ისეთი სიტყვები აქვს იესოს მაგის გარდა ვერავინ იტყოდაო. ღმერთი არის სიყვარული. :))
// DMT სულის მოლეკულა - სიყვარულის დროს სუნთვის დროს წარმოიქმნება და გვაძლევს ამ სიზმრის ნახვის საშშუალებას სადაც ვართ
// ღმერთი როცა გსჯის მისი ძუძუები გლოცავენ. :)))
// არ უნდა გეშინოდესო. მამა გაბრიელმა. ესეა საჭიროო. :)
// ნოეს სამი შვილი. სემი იაფეტი და ქამი
// თურქებზე ვლაპარაკობთ.
// იაფეტელები ვართ ქრისტიანები. იზრაელი იბერიელი ერთი და იგივეაო :)
// მომიტევე ვითარცა მე მივუტევებ სხვებს. გთხოვ. :( სული მტკივა - მეშინია) - სინანულით ვიწმინდებით. და შრომით.
// სინანულით და შრომით. სხვისთვის როცა შრომობ მოგეტევება.
// ისევ სინდისთან მივედით. :)
// აპოკალიფსია? ღმერთი დაალაგებს ყველაფერს როგროც საჭიროა :)
// ისევ სინდისთან მოვედით
// პაპავ პაპავ პაპუნაა ვ :))
// აღზდექ შე მაიმუნო )))
// ხარებაა? მოდი გიტ ჰაბს ვახაროთ ეს ამბავი
// ეხლა უნდა დამეწერა რომ ჰმ.. იცი რაზე ვგიჟდები? სულ ბიგინინგში რომ ვარ იმენა
// და მერე წავიკითხე წინა თავი აპოკალიფსიაო. და შემდეგი იასნია დასაწყისი იქნება.
// დასაწყისი იწყება. ანუ / მეც მაგიტომ ვარ ბიგინერი იესს :))
// ყველაფერი ოკ იქნება
