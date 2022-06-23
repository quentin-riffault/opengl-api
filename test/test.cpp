#include "test.h"
#include "window.h"

#include "renderers/triangle_renderer.h"
#include "renderers/triangle_color_renderer.h"
#include "renderers/triangle_tex_renderer.h"
#include "renderers/companion_cube_renderer.h"
#include "renderers/line.h"
#include "renderers/trihedron_renderer.h"

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


    /*const std::vector<float> triangleData = {

    //  x       y     z     r     g     b     a     u      v
        0.0f,   0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.0f,
        0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f
    };

    win.addRenderer("triangleTexData", std::make_shared<TriangleTexRenderer>(triangleData));
    */


    //win.addRenderer("companionCube", std::make_shared<CompanionCubeRenderer>()); 
    //win.setWireframe("companionCube", true);

    /*win.addRenderer("LineX", std::make_shared<Line>(Line::getAxis(X)));
    win.addRenderer("LineY", std::make_shared<Line>(Line::getAxis(Y)));
    win.addRenderer("LineZ", std::make_shared<Line>(Line::getAxis(Z)));*/

    win.addRenderer("Trihedron", std::make_shared<TrihedronRenderer>());    

    while(win.renderLoop());
}