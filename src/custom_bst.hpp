/*
Author: Hayden Warmington
Student ID: s3486075
*/
#pragma once

#include <string>
#include <iostream>
#include <memory>
#include "bst_node.hpp"
#include "datastructure.hpp"

/*
@class custom_bst contains all methods to interface with the binary search tree
as well as methods to interface with the binary search tree dictionary
this class inherits from the datastructure class
*/

class custom_bst: public datastructure
{
	public:
		custom_bst();
		virtual ~custom_bst() {}
		int insert(std::string str);
		int search(std::string str);
		int delete_one(std::string str);
		int delete_all(std::string str);
		bst_node* get_min(bst_node* curr);
		bst_node* get_root();
		void ordered_print(bst_node* curr);
		void add_line_to_dict(std::string);
		void add_line_to_word_map(std::string);
		void send_word_count_to_file(std::ofstream &out_stream);
		void init_dictionary();
		bst_node* get_next(bst_node *curr);


	private:
		std::unique_ptr<bst_node> root;
		std::unique_ptr<custom_bst> dictionary;
		enum direction {
			LEFT, RIGHT
		};
		
};
