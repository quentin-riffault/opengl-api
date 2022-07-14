#pragma once

#include "renderers/renderer.h"
#include "renderers/line.h"

class TrihedronRenderer : public Renderer{
	public:

		TrihedronRenderer();
		~TrihedronRenderer();

		void render() override;


	private:
		const std::string FSHADER_PATH = TEST_SHADER_PATH+"/line_shader.f.glsl";
		const std::string VSHADER_PATH = TEST_SHADER_PATH+"/line_shader.v.glsl";

		std::shared_ptr<Program> _prog = std::make_shared<Program>(FSHADER_PATH, VSHADER_PATH);
		
		Line axes[3] = {
			Line(Axis::X, _prog),
			Line(Axis::Y, _prog), 
			Line(Axis::Z, _prog)
		}; 

		glm::mat4 trihedron_view = glm::mat4(1.0f);
		glm::mat4 trihedron_projection = glm::mat4(1.0f);

};