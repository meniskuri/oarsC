#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"


int main(void){
    int num1;
    int num2;
    
    printf("sheviyvanot klaviaturidan rame brzaneba: ");
    
    
    // scanf("%d",&num1);
    // printf("brzaneba aris %d",num1);
    float a; 
    int n; 
    scanf("%d%f",&n,&a);
    
    printf("n aris %d\n a aris %f\n",n,a);
    
    
    int k = 10;
    void *gio = &k;
    printf("%d\n",*(int*)gio);
    
    /////////////////////////////
    const int WindowWidth = 800;
    const int WindowHeith = 450;
    
    
    InitWindow(WindowWidth, WindowHeith, "raylib [core] example - keyboard input, Kapana");
    SetTargetFPS(60); 
    
    // game main loop //
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(MAGENTA);

        DrawText("Congrats! You created your first window! Giorgi Kapanadze", WindowWidth/2, WindowHeith/2, 20, GREEN);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    
    return 0;
}
