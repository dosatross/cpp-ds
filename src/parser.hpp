/*
Author: Hayden Warmington
Student ID: s3486075
*/
#pragma once
#include <string>
#include <boost/program_options.hpp>
#include <iostream>

/*
@class parser parses the command line arguments
*/

class parser
{
	private:
		std::string datastructure;
		std::string outputfile;
		std::string inputfile;
		std::string dictionaryfile;
		int argc;
		char** argv;

	public: 
		parser(int argc, char** argv) : argc(argc), argv(argv) {}
		~parser() {}
		int parse();
		std::string get_data_structure_string();
		std::string get_output_file_string();
		std::string get_input_file_string();
		std::string get_dictionary_file_string();
};