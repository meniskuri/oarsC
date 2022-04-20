
//gagrdzeleba 3 - struct - ebidan - video განვაგრძო

#include <stdio.h>
#include <string.h>

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


void jadoqrebi_info_prnt (struct Jadoqrebi *jadoqrebi) // მისამართს მივცემ
{
  printf("================================ \n");
  printf("pntr print \n");
  printf("ჯადოქრის სახელი:           %s \n",jadoqrebi->saxeli);
  printf("ჯადოქრული სახელი:          %s \n",jadoqrebi->jadoqruli_saxeli);
  printf("ჯადოქრის ძალები:           %s \n",jadoqrebi->dzalebi);
  printf("ჯადოქრის ტოტემი:           %s \n",jadoqrebi->totemi);
  printf("ჯადოქრის გაფიდვის ლეველი: %d \n",jadoqrebi->gafidvis_lvl);
}

void jadoqrebi_info (struct Jadoqrebi jadoqrebi) // სახელს მივცემ
{
  printf("ჯადოქრის სახელი:           %s \n",jadoqrebi.saxeli);
  printf("ჯადოქრული სახელი:          %s \n",jadoqrebi.jadoqruli_saxeli);
  printf("ჯადოქრის ძალები:           %s \n",jadoqrebi.dzalebi);
  printf("ჯადოქრის ტოტემი:           %s \n",jadoqrebi.totemi);
  printf("ჯადოქრის გაფიდვის ლეველი: %d \n",jadoqrebi.gafidvis_lvl);
}

int main()
{
  struct Jadoqrebi ojaxi_da;
  struct Jadoqrebi *ojaxi_da_pntr;
  ojaxi_da_pntr = &ojaxi_da;

  strcpy(ojaxi_da.saxeli,"Shoshi");
  strcpy(ojaxi_da.jadoqruli_saxeli,"SunGolden Dragon");
  strcpy(ojaxi_da.dzalebi,"Sun Light and Green Trees Power Earth Power");
  strcpy(ojaxi_da.totemi,"Leopard");
  ojaxi_da.gafidvis_lvl = 28;

  jadoqrebi_info(ojaxi_da);
  jadoqrebi_info_prnt(ojaxi_da_pntr);

  int index = 6;
  do {
    printf("index = %d \n", index);
    index++;
  } while (index <= 5);
  printf("index = %d \n", index);

  return 0;
}


/*
არჩილმა დამირეკა და მითხრა რომ ნუ აძინებ ტვინსო
როცა ტვინი არ გყავს დაძინებული მაშინ გამოგივა ყველაფერიო
ნუ გუდავ ტვინსო. ისე როცა არ გყავს გაგაუდული ტვინი.. ტვინი თვითონ ვერ გაჩერდებაო
*/
