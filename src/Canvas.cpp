#include "Canvas.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x,  y, w, h) {}

void Canvas::render()  { 
    //Current Render function creates a hole in the center in order to check if it is working.
    glEnable(GL_POINT_SMOOTH);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(10.0);

    glBegin(GL_POINT_SMOOTH);
        glVertex2f(0.0, 0.0);
}