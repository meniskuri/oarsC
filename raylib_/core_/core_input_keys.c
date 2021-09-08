/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include <stdio.h>
#include <math.h>
#include "raylib.h"

// Initialization ARRY (კლავიატურიდან როგორც შევუცვლი ბურთს პოზიციას, ეს კოორდინატები მინდა ჩავწერო მასივში)
//--------------------------------------------------------------------------------------
float tailPositionsX[1000000];  // ჰმ. როგორ გავადიდო კუდის მასივის სიგრძე counter ით?
float tailPositionsY[1000000];

const int screenWidth    = 800;
const int screenHeight   = 450;

static int framesCounter = 0;
float speed              = 3;   // ნაბიჯი წამში. სიჩქარე იქნება speed = x * framesCounter ;
float x                  = 1.0; // x = speed / framesCounter ;  

int counter = 0;                // რამდენი ნაბიჯი გააკეთა გველმა. მთვლელი 

Vector2 ballPosition     = { (float)screenWidth/2, (float)screenHeight/2 };
Color ballColor          = DARKBLUE;


// ენდ
//--------------------------------------------------------------------------------------
int main(void)
{    
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input - Kapana");

    SetTargetFPS(10);               // Set our game to run at 60 frames-per-second // <<<<< 
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateGame();
       
        // Draw
        //----------------------------------------------------------------------------------
        DrawGame();
        
        //----------------------------------------------------------------------------------
    }
    
    // tailPositions tracker 
    //--------------------------------------------------------------------------------------
    for (int i =0;i<=counter;i++) 
    {
        printf("vnaxot --- tailPositionsX[i] = %lf\ni = %d\n",tailPositionsX[i],i);
    }
    
    // Timing-related functions
    //----------------------------------------------------------------------------------
    printf("//---------------------------- Timing-related functions ---------------------------------------");
    printf("\n");
    printf("GetFramesTime = %f\n",GetFrameTime()); // Returns time in seconds for last frame drawn (delta time)
    printf("GetTime = %d\n",GetTime());            // Returns elapsed time in seconds since InitWindow() // რას აბრუნებს ვერ გავიგე ???
    
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
        
    return 0;
}



void UpdateGame(void)
{
    //do 
    if (IsKeyDown(KEY_RIGHT))
        {
            ballPosition.x += 2.0f;
            ballColor = GREEN;
            // printf("(marjvniv davachire) ballPosition.x = %f\n",ballPosition.x);
        }
        if (IsKeyDown(KEY_LEFT))
        {
            ballPosition.x -= 2.0f;
            ballColor = RED;
            // printf("(marcxniv davachire) ballPosition.x = %f\n",ballPosition.x);
        }
        if (IsKeyDown(KEY_UP))
        {
            ballPosition.y -= 2.0f;
            ballColor = MAGENTA;
            // printf("(zemot davachire) ballPosition.y %f\n",ballPosition.y);
        }
        if (IsKeyDown(KEY_DOWN))
        {
            ballPosition.y += 2.0f; // 2.0f არის თითო ნაბიჯის სიგრძე? 
            ballColor = LIME;
            // printf("qvemot davachire %f\n",ballPosition.y);
        }
        
        // კლავიატურიდან ბრძანების მიცემის დროს დაიწერება შესაბამისი კოორდინატები 
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN))
        {   
            printf("//----------------------------------------------------------------------------------");
            printf("\n");

            printf("counter = %d\n",counter);             
            
            printf("Vector2 ballPosition = %lf\n",(ballPosition)); // აი ეს რას მიჩვენებს? )) ???
            printf("ballPosition.x = %f\n",ballPosition.x);
            printf("ballPosition.y = %f\n",ballPosition.y);
            printf("Vector2 magn = %f\n",sqrt(pow(ballPosition.y,2) + pow(ballPosition.x,2)));
            
            printf("//----------------------------------------------------------------------------------");
            printf("\n");

            tailPositionsX[counter] = ballPosition.x;
            tailPositionsY[counter] = ballPosition.y;
            
            printf("tailPositionsX[counter] = %f\n tailPositionsY[counter] = %f\n",tailPositionsX[counter],tailPositionsY[counter]);
            
            printf("//----------------------------------------------------------------------------------");
            printf("\n");
            
            counter++; // რამდენი ნაბიჯი გააკეთა გველმა. მთვლელი        
        }
    
    framesCounter++;   // რამდენჯერ იხატება ეკრანი წამში 
    printf("framesCounter = %d\n",framesCounter);
}

void DrawGame(void)
{
    //do
    BeginDrawing();

        ClearBackground(DARKGRAY);

        DrawText("move the ball with arrow keys", 10, 10, 20, BLUE);
            
        DrawFPS(screenWidth/4, screenHeight/4); // ფერი როგორ შევუცვალო? :))

        DrawCircleV(ballPosition, 50, ballColor); // Draw a color-filled circle (Vector version)

    EndDrawing();
}