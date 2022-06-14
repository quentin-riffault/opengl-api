#pragma once
#include "bindable.h"
#include "vbo.h"
#include "ebo.h"

class VAO : public Bindable{

	public: 
		VAO(uint vbo_count=1);
		~VAO();

		void bind() override{
			glBindVertexArray(_id);
		}

		void unbind() override{
			glBindVertexArray(0);
		}

		template<typename T, uint N> void set_vbo(const uint& index, const std::array<T, N>& values){
			if(index >= _vbos.size()) throw std::runtime_error("VBO Index overflow");
			_vbos[index]->setData<T, N>(values);
			_vbos[index]->setAttribPointer<T>(index);
		}
		
		template<typename T> void set_vbo(const uint& index, const std::vector<T>& values){
			if(index >= _vbos.size()) throw std::runtime_error("VBO Index overflow");
			_vbos[index]->setData<T>(values);
			_vbos[index]->setAttribPointer<T>(index);
		}

		void set_ebo(const std::vector<uint>& indices){
			_ebo.bind();
			_ebo.setData(indices);
		}

		template <uint N> void set_ebo(const std::array<uint, N>& indices){
			_ebo.bind();
			_ebo.setData<N>(indices);
		}

		void draw(GLenum mode=GL_TRIANGLES){
			bind();
			glDrawElements(mode, _ebo.size(), GL_UNSIGNED_INT, 0);
			unbind();
		}

	private:
    	EBO _ebo;
    	std::vector<std::shared_ptr<VBO>> _vbos;

};