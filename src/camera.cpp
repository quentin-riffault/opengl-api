#include "camera.h"

Camera::Camera(){
	_view = glm::mat4(1.0f);
	_projection = glm::mat4(1.0f);
}

void Camera::reset(){
	_view = glm::mat4(1.0f);
	_projection = glm::mat4(1.0f);
}

void Camera::translate(const glm::vec3& translation){
	_view = glm::translate(_view, translation);
}

void Camera::rotate(const float& angle, const glm::vec3& axis){
	_view = glm::rotate(_view, angle, axis);
}
