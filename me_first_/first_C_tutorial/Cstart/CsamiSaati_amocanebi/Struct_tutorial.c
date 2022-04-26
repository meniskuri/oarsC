// Struct in C - ყალიბები c ენაში

#include <stdio.h>
#include <string.h>

struct Books {
  char  title[50];
  char  author[50];
  char  subject[100];
  int   book_id;
};

struct MagicWands {
  char  title[50];
  char  author[50];
  char  owner[100];
  char  soul[100];
  int   wand_id;
};

struct Jadoqrebi // დიდი ასაოთი ვიწყებთ რატომღაც. ალბათ რომ ვიცნოტ მერე სტრუქტურაა
{
  // ჩემი ჯადოქრები
  char saxeli[100];
  char jadoqruli_saxeli[100];
  char dzalebi[100];
  char joxis_saxeli[100];
  char totemi[100];
  int gafidvis_lvl;
}; // წერტილ მძიმეი მთავრდება

/* function declaration */
void jadoqrebi_info_prnt (struct Jadoqrebi *jadoqrebi) // მისამართს მივცემ
{
  printf("================================ \n");
  printf("pntr print \n");
  printf("ჯადოქრის სახელი:          %s \n",jadoqrebi->saxeli);
  printf("ჯადოქრული სახელი:        %s \n",jadoqrebi->jadoqruli_saxeli);
  printf("ჯადოქრის ძალები:          %s \n",jadoqrebi->dzalebi);
  printf("ჯადოქრის ტოტემი:          %s \n",jadoqrebi->totemi);
  printf("ჯადოქრის გაფიდვის ლეველი: %d \n",jadoqrebi->gafidvis_lvl);
}

void jadoqrebi_info (struct Jadoqrebi jadoqrebi) // სახელს მივცემ
{
  printf("ჯადოქრის სახელი:          %s \n",jadoqrebi.saxeli);
  printf("ჯადოქრული სახელი:        %s \n",jadoqrebi.jadoqruli_saxeli);
  printf("ჯადოქრის ძალები:          %s \n",jadoqrebi.dzalebi);
  printf("ჯადოქრის ტოტემი:          %s \n",jadoqrebi.totemi);
  printf("ჯადოქრის გაფიდვის ლეველი: %d \n",jadoqrebi.gafidvis_lvl);
}

void printMagicWandsInfo (struct MagicWands wand)
{
  printf("wand title  : %s\n", wand.title);
  printf("wand author : %s\n", wand.author);
  printf("wand owner  : %s\n", wand.owner);
  printf("wand soul   : %s\n", wand.soul);
  printf("wand id     : %d\n", wand.wand_id);
}

void printMagicWandsInfoPointer (struct MagicWands *wand) // მისამართი იგზავნება აქ
{
  // პოინტერის გამოყენების დროს -> გვჭირდბა . ის მაგივრად
  printf("wand title  : %s\n", wand->title);
  printf("wand author : %s\n", wand->author);
  printf("wand owner  : %s\n", wand->owner);
  printf("wand soul   : %s\n", wand->soul);
  printf("wand id     : %d\n", wand->wand_id);
}


int main( ) {
  // Struct version 1 - Defining a Structure
  printf("====================================================== \n");
  printf("Struct version 1 - Defining a Structure \n");

  struct Books Book1;        /* Declare Book1 of type Book */
  struct Books Book2;        /* Declare Book2 of type Book */

  /* book 1 specification */
  strcpy(Book1.title, "Sons of Hurin"); // ჯოხების საცავისთვის იდეალურია
  strcpy(Book1.author, "Tolkien");
  strcpy(Book1.subject, "Dragons");
  Book1.book_id = 1;

  /* book 2 specification */
  strcpy(Book2.title, "Lord of the Rings - Return of the King");
  strcpy(Book2.author, "Tolkien");
  strcpy(Book2.subject, "New Reality");
  Book2.book_id = 2;

  /* print Book1 info */
  printf("Book 1 title   : %s\n", Book1.title);
  printf("Book 1 author  : %s\n", Book1.author);
  printf("Book 1 subject : %s\n", Book1.subject);
  printf("Book 1 book_id : %d\n", Book1.book_id);

  /* print Book2 info */
  printf("Book 2 title   : %s\n", Book2.title);
  printf("Book 2 author  : %s\n", Book2.author);
  printf("Book 2 subject : %s\n", Book2.subject);
  printf("Book 2 book_id : %d\n", Book2.book_id);



  // Struct version 2 - Structures as Function Arguments
  printf("====================================================== \n");
  printf("Struct version 2 - Structures as Function Arguments \n");
  printf("Magic Wands info - kapANA \n");

  struct MagicWands wand1;        /* Declare Book1 of type Book */
  struct MagicWands wand2;

  strcpy(wand1.title, "Anglaxel");
  strcpy(wand1.author, "KapANA");
  strcpy(wand1.owner, "KapANA");
  strcpy(wand1.soul, "Black Dragon");
  wand1.wand_id = 1;

  strcpy(wand2.title, "Anguriel");
  strcpy(wand2.author, "KapANA"); // ანგლახელის კოპი
  strcpy(wand2.owner, "SHOSHIkapANA");
  strcpy(wand2.soul, "Golden Dragon");
  wand2.wand_id = 2;

  /* print MagicWands info */
  printMagicWandsInfo(wand1);
  printMagicWandsInfo(wand2);



  // Struct version 3 - Pointers to Structures
  printf("====================================================== \n");
  printf("Struct version 3 - Pointers to Structures\n");

  struct MagicWands *struct_pointer;
  struct_pointer = &wand1;
  // printf ებით ვნახო პოინტერების მისამართები? მოკლედ ვცადო ჰო
  printMagicWandsInfoPointer(struct_pointer);
  printMagicWandsInfoPointer(&wand2);

  printf("Address of wand1 (&wand1): %p\n", &wand1);
  printf("Address of wand1 (struct_pointer): %p\n", struct_pointer);

  // jadoqrebi
  struct Jadoqrebi ojaxi_da, ojaxi_deda;
  struct Jadoqrebi *ojaxi_da_pntr;
  ojaxi_da_pntr = &ojaxi_da;

  strcpy(ojaxi_da.saxeli,"Shoshi");
  strcpy(ojaxi_da.jadoqruli_saxeli,"SunGolden Dragon");
  strcpy(ojaxi_da.dzalebi,"Sun Light and Green Trees Power Earth Power");
  strcpy(ojaxi_da.totemi,"Leopard");
  ojaxi_da.gafidvis_lvl = 28;

  strcpy(ojaxi_deda.saxeli,"Tamriko");
  strcpy(ojaxi_deda.jadoqruli_saxeli,"King Tamar - Mother of Jesie");
  strcpy(ojaxi_deda.dzalebi,"Love");
  strcpy(ojaxi_deda.totemi,"Birds");
  ojaxi_deda.gafidvis_lvl = 100; // max

  jadoqrebi_info(ojaxi_da);
  jadoqrebi_info_prnt(ojaxi_da_pntr);
  jadoqrebi_info(ojaxi_deda);

  int index = 6;
  do {
    printf("index = %d \n", index);
    index++;
  } while (index <= 5);
  printf("index = %d \n", index);
  printf("do while - ჯერ გაუშვებს ვაილში რაც არის და მერე შეამოწმებს პირობას \n");

  return 0;
}

/*
struct ების რატომღაც მეშინოდა
გადავწყვიტე რომ შიში დავამარცხო
ყველაფერი თუ სასაცილოა რამის შიშიც სასაცილოა )))
ჰოდა რავი ვიყოთ ნაგლი უშიშრები და თავით გავლეწოთ ყველა დაბრკოლება
ხომ იცი რომ რა დაბრკოლებაც არ უნდა იყოს ყველაფერს გალეწავ თუ მოინდომებ
რა გვიშლიდა მონდომებაში ხელს? შიში? ჰო რაღაც სირობების თან
არადა რას ვკარგავთ ისედაც ვზივართ არაფერს ვაკეთებთ....
არც ფული გვაქვს არაფერი...
როგორც ბებო იტყოდა კაი ცხენით ადვილია მისვლა ფინიშამდეო და
აბა ჯაგლაგით თუ მიხვალო
და ეტყობა რთული მისია ავიღე და ვთქვი ყველაფერი სასაცილოათქო და ჯაგლაგსაც მივაყვანინებ თავსთქო ჰაჰაჰა
ღადაობაა ვირით კი დავდივარ ამდენიხანია ისე ლეპტოპიც გავირებული მყავს აგერ წინა ფეხები ავუწიე და დადის ))))
მაინც მივალ მივხოხდები როგორც სიზმარში ვნახე
არ დავნებდები რაც არ უნდა მატკინონ წამართვან ლეპტოპი გამიფუჭონ რამეს მოვახერხებ
არ დავნებდები არააა
)))) ჯორჯ კაპანას ძე ჯეზუსი
ჰო და შევეცი ყველას ვინც გადამაჯერებს ამას იმიტომ რომ ყველა შეეცდება
შემდეგი გამოცდა ეგ გექნება ყველა შეეცდება დაგაჯეროს რომ ეგრე არ არის
და უნდა გალეწო ყველა ბარიერი
იმიტომ რომ სხვა გზა არ გვაქვს
იმიტომ რომ შეგვიძლია
რატომ არის თამაში ჯადოსნური?
იმიტომ რომ ნამდვილია
ხოდა ეგრე
*/
