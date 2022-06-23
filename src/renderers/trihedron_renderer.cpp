#include "renderers/trihedron_renderer.h"
TrihedronRenderer::TrihedronRenderer() : _prog(FSHADER_PATH, VSHADER_PATH){



	for(Renderer& r : _axes){
		r.scale(glm::vec3(0.25f));
		r.set_projection(&trihedron_projection);
		r.set_view(&trihedron_view);
	}
}



TrihedronRenderer::~TrihedronRenderer(){

}

void TrihedronRenderer::render(){
	for(Renderer& r : _axes){
		trihedron_view = *(_view);
		trihedron_view = glm::translate(trihedron_view, -glm::vec3(trihedron_view[3])); // Cancel translation
		r.render();
	}
}