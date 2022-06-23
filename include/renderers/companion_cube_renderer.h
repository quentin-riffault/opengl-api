#pragma once

#include "renderers/renderer.h"

class CompanionCubeRenderer : public Renderer{
	public: 
		CompanionCubeRenderer();
		virtual ~CompanionCubeRenderer();

		virtual void render() override;

	private:
		const std::vector<float> vertices = {
			0.0, 0.0, 1.0,		0.0, 1.0, // 0
			0.0, 0.0, 0.0,		0.0, 0.0, // 1
			1.0, 0.0, 0.0, 		1.0, 0.0, // 2
			1.0, 0.0, 1.0, 		1.0, 1.0, // 3
			0.0, 1.0, 1.0, 		1.0, 1.0, // 4
			0.0, 1.0, 0.0, 		0.0, 1.0, // 5
			1.0, 1.0, 0.0, 		0.0, 0.0, // 6
			1.0, 1.0, 1.0,		1.0, 0.0  // 7

		};

		const std::vector<uint> indices = {
			0,1,2,	2,3,0, // -y
			2,6,3,	6,7,3, // +x
			6,5,7,	5,4,7, // +y
			0,4,5,	1,0,5, // -x
			4,3,7,	4,0,3, // +z
			2,1,5,	2,5,6  // -z
		};
		
		Texture _tex; 
    	Program _prog;
    	VAO _vao;
};
