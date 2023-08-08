//
// Created by iurmfy on 2023/8/8.
//
#include "ranlib.h"

#ifndef RAYGUI_EXTRA_H
#define RAYGUI_EXTRA_H

#ifdef __cplusplus
extern "C" {
#endif

void GuiMenuBar(Rectangle bounds, const char **option, int n);

#ifdef __cplusplus
}
#endif

#endif // RAYGUI_EXTRA_H


#ifdef RAYGUI_EXTRA_IMPLEMENTATION

#include "raygui.h"

const int MENU_WIDTH = 50;

void GuiMenuBar(Rectangle bounds, const char **option, int n)
{
    // Draw Menu Bar background
    DrawRectangleRec(bounds, LIGHTGRAY);

    int style = GuiGetStyle(DEFAULT, BORDER_WIDTH);
    // remove origin button border
    GuiSetStyle(DEFAULT, BORDER_WIDTH, 0);
    for (int i = 0; i < n; ++i)
    {
        // Draw Segmentation
        DrawLine((i * MENU_WIDTH) + bounds.x,
                 bounds.y,
                 (i * MENU_WIDTH) + bounds.x,
                 bounds.y + bounds.height,
                 BLACK);
        // Draw Opinion for menu
        GuiButton(
                (Rectangle)
                        {(i * MENU_WIDTH) + bounds.x,
                         bounds.y,
                         MENU_WIDTH,
                         bounds.height
                        },
                option[i]);
    }
    // Last Opinion
    DrawLine((n * MENU_WIDTH) + bounds.x,
             bounds.y,
             (n * MENU_WIDTH) + bounds.x,
             bounds.y + bounds.height,
             BLACK);
    // Recover style
    GuiSetStyle(DEFAULT, BORDER_WIDTH, style);
}

#endif // RAYGUI_EXTRA_IMPLEMENTATION