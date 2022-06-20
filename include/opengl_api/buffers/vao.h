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
    		gl_utils::check_errors();
			_enabled = true;
		}

		void unbind() override{
			glBindVertexArray(0);
    		gl_utils::check_errors();
			_enabled = false;
		}

		template<typename T, uint N> void set_vbo(const uint& index, const std::array<T, N>& values, const size_t& n_components = 3){
			if(index >= _vbos.size()) throw std::runtime_error("VBO Index overflow");
			const std::shared_ptr<VBO>& vbo = _vbos[index];

			vbo->bind();
			vbo->setData<T, N>(values);
			vbo->setAttribPointer<T>(index, n_components);
			vbo->unbind();
		}
		
		template<typename T> void set_vbo(const uint& index, const std::vector<T>& values, const size_t& n_components = 3){
			if(index >= _vbos.size()) throw std::runtime_error("VBO Index overflow");
			const std::shared_ptr<VBO>& vbo = _vbos[index];

			vbo->bind();
			vbo->setData<T>(values);
			vbo->setAttribPointer<T>(index, n_components);
			vbo->unbind();
		}

		template<typename T> void set_vbo(const uint & index, const std::vector<T>& values, const std::function<void(void)>& attributor){
			if(index >= _vbos.size()) throw std::runtime_error("VBO Index overflow");
			const std::shared_ptr<VBO>& vbo = _vbos[index];

			vbo->bind();
			vbo->setData<T>(values);
			attributor();
			vbo->unbind();
		}
		
		template<typename T, std::size_t N> void set_vbo(const uint & index, const std::array<T, N>& values, const std::function<void(void)>& attributor){
			if(index >= _vbos.size()) throw std::runtime_error("VBO Index overflow");
			const std::shared_ptr<VBO>& vbo = _vbos[index];

			vbo->bind();
			vbo->setData<T, N>(values);
			attributor();
			vbo->unbind();
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
    		gl_utils::check_errors();
			unbind();
		}
    
	private:
    	EBO _ebo;
    	std::vector<std::shared_ptr<VBO>> _vbos;

};