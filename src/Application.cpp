#include "Application.h"
#include <bobcat_ui/bobcat_ui.h>

using namespace bobcat;
using namespace std;

Application::Application() {
    window = new Window(100, 100, 400, 400, "Paint Application");
    canvas = new Canvas(10, 10, 350, 350);
    
    window->show();

    ON_MOUSE_DOWN(canvas, Application::onMouseDown);
    ON_DRAG(canvas, Application::onMouseDrag);
    ON_MOUSE_UP(canvas, Application::onMouseUp);
}

void Application::onMouseDown(bobcat::Widget* sender, float x, float y) {
    canvas->startScribble();
    canvas->updateScribble(x, y, 0.0f, 0.0f, 0.0f, 5);
    canvas->redraw();
}

void Application::onMouseDrag(bobcat::Widget* sender, float x, float y) {
    canvas->updateScribble(x, y, 0.0f, 0.0f, 0.0f, 5);
    canvas->redraw();
}

void Application::onMouseUp(bobcat::Widget* sender, float x, float y) {
    canvas->endScribble();
    canvas->redraw();
}