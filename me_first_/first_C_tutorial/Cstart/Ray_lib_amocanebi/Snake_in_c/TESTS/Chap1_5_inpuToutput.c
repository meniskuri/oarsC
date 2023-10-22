/*
- Chapter 1.5   Character input and output +
- Chapter 1.5.1 File copying +
- chapter 1.5.2 Character counting +
- chapter 1.5.3 Line counting -

- read a character while (character is not end-of-file indicator)
output the character just read read a character

- EOF is an integer defined in <stdio.h>, but the specific numeric value
doesn’t matter as long as it is not the same as any char value
ენდ ოფ ფაილ. გეთჩარი რომ დამთავრდება ეგეც ესეთ ვალუეს მოგვცემს რასაც EOF. შემოწმებისთვის

TODO:
1. გამოსვლა ვაილიდან გასაკეთებელია თუ აღარ გინდა იყო მანდ. <<<<<
2. რასაც შეიყვან სიმბოლოების რაოდენობას ითვლიდეს
3. ვთქვათ ქაუნთერი გავანულო ყოველ ბოლო სიტყვაზე. ანუ ითვლიდეს იმ მომენტში რა სიტყვაც მყავს შეყვანილი იმას
4. ყველა შიშების გულიდან გაყრა (განდევ ჩემგან სატანავ :დ)
5. ლაი-ნ ქაუნთინგი. ისე გავაკეთო რომ ამ კოდში იყოს. <<<<<<<
6. შეიძლება დამჭირდეს ვაილიდან ამოგდების ჩამატება. ოკ
*/

#include <stdio.h>

int main()
{
  int c, counter1 = 0;
  int k, y;
  printf("შეიყვანეთ კლავიატურიდან სიმბოლო ან სიმბოლოები \n");
  printf("თქვი 'cntrl C' და გამოდი \n");
  c = getchar();
  y = EOF;

  printf("##############\n");
  while (c != y)
  {
    putchar(c);
    ++counter1;

    /* ითვლის ერთი სიმბოლოთი მეტს გეთჩარი ბოლოს კიდევ ერთ მონაცემს აგზავნის,
    დამთავრებას რაც ნიშნავს. მაგას ვადარებთ EOF თან */

    if (c == 10)
    {
      counter1 = 0;
    } else {
      printf("counter1 = %d\n",counter1);
      printf("vnaxot c = %d\n",c); // vnaxot
    }

    c = getchar();
  }

  printf("counter1amovardna = %d\n",counter1);
}
