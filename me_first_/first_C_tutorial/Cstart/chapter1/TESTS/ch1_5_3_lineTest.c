/*
- TESTInG chapter 1.5.3 Line counting
- count lines in input

- ეს კოდი. გეთჩარით სიტყვებს იღებს. და მერე ითვლის სიტყვაში რამდენჯერ მოხდა
"/n" შემთხვევა ერთდოულად. '/n' ერთი სიმბოლოა. ასკიში უდრის 10 სო. ამეებს ვეძებ
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



main()
{
  // ცვლადები
  int nl, c, counter;
  nl      = 0;
  counter = 0;

  bool pirobadidi = false;

  while ((c = getchar()) != EOF)
  {
    // რამდენი ასოც არის სიტყვაში. იმდენჯერ + 1 (+ გეთჩარის დამთავრება) შემოვდივარ ვაილში
    printf("c (ascii sheyvanili sityvis asoebi) = %d\n",c);

    if (c == '\n') // ასკი კოდს შევადაროთ. n >> 110; / >> 47;
    {
      ++nl;
      // როცა მოვა სლეში და მერე ნ ეგ შემთხვევა მჭირდება
      printf("+ (n roca movida) \n");
    }

    // ++counter;
  }

  printf("nl = %d\n", nl);
  printf("counter = %d\n", counter);
}

/*
// ტესტი
// დაითვალოს ლაინების რაოდენობა /////////////////

FILE *fileptr;
int  count_lines = 0;
char filechar[51], chr;

// printf("Enter file name: ");
// scanf("%s", filechar);

fileptr = fopen("parolebisSacavi.txt", "r");
chr = getc(fileptr); //extract character from file and store in chr
while (chr != EOF) // ენდ ოფ ფაილ
{
    //Count whenever new line is encountered
    if (chr == 'n')
    {
        count_lines = count_lines + 1;
    }
    //take next character from file.
    chr = getc(fileptr);
}
fclose(fileptr); //close file.
// printf("There are %d lines in parolebisSacavi \n", count_lines); // რამდენი ლაინია პაროლების საცავში

*/
