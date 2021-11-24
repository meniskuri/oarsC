// text failshi lainebis raodenobis mozebna

#include <stdio.h>

int main()
{
    FILE *fileptr;
    int count_lines = 0;
    char filechar[40], chr;

    printf("Enter file name: ");
    scanf("%s", filechar);
    fileptr = fopen(filechar, "r");
   //extract character from file and store in chr
    chr = getc(fileptr);
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == 'n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(fileptr);
    }
    fclose(fileptr); //close file.
    printf("There are %d lines in %s  in a file\n", count_lines, filechar);
    return 0;
}
