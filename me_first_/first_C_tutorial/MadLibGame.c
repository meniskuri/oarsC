//Building a Mad Lib Game - Tutorial - Kapana
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char ucnauri[20];
    char     vin[20];
    char movlena[20];
    
    printf("gamosvlistvis daweret -> gamortva\n");
    
    while(1){
        
        printf("enter => 'ucnauri', 'vin' da 'movlena'");
        scanf("%s%s%s",&ucnauri,&vin,&movlena);
    
        printf("ucnauria {%s} is rom {%s} vart da rogor damtavrdeba {%s} es?",ucnauri,vin,movlena);
        
        if(ucnauri || vin || movlena == "gamortva") break; // ეს არ მუშაობს ჯერ. გავასწრებ  დედას შევეცი ! 
            
        }
    
    return 0;    
}
