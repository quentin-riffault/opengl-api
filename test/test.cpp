#include "test.h"
#include "window.h"

#include "renderers/triangle_renderer.h"
#include "renderers/triangle_color_renderer.h"

void OGLBPTest::test(){

    AppWindow win;

    win.addRenderer("triangleColor", std::make_shared<TriangleColorRenderer>(gl_utils::make_triangle(), gl_utils::random_colors()));
    win.addRenderer("triangleCustomColor", std::make_shared<TriangleColorRenderer>(gl_utils::random_colored_triangles()));

    while(win.renderLoop());
}