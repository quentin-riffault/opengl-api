#include "programs/program_bank.h"

ProgramBank::ProgramBank() : _bank(16){}
ProgramBank::~ProgramBank(){}

/**
 * @brief Fetches a program in cache or on the disk.
 * 
 * @param program_identifier Name of the shader, without the .{f|v}.glsl extension
 * @return std::shared_ptr<Program> 
 */
std::shared_ptr<Program> ProgramBank::getProgramInstance(const std::string& program_identifier){

	if(_bank.find(program_identifier) != _bank.end()){
		std::cout << "[getProgramInstance] Using cached program " << program_identifier << std::endl;
		return _bank[program_identifier];		
	}

	std::cout << "[getProgramInstance] Loading new " << program_identifier << " program instance" << std::endl;

	const std::string vshader = shader_directory + "/" + program_identifier+".v.glsl";
	const std::string fshader = shader_directory + "/" + program_identifier+".f.glsl"; 

	//std::cout << vshader << " - " << fshader << std::endl;

	std::shared_ptr<Program> p = std::make_shared<Program>(fshader, vshader);
	_bank.insert(std::make_pair(program_identifier, p));
	std::cout << "[getProgramInstance] Program " << program_identifier << " Loaded - Loaded programs : " << _bank.size() << std::endl;
	return p; 	
}

