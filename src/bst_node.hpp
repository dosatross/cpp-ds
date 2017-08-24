/*
Author: Hayden Warmington
Student ID: s3486075
*/
#pragma once

#include <string>
#include <memory>

/*
@class bst_node contains all methods to interface with the node
bst_node only supports the std::string data type
each node owns (through unique_ptr) its left and right children and has a
pointer to its parent
each node has a count for each string to avoid duplicates in the bst
*/

class bst_node
{
	private:
		unsigned count;
		std::string str;
		std::unique_ptr<bst_node> left;
		std::unique_ptr<bst_node> right;
		bst_node* parent;
		
	public:
		bst_node(std::string &s);
		virtual ~bst_node() {}
		std::string get_string();
		void set_string(std::string);
		unsigned get_count();
		void set_count(unsigned);
		void incr_count();
		void decr_count();
		void set_left(std::unique_ptr<bst_node> &&new_left);
		void set_right(std::unique_ptr<bst_node> &&new_right);
		void set_parent(bst_node* new_parent);

		bst_node* get_left();
		bst_node* get_right();
		bst_node* get_parent();
		std::unique_ptr<bst_node>& get_left_ptr();
		std::unique_ptr<bst_node>& get_right_ptr();
		
};