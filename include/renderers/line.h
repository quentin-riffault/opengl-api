#pragma once

#include "renderers/renderer.h"

class Line : public Renderer{
	public:

		Line(const std::vector<float>& data);
		Line(const Axis& ax, std::shared_ptr<Program> p);

		~Line();

		static std::vector<float> getAxis(Axis a){
		
			switch(a){
				case X: return std::vector<float>({
					-X_AXIS.x, -X_AXIS.y, -X_AXIS.z,	0.0f, 1.0f, 1.0f, 1.0f,
					X_AXIS.x, X_AXIS.y, X_AXIS.z,		1.0f, 0.0f, 0.0f, 1.0f
				});
				case Y: return std::vector<float>({
					-Y_AXIS.x, -Y_AXIS.y, -Y_AXIS.z,	1.0f, 0.0f, 1.0f, 1.0f,
					Y_AXIS.x, Y_AXIS.y, Y_AXIS.z,		0.0f, 1.0f, 0.0f, 1.0f
				});
				case Z: return std::vector<float>({
					-Z_AXIS.x, -Z_AXIS.y, -Z_AXIS.z,	1.0f, 1.0f, 0.0f, 1.0f,
					Z_AXIS.x, Z_AXIS.y, Z_AXIS.z,		0.0f, 0.0f, 1.0f, 1.0f
				});
				default:
					throw std::logic_error("[getAxis] Unhandled Axis");
			}
			
		}

		void render() override;
		void slave_render() override;

	private:
    const std::string FSHADER_PATH = TEST_SHADER_PATH+"/line_shader.f.glsl";
    const std::string VSHADER_PATH = TEST_SHADER_PATH+"/line_shader.v.glsl";

	const std::vector<uint> indices = {0, 1};


    std::shared_ptr<Program> _prog;
    VAO _vao;

};