#include "test.h"
#include "window.h"

void OGLBPTest::test(){

    AppWindow win;
    win.setCurrent();

    while(win.renderLoop());
}