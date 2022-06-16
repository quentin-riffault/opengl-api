#include "test.h"
#include "window.h"

#include "renderers/triangle_renderer.h"

void OGLBPTest::test(){

    AppWindow win;

    win.addRenderer("triangle", std::make_shared<TriangleRenderer>());


    while(win.renderLoop());
}