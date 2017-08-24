/*
Author: Hayden Warmington
Student ID: s3486075
*/
#include "parser.hpp"


int parser::parse()
{
	namespace po = boost::program_options;

	try
	{
		po::options_description desc{ "Options" };
		desc.add_options()
			("help,h", "Display help menu")
			(",s", po::value<std::string>()->required(), "Data Structure")
			(",d", po::value<std::string>()->required(), "Dictionary")
			(",t", po::value<std::string>()->required(), "Input Text File")
			(",o", po::value<std::string>()->default_value("output.txt"),
				"Output Text File");

		po::variables_map vm;
		store(parse_command_line(argc, argv, desc), vm);

		if (vm.count("help"))
			std::cout << desc << std::endl;

		po::notify(vm);

		datastructure.assign(vm["-s"].as<std::string>());
		outputfile.assign(vm["-o"].as<std::string>());
		inputfile.assign(vm["-t"].as<std::string>());
		dictionaryfile.assign(vm["-d"].as<std::string>());
	}
	catch (const po::error &ex)
	{
		std::cerr << ex.what() << std::endl;
		std::cout << "-h or --help for options" << std::endl;
		return -1;
	}
	return 0;
}

std::string parser::get_data_structure_string()
{
	return datastructure;
}

std::string parser::get_output_file_string()
{
	return outputfile;
}

std::string parser::get_input_file_string()
{
	return inputfile;
}

std::string parser::get_dictionary_file_string()
{
	return dictionaryfile;
}
