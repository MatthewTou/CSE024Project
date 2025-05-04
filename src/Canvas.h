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
#include "Selector.h"
#include <bobcat_ui/canvas.h>
#include <vector>

class Canvas : public bobcat::Canvas_ {
    std::vector<Shape*> shapes;
    Scribble* currentScribble;
    Shape* selected;
    Selector* selector;

    
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

        void select(float x, float y);
        void moveSelected(float dx, float dy);
        void recolorSelected(float r, float g, float b);
        void bringSelectedToFront();
        void sendSelectedToBack();
        void resizeSelected(bool increase);

        Shape* getSelected() const;
        void deselect();

        void clear();
        void undo();

};

#endif