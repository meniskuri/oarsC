// print Fahrenheit-Celsius table

# include<stdio.h>
# include<string.h>

float C,F;
float arrCF[2][300]; // 2D array minda mqondes
float meoremasivi[2][300]; // todo ერთი for ციკლით მინდა შევავსო
int threedim[5][10][4];

#define zedalimitiT 300
#define bijiT 20
#define dasawyisiT 0

int counter    = 0;
float shesamowmebeli[300];
float chasaweri;

const int SIZE = 5; // const ები ყოველთვის დიდი ასოებით/ define -იც
#define SIZE2 9
int fasebi[SIZE2];
fasebi[0] = 1;

int main()
{   /* print Fahrenheit-Celsius table
           for fahr = 0, 20, ..., 300
                 ◦C = (5/9)(◦F-32) */

  ///////////////////////////////////////////////////////////////////////

  printf("sizeof(fasebi) %d\n",sizeof(fasebi)/sizeof(fasebi[0]));
  printf("fasebi[0] = %d\n",fasebi[0]);
  printf("address fasebi[0] = %p\n",&fasebi[0]);
  printf("address fasebi[0] = %x\n",&fasebi[0]);

  printf("######################\n");
  printf("F to C table with one for loop\n");
  int counter2 = 0;
  for (int i = dasawyisiT; i <= zedalimitiT; i = i + bijiT)
  {
    //..
    meoremasivi[0][counter2] = i;
    meoremasivi[1][counter2] = 5.0 * (i - 32.0) / 9.0;

    printf("F - %f\t",meoremasivi[0][counter2]);
    printf("C - %f\n",meoremasivi[1][counter2]);

    // printf("F meoremasivi[0][counter2] = %f\n",meoremasivi[0][counter2]);
    // printf("C meoremasivi[1][counter2] = %f\n",meoremasivi[1][counter2]);

    counter2++;
  }

  printf("######################\n");
  printf("F to C table with two for loop\n");
  for (int k = 0; k < 2; k++)
  {
    counter = 0;
    for (int j = dasawyisiT; j <= zedalimitiT; j = j + bijiT)
    {
      F = j;
      C = 5.0 * (F - 32.0) / 9.0;

      chasaweri = (k == 1)? C : F;

      arrCF[k][counter] = chasaweri;

      printf("arrCF[%d][%2d] = %7.3f", k, counter, arrCF[k][counter]);
      k ? printf(" - Celsius\n") : printf(" - Fahrenheit\n");

      // printf("meoremasivi[%d][%2d] = %7.3f\n", k, counter, meoremasivi[k][counter]);

      counter++; // პირველი ციკლის მერე counter უნდა გავანულო // და ამ ორმაგი ციკლითაც ნორმალურად ჩავწერო მასივი
    }
  }

  char* gamortva = "G";
  printf("G = %s\n",gamortva);

  printf("######################\n");
  printf("sizeof(arrCF) aris %d\n",sizeof(arrCF)/sizeof(arrCF[0][0]));
  printf("sizeof(threedim) %d\n",sizeof(threedim)/sizeof(threedim[0][0][0]));

  printf("######################\n");
  // პატარა მაგალითი პოინტერებზე / შესვენება 5 წუთი
  printf("%lu\n",*arrCF);

  int TEST[3] = {1,2,3};
  printf("%u\n", *(TEST + 3)); //*TEST არის მასივის პირველი ელემენტის პოინტერი

  return 0;
}
