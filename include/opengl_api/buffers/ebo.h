#pragma once
#include "bindable.h"

class EBO : public Bindable{

	public:
		EBO();
		~EBO();

		void bind() override {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
			_enabled = true;
		}

		template<uint N> void setData(const std::array<uint, N>& indices, GLenum mode=GL_STATIC_DRAW){
			require_bound("EBO", "setData");
			_size = N;
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint)*N, indices.data(), mode);	
		}

		void setData(const std::vector<uint>& indices, GLenum mode=GL_STATIC_DRAW){
			require_bound("EBO", "setData");
			_size = indices.size();
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint)*indices.size(), indices.data(), mode);	
		}

		void unbind() override {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			_enabled = false;
		}

		uint size(){
			return _size;
		}

	private:
		uint _size;	

};