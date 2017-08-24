/*
Author: Hayden Warmington
Student ID: s3486075
*/
#pragma once

#include "datastructure.hpp"
#include <list>


class list : public datastructure
{
private:
	std::list<std::string> dictionary;

public:
	list() {}
	virtual ~list() {}
	void add_line_to_dict(std::string);
	void add_line_to_word_map(std::string);
	void send_word_count_to_file(std::ofstream &out_stream);
};