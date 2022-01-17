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
  y = EOF; // ენდ ოფ ფაილ. გეთჩარი რომ დამთავრდება ეგეც ესეთ ვალუეს მოგვცემს რასაც EOF. შემოწმებისთვის

  /*
  EOF is an integer defined in <stdio.h>, but the specific numeric value
  doesn’t matter as long as it is not the same as any char value
  */

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

  // ვერსია 1
  while (c != y) // ექსპერიმენტობა )) EOF მინუს ერთს მაძლევს რავი. როდის გაუტოლდება?
  {
    putchar(c);
    printf("\n");
    // printf("while shi var \n");

    counter1 = counter1 + 1;
    printf("counter1 = %d\n",counter1);
    c = getchar();
  }

  printf("counter1 = %d\n",counter1);
  printf("amovardna1 \n");

}
// tamri movida 
