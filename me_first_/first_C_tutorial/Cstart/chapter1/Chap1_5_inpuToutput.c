// Chapter 1.5 Character input and output
// Chapter 1.5.1 File copying
// copy input to output; 1st version

/* read a character while (character is not end-of-file indicator)
output the character just read read a character */

#include <stdio.h>

int main()
{
  int c, counter1 = 0;
  int k, y;
  printf("შეიყვანეთ კლავიატურიდან სიმბოლო ან სიმბოლოები \n");
  c = getchar();

  k = 103; // შეესაბამება g ასოს
  y = EOF; // EOF რა ჩემი ფეხებია?

  // ვაილამდე ბეჭდვა სიმბოლოების
  printf("c(d) = %d\n", c);
  printf("c(c) = %c\n", c);
  //
  printf("k(d) = %d\n", k);
  printf("k(c) = %c\n", k);
  //
  printf("y(c) = %c\n", y);
  printf("y(d) = %d\n", y);

  putchar(c);
  printf("\n");
  printf("########");
  printf("\n");

  while (c != y) // ექსპერიმენტობა )) EOF მინუს ერთს მაძლევს რავი. როდის გაუტოლდება?
  {
    putchar(c);
    printf("\n");
    // printf("while shi var \n");
    c = getchar();

    counter1 = counter1 + 1; // როცა შემყავ ერთი ასო counter1 = 2; rato? debagerit gadavurbino GDB
  }

  printf("counter1 = %d\n",counter1);
  printf("amovardna \n");
}
