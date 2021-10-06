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
  
void show_char(char x) // ახალი :) <<<<<<< შეიძლება არ იმუშაოს 
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}


/*C - Program to compare two characters.*/
/* // ტესტ // 
#include<stdio.h>
int main(){
	char c1,c2;
	char c3 = "m";
      
	printf("Enter two characters: ");
	scanf("%c %c",&c1,&c2); //space b/w %c and %c
    
    
    printf("C1 = %c\n",c1);
    printf("C2 = %c\n",c2);
    printf("C3 (with c) = %c\n",c3);
	
	if(c1==c3)
		printf("Characters are equal.\n");
	else
		printf("Characters are not equal.\n");
	
	return 0;
}
*/



int main()
{
    char ucnauri,vin,movlena;
    char gamortva = "Q";    // <<<< ===== ეს სიმბოლო გადადის J ში. ვნახო ცხრილი 
    
    int SIZE     = 3;
    
    printf("MasivIntsize = %d\n",SIZE);
    
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
    
    // 
    //----------------------------------------------------------------------------------
    printf("sizeof(masiviIntebis) = (bites)%d\n",sizeof(masiviIntebis));
    
    for (int i = 0; i < (sizeof(masiviIntebis)/sizeof(masiviIntebis[0])); i++) // sizeof() ბაიტების რაოდენობას აბრუნეს
    {
        printf("masiviIntebis %d\n",masiviIntebis[i]);
        
        printf("memory read : "), show_int(masiviIntebis[i]); // memory read
    }
    
    
    return 0;    
}

