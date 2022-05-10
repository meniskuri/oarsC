/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window - Kapana");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    printf("WindowShouldClose is %d\n",WindowShouldClose());

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {    
    
        // test
        // printf("WindowShouldClose is (inside while) %d\n",WindowShouldClose());
        
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(DARKGRAY);

        DrawText("Congrats! You created your first window! Giorgi Kapanadze", 100, 200, 20, BLUE);
        DrawFPS(screenWidth/4, screenHeight/4); // ფერი როგორ შევუცვალო? :))
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    
    //--------------------------------------------------------------------------------------
    printf("WindowShouldClose is (outside while) %d\n",WindowShouldClose());
    
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    printf("WindowShouldClose is (end) %d\n",WindowShouldClose());
    return 0;
}