
#include "raylib.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>



void CleanString(const char *src, char *dst)
{
    int j = 0;
    int i = 0;
    while (src[i] != '\0')
    {
        if (isalpha((unsigned char)src[i]))
        {
            dst[j] = tolower(src[i]);
            j++;
        }
        i++;
    }
    dst[j] = '\0';
}


// Palindrome Checker using while logic exactly
int PalindromeCheck(const char *input)
{
    char clean[300];
    char reversed[300];

    CleanString(input, clean);

    int length = strlen(clean);
    int i = 0;

    while (length != 0)
    {
        reversed[i] = clean[length - 1];
        i++;
        length--;
    }
    reversed[i] = '\0';

    if (strcmp(clean, reversed) == 0)
        return 1;
    return 0;
}


#define MAX_INPUT_CHARS 200


void DrawGlassPanel(Rectangle rec, Color tint)
{
    DrawRectangleRounded(rec, 0.20f, 20, (Color){tint.r, tint.g, tint.b, 100});
    DrawRectangleRoundedLines(rec, 0.20f, 20, (Color){255, 255, 255, 150});
}


// Neon Button 
int NeonButton(Rectangle rec, const char *text, float size, float glow)
{
    Vector2 center = {rec.x + rec.width / 2, rec.y + rec.height / 2};

    
    DrawCircleGradient(center.x, center.y, glow,
                       (Color){40, 200, 255, 120},
                       (Color){60, 255, 255, 40});

    DrawRectangleRounded(rec, 0.35f, 20, (Color){25, 180, 220, 240});
    DrawRectangleRoundedLines(rec, 0.35f, 20, (Color){255, 255, 255, 250});

    int tw = MeasureText(text, (int)size);
    DrawText(text, center.x - tw / 2, center.y - size / 2 - 2, size,
             (Color){255, 255, 255, 255});

    Vector2 mp = GetMousePosition();
    if (CheckCollisionPointRec(mp, rec))
    {
        DrawRectangleRoundedLines(rec, 0.35f, 20, (Color){255, 255, 255, 255});
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 1;
    }
    return 0;
}

// Main Entry
int introScreen = 1; // 1 = show names, 0 = show palindrome app
int main(void)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(900, 600, "PALINDROME CHECKER  •  GUI");
    InitAudioDevice(); // start audio system

    Sound sClick = LoadSound("assets/preview.wav");
    Sound sSuccess = LoadSound("assets/Success.wav");
    Sound sFail = LoadSound("assets/Wrong.wav");

    Texture2D uniLogo = LoadTexture("assets/logo.png");

    char input[MAX_INPUT_CHARS + 1] = {0};
    int inputIndex = 0;
    int checked = 0;
    int isPalin = 0;

    float glow = 60.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        glow += 0.3f;
        if (glow > 80)
            glow = 60;

        // Text Input
        int key = GetCharPressed();
        while (key > 0)
        {
            if (key >= 32 && key <= 125 && inputIndex < MAX_INPUT_CHARS)
            {
                input[inputIndex] = (char)key;
                inputIndex++;
                input[inputIndex] = '\0';
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE) && inputIndex > 0)
        {
            inputIndex--;
            input[inputIndex] = '\0';
        }

        BeginDrawing();
        ClearBackground((Color){18, 18, 18, 255});

        
        if (introScreen)
        {
            DrawText("PALINDROME CHECKER",
                     GetScreenWidth() / 2 - MeasureText("PALINDROME CHECKER", 50) / 2,
                     100, 50, (Color){100, 255, 200, 255});

            DrawText("Mustafa Muhammad Ali (25K-0076)",
                     GetScreenWidth() / 2 - MeasureText("Mustafa Muhammad Ali (25K-0076)", 30) / 2,
                     220, 30, (Color){200, 200, 255, 255});

            DrawText("Safiullah Khan (25K-0036)",
                     GetScreenWidth() / 2 - MeasureText("Safiullah Khan (25K-0036)", 30) / 2,
                     270, 30, (Color){200, 200, 255, 255});

            DrawText("Press ENTER to Continue",
                     GetScreenWidth() / 2 - MeasureText("Press ENTER to Continue", 22) / 2,
                     400, 22, (Color){150, 150, 150, 255});

            if (IsKeyPressed(KEY_ENTER))
                introScreen = 0;

            EndDrawing();
            continue;
        }
        // ========= END INTRO SCREEN =========
        // Draw University Logo (top-right corner)
        if (uniLogo.id != 0)
        {
            float scale = 0.35f; // adjust size
            DrawTextureEx(uniLogo,
                          (Vector2){GetScreenWidth() - uniLogo.width * scale - 20, 20},
                          0.0f, scale,
                          (Color){255, 255, 255, 255});
        }

        DrawText("PALINDROME CHECKER",
                 47, 48, 48, (Color){0, 200, 255, 70});
        DrawText("PALINDROME CHECKER",
                 50, 50, 48, (Color){200, 255, 255, 255});

        Rectangle panel = {100, 150, 700, 250};
        DrawGlassPanel(panel, (Color){30, 30, 30, 255});

        DrawText("ENTER TEXT:",
                 panel.x + 30, panel.y + 20, 30,
                 (Color){150, 220, 255, 255});

        DrawRectangleRounded(
            (Rectangle){panel.x + 25, panel.y + 70, panel.width - 50, 60},
            0.20f, 20, (Color){255, 255, 255, 30});
        DrawRectangleRoundedLines(
            (Rectangle){panel.x + 25, panel.y + 70, panel.width - 50, 60},
            0.20f, 20, (Color){255, 255, 255, 100});

        DrawText(input, panel.x + 35, panel.y + 90, 30,
                 (Color){240, 250, 255, 255});

        Rectangle btn = {panel.x + panel.width / 2 - 140, panel.y + 150, 280, 70};

        if (NeonButton(btn, "CHECK", 36, glow))
        {
            PlaySound(sClick);
            isPalin = PalindromeCheck(input);
            checked = 1;
            if (isPalin)
                PlaySound(sSuccess);
            else
                PlaySound(sFail);
        }

        if (checked)
        {
            Rectangle resultPanel = {100, 420, 700, 120};
            DrawGlassPanel(resultPanel, (Color){60, 60, 60, 255});

            const char *msg = (isPalin ? "IT IS A PALINDROME" : "NOT A PALINDROME");

            Color clr = (isPalin ? (Color){40, 255, 140, 255} : (Color){255, 80, 80, 255});

            DrawText(msg, resultPanel.x + 90, resultPanel.y + 35, 38, clr);
        }

        EndDrawing();
    }
    UnloadSound(sClick);
    UnloadSound(sSuccess);
    UnloadSound(sFail);
    UnloadTexture(uniLogo);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
