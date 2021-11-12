/*
  ############################################################################
  Passwords must contain:
  - a minimum of 1 lower case letter [a-z] - ASCII ( )
  - a minimum of 1 upper case letter [A-Z] - ASCII (  )
  - a minimum of 1 numeric character [0-9] - ASCII (   )
  - a minimum of 1 special character: ~`!@#$%^&*()-_+={}[]|\;:"<>,./? - ASCII ()
  - Passwords must be at least 6 characters in length, but can be much longer
  ############################################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char brzaneba[20];
char shesadarebeli = 65; // 65 - 90 >> A - Z // ტესტ

bool amomgdebi1 = false;
int counter = 0;

int main()
{

  while(true) // პირველი ვაილი
  {
    // მეინ გეთჩარ() // სკანფ() ს აღარ ვიყენებ
    printf("########################### 1 \n");
    printf("Enter password (თქვი ! და გამოდი): \n");
    // scanf("%s\n",&brzaneba); // ჩარების მასივს მიბრუნებს // სკანეფი შევცვალო <<
    gets(brzaneba);

    printf("Password is %s\n", brzaneba);
    printf("########################### 2 > შედის ფორში \n");
    for (int i = 0; i <= sizeof(brzaneba); i++)
    {
      //
      printf("ვბეჭდავ პაროლს %c\n",brzaneba[i]); // ჩარები როგორც %S სტრინგებად ვერ იბეჭდება

      if (brzaneba[i] == 33) // 33 >> ! (პაროლში თუ შეიყვანთ ! ამოვარდება)
      {
        //
        amomgdebi1 = true;
        printf("amomgdebi1 = true\n");
        break; // 33 >> !
      }

      if (brzaneba[i] >= 65 && brzaneba[i] <= 90) // სიმბოლოების შედარება. მათი ასკი კოდები. :)
      {
        //
        printf("Password cointains upper case letter(s) [A-Z] \n");
      }
    }
    //
    counter++;
    //
    if (amomgdebi1 == true) break;
  }

  printf("counter is %d\n",counter);
  return 0;
}

//----------------------------------------------------------------------------------
// #include <stdio.h>
// int main()
// {
// int num, original, rem, sum = 0;
// printf("Enter a three digit Number: ");
// scanf("%d", &num);
// original = num;
// while (original != 0)
// {
// rem = original%10;
// sum =sum + rem*rem*rem;
// original =original/ 10;
// }
// if(sum == num)
// printf("%d is an Armstrong number.",num);
// else
// printf("%d is not an Armstrong number.",num);
// return 0;
// }
//----------------------------------------------------------------------------------
