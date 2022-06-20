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

#define CUSTOM_GLEW_VERSION GLEW_VERSION_4_4
