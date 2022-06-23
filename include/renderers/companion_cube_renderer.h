#pragma once

#include "renderers/renderer.h"

class CompanionCubeRenderer : public Renderer{
	public: 
		CompanionCubeRenderer();
		virtual ~CompanionCubeRenderer();

		virtual void render() override;

	private:
		const std::vector<float> vertices = {
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,	//  0 
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, // 1 Might be inverted
			0.5f, -0.5f, -0.5f, 1.0f, 1.0f, //	2
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f, //	3 Might be inverted
			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f // 	4 = 3
			-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, //	5
			0.5f, 0.5f, -0.5f, 0.0f, 1.0f, //	6 = 1
			0.5f, 0.5f, 0.5f, 0.0f, 0.0f //		7

		};

		const std::vector<uint> indices = {

		};
		
		Texture _tex; 
    	Program _prog;
    	VAO _vao;
};
