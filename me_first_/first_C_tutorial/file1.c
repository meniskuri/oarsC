#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"


int main(){
    //----------------------------------------------------------------------------------
    const char myName[] = "giorgi";
    int myAge     = 29;
    //----------------------------------------------------------------------------------
    printf("hello\nxalxno\n");
    printf("   /|\n");
    printf("  / |\n");
    printf(" /  |\n");
    printf("/___|\n");
    printf("vnaxot\"ramoxdeba\n");
    printf("my name is %s\n",myName);
    printf("%s my age is %d\n",myName,myAge);

    double gio = 3.0;
    char grade = "B"; // აქ მხოლოდ ერთი სიმბოლოს შენახვა შემიძლია (char grade = "BACD" - არასწორი იქნება)

    printf("gio aris %f\n",gio + 3.9); // %c for chars
    printf("2 is 3 xarisxi %f\n", pow(2,3));

    //----------------------------------------------------------------------------------
    printf("sheviyvanot klaviaturidan rame brzaneba: ");

    char brzaneba[50];
    scanf("%s\n",&brzaneba);
    printf("brzaneba aris %s\n", brzaneba); // space is mere teqsts ar sheiyvans


    char brzaneba2[50];
    scanf("%s\n",&brzaneba2);
    printf("brzaneba 2 aris %s\n", brzaneba2);


    char brzaneba3[50];
    // fgets(brzaneba3);
    scanf("%s\n",&brzaneba3);
    printf("brzaneba 3 aris %s\n", brzaneba3);

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
