#include "Application.h"
#include "Enums.h"
#include <bobcat_ui/bobcat_ui.h>

using namespace bobcat;
using namespace std;

Application::Application() {
    window = new Window(100, 100, 600, 500, "Paint Application");
    canvas = new Canvas(50, 0, 550, 450);
    toolbar = new Toolbar(0, 0, 50, 450);
    
    window->add(canvas);
    window->add(toolbar);

    ON_MOUSE_DOWN(canvas, Application::onMouseDown);
    ON_DRAG(canvas, Application::onMouseDrag);
    ON_MOUSE_UP(canvas, Application::onMouseUp);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    
    window->show();
}

void Application::onMouseDown(bobcat::Widget* sender, float x, float y) {
    TOOL tool = toolbar->getTool();
    if (tool == PENCIL) {
        canvas->startScribble();
        canvas->updateScribble(x, y, 0.0f, 0.0f, 0.0f, 5);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->startScribble();
        canvas->updateScribble(x, y, 1, 1, 1, 14);
        canvas->redraw();
    }
    else if (tool == CIRCLE) {
        canvas->addCircle(x, y, 1.0f, 0.0f, 0.0f);
        canvas->redraw();
    }
    else if (tool == TRIANGLE) {
        canvas->addTriangle(x, y, 1.0f, 0.0f, 0.0f);
        canvas->redraw();
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(x, y, 1.0f, 0.0f, 0.0f);
        canvas->redraw();
    }
    else if (tool == POLYGON) {
        canvas->addPolygon(x, y, 1.0f, 0.0f, 0.0f);
        canvas->redraw();
    }
}

void Application::onMouseDrag(bobcat::Widget* sender, float x, float y) {
    TOOL tool = toolbar->getTool();
    if (tool == PENCIL) {
        canvas->updateScribble(x, y, 0.0f, 0.0f, 0.0f, 5);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->updateScribble(x, y, 1.0, 1.0, 1.0, 14);
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
}