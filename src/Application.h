#ifndef APPLICATION_H
#define APPLICATION_H

#include <bobcat_ui/all.h>
#include "Canvas.h"

class Application : public bobcat::Application_ {
    bobcat::Window* window;
    Canvas* canvas;

    void onMouseDown(bobcat::Widget*sender, float x, float y);
    void onMouseDrag(bobcat::Widget* sender, float x, float y);
    void onMouseUp(bobcat::Widget*sender, float x, float y);
    
public:
    Application();

    friend struct::AppTest;
};


#endif