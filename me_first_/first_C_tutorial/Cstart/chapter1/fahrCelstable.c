// print Fahrenheit-Celsius table

# include<stdio.h>

int main()
{   /* print Fahrenheit-Celsius table
           for fahr = 0, 20, ..., 300 
                    ◦C = (5/9)(◦F-32) */
    
    float C,F;
    float arrCF[2][300]; // 2D array minda mqondes 
    
    int threedim[5][10][4];
    
    int zedalimitiT = 300;
    int bijiT       =  20;
    int dasawyisiT  =   0;
    
    int counter     =   0;
    
    float chasaweri;
    
    printf("######################\n");
    // @D arr
    // arrCF[0][counter] = {1,1};
    
    for (int k = 0; k < 2; k++)
    {
        for (int j = dasawyisiT; j <= zedalimitiT; j = j + bijiT)
        {
            F = j;
            C = 5.0 * (F - 32.0) / 9.0;
     
            k ? printf("%3d %3.3f\n",j,chasaweri = C) : printf("%3d %3.3f\n",j,chasaweri = F); // ესეც არ მომწონს 
            // k ? chasaweri = C : chasaweri = F; // ესე რატპ არ გამოდის?
            // k ? eval("chasaweri = C") : eval("chasaweri = F");
            
            arrCF[k][counter] = chasaweri; 
        
            counter++;
        }
    }    
    
    
    
    
    printf("######################\n");
    printf("sizeof(arrCF) aris %d\n",sizeof(arrCF)/sizeof(arrCF[0][0]));
    printf("sizeof(threedim) %d\n",sizeof(threedim)/sizeof(threedim[0][0][0]));
    
    
    printf("######################\n");
    float cxra = 9;
    float xuti = 5;
    float ganayofi;
    
    ganayofi = xuti / cxra;
    printf("ganayofi %f\n",ganayofi);
  
    printf("######################\n");
    int ati = 5;
    int ori = 9;
    int ganayofi2;
    
    ganayofi2 = ati / ori;
    printf("ganayofi2 int 5 / int 9 ze aris %d\n",ganayofi2);
    
    
    return 0;
}
