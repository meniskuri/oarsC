// C program to find the size of file

#include <stdio.h>

long int findSize(char file_name[])
{
  // opening the file in read mode
  FILE *fp = fopen(file_name, "r");

  // checking if the file exist or not
  if (fp == NULL) {
    printf("File Not Found!\n");
    return -1;
  }

  fseek(fp, 0L, SEEK_END); // ეს რას ნიშნავს? fseek() <<<<

  // calculating the size of the file
  long int res = ftell(fp); // ftell()

  // closing the file
  fclose(fp);

  return res;
}

// Driver code
int main()
{
  char file_name[] = { "program.txt" };
  long int res = findSize(file_name);
  if (res != -1)
  {
    printf("Size of the file is %ld bytes \n", res);
  }
  // gio (3) - 14; giorgi (6) - 17
  // MELON (5) - 9
  // ~ - 3

  return 0;
}
// gio (3) - 14; giorgi (6) - 17
// MELON (5) - 9
// ~ - 3
