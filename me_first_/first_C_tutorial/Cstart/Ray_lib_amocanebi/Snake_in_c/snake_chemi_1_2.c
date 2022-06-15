/*******************************************************************************************
*
*   Kapana. Snake C Raylib
*   ვ.1.2 (მაუსს უნდა დაყვებოდეს გველი)
*
********************************************************************************************/

/*
- გადაწერის პროცესი რომ იწერებოდეს "მიმდინარეობს მასივების გადაწერის პროცესი - სანამ მიდის პრცესი იქამდე ეწეროს ეკრანზე ეგ"

- მაუსის ჩამატება 

- მაუსის ისარს გაყვეს სნეიქი
*/

#include <stdio.h>
#include <math.h>
#include "raylib.h"

// ცვლადები 
//--------------------------------------------------------------------------------------
// #define SNAKE_LENGTH   1000000
#define SNAKE_LENGTH   20

const  int screenWidth   = 800;
const  int screenHeight  = 450;
int framesCounter        = 0;
const  int fps_chemi     = 60;   // Set our game to run at 'fps_chemi' frames-per-second  
float iqsi               = 1.0;  // ჯერ არ ვიყენებ არაფერში 

int counter_meatedi      = 0;    // ყოველი მეათე ბიჯი ერთია აქ რაც გააკეთა გველის თავმა 
int counter              = 0;    // რამდენი ბიჯი გააკეთა გველის თავმა მაგის მთვლელი 

// გველი    
Vector2 ballPosition     = { (float)screenWidth/2, (float)screenHeight/2 }; 
Color ballColor          = DARKBLUE;
const float ballRadius   = 10.0;
const float speed        = (int)ballRadius * 2;  // 20 step 
float speed2             = 0; 

int tailPositionsX[SNAKE_LENGTH];   
int tailPositionsY[SNAKE_LENGTH];    
int test_snake_modzraoba_x[SNAKE_LENGTH]; 
int test_snake_modzraoba_y[SNAKE_LENGTH]; 
int test_snake_gadawera_x[SNAKE_LENGTH];
int test_snake_gadawera_y[SNAKE_LENGTH];

// ვაშლი
Vector2 vashliPosition   = {0,0}; 
Vector2 chek_vashli_pos  = {0,0}; 
Color vashliColor        = RED;
float vashliRadius       = 10.0;
int counter_vashlebi     = 0; 

// კუდის ვექტორის
Vector2 kudi      = {0,0}; 
float kudi_radius = ballRadius;

// ბულიანები
static bool pause        = false;
static bool game_over    = false;

static bool kudze_aris   = false;
static bool kudze_araris = false;

static bool game_win     = false;

bool marjvenaKlaviatura  = true; // მიმართულებები
bool marcxenaKlaviatura  = false;
bool zedaKlaviatura      = false;
bool qvedaKlaviatura     = false;
bool diagonali           = false;

// ფერები (კუდის)
Color colors[10] = { 0 };

// 2დ კამერა ინიციალიზაცია 
Camera2D camera = { 0 };

// მაუსი 
Vector2 mausPosition  = { -100.0f, -100.0f };
Color mausColor       = RED;
int touchCounter      = 0;
Vector2 touchPosition = { 0 };
#define MAX_TOUCH_POINTS 10

int A   = 0;
int B   = 0; 
float C = 0.0;

int main(void) 
{   
    // 2დ კამერა ინიციალიზაცია 
    //--------------------------------------------------------------------------------------
    camera.target = (Vector2){ ballPosition.x, ballPosition.y}; // აქ რაღაც შევცვალე 
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    
    // ფერების გენერირება
    //--------------------------------------------------------------------------------------
    for (int i = 0; i < 10; i++) colors[i] = (Color){ GetRandomValue(0, 250), GetRandomValue(50, 150), GetRandomValue(10, 100), 255 };
    
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Snake - Kapana");
    
    // ვაშლი (ინიციალიზაცია)
    //--------------------------------------------------------------------------------------
    VashliRandom(); 
    
    // Set our game to run at 60 frames-per-second  
    //--------------------------------------------------------------------------------------
    SetTargetFPS(fps_chemi);
    
    
    // Main game loop
    while (!WindowShouldClose())                    // Detect window close button or ESC key
    {   
        // 2 დ კამერა
        //----------------------------------------------------------------------------------
        // Camera rotation controls
        if (IsKeyDown(KEY_A)) camera.rotation--;
        else if (IsKeyDown(KEY_S)) camera.rotation++;

        // Limit camera rotation to 80 degrees (-40 to 40)
        if (camera.rotation > 40) camera.rotation = 40;
        else if (camera.rotation < -40) camera.rotation = -40;

        // Camera zoom controls
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);

        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

        // Camera reset (zoom and rotation)
        if (IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
            camera.rotation = 0.0f;
        }
        
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
    
    // კითხვარი - სახელის შეყვანა მაგალითად 
    // sheyvanaSaxelis(); // <------------------||||+ პრობლემა 
    
    // მიმართულების მიცემა  
    mimartulebebiKlaviaturidan();
    
    // გველის თავის სიარული speed(მეტამფეტამინით) და პაუზა
    gvelisSiaruliANDpasuse(); 
    
    // გველის თავის სიარული კედლებში (დასახვეწია გასვლა კედელში) 
    gvelisSiaruliKedlebshi();
    
    // ვაშლის ჭამა (დასახვეწია)
    vashlisChama();
    
    // მაუსი 
    mausiJoistiki();
   
    // თავის ჭამა (დასახვეწია)
    tavisChama();
}

void mausiJoistiki(void)
{
    // სამკუთხედების გამოთვლები A და B და ერთეულოვანი a და b ს მოძებნის ალგორითმი. 
    // ასევე თარგეთამდე მანძილის და იტერაციების რაოდენობის გამოთვლა 
    
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        mausPosition = GetMousePosition();
        DrawLine(ballPosition.x, ballPosition.y, mausPosition.x, mausPosition.y, BLACK);
        
        A = abs(mausPosition.x - ballPosition.x); // x
        B = abs(mausPosition.y - ballPosition.y); // y 
        C = sqrt(pow(A,2) + pow(B,2));      
        
        pause = !pause;
        printf("GAME PAUSED\n");
    }
    mausColor = BEIGE;
    
    
    
        
    DrawText(TextFormat("A.x = %d", A), 100, 130, 20, RED);
    DrawText(TextFormat("B.y = %d", B), 100, 150, 20, RED);
    DrawText(TextFormat("C.hipotenoza (target vs head) = %f", C), 100, 170, 20, RED);
    
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))   mausColor = MAROON;
    if (IsMouseButtonDown(MOUSE_MIDDLE_BUTTON)) mausColor = LIME;
    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))  mausColor = DARKBLUE;

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))   touchCounter = 10;
    if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON)) touchCounter = 10;
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))  touchCounter = 10;

    if (touchCounter > 0) touchCounter--;
}

void sheyvanaSaxelis(void) // <------------------||||+ პრობლემა 
{
    char brzaneba[51];  
    
    while(true)
    {
        printf("enter player name: \n");
        gets(brzaneba);
        
        /* ვაილიდან გამოსვლა */
        printf("=================== \n");
        printf("ვაილ ციკლი გაგრძელდეს? (y or n) \n");
        gets(brzaneba);

        if (brzaneba[0] == 110)
        {
            printf("break \n");
            break;
        } else
        {
            printf("ვაილი გრძელდება \n");
            // continue;
        }
    }
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
        if (counter_vashlebi == SNAKE_LENGTH/2)
        {
            // თამაში მოიგე 
            game_win = true;
            pause = !pause;
            printf("GAME PAUSED you win \n");  
        }
    }
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
    if ((IsKeyPressed(KEY_Y) && game_over == true) || (IsKeyPressed(KEY_Y) && game_win == true)) 
    {
        tavidanDawyeba();       
    } else if (KEY_N){
        gamortva();
    }
    
    if (IsKeyPressed(KEY_P)) 
    {
        pause = !pause;
        printf("GAME PAUSED\n");        
    }
    if (!pause) // || (game_over == false)
    {   
        if ((framesCounter % ((int)ballRadius*2) == 0) && (diagonali == false)) 
        {
            if (marjvenaKlaviatura == true) ballPosition.x += speed; 
            if (marcxenaKlaviatura == true) ballPosition.x -= speed;
            if (zedaKlaviatura     == true) ballPosition.y -= speed;
            if (qvedaKlaviatura    == true) ballPosition.y += speed;
        }
        
        if ((framesCounter % ((int)ballRadius*2) == 0) && (diagonali == true)) // დიაგონალზე სიარული 
        {
            speed2 = speed/sqrt(2);
            if (marjvenaKlaviatura == true) ballPosition.x += speed2; 
            if (marcxenaKlaviatura == true) ballPosition.x -= speed2;
            if (zedaKlaviatura     == true) ballPosition.y -= speed2;
            if (qvedaKlaviatura    == true) ballPosition.y += speed2;
        }
        
        // როცა დადის. ყველა პოზიციას იმახსოვრებს tailPositionsX და tailPositionsY მასივებშi
        tailPositionsX[counter_meatedi] = ballPosition.x; 
        tailPositionsY[counter_meatedi] = ballPosition.y; 
                                                                
        if (counter_meatedi == SNAKE_LENGTH) // მეხსიერებაში დაათრევს ყველა პოზიციას - დაბალ ლენგზზე შესამოწმებელია
        {
            for (int i = counter_vashlebi; i >= 0; i--) // მასივის გადატვირთვისგან დაცვა 
            {
                tailPositionsX[i] = tailPositionsX[counter_meatedi - i];
                tailPositionsY[i] = tailPositionsY[counter_meatedi - i];
                // printf("tailPositionsX[%d] %d ; tailPositionsY[%d] %d\n", i, tailPositionsX[i], i, tailPositionsY[i]);
            }
            counter_meatedi = counter_vashlebi + 1;  
        }
        
        if (counter % ((int)ballRadius*2) == 0) 
        {                      
            for (int i = counter_vashlebi; i >= 0; i--)
            {
                test_snake_modzraoba_x[i] = tailPositionsX[counter_meatedi - i];
                test_snake_modzraoba_y[i] = tailPositionsY[counter_meatedi - i];
                // printf("test_snake_modzraoba_x[%d] %d ; test_snake_modzraoba_y[%d] %d\n", i, test_snake_modzraoba_x[i], i, test_snake_modzraoba_y[i]);
            }    
            counter_meatedi++;
        }
        counter++;
    }
}

void mimartulebebiKlaviaturidan(void)
{
    if (IsKeyDown(KEY_RIGHT) && marcxenaKlaviatura != true)
    { 
        marjvenaKlaviatura = true;
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = false;
        diagonali          = false;
    }
    if (IsKeyDown(KEY_LEFT) && marjvenaKlaviatura != true)
    {
        marjvenaKlaviatura = false;
        marcxenaKlaviatura = true; 
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = false;
        diagonali          = false;
    }
    if (IsKeyDown(KEY_UP) && qvedaKlaviatura != true)
    {
        marjvenaKlaviatura = false;
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = true;     
        qvedaKlaviatura    = false;
        diagonali          = false;
    }
    if (IsKeyDown(KEY_DOWN) && zedaKlaviatura != true)
    {
        marjvenaKlaviatura = false;
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = true;
        diagonali          = false;        
    }
    if ((IsKeyDown(KEY_RIGHT)) && (IsKeyDown(KEY_UP))) // დიაგონალზე სიარულით თავზე გადავლა მაინც შეუძლია 
    {                                                  
        marjvenaKlaviatura = true; // 
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = true; //    
        qvedaKlaviatura    = false;
        diagonali          = true;        
    }
    if ((IsKeyDown(KEY_LEFT)) && (IsKeyDown(KEY_UP)))  
    {
        marjvenaKlaviatura = false;
        marcxenaKlaviatura = true; //
        zedaKlaviatura     = true; //    
        qvedaKlaviatura    = false; 
        diagonali          = true;        
    }
    if ((IsKeyDown(KEY_LEFT)) && (IsKeyDown(KEY_DOWN))) 
    {
        marjvenaKlaviatura = false;
        marcxenaKlaviatura = true; //
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = true; // 
        diagonali          = true;
    }
    if ((IsKeyDown(KEY_RIGHT)) && (IsKeyDown(KEY_DOWN)))  
    {
        marjvenaKlaviatura = true; //
        marcxenaKlaviatura = false; 
        zedaKlaviatura     = false;     
        qvedaKlaviatura    = true; // 
        diagonali          = true;
    }
}

void VashliRandom(void)
{   
    for (int i = 0; i <= 100; i++) // ვაშლი არ დაახტება თავზე და კუდზე გველს
    {
        kudze_aris = false;
        kudze_araris = false;
        chek_vashli_pos.x = GetRandomValue(0,screenWidth);
        chek_vashli_pos.y = GetRandomValue(0,screenHeight);
        
        for (int k = 0; k <= counter_vashlebi; k++)
        {
            
            kudi.x = (float)test_snake_modzraoba_x[k];
            kudi.y = (float)test_snake_modzraoba_y[k];
            
            if (CheckCollisionCircles(kudi, kudi_radius, chek_vashli_pos, vashliRadius) == true) 
            {
                kudze_aris = true;                
            } else {
                kudze_araris = true;
            }                
            // printf("i da k %d %d\n",i,k);            
        }
            
        if (kudze_aris == false && kudze_araris == true)
        {
            vashliPosition.x = chek_vashli_pos.x;
            vashliPosition.y = chek_vashli_pos.y; 
            break;            
        }         
    }
}

void tailDraw(void)
{
    for (int i = counter_vashlebi; i > 0; i--) 
    { 
        DrawCircle(test_snake_modzraoba_x[i], test_snake_modzraoba_y[i], kudi_radius, colors[GetRandomValue(0, 10)]);   
    }
}

void tavisChama(void) 
{    
    for (int i = 1; i <= counter_vashlebi; i++)
    {
        kudi.x = (float)test_snake_modzraoba_x[i];
        kudi.y = (float)test_snake_modzraoba_y[i];
        
        if (CheckCollisionCircles(ballPosition, ballRadius, kudi, kudi_radius/2) == true)
        {                                                                                  
            tamashisGadatvirtva();
        }
    }
}

void tamashisGadatvirtva(void)
{
    pause = true;
    game_over = true;
}

void tavidanDawyeba(void)
{
    counter_vashlebi = 0;
    counter_meatedi = 0;
    counter = 0; 
    ballPosition.x = (float)screenWidth/2;
    ballPosition.y = (float)screenHeight/2;
    pause = false;
    game_over = false;
    game_win = false;
}

void gamortva(void)
{
    SetExitKey(KEY_N);
}

void DrawGame(void)
{
    BeginDrawing();

        ClearBackground(DARKGRAY);
        
        // 2დ ხატვა 
        //--------------------------------------------------------------------------------------  
        BeginMode2D(camera);
            
            DrawCircleV(ballPosition, ballRadius, ballColor); // გველის თავის ხატვა 
            tailDraw(); // ტანის ხატვა

            DrawCircleV(vashliPosition, vashliRadius, RED); // ვაშლის ხატვა 
            DrawLine(ballPosition.x, ballPosition.y, vashliPosition.x, vashliPosition.y, BLACK); // ვაშლისა და თავის ცენტრებს შორის ჯოხი
            
            DrawText("SCREEN AREA", 640, 10, 20, RED);
            
            for (int i = 0; i > -100; i--)
            {
                DrawRectangleLines(0 + i, 0 + i, screenWidth - 2*i, screenHeight - 2*i,  colors[GetRandomValue(0, 10)]);
                if (counter_meatedi == SNAKE_LENGTH)
                {
                    DrawRectangleLines(0 + i, 0 + i, screenWidth - 2*i, screenHeight - 2*i, RED);
                }
            }
            
            // მაუსის ხატვა 
            //--------------------------------------------------------------------------------------
            // Multitouch
            for (int i = 0; i < MAX_TOUCH_POINTS; ++i)
            {
                touchPosition = GetTouchPosition(i);                    // Get the touch point    
                if ((touchPosition.x >= 0) && (touchPosition.y >= 0))   // Make sure point is not (-1,-1) as this means there is no touch for it
                {
                    // Draw circle and touch index number
                    DrawCircleV(touchPosition, vashliRadius, ORANGE);
                    DrawText(TextFormat(".x %d .y %d", (int)mausPosition.x,(int)mausPosition.y), (int)touchPosition.x - 10, (int)touchPosition.y - 70, 20, RED);
                }
            }
            // Draw the normal mouse location
            DrawCircleV(mausPosition, vashliRadius + (touchCounter*3.0f), mausColor); 
            DrawLine(ballPosition.x, ballPosition.y, mausPosition.x, mausPosition.y, BLACK);
            
        EndMode2D();
        
        DrawText("move the ball with arrow keys", 10, 10, 20, BLUE);
        DrawText(TextFormat("VASHLI VUSHLEBI %i", counter_vashlebi), 100, 30, 20, GREEN); 
        // DrawText(TextFormat("counter (tracker) %i", counter), 100, 50, 20, LIGHTGRAY);
        DrawText(TextFormat("counter_meatedi (tracker) %i", counter_meatedi), 100, 70, 20, YELLOW);
         
        //DrawText(TextFormat("framesCounter (tracker) %d *60", framesCounter/60), 100, 70, 20, LIGHTGRAY);
        DrawText(TextFormat("test_snake_modzraoba_x[0] (tracker) %d", test_snake_modzraoba_x[0]), 100, 90, 20, RED);
        DrawText(TextFormat("test_snake_modzraoba_y[0] (tracker) %d", test_snake_modzraoba_y[0]), 100, 110, 20, RED);
        // DrawText(TextFormat("test_snake_modzraoba_x[1] (tracker) %d", test_snake_modzraoba_x[1]), 100, 130, 20, RED);
        // DrawText(TextFormat("test_snake_modzraoba_y[1] (tracker) %d", test_snake_modzraoba_y[1]), 100, 150, 20, RED);
        // DrawText(TextFormat("kudi.x (tracker) %f", kudi.x), 100, 170, 20, RED);
        // DrawText(TextFormat("kudi.y (tracker) %f", kudi.y), 100, 190, 20, RED);   
        // DrawText(TextFormat("speed2 %f", speed2), 100, 220, 20, RED);
        // DrawText(TextFormat("marjvenaKlaviatura %i", marjvenaKlaviatura), 100, 220, 20, RED);
        
        DrawFPS(screenWidth/2, 10); 
        
        // DrawRectangle( 10, 70, 250, 113, Fade(SKYBLUE, 0.5f));
        // DrawRectangleLines( 10, 70, 250, 113, BLUE);

        // DrawText("Free 2d camera controls:", 20, 80, 10, BLACK);
        // DrawText("- Right/Left to move Offset", 40, 100, 10, DARKGRAY);
        // DrawText("- Mouse Wheel to Zoom in-out", 40, 120, 10, DARKGRAY);
        // DrawText("- A / S to Rotate", 40, 140, 10, DARKGRAY);
        // DrawText("- R to reset Zoom and Rotation", 40, 160, 10, DARKGRAY); 

        // if (pause) DrawText("GAME PAUSED", screenWidth/2 - MeasureText("GAME PAUSED", 40)/2, screenHeight/2 - 40, 40, GRAY);  
        if (pause && game_over)
        {
            DrawText("GAME OVER", screenWidth/2 - MeasureText("GAME OVER", 40)/2, screenHeight/2 - 40, 40, RED);
            DrawText("tavidan? (y) or (n)", screenWidth/2 - MeasureText("tavidan? (y) or (n)", 40)/2, screenHeight/2 - 10, 40, RED);
        }
        else if (pause && game_win) 
        {
            DrawText("moige", screenWidth/2 - MeasureText("moige", 40)/2, screenHeight/2 - 40, 40, RED);
            DrawText("tavidan? (y) or (n)", screenWidth/2 - MeasureText("tavidan? (y) or (n)", 40)/2, screenHeight/2 - 10, 40, RED);
        }
        else if (pause) DrawText("GAME PAUSED", screenWidth/2 - MeasureText("GAME PAUSED", 40)/2, screenHeight/2 - 40, 40, GRAY); 
        
    EndDrawing();
}

/* 
თავიდან თამაშს რომ დაიწყებ უნდა შეიყვანო სახელი 
და ტექსტ ფაილში წერდეს სიას რეკორდების 10 გრადაციაში ვთქვათ  
თამაშის ბოლოს გაჩვენებდეს მაგ ინფორმაციას - ანუ ფაილიდან ამოწერა და ეკრანზე დაწერა

rey-lib ამოცანების გადახედვა რათა ვისწავლო კლავიატურიდან რამის დაწერა 

მალაშევსკის ჯოხი - ჰილერის ჯოხი
ჯოხების საცავი გასაახლებელი მაქვს 
*/

/*
გორგასლის 28 - ატომს :)) 
*/
