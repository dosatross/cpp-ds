/*
Author: Hayden Warmington
Student ID: s3486075
*/

/*
TODO
run valgrind
ds's miss the last line print to file
ordering out word count output

replace enum direction with get_parent()

comments for lines and functions
make sure i dont go over 80 characters/line
*/

#include "main.hpp"


int main(int argc, char*argv[])
{
	parser cmd_parser(argc, argv);
	if (cmd_parser.parse())
	{
		return EXIT_FAILURE;
	}

	//open files
	std::ifstream dict_stream;
	dict_stream.open(cmd_parser.get_dictionary_file_string()); //open dictionary
	if (!dict_stream.good())
	{
		std::cout << "Could not open file: " << cmd_parser.get_dictionary_file_string() << std::endl;
		dict_stream.close();
		return EXIT_FAILURE;
	}

	std::ifstream txt_stream;
	txt_stream.open(cmd_parser.get_input_file_string()); //open text file
	if (!txt_stream.good())
	{
		std::cout << "Could not open file: " << cmd_parser.get_input_file_string() << std::endl;
		dict_stream.close();
		txt_stream.close();
		return EXIT_FAILURE;
	}

	std::ofstream out_stream;
	out_stream.open(cmd_parser.get_output_file_string()); //output file
	if (!out_stream.good())
	{
		std::cout << "Could not open file: " << cmd_parser.get_output_file_string() << std::endl;
		dict_stream.close();
		txt_stream.close();
		out_stream.close();
		return EXIT_FAILURE;
	}


	std::unique_ptr<datastructure> ds;
	std::string line;
	std::string ds_string = cmd_parser.get_data_structure_string();


	if (!ds_string.compare("list"))
	{
		ds = std::make_unique<list>();
	}
	else if (!ds_string.compare("vector"))
	{
		ds = std::make_unique<vector>();
	}
	else if (!ds_string.compare("set"))
	{
		ds = std::make_unique<set>();
	}
	else if (!ds_string.compare("custom_list"))
	{
		ds = std::make_unique<custom_list>();
		ds->init_dictionary();
	}
	else if (!ds_string.compare("custom_tree"))
	{
		ds = std::make_unique<custom_bst>();
		ds->init_dictionary();
	}
	else
	{
		std::cout << "Datastructure is not supported" << std::endl;
		dict_stream.close();
		txt_stream.close();
		out_stream.close();
		return EXIT_SUCCESS;
	}

	while (getline(dict_stream, line) && dict_stream.good())
	{
		ds->add_line_to_dict(line);
	}

	while (getline(txt_stream, line) && txt_stream.good())
	{
		ds->add_line_to_word_map(line);
	}
	ds->send_word_count_to_file(out_stream);


	dict_stream.close();
	txt_stream.close();
	out_stream.close();

	return EXIT_SUCCESS;
}
