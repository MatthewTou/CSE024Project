#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include "Scribble.h"
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Shape.h"
#include <bobcat_ui/canvas.h>
#include <vector>

class Canvas : public bobcat::Canvas_ {
    std::vector<Shape*> shapes;
    Scribble* currentScribble;

    
    public:
        Canvas(int x, int y, int w, int h);
        
        void render();
        void startScribble();
        void updateScribble(float x, float y, float r, float g, float b, int size);
        void endScribble();

        void addRectangle(float x, float y, float r, float g, float b);
        void addCircle(float x, float y, float r, float g, float b);
        void addTriangle(float x, float y, float r, float g, float b);
        void addPolygon(float x, float y, float r, float g, float b);

        void clear();
        void undo();

};

#endif