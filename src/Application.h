#ifndef APPLICATION_H
#define APPLICATION_H

#include <bobcat_ui/all.h>
#include "Canvas.h"
#include "Toolbar.h"
#include "Enums.h"

class Application : public bobcat::Application_ {
    bobcat::Window* window;
    Canvas* canvas;
    Toolbar* toolbar;

    void onMouseDown(bobcat::Widget*sender, float x, float y);
    void onMouseDrag(bobcat::Widget* sender, float x, float y);
    void onMouseUp(bobcat::Widget*sender, float x, float y);
    void onToolbarChange(bobcat::Widget* sender);
    
public:
    Application();

    friend struct::AppTest;
};


#endif