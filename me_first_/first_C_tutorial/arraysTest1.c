//Arrays - TEST
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;
  
/*show bytes takes byte pointer as an argument
  and prints memory contents from byte_pointer
  to byte_pointer + len */
void show_bytes(byte_pointer start, int len) 
{
     int i;
     for (i = 0; i < len; i++)
           printf(" %.2x", start[i]);
     printf("\n");
}
  
void show_int(int x)
{
     show_bytes((byte_pointer) &x, sizeof(int));
}
  
void show_float(double x) 
{
     show_bytes((byte_pointer) &x, sizeof(double));
}
  
void show_pointer(void *x) 
{
     show_bytes((byte_pointer) &x, sizeof(void *));
}
  
void show_char(char x)       // ახალი :) <<<<<<< შეიძლება არ იმუშაოს 
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main()
{
    char ucnauri,vin,movlena;
    char gamortva = "Q";     // <<<< ===== ეს სიმბოლო გადადის J ში. ვნახო ცხრილი 
    
    static int SIZE     = 3; // უნდა გავარკვიო რატომ ვერ ვსვავ // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< გასარკვევია 
    
    printf("MasivIntsize = %d\n",SIZE); // <<<
    
    int masiviIntebis[3] = {2,5,6}; // რატო ატრაკებს? როცა 3 ს ვსვავ მუშაობს. მინდა ჩავსვა SIZE ბლიად 3 ის მაგივრად 
    
    printf("gamosvlistvis daweret -> J \n"); 
    
    while(1)
    {
        printf("enter => 'ucnauri', 'vin' da 'movlena'");
        scanf("%c%c%c",&ucnauri,&vin,&movlena); 
    
        printf("ucnauria {%c} is rom {%c} vart da rogor damtavrdeba {%c} es?\n",ucnauri,vin,movlena);
        
        printf("gamortva ---> %c and sizeof(gamortva)--> %d\n",gamortva,sizeof(gamortva));
        printf("ucnauri ---> %c and sizeof(ucnauri)--> %d\n",ucnauri,sizeof(ucnauri));
        printf("vin ---> %c and sizeof(vin)-- > %d\n",vin,sizeof(vin));
        printf("movlena ---> %c and sizeof(movlena)--> %d\n",movlena,sizeof(movlena));
        
        if(ucnauri == gamortva || vin == gamortva || movlena == gamortva)
        {   
            printf("break - shi shemovedi\n");
            break;
            
        } else
        {
            printf("giorgi chkviania \n");
        }
    }
    
    printf("sizeof(masiviIntebis) = (bites)%d\n",sizeof(masiviIntebis));
    
    for (int i = 0; i < (sizeof(masiviIntebis)/sizeof(masiviIntebis[0])); i++) // sizeof() ბაიტების რაოდენობას აბრუნეს
    {
        printf("masiviIntebis %d\n",masiviIntebis[i]);
        printf("memory read : "), show_int(masiviIntebis[i]); // memory read // დასახვეწია 
    }
 
    return 0;    
}

