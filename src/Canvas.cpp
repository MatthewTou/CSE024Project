#include "Canvas.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x,  y, w, h) {}

void Canvas::render()  { 
    //Current Render function creates a hole in the center in order to check if it is working.
    for (unsigned int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
    if (currentScribble) {
        currentScribble->draw();
    }
}

void Canvas::startScribble() { 
    currentScribble = new Scribble();
}

void Canvas::updateScribble(float x, float y, float r, float g, float b, int size) {
    if (currentScribble) {
        currentScribble->addPoint(x,y,r,g,b,size);
    }
}

void Canvas::endScribble() { 
    if (currentScribble) {
        shapes.push_back(currentScribble);
        currentScribble = nullptr;
    }
}
