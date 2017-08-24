/*
Author: Hayden Warmington
Student ID: s3486075
*/
#pragma once

#include "datastructure.hpp"
#include <set>

/*
@class set class contains an std::set and implements the methods for adding a
word to the set dictionary, adding a line to the word count map and sending
the word count data to a csv
this class inherits from the datastructure class
*/

class set : public datastructure
{
private:
	std::set<std::string> dictionary;

public:
	set() {}
	virtual ~set() {}
	void add_line_to_dict(std::string);
	void add_line_to_word_map(std::string);
	void send_word_count_to_file(std::ofstream &out_stream);
};