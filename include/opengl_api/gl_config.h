#pragma once

#define GLFW_INCLUDE_NONE
#define GL_GLEXT_PROTOTYPES

#define CUSTOM_GLFW_VERSION_MINOR 4
#define CUSTOM_GLFW_VERSION_MAJOR 4

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <unordered_map>
#include <vector>
#include <array>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <assert.h>
#include <exception>
#include <utility>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <functional>


#include "gl_utils.h"

const glm::vec3 X_AXIS = glm::vec3(1.0f, 0.0f, 0.0f);
const glm::vec3 Y_AXIS = glm::vec3(0.0f, 1.0f, 0.0f);
const glm::vec3 Z_AXIS = glm::vec3(0.0f, 0.0f, 1.0f);

const glm::vec3 XY_AXIS = X_AXIS + Y_AXIS;
const glm::vec3 YX_AXIS = XY_AXIS;

const glm::vec3 XZ_AXIS = X_AXIS + Z_AXIS;
const glm::vec3 ZX_AXIS = XZ_AXIS;

const glm::vec3 YZ_AXIS = Y_AXIS + Z_AXIS;
const glm::vec3 ZY_AXIS = YZ_AXIS;

const glm::vec3 XYZ_AXIS = glm::vec3(1.0f);
const glm::vec3 XZY_AXIS = XYZ_AXIS;
const glm::vec3 YXZ_AXIS = XYZ_AXIS;
const glm::vec3 ZXY_AXIS = XYZ_AXIS;
const glm::vec3 ZYX_AXIS = XYZ_AXIS;
const glm::vec3 YZX_AXIS = XYZ_AXIS;

enum Axis{
	X, Y, Z
};

#define CUSTOM_GLEW_VERSION GLEW_VERSION_4_4
