/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Kapana. Snake C Raylib
*   კოდი დასალაგებელია. დასავარცხნია ფუნქციებად. და გასალამაზებელი. ჯერ დეველოპმენტ ვერსიაა ვ.1.1
*
********************************************************************************************/

#include <stdio.h>
#include <math.h>
#include "raylib.h"

// ცვლადები 
//--------------------------------------------------------------------------------------
const  int screenWidth   = 800;
const  int screenHeight  = 450;
int framesCounter        = 0;
const  int fps_chemi     = 60;   // Set our game to run at 'fps_chemi' frames-per-second  
float iqsi               = 1.0;  // ჯერ არ ვიყენებ არაფერში 

int counter_meatedi      = 0;    // ყოველი მეათე ბიჯი ერთია აქ რაც გააკეთა გველის თავმა 
int counter              = 0;    // რამდენი ბიჯი გააკეთა გველის თავმა მაგის მთვლელი 
bool marjvenaKlaviatura  = true; // მიმართულებები
bool marcxenaKlaviatura  = false;
bool zedaKlaviatura      = false;
bool qvedaKlaviatura     = false;

// გველი    
Vector2 ballPosition     = { (float)screenWidth/2, (float)screenHeight/2 }; 
Color ballColor          = DARKBLUE;
const float ballRadius   = 10.0;
const float speed        = 20;  
int tailPositionsX[1000000];   
int tailPositionsY[1000000];    
int test_snake_modzraoba_x[1000000]; 
int test_snake_modzraoba_y[1000000]; 

// ვაშლი
Vector2 vashliPosition   = {0,0}; 
Color vashliColor        = RED;
float vashliRadius       = 10.0;
int counter_vashlebi     = 0; 

static bool pause = false; 

// ფერები (კუდის)
Color colors[10] = { 0 };


int main(void) 
{    
    // ფერების გენერირება
    //--------------------------------------------------------------------------------------
    for (int i = 0; i < 10; i++) colors[i] = (Color){ GetRandomValue(0, 250), GetRandomValue(50, 150), GetRandomValue(10, 100), 255 };
    
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input - Kapana");
    
    // ვაშლი (ინიციალიზაცია)
    //--------------------------------------------------------------------------------------
    VashliRandom(); 
    
    // Set our game to run at 60 frames-per-second  
    //--------------------------------------------------------------------------------------
    SetTargetFPS(fps_chemi);
    
    
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
    
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();                                        // Close window and OpenGL context
    
    //--------------------------------------------------------------------------------------        
    return 0;
}


void UpdateGame(void)
{   
    // რამდენჯერ იხატება ეკრანი წამში
    framesCounter++;
    
    // მიმართულების მიცემა  
    mimartulebebiKlaviaturidan();
    
    // გველის თავის სიარული speed(მეტამფეტამინით) და პაუზა
    gvelisSiaruliANDpasuse(); 
    
    // გველის თავის სიარული კედლებში (დასახვეწია გასვლა კედელში) 
    gvelisSiaruliKedlebshi();
    
    // ვაშლის ჭამა (დასახვეწია)
    vashlisChama();
}

void vashlisChama(void)
{
    Vector2 katetebiSheerteba = {abs(ballPosition.x - vashliPosition.x),abs(ballPosition.y - vashliPosition.y)};
    float hipotenoza          = sqrt(pow(katetebiSheerteba.x,2) + pow(katetebiSheerteba.y,2));
    float distance2points     = (ballRadius + vashliRadius); // ორ წერტილს შორის მანძილი, თავსა და ვაშლს შორის 
    
    if (hipotenoza <= (distance2points)) 
    {
        counter_vashlebi++;    
        VashliRandom();   
    }
    
    /* // <<<<<--------------------------------||||-
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

void gvelisSiaruliKedlebshi(void)
{
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
}

void gvelisSiaruliANDpasuse(void)
{
    if (IsKeyPressed('P')) 
    {
        pause = !pause;
        printf("GAME PAUSED\n");        
    }
    if (!pause)
    {   
        if (framesCounter % 20 == 0) // რადიუსი გამრავლებული ორზეა ჩასასმელი აქ // <<<<<--------------------------------||||-
        {
            if (marjvenaKlaviatura == true) ballPosition.x += speed; // დასახვეწია 
            if (marcxenaKlaviatura == true) ballPosition.x -= speed;
            if (zedaKlaviatura     == true) ballPosition.y -= speed;
            if (qvedaKlaviatura    == true) ballPosition.y += speed;
        }
        
        // როცა დადის. ყველა პოზიციას იმახსოვრებს tailPositionsX და tailPositionsY მასივებშi
        tailPositionsX[counter_meatedi] = ballPosition.x;
        tailPositionsY[counter_meatedi] = ballPosition.y;
        
        for (int i = counter_vashlebi; i >= 0; i--)
        {
            test_snake_modzraoba_x[i] = tailPositionsX[counter_meatedi -1 - i];
            test_snake_modzraoba_y[i] = tailPositionsY[counter_meatedi -1   - i];
        }
        
        if (counter % 20 == 0) // <<<<<--------------------------------||||-
        {
            counter_meatedi++;
        }
        counter++;
    }
}

void mimartulebebiKlaviaturidan(void)
{
    if (IsKeyDown(KEY_RIGHT))
    { 
        marjvenaKlaviatura = true;
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = false;
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
    if ((IsKeyDown(KEY_RIGHT)) && (IsKeyDown(KEY_UP))) // დიაგონალზე სიარული // <<<<<--------------------------------||||-
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
}

void VashliRandom(void)
{
    vashliPosition.x = GetRandomValue(0,screenWidth);
    vashliPosition.y = GetRandomValue(0,screenHeight);
    // <<<<<--------------------------------||||-
    // vashliPosition = {(float)GetRandomValue(0,screenWidth), (float)GetRandomValue(0,screenHeight)}; // რატო? )) კითხვა
}

void tailDraw(void)
{
    for (int i = counter_vashlebi; i > 0; i--) 
    { 
        DrawCircle(test_snake_modzraoba_x[i], test_snake_modzraoba_y[i], ballRadius, colors[GetRandomValue(0, 10)]);   
    }
}

void tavisChama(void) // <<<<<--------------------------------||||-
{
    // გველის სიკვდილი ანუ თავის თავის ჭამა 

}

void DrawGame(void)
{
    BeginDrawing();

        ClearBackground(DARKGRAY);

        DrawText("move the ball with arrow keys", 10, 10, 20, BLUE);
        DrawText(TextFormat("VASHLI VUSHLEBI %i", counter_vashlebi), 100, 30, 20, GREEN); 
        DrawText(TextFormat("counter (tracker) %i", counter), 100, 50, 20, LIGHTGRAY);
        // DrawText(TextFormat("framesCounter (tracker) %d *60", framesCounter/60), 100, 70, 20, LIGHTGRAY);
        // DrawText(TextFormat("test_snake_modzraoba_x[0] (tracker) %d", test_snake_modzraoba_x[0]), 100, 90, 20, RED);
        // DrawText(TextFormat("test_snake_modzraoba_y[0] (tracker) %d", test_snake_modzraoba_y[0]), 100, 110, 20, RED);
        // DrawText(TextFormat("test_snake_modzraoba_x[1] (tracker) %d", test_snake_modzraoba_x[1]), 100, 130, 20, RED);
        // DrawText(TextFormat("test_snake_modzraoba_y[1] (tracker) %d", test_snake_modzraoba_y[1]), 100, 150, 20, RED);
        
        DrawFPS(screenWidth/2, 10);   // ფერი როგორ შევუცვალო? :))
        
        DrawCircleV(ballPosition, ballRadius, ballColor); // გველის თავის ხატვა 
        tailDraw(); // ტანის ხატვა
        
        DrawCircleV(vashliPosition, vashliRadius, RED); // ვაშლის ხატვა 
        DrawLine(ballPosition.x, ballPosition.y, vashliPosition.x, vashliPosition.y, BLACK); // ვაშლისა და თავის ცენტრებს შორის ჯოხი
        
        if (pause) DrawText("GAME PAUSED", screenWidth/2 - MeasureText("GAME PAUSED", 40)/2, screenHeight/2 - 40, 40, GRAY); 
        
    EndDrawing();
}

