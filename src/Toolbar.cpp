#include "Toolbar.h"
#include "Enums.h"
#include <FL/Enumerations.H>
using namespace bobcat;

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
    pencilButton = new Image(x, y, 50, 50, "./assets/pencil.png");
    eraserButton = new Image(x, y + 50, 50, 50, "./assets/eraser.png");
    circleButton = new Image(x, y + 100, 50, 50, "./assets/circle.png");
    triangleButton = new Image(x, y + 150, 50, 50, "./assets/triangle.png");
    rectangleButton = new Image(x, y + 200, 50, 50, "./assets/rectangle.png");
    polygonButton = new Image(x, y + 250, 50, 50, "./assets/polygon.png"); 
    selectorButton = new Image(x, y + 300, 50, 50, "./assets/mouse.png");
    bringToFrontButton = new Image(x, y + 350, 50, 50, "./assets/bring-to-front.png");
    sendToBackButton = new Image(x, y + 400, 50, 50, "./assets/send-to-back.png");
    decreaseSizeButton = new Image(x, y + 450, 50, 50, "./assets/minus.png");
    increaseSizeButton = new Image(x, y + 500, 50, 50, "./assets/plus.png");
    undoButton = new Image(x, y + 550, 50, 50, "./assets/undo.png");
    clearButton = new Image(x, y + 600, 50, 50, "./assets/clear.png");
    
    pencilButton->box(FL_BORDER_BOX);
    eraserButton->box(FL_BORDER_BOX);
    circleButton->box(FL_BORDER_BOX);
    triangleButton->box(FL_BORDER_BOX);
    rectangleButton->box(FL_BORDER_BOX);
    polygonButton->box(FL_BORDER_BOX);
    undoButton->box(FL_BORDER_BOX);
    clearButton->box(FL_BORDER_BOX);
    decreaseSizeButton->box(FL_BORDER_BOX);
    increaseSizeButton->box(FL_BORDER_BOX);
    selectorButton->box(FL_BORDER_BOX);
    bringToFrontButton->box(FL_BORDER_BOX);
    sendToBackButton->box(FL_BORDER_BOX);
    
    tool = PENCIL;
    action = NONE;

    visualizeTool();

    ON_CLICK(pencilButton, Toolbar::onClick);
    ON_CLICK(eraserButton, Toolbar::onClick);
    ON_CLICK(circleButton, Toolbar::onClick);
    ON_CLICK(triangleButton, Toolbar::onClick);
    ON_CLICK(rectangleButton, Toolbar::onClick);
    ON_CLICK(polygonButton, Toolbar::onClick);
    ON_CLICK(polygonButton, Toolbar::onClick);
    ON_CLICK(selectorButton, Toolbar::onClick);
    ON_CLICK(bringToFrontButton, Toolbar::onClick);
    ON_CLICK(sendToBackButton, Toolbar::onClick);
    ON_CLICK(undoButton, Toolbar::onClick);
    ON_CLICK(clearButton, Toolbar::onClick);
    ON_CLICK(decreaseSizeButton, Toolbar::onClick);
    ON_CLICK(increaseSizeButton, Toolbar::onClick);
}

void Toolbar::onClick(bobcat::Widget* sender) {
    deselectAllTools();

    action = NONE;
    
    if (sender == pencilButton) {
        tool = PENCIL;
    }
    else if (sender == eraserButton) {
        tool = ERASER;
    }
    else if (sender == circleButton) {
        tool = CIRCLE;
    }
    else if (sender == triangleButton) {
        tool = TRIANGLE;
    }
    else if (sender == rectangleButton) {
        tool = RECTANGLE;
    }
    else if (sender == polygonButton) {
        tool = POLYGON;
    }
    else if (sender == selectorButton) {
        tool = SELECTOR;
    }
    else if (sender == undoButton) {
        action = UNDO;
    }
    else if (sender == clearButton) {
        action = CLEAR;
    }
    else if (sender == increaseSizeButton) {
        action = INCREASE_SIZE;
    }
    else if (sender == decreaseSizeButton) {
        action = DECREASE_SIZE;
    }
    else if (sender == bringToFrontButton) {
        action = BRING_TO_FRONT;
    }
    else if (sender == sendToBackButton) {
        action = BRING_TO_BACK;
    }

    if (onChangeCb) {
        onChangeCb(this);
    }

    visualizeTool();
    redraw();
}

void Toolbar::deselectAllTools() {
    pencilButton->color(FL_BACKGROUND_COLOR);
    eraserButton->color(FL_BACKGROUND_COLOR);
    circleButton->color(FL_BACKGROUND_COLOR);
    triangleButton->color(FL_BACKGROUND_COLOR);
    rectangleButton->color(FL_BACKGROUND_COLOR);
    polygonButton->color(FL_BACKGROUND_COLOR);
    selectorButton->color(FL_BACKGROUND_COLOR);
    bringToFrontButton->color(FL_BACKGROUND_COLOR);
    sendToBackButton->color(FL_BACKGROUND_COLOR);
    undoButton->color(FL_BACKGROUND_COLOR);
    decreaseSizeButton->color(FL_BACKGROUND_COLOR);
    increaseSizeButton->color(FL_BACKGROUND_COLOR);
}

void Toolbar::visualizeTool() {
    if (tool == PENCIL) {
        pencilButton->color(FL_WHITE);
    }
    if (tool == ERASER) {
        eraserButton->color(FL_WHITE);
    }
    else if (tool == CIRCLE) {
        circleButton->color(FL_WHITE);
    }
    else if (tool == TRIANGLE) {
        triangleButton->color(FL_WHITE);
    }
    else if (tool == RECTANGLE) {
        rectangleButton->color(FL_WHITE);
    }
    else if (tool == POLYGON) {
        polygonButton->color(FL_WHITE);
    }
    else if (tool == SELECTOR) {
        selectorButton->color(FL_WHITE);
    }
}

TOOL Toolbar::getTool() const {
    return tool;
}

ACTION Toolbar::getAction() const {
    return action;
}

