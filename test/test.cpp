#include "test.h"
#include "window.h"

#include "renderers/triangle_renderer.h"
#include "renderers/triangle_color_renderer.h"
#include "renderers/triangle_tex_renderer.h"

void OGLBPTest::test(){

    AppWindow win;

    //win.addRenderer("triangle", std::make_shared<TriangleRenderer>());
    //win.addRenderer("triangleColor", std::make_shared<TriangleColorRenderer>(gl_utils::make_triangle(), gl_utils::random_colors()));
    //win.addRenderer("triangleCustomColor", std::make_shared<TriangleColorRenderer>(gl_utils::random_colored_triangles()));
    
    /*
    const std::vector<float> triangleData = {
        0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    };

    win.addRenderer("triangleColorData", std::make_shared<TriangleColorRenderer>(triangleData));
    */

    const std::vector<float> triangleData = {
    //  Position(3)       Color(4)                Texture (2)
        0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f
    };

    win.addRenderer("triangleTexData", std::make_shared<TriangleTexRenderer>(triangleData));



    while(win.renderLoop());
}