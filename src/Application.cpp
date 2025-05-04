#include "Application.h"
#include "Enums.h"
#include "Point.h"
#include <bobcat_ui/bobcat_ui.h>

using namespace bobcat;
using namespace std;

Application::Application() {
    r = 1.0;
    g = 0.0;
    b = 0.0;
    pointSize = 5;
    color = "Red";
    
    window = new Window(100, 100, 400, 550, "Paint Application");
    canvas = new Canvas(50, 0, 450, 500);
    toolbar = new Toolbar(0, 0, 50, 500);
    colorSelector = new ColorSelector(50, 500, 300, 50);
    colorSelector->box(FL_BORDER_BOX);
    
    window->add(canvas);
    window->add(toolbar);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onMouseDown);
    ON_DRAG(canvas, Application::onMouseDrag);
    ON_MOUSE_UP(canvas, Application::onMouseUp);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    
    window->show();
}

void Application::onMouseDown(bobcat::Widget* sender, float x, float y) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->startScribble();
        canvas->updateScribble(x, y, color.getR(), color.getG(), color.getB(), pointSize);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->startScribble();
        canvas->updateScribble(x, y, 1, 1, 1, pointSize);
        canvas->redraw();
    }
    else if (tool == CIRCLE) {
        canvas->addCircle(x, y, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == TRIANGLE) {
        canvas->addTriangle(x, y, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(x, y, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == POLYGON) {
        canvas->addPolygon(x, y, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
}

void Application::onMouseDrag(bobcat::Widget* sender, float x, float y) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->updateScribble(x, y, color.getR(), color.getG(), color.getB(), pointSize);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->updateScribble(x, y, 1.0, 1.0, 1.0, pointSize);
        canvas->redraw();
    }
}

void Application::onMouseUp(bobcat::Widget* sender, float x, float y) {
    canvas->endScribble();

}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();

    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
    else if (action == UNDO) {
        canvas->undo();
        canvas->redraw();
    }
    else if (action == INCREASE_SIZE) {
        pointSize++;
        std::cout << "[DEBUG] pointSize increased to: " << pointSize << std::endl;
    }
    else if (action == DECREASE_SIZE) {
        if (pointSize > 1) {
            pointSize--;
        std::cout << "[DEBUG] pointSize decreased to: " << pointSize << std::endl;
        }
    }
}