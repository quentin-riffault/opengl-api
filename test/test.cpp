#include "test.h"

#include "renderers/triangle_renderer.h"
#include "renderers/triangle_color_renderer.h"
#include "renderers/triangle_tex_renderer.h"
#include "renderers/companion_cube_renderer.h"
#include "renderers/line.h"
#include "renderers/trihedron_renderer.h"

void OGLBPTest::test(){

    AppWindow win;

    //triangles(win); 
    //lines(win);
    trihedron(win);
    companion(win);
    while(win.renderLoop());
}

void OGLBPTest::lines(AppWindow& win){
    win.addRenderer("LineX", std::make_shared<Line>(Line::getAxis(X)));
    win.addRenderer("LineY", std::make_shared<Line>(Line::getAxis(Y)));
    win.addRenderer("LineZ", std::make_shared<Line>(Line::getAxis(Z)));
}

void OGLBPTest::trihedron(AppWindow& win){
    win.addRenderer("Trihedron", std::make_shared<TrihedronRenderer>());
}

void OGLBPTest::triangles(AppWindow& win){
    win.addRenderer("triangle", std::make_shared<TriangleRenderer>());
    win.addRenderer("triangleColor", std::make_shared<TriangleColorRenderer>(gl_utils::make_triangle(), gl_utils::random_colors()));


    const std::vector<float> triangleData = {
        0.0f,   0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.0f,
        0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f
    };

    win.addRenderer("triangleTexData", std::make_shared<TriangleTexRenderer>(triangleData));
}

void OGLBPTest::companion(AppWindow& win){
    win.addRenderer("CompanionCube", std::make_shared<CompanionCubeRenderer>()); 
}
