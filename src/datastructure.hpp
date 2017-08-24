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

/*
@class datastructure contains all the common members of each data structure
it defines a tokeniser to specify delimitters, a map for word counts and an
initial value for the minimum edit distance
it contains virtual methods for adding a word to the datastructure dictionary, 
adding a line to the word count map, sending the word count data to a csv and 
initialising the dictionary
it also has the edit distance method to find fuzzy words of map elements in the 
dictionary
*/

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