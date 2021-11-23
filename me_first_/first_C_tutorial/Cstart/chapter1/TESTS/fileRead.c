// read from file

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char nums[100];
  FILE *fptr;

  if ((fptr = fopen("program.txt","r")) == NULL)
  {
    printf("Error! opening file");

    // Program exits if the file pointer returns NULL.
    exit(1);
  }

  for (int i = 0; i <= 100; i++)
  {
    //
    fscanf(fptr,"%c", &nums[i]);
    printf("Value of n=%c\n", nums[i]);
    
  } // არ უნდა იმუშაოს

  fclose(fptr);

  return 0;
}
