#pragma once

#define GLFW_INCLUDE_NONE
#define GL_GLEXT_PROTOTYPES

#define CUSTOM_GLFW_VERSION_MINOR 4
#define CUSTOM_GLFW_VERSION_MAJOR 4

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include <string>
#include <unordered_map>
#include <vector>
#include <array>
#include <memory>
#include <stdexcept>
#include <iostream>

#include "gl_utils.h"

#define CUSTOM_GLEW_VERSION GLEW_VERSION_4_4
