#include "Application.h"
#include "Enums.h"
#include "Point.h"
#include <bobcat_ui/bobcat_ui.h>

using namespace bobcat;
using namespace std;

Application::Application() {
    
    window = new Window(100, 100, 500, 650, "Paint Application");
    canvas = new Canvas(50, 0, 450, 600);
    toolbar = new Toolbar(0, 0, 50, 650);
    colorSelector = new ColorSelector(100, 600, 350, 50);
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
    else if (tool == SELECTOR) {
        canvas->select(x, y);

        Shape* current = canvas->getSelected();
        if (current) {
            
            Color color = colorSelector->getColor();

            // Recolor only if it's different
            float r = color.getR();
            float g = color.getG();
            float b = color.getB();

            // Check if color is different before applying
            if (current->getR() != r || current->getG() != g || current->getB() != b) {
                canvas->recolorSelected(r, g, b);
                canvas->redraw();
            } else {
            }
        }
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
    else if (tool == SELECTOR) {
        Shape* selected = canvas->getSelected();
        if (selected) {
            float dx = x - selected->getX();
            float dy = y - selected->getY();
            canvas->moveSelected(dx, dy);
            canvas->redraw();
        }
    }
}

void Application::onMouseUp(bobcat::Widget* sender, float x, float y) {
    canvas->endScribble();

}

void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();
    TOOL tool = toolbar->getTool();

    if (tool != SELECTOR) {
    canvas->deselect();  
    }

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
        canvas->resizeSelected(true);
        canvas->redraw();
    }
    else if (action == DECREASE_SIZE) {
        pointSize--;
        canvas->resizeSelected(false);
        canvas->redraw();
        }
    else if (action == BRING_TO_BACK) {
        canvas->sendSelectedToBack();
        canvas->redraw();
    }
    else if (action == BRING_TO_FRONT) {
        canvas->bringSelectedToFront();
        canvas->redraw();
    }

}