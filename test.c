//
// Created by iurmfy on 2023/8/8.
//

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION

#include "raygui.h"

#undef RAYGUI_IMPLEMENTATION
#define RAYGUI_EXTRA_IMPLEMENTATION

#include "raygui_extra.h"

const char *list_str[] =
        {
        "New",
        "Open",
        "About",
        "Name"
        };

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        GuiMenuBar((Rectangle) {0, 0, GetScreenWidth(), 30}, list_str, 4);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        GuiStatusBar((Rectangle)
                             {0,
                              (float) GetScreenHeight() - 40,
                              (float) GetScreenWidth(),
                              40
                             }, "HelloWorld");
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
