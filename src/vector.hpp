/*
Author: Hayden Warmington
Student ID: s3486075
*/
#pragma once

#include "datastructure.hpp"
#include <vector>


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