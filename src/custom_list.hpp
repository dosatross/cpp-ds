/*
Author: Hayden Warmington
Student ID: s3486075
*/
#pragma once
#include <string>
#include <iostream>
#include "list_node.hpp"
#include "datastructure.hpp"

/*
@class custom_list contains all methods to interface with the linked list
as well as methods to interface with the linked list dictionary
this class inherits from the datastructure class
*/

class custom_list : public datastructure
{
	private:
		std::unique_ptr<list_node> head;
		unsigned length;
		std::unique_ptr<custom_list> dictionary;
		

	public:
		custom_list();
		virtual ~custom_list() {}
		int insert(std::string str);
		int search(std::string str);
		int delete_one(std::string str);
		int delete_all(std::string str);
		void print();
		void add_line_to_dict(std::string);
		void add_line_to_word_map(std::string);
		void send_word_count_to_file(std::ofstream &out_stream);
		void init_dictionary();

};