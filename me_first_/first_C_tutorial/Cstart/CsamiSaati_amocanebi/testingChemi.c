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

/* function declaration */
void printMagicWandsInfo( struct MagicWands wand )
{
  printf( "wand1 title  : %s\n", wand.title);
  printf( "wand1 author : %s\n", wand.author);
  printf( "wand1 owner  : %s\n", wand.owner);
  printf( "wand1 soul   : %s\n", wand.soul);
  printf( "wand1 id     : %d\n", wand.wand_id);
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

   return 0;
}
