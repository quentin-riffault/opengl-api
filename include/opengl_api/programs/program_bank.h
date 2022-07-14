#pragma once

#include "programs/program.h"
using ProgramMap = StringMap<std::shared_ptr<Program>>;

/**
 * @brief Manages all programs, useful to compile every shader at startup
 * 
 */
class ProgramBank{

	
	public:
		ProgramBank();
		~ProgramBank();

		std::shared_ptr<Program> getProgramInstance(const std::string& program_identifier);
		std::string shader_directory = "../src/shaders"; 

		ProgramMap _bank;
	private:
};
