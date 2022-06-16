#include "test.h"
#include "window.h"

#include "renderers/triangle_renderer.h"
#include "renderers/triangle_color_renderer.h"

void OGLBPTest::test(){

    AppWindow win;

    win.addRenderer("triangle", std::make_shared<TriangleColorRenderer>(gl_utils::make_triangle()));

    while(win.renderLoop());
}