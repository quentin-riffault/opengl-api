#include "renderers/trihedron_renderer.h"
TrihedronRenderer::TrihedronRenderer() : _prog(FSHADER_PATH, VSHADER_PATH){

	for(auto& r : axes){
		_slaves.push_back(&r);
	}
}

TrihedronRenderer::~TrihedronRenderer(){

}

void TrihedronRenderer::render(){
	for(Renderer* r : _slaves){
		r->render_call();
	}
}