#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <bobcat_ui/all.h>
#include "Enums.h"

class Toolbar : public bobcat::Group {
    bobcat::Image* pencilButton;
    bobcat::Image* eraserButton;
    bobcat::Image* undoButton;
    bobcat::Image* clearButton;
    bobcat::Image* triangleButton;
    bobcat::Image* polygonButton;
    bobcat::Image* circleButton;
    bobcat::Image* rectangleButton;
    bobcat::Image* decreaseSizeButton;
    bobcat::Image* increaseSizeButton;


    TOOL tool;
    ACTION action;

    void onClick(bobcat::Widget* sender);
    void deselectAllTools();
    void visualizeTool();

public:
    Toolbar(int x, int y, int w, int h);

    TOOL getTool() const;
    ACTION getAction() const;
};

#endif
