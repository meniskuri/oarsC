// test
// C program to illustrate
// fgets()
#include <stdio.h>
#define MAX 15
int main()
{
  char name[20];

  char brzaneba[50];

  char buf[MAX];
  fgets(buf, MAX, stdin);
  printf("string is: %s\n", buf);

  // scanf() - რატომღაც არ მომწონდა. სლეშებს ვერ ამუღამებს "გიორგი კაპანაძე" და აღიქვავს მარტო "გიორგი" -ს )) სირობა მოკლედ
  printf("scanf() ბრძანებით შეყვანა ტექსტის \n");
  scanf("%s",&brzaneba); // ამპერსანტი უნდა თუარა ხზ. უნდა ალბათ
  printf("brzaneba = %s \n",brzaneba);


  // fgets(name,int,stdin); name - სახელი ცვლადის რაც გინდა რომ დაბეჭდო. int - რამდენი გინდა დაბეჭდო. stdin - სტანდარტულიინფუტის მექანიზმის მეშვებოით ალბათ :))
  printf("fgets() ბრძანებით შეყვანა ტექსტის \n");
  fgets(name, 33, stdin); // რატო არ მუშაობს?
  printf("name = %s \n",brzaneba); // stdin დათრეული აქვს scanf ს და მაგიტომ მაგ სთრიმს თრეულობს მაშინ უნდა ვუთხრა ფაილი რამე იასნა.
  // ან სტრიმი თავიდან გავჩითო? ჰმ :)) მოკლედ პრობლემაა. ეხლა არ მჭირდება მაგის ამოხსნა 

  return 0;
}
