/*
Author: Hayden Warmington
Student ID: s3486075
*/
#pragma once

#include "datastructure.hpp"
#include <vector>

/*
@class vector class contains an std::vector and implements the methods for 
adding a word to the vector dictionary, adding a line to the word count map and 
sending the word count data to a csv
this class inherits from the datastructure class
*/

class vector : public datastructure
{
	private:
		std::vector<std::string> dictionary;

	public:
		vector() {}
		virtual ~vector() {}
		void add_line_to_dict(std::string);
		void add_line_to_word_map(std::string);
		void send_word_count_to_file(std::ofstream &out_stream);
};