/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Kapana. Snake C Raylib
*
********************************************************************************************/

#include <stdio.h>
#include <math.h>
#include "raylib.h"

// ცვლადები 
//--------------------------------------------------------------------------------------
    const  int screenWidth   = 800;
    const  int screenHeight  = 450;
    static int framesCounter = 0;
    const  int fps_chemi     = 60;   // Set our game to run at 'fps_chemi' frames-per-second  
    float iqsi               = 1.0;  // ჯერ არ ვიყენებ არაფერში <<<<< დასამთავრებელია <<<<<<

    int counter              = 0;    // რამდენი ბიჯი გააკეთა გველის თავმა მაგის მთვლელი 
    bool marjvenaKlaviatura  = true; // მიმართულებები
    bool marcxenaKlaviatura  = false;
    bool zedaKlaviatura      = false;
    bool qvedaKlaviatura     = false;

    // გველი    
    Vector2 ballPosition     = { (float)screenWidth/2, (float)screenHeight/2 }; // გველის თავი
    Color ballColor          = DARKBLUE;
    const float ballRadius   = 15.0;
    const float speed        = 1;  // ნაბიჯი წამში. სიჩქარე
    int tailPositionsX[1000000]; // ჰმ. როგორ გავადიდო კუდის მასივის სიგრძე counter ით?
    int tailPositionsY[1000000];    
    int test_snake_modzraoba_x[1000000]; // test
    int test_snake_modzraoba_y[1000000]; // test

    // ვაშლი
    Vector2 vashliPosition   = {0,0}; // GetRandomValue(0,screenWidth), GetRandomValue(0,screenHeight) // ვაშლები
    Color vashliColor        = RED;
    float vashliRadius       = 10.0;
    int counter_vashlebi     = 0; // რამდენი ვაშლი აქვს ნაჭამი

    static bool pause = false; // დაპაუზება 


int main(void)
{   
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input - Kapana");
    
    // ვაშლი (ინიციალიზაცია)
    //--------------------------------------------------------------------------------------
    VashliRandom(); 
    
    // ალგორითმი იმისთვის რომ არ დააჯდეს გველს თავზე პირდაპირ ვაშლი. ან ჰმ ეგეც შეიძლება ანუ გაუმართლა? 
    //--------------------------------------------------------------------------------------
    // .... 
    
    SetTargetFPS(fps_chemi);                  // Set our game to run at 60 frames-per-second  
    //--------------------------------------------------------------------------------------


    // Main game loop
    while (!WindowShouldClose())                    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateGame();
       
        // Draw
        //----------------------------------------------------------------------------------
        DrawGame();
    }
    
    // snake head position tracker 
    //--------------------------------------------------------------------------------------
    for (int i = 0; i < counter; i++) 
    {
        // printf("vnaxot --- tailPositionsX[i] = %lf i = %d\n",tailPositionsX[i],i);
        // printf("vnaxot --- counter = %d\n",counter);
    }
 
    // Timing-related functions
    //----------------------------------------------------------------------------------
    printf("//---------------------------- Timing-related functions ---------------------------------------");
    printf("\n");
    printf("GetFramesTime = %f\n",GetFrameTime()); // Returns time in seconds for last frame drawn (delta time)
    printf("GetTime = %d\n",GetTime());            // Returns elapsed time in seconds since InitWindow() // რას აბრუნებს ვერ გავიგე ???
    
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();                                        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------        
    return 0;
}


void UpdateGame(void)
{   
    // მიმართულების მიცემა  
    //----------------------------------------------------------------------------------
    if (IsKeyDown(KEY_RIGHT))
    { 
        marjvenaKlaviatura = true;
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = false;
        // printf("IsKeyDown(KEY_RIGHT) = %d \n",IsKeyDown(KEY_RIGHT)); // print boolean        
    }
    if (IsKeyDown(KEY_LEFT))
    {
        marjvenaKlaviatura = false;
        marcxenaKlaviatura = true; 
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = false;
    }
    if (IsKeyDown(KEY_UP))
    {
        marjvenaKlaviatura = false;
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = true;     
        qvedaKlaviatura    = false;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        marjvenaKlaviatura = false;
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = true;     
    }
    if ((IsKeyDown(KEY_RIGHT)) && (IsKeyDown(KEY_UP))) // დიაგონალზე სიარული // შესამცირებელია იფ ელსები ;)
    {
        marjvenaKlaviatura = true; // 
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = true; //    
        qvedaKlaviatura    = false;  
    }
    if ((IsKeyDown(KEY_LEFT)) && (IsKeyDown(KEY_UP)))  
    {
        marjvenaKlaviatura = false;
        marcxenaKlaviatura = true; //
        zedaKlaviatura     = true; //    
        qvedaKlaviatura    = false;  
    }
    if ((IsKeyDown(KEY_LEFT)) && (IsKeyDown(KEY_DOWN))) 
    {
        marjvenaKlaviatura = false;
        marcxenaKlaviatura = true; //
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = true; // 
    }
    if ((IsKeyDown(KEY_RIGHT)) && (IsKeyDown(KEY_DOWN)))  
    {
        marjvenaKlaviatura = true; //
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = true; // 
    }
    
    framesCounter++; // რამდენჯერ იხატება ეკრანი წამში 
    // printf("framesCounter = %d\n",framesCounter);
    
    // გველის თავის სიარული speed ით )) და პაუზა
    //----------------------------------------------------------------------------------
    if (IsKeyPressed('P')) 
    {
        pause = !pause;
        printf("GAME PAUSED\n");        
    }
    if (!pause)
    {
        if (marjvenaKlaviatura == true) ballPosition.x += speed; // დასახვეწია 
        if (marcxenaKlaviatura == true) ballPosition.x -= speed;
        if (zedaKlaviatura     == true) ballPosition.y -= speed;
        if (qvedaKlaviatura    == true) ballPosition.y += speed;
        
        // როცა დადის. ყველა პოზიციას იმახსოვრებს tailPositionsX და tailPositionsY მასივებში
        //----------------------------------------------------------------------------------
        tailPositionsX[counter] = ballPosition.x;
        tailPositionsY[counter] = ballPosition.y;
        
        
        for (int i = counter_vashlebi; i >= 0; i--)
        {
            // printf("i (test) = %d\n", i);
            test_snake_modzraoba_x[i] = tailPositionsX[counter - i];
            // printf("test_snake_modzraoba_x[%d]%f\n",i,test_snake_modzraoba_x[i]);
            test_snake_modzraoba_y[i] = tailPositionsY[counter - i];
            // printf("test_snake_modzraoba_y[%d]%f\n",i,test_snake_modzraoba_y[i]);
            // pause = true;
        }
 
        counter++;
    } 
    
    // გველის თავის სიარული კედლებში (დასახვეწია გასვლა კედელში) 
    //----------------------------------------------------------------------------------
    int zero           = 0;           // ჯერ არ ვიყენებ 
    int MaxSqreenWidht = screenWidth; // ჯერ არ ვიყენებ 
    
    if ((ballPosition.x - ballRadius) >= screenWidth)             // მარჯვნივ სიარული
    {
        ballPosition.x = -ballRadius;
    }
    if ((ballPosition.x + ballRadius) <= 0 && marcxenaKlaviatura) // მარცხნივ სიარული
    {
        ballPosition.x = (screenWidth + ballRadius);
    }
    if ((ballPosition.y - ballRadius) >= screenHeight)            // ქვემოთ სიარული
    {
        ballPosition.y = -ballRadius;
    }
    if ((ballPosition.y + ballRadius) <= 0 && zedaKlaviatura)     // ზემოთ სიარული
    {
        ballPosition.y = (screenHeight + ballRadius);
    }
    
    // ვაშლის ჭამა (დასახვეწია)
    //--------------------------------------------------------------------------------------
    Vector2 katetebiSheerteba = {abs(ballPosition.x - vashliPosition.x),abs(ballPosition.y - vashliPosition.y)};
    float hipotenoza          = sqrt(pow(katetebiSheerteba.x,2) + pow(katetebiSheerteba.y,2));
    float distance2points     = (ballRadius + vashliRadius); // ორ წერტილს შორის მანძილი, თავსა და ვაშლს შორის 
    
    if (hipotenoza <= (distance2points)) 
    {
        counter_vashlebi++;    
        VashliRandom();   
    }
    
    /*
    // Check collision between two circles // CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);
    //--------------------------------------------------------------------------------------
    if (CheckCollisionCircles(ballPosition, ballRadius, vashliPosition, vashliRadius) == true)
    {
        // counter_vashlebi++;
        // printf("counter_vashlebi = %d\n",counter_vashlebi);
        // VashliRandom();
        // pause = !pause;
        // printf("aq var? \n");
    }
    */
}

void VashliRandom(void)
{
    // ვაშლი დავსვა ეკრანზე. ჭამის მერე. ახალ ადგილას გადასმა
    //--------------------------------------------------------------------------------------
    vashliPosition.x = GetRandomValue(0,screenWidth);
    vashliPosition.y = GetRandomValue(0,screenHeight);
    
    // vashliPosition = {(float)GetRandomValue(0,screenWidth), (float)GetRandomValue(0,screenHeight)}; // რატო? )) კითხვა
}

void tailDraw(void)
{
    // აქ ვარ <<<<<<<<<<
    printf("counter_vashlebi = %d\n",counter_vashlebi);
}

void DrawGame(void)
{
    BeginDrawing();

        ClearBackground(DARKGRAY);

        DrawText("move the ball with arrow keys", 10, 10, 20, BLUE);
        DrawText(TextFormat("VASHLI VUSHLEBI %i", counter_vashlebi), 100, 30, 20, GREEN); 
        DrawText(TextFormat("counter (tracker) %i", counter), 100, 50, 20, LIGHTGRAY);
        DrawText(TextFormat("framesCounter (tracker) %i", framesCounter), 100, 70, 20, LIGHTGRAY);
        DrawText(TextFormat("test_snake_modzraoba_x (tracker) %i", test_snake_modzraoba_x[0]), 100, 90, 20, RED);
        DrawText(TextFormat("test_snake_modzraoba_y (tracker) %i", test_snake_modzraoba_y[0]), 100, 110, 20, RED);
        
        DrawFPS(screenWidth/2, 10);   // ფერი როგორ შევუცვალო? :))
        
        
        Color colors[10] = { 0 };
        for (int i = 0; i < 10; i++) colors[i] = (Color){ GetRandomValue(100, 250), GetRandomValue(50, 150), GetRandomValue(10, 100), 255 };
        
        DrawCircleV(ballPosition, ballRadius, ballColor); // Draw a color-filled circle (Vector version)
        for (int i = 0; i < counter_vashlebi; i++) 
        {
            // test
            DrawCircleLines(test_snake_modzraoba_x[i], test_snake_modzraoba_y[i], ballRadius/2, colors[GetRandomValue(0, 10)]);
        }
        
        DrawCircleV(vashliPosition, vashliRadius, vashliColor); // ვაშლის ხატვა 
        
        DrawLine(ballPosition.x, ballPosition.y, vashliPosition.x, vashliPosition.y, BLACK); // ვაშლისა და თავის ცენტრებს შორის ჯოხი
        
        // printf("aq ar movdivar? \n");
        if (pause) DrawText("GAME PAUSED", screenWidth/2 - MeasureText("GAME PAUSED", 40)/2, screenHeight/2 - 40, 40, GRAY); // პაუზის ტექსტის დაწერა
        
    EndDrawing();
}

