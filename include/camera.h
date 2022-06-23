#pragma once

#include "gl_config.h"

enum Direction{
	FORWARD,
	BACKWARDS,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	PITCH_PLUS,
	PITCH_MINUS,
	ROLL_PLUS,
	ROLL_MINUS,
	YAW_PLUS,
	YAW_MINUS,
	ZOOM_PLUS,
	ZOOM_MINUS
};

class Camera{

	public:

		Camera();

		glm::mat4 pv() const{
			return _cached_pv;
		}

		void update_pv(){
			_cached_pv = _projection*_view;
		}

		glm::mat4 view() const{
			return _view;
		}
		
		glm::mat4 projection() const{
			return _projection;
		}


		void reset();
		void translate(const glm::vec3& translation);
		void rotate(const float& angle, const glm::vec3& axis);



	private:
		glm::mat4 _view;
		glm::mat4 _projection;
		glm::mat4 _cached_pv;
};