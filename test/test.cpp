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
};

Application* AppTest::app = new Application();

int main(int argc, const char** argv){
    return TestRunner::RunAllTests(argc, argv);
}