#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include "Scribble.h"
#include <vector>

class Canvas : public bobcat::Canvas_ {
    public:
        Canvas(int x, int y, int w, int h);
        
        void render();
        void startScribble();
        void updateScribble(float x, float y, float r, float g, float b, int size);
        void endScribble();
    
    private: 
        std::vector<Shape*> shapes;
        Scribble* currentScribble = nullptr;

        friend struct::AppTest;
};

#endif