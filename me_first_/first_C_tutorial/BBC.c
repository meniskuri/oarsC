#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

//----------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------

int main(void){
    //----------------------------------------------------------------------------------
    float a;
    int n;

    //----------------------------------------------------------------------------------
    printf("sheviyvanot klaviaturidan rame brzaneba: ");
    scanf("%d%f",&n,&a);
    printf("n aris%d\n a aris %f\n",n,a);

    int k = 1;
    void *gio = &k;
    show_int(k);
    printf("aq ra xdeba? %d\n",*(int*)gio);
    printf("int is zoma %d\n",sizeof(int));
    printf("                          \n");

    //----------------------------------------------------------------------------------
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

        DrawText("Congrats! You created your first window! Giorgi Kapanadze", WindowWidth/5, WindowHeith/2, 20, GREEN);
        DrawFPS(WindowWidth/4, WindowHeith/4);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
     // getchar(); // ეს რა არის უნდა გავიგო და რატო :)
    return 0;
}
