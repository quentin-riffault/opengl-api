#include "renderers/trihedron_renderer.h"
TrihedronRenderer::TrihedronRenderer(){

	for(auto& r : axes){
		_slaves.push_back(&r);
	}
}

TrihedronRenderer::~TrihedronRenderer(){

}

void TrihedronRenderer::render(){
	_prog->enable();

	for(Renderer* r : _slaves){
		r->render_call(true);
	}
	_prog->disable();
}