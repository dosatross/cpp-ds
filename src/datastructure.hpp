/*
Author: Hayden Warmington
Student ID: s3486075
*/
#pragma once

#include <string>
#include <map>
#include <boost/tokenizer.hpp>
#include <fstream>

#define DELIM " 1234567890!@#$%^&*()_+=[{}]\\|;:'\"<>,./?"

class datastructure
{
	protected:
		typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
		std::map<std::string, unsigned> word_count_map;
		const unsigned init_min_ed;


	public:
		datastructure() : init_min_ed(10000) {} //init min_ed
		virtual ~datastructure() {}
		virtual void add_line_to_dict(std::string) {}
		virtual void add_line_to_word_map(std::string) {}
		virtual void send_word_count_to_file(std::ofstream&) {}
		virtual void init_dictionary() {}
		unsigned edit_distance(std::string, std::string);
};