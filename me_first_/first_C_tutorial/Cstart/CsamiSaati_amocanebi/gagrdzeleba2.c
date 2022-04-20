/*
3 საათიანი ვიდეოს გაგრძელება
calculator from video
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>


int main()
{
  // 3 სთ ვიდეოს კალკულატორი
  double num1;
  double num2;
  char op;

  printf("Enter the number: \n");
  scanf("%lf", &num1); // %lf for double
  printf("Enter the operator: \n");
  scanf(" %c", &op); // space before %c or it is not goint to work :))
  printf("Enter the number: \n");
  scanf("%lf", &num2);

  if (op == '+') // '+' - ესეთი სახით უნდა შევადარო სიმბოლო '' (ერთი ბრჭყალით)
  {
    printf("num1 = %f \n",num1);
    printf("num2 = %f \n",num2);
    printf("num1 + num2 = %f \n", num1 + num2);
  } else if (op == '-')
  {
    printf("num1 = %f \n",num1);
    printf("num2 = %f \n",num2);
    printf("num1 - num2 = %f \n", num1 - num2);
  } else if (op == '*')
  {
    printf("num1 = %f \n",num1);
    printf("num2 = %f \n",num2);
    printf("num1 * num2 = %f \n", num1 * num2);
  } else if (op == '/')
  {
    printf("num1 = %f \n",num1);
    printf("num2 = %f \n",num2);
    printf("num1 / num2 = %f \n", num1 / num2);
  } else
  {
    printf("================ \n");
    printf("Error \n");
    printf("Invalid operator \n");
  }

  switch(op)
  {
    case '+':
    printf("მიმატება \n");
    break;

    case '-':
    printf("გამოკლება \n");
    break;

    case '*':
    printf("გამრავლება \n");
    break;

    case '/':
    printf("გაყოფა \n");
    break;

    default:
    printf("ერორ-ერორ \n");
    printf("ინვალიდი ოპერატორი \n");
  }

  return 0;
}

/*
მეცადინეობის გაგრძელება
ვუტევთ პუტინს შრომით
იმით რაც ყველაზე მეტად გვეზარბა, ჩვენს თავში უნდა დავამარცხოთ და ამით ბოროტებას ძალას გამოვაცლით.
*/
