/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Kapana. Snake C Raylib.os
*
********************************************************************************************/
#include <stdio.h>
#include <math.h>
#include "raylib.h"

// Initialization ARRY (კლავიატურიდან როგორც შევცვლი ბურთს პოზიციას, ეს კოორდინატები მინდა ჩავწერო მასივში)
//--------------------------------------------------------------------------------------
float tailPositionsX[1000000];   // ჰმ. როგორ გავადიდო კუდის მასივის სიგრძე counter ით?
float tailPositionsY[1000000];

const int screenWidth    = 800;
const int screenHeight   = 450;

static int framesCounter = 0;
const int  fps_chemi     = 60;   // Set our game to run at 'fps_chemi' frames-per-second  
float      speed         = 1;    // ნაბიჯი წამში. სიჩქარე
float      iqsi          = 1.0;  // ჯერ არ ვიყენებ არაფერში <<<<<

int        counter       = 0;    // კლავიატურაზე რამდენჯერ მქონდა დაჭერილი წინ ქვემოთ მარჯვნივ მარცხნივ კლავიშები. მაგის მთვლელი 

bool marjvenaKlaviatura  = true; // მიმართულებები
bool marcxenaKlaviatura  = false;
bool zedaKlaviatura      = false;
bool qvedaKlaviatura     = false;

// გველი //
Vector2 ballPosition     = { (float)screenWidth/2, (float)screenHeight/2 }; // გველის თავი
Color ballColor          = DARKBLUE;
float ballRadius         = 50.0;

//  Types and Structures Definition
typedef struct Snake { // შესაძლოა ჩავამატო
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    Color color;
} Snake;


// ვაშლი //
Vector2 vashliPosition   = {0,0}; // GetRandomValue(0,screenWidth), GetRandomValue(0,screenHeight) // ვაშლები
Color vashliColor        = RED;
float vashliRadius       = 25.0;

//  Types and Structures Definition
typedef struct Food {  // შესაძლოა ჩავამატო
    Vector2 position;
    Vector2 size;
    bool active;
    Color color;
} Food;

int counter_vashlebi = 0; // რამდენი ვაშლი აქვს ნაჭამი


int main(void)
{    
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input - Kapana");
    
    // ვაშლი დავსვა ეკრანზე (ინიციალიზაცია)
    //--------------------------------------------------------------------------------------
    VashliRandom(); 
    // ალგორითმი იმისთვის რომ არ დააჯდეს გველს თავზე პირდაპირ. ან ჰმ ეგეც შეიძლება ანუ გაუმართლა? 

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
    
    // tailPositions tracker 
    //--------------------------------------------------------------------------------------
    // for (int i =0;i<counter;i++) 
    // {
    //     printf("vnaxot --- tailPositionsX[i] = %lf i = %d\n",tailPositionsX[i],i);
    //     printf("vnaxot --- counter = %d\n",counter);
    // }
    
    // Size-related functions
    //----------------------------------------------------------------------------------
    printf("//---------------------------- Size-related functions ---------------------------------------");
    printf("\n");
    printf("sizeof(tailPositionsX) = %d\n",sizeof(tailPositionsX)); // კითხვა მაქვს 
    
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
        ballColor = GREEN;
        // printf("IsKeyDown(KEY_RIGHT) = %d \n",IsKeyDown(KEY_RIGHT)); // print boolean 
        marjvenaKlaviatura = true;
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = false;        
    }
    if (IsKeyDown(KEY_LEFT))
    {
        ballColor = RED;
        // printf("IsKeyDown(KEY_LEFT) = %d \n",IsKeyDown(KEY_LEFT)); 
        marjvenaKlaviatura = false;
        marcxenaKlaviatura = true; 
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = false;
    }
    if (IsKeyDown(KEY_UP))
    {
        ballColor = MAGENTA;
        // printf("IsKeyDown(KEY_UP) = %d \n",IsKeyDown(KEY_UP));
        marjvenaKlaviatura = false;
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = true;     
        qvedaKlaviatura    = false;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        ballColor = LIME;
        // printf("IsKeyDown(KEY_DOWN) = %d \n",IsKeyDown(KEY_DOWN));
        marjvenaKlaviatura = false;
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = true;     
    }
        
    // კლავიატურიდან ბრძანების მიცემის დროს დაიწერება შესაბამისი კოორდინატები 
    //----------------------------------------------------------------------------------
    /*
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN))
    {   
        printf("//----------------------------------------------------------------------------------");
        printf("\n");

        printf("counter = %d\n",counter);             
            
        printf("Vector2 ballPosition = %lf\n",(ballPosition)); // აი ეს რას მიჩვენებს? )) ???
        printf("ballPosition.x = %f\n",ballPosition.x);
        printf("ballPosition.y = %f\n",ballPosition.y);
        printf("Vector2 magn = %f\n",sqrt(pow(ballPosition.y,2) + pow(ballPosition.x,2)));
           
        tailPositionsX[counter] = ballPosition.x;
        tailPositionsY[counter] = ballPosition.y;
            
        printf("tailPositionsX[counter] = %f\ntailPositionsY[counter] = %f\n",tailPositionsX[counter],tailPositionsY[counter]);
              
        counter++; // კლავიატურაზე რამდენჯერ მქონდა დაჭერილი წინ ქვემოთ მარჯვნივ მარცხნივ კლავიშები. მაგის მთვლელი   
        
        printf("(after counter++ in UpdateGame(void)) counter = %d\n",counter); 
        printf("//----------------------------------------------------------------------------------");
        printf("\n");  
    }
    */
    
    framesCounter++; // რამდენჯერ იხატება ეკრანი წამში 
    // printf("framesCounter = %d\n",framesCounter);
    
    // გველის თავის სიარული speed ით )) 
    //----------------------------------------------------------------------------------
    if (marjvenaKlaviatura == true) ballPosition.x += speed; // დასახვეწია
    if (marcxenaKlaviatura == true) ballPosition.x -= speed;
    if (zedaKlaviatura == true)     ballPosition.y -= speed;
    if (qvedaKlaviatura == true)    ballPosition.y += speed;
    
    // გველის თავის სიარული კედლებში (დასახვეწია გასვლა კედელში)
    //----------------------------------------------------------------------------------
    if (ballPosition.x + ballRadius >= screenWidth)
    {
        ballPosition.x = 0;
    }
    
    // ვაშლის ჭამა (პარამეტრები - ბეჭდვა)
    //--------------------------------------------------------------------------------------
    printf("ballRadius + vashliRadius = %f\n",ballRadius + vashliRadius);
    printf("",);
    
    
    // ვაშლის ჭამა (დასახვეწია)
    //--------------------------------------------------------------------------------------
    if ((ballPosition.y == vashliPosition.y) && (abs(ballPosition.x - vashliPosition.x) <= (ballRadius + vashliRadius)) ||
       (ballPosition.x == vashliPosition.x) && (abs(ballPosition.y - vashliPosition.y) <= (ballRadius + vashliRadius)))
    {
        counter_vashlebi++;
        printf("counter_vashlebi = %d\n",counter_vashlebi);
        
        VashliRandom(); // ვაშლი დავსვა ეკრანზე. ჭამის მერე. ახალ ადგილას გადასმა
    }
    
    
    /*
    // Check collision between two circles // CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);
    //--------------------------------------------------------------------------------------
    if (CheckCollisionCircles(ballPosition, ballRadius, vashliPosition, vashliRadius) == true)
    {
        //
        printf("gio chkviania -- vashli nachamia\n");
        VashliRandom();
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


void DrawGame(void)
{
    BeginDrawing();

        ClearBackground(DARKGRAY);

        DrawText("move the ball with arrow keys", 10, 10, 20, BLUE);
            
        DrawFPS(screenWidth/4, screenHeight/4);   // ფერი როგორ შევუცვალო? :))

        DrawCircleV(ballPosition, ballRadius, ballColor); // Draw a color-filled circle (Vector version)
        
        DrawCircleV(vashliPosition, vashliRadius, vashliColor); // ვაშლის ხატვა 
        
        DrawLine(ballPosition.x, ballPosition.y, vashliPosition.x, vashliPosition.y, BLACK); // ვაშლისა და თავის ცენტრებს შორის ჯოხი
        
    EndDrawing();
}