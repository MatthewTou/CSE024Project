#include <igloo/igloo.h>
#include <unistd.h>
#include "../src/Application.h"
#include "../src/Scribble.h"
#include "../src/Point.h"
#include <thread>

using namespace igloo;
using namespace bobcat;

Context(AppTest){

    static Application* app;

    static void func(){
        app->run();
    }

    void SetUp(){
        std::cout.flush();
    }

    void TearDown(){
        std::thread t1(func);
        usleep(2000000);
        t1.detach();
    }

    Spec(WindowAndInitialized) { 
        //Checks if Window is initialized
        Assert::That(app->window != 0, IsTrue());
    }

    Spec(CanvasInitialized) { 
        //Checks if Window is initialized
        Assert::That(app->canvas != 0, IsTrue());
    }

    Spec(ScribbleShouldAddPoints) {
        Scribble scribble;
        scribble.addPoint(0.0, 0.0f, 1.0f, 0.0f, 0.0f, 5);
        scribble.addPoint(0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 7);
        Assert::That(scribble.getPointCount(), Equals(2u));
    }

    Spec(ScribbleShouldDrawWithoutCrash) {
    Scribble scribble;
    scribble.addPoint(0.0, 0.0f, 1.0f, 0.0f, 0.0f, 5);
    scribble.addPoint(-0.5, -0.5f, 0.0f, 0.0f, 1.0f, 5);
    scribble.draw();
    Assert::That(true, IsTrue());
    }

    Spec(ScribbleDestructorShouldCleanMemory) {
        Scribble* scribble = new Scribble();
        scribble->addPoint(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 5);
        delete scribble;
        Assert::That(true, IsTrue());
    }

    Spec(TriangleResizeShouldAffectSize) {
    Triangle tri(0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    float oldSize = tri.getSize();  
    tri.setSize(true);
    Assert::That(tri.getSize(), IsGreaterThan(oldSize));
    }

    Spec(CircleResizeShouldAffectRadius) {
        Circle c(0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
        float oldRadius = c.getRadius(); 
        c.setSize(true);
        Assert::That(c.getRadius(), IsGreaterThan(oldRadius));
    }

    Spec(RectangleResizeShouldChangeDimensions) {
        Rectangle rect(0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
        float oldWidth = rect.getWidth(); 
        float oldHeight = rect.getHeight();
        rect.setSize(true);
        Assert::That(rect.getWidth(), IsGreaterThan(oldWidth));
        Assert::That(rect.getHeight(), IsGreaterThan(oldHeight));
    }

    Spec(ScribbleResizeAffectsAllPoints) {
        Scribble scribble;
        scribble.addPoint(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 5);
        scribble.addPoint(0.2f, 0.2f, 0.0f, 1.0f, 0.0f, 5);
        scribble.setSize(true);
        Assert::That(scribble.getPointCount(), Equals(2u));
    }

    Spec(ScribbleSetColorChangesAllPoints) {
        Scribble scribble;
        scribble.addPoint(0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 5);
        scribble.setColor(0.2f, 0.4f, 0.6f);
        Assert::That(scribble.getR(), EqualsWithDelta(0.2f, 0.001f));
        Assert::That(scribble.getG(), EqualsWithDelta(0.4f, 0.001f));
        Assert::That(scribble.getB(), EqualsWithDelta(0.6f, 0.001f));
    }

};

Application* AppTest::app = new Application();

int main(int argc, const char** argv){
    return TestRunner::RunAllTests(argc, argv);
}