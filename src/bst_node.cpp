/*
Author: Hayden Warmington
Student ID: s3486075
*/
#include "bst_node.hpp"

bst_node::bst_node(std::string &s)
{
	str = s;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	count = 0;
}

std::string bst_node::get_string()
{
	return str;
}

void bst_node::set_string(std::string new_string)
{
	str = new_string;
}

/*
node accessors for traversal
*/
bst_node* bst_node::get_left()
{
	return left.get();
}

bst_node* bst_node::get_right()
{
	return right.get();
}

bst_node* bst_node::get_parent()
{
	return parent;
}

/*
node accessor for change of ownership
*/
std::unique_ptr<bst_node>& bst_node::get_left_ptr()
{
	return left;
}
std::unique_ptr<bst_node>& bst_node::get_right_ptr()
{
	return right;
}

unsigned bst_node::get_count()
{
	return count;
}

void bst_node::set_count(unsigned new_count)
{
	count = new_count;
}

void bst_node::incr_count()
{
	count++;
}

void bst_node::decr_count()
{
	count--;
}

void bst_node::set_left(std::unique_ptr<bst_node> &&new_left)
{
	left = std::move(new_left);
}

void bst_node::set_right(std::unique_ptr<bst_node> &&new_right)
{
	right = std::move(new_right);
}

void bst_node::set_parent(bst_node* new_parent)
{
	parent = new_parent;
}
