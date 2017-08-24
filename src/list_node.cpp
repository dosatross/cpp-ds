/*
Author: Hayden Warmington
Student ID: s3486075
*/
#include "list_node.hpp"

list_node::list_node(std::string &s)
{
	str = s;
	count = 0;
	next = nullptr;
}

std::unique_ptr<list_node>& list_node::get_next_ptr()
{
	return next;
}

list_node* list_node::get_next()
{
	return next.get();
}

std::string list_node::get_string()
{
	return str;
}

void list_node::set_string(std::string new_string)
{
	str = new_string;
}

unsigned list_node::get_count()
{
	return count;
}

void list_node::incr_count()
{
	count++;
}

void list_node::decr_count()
{
	count--;
}

void list_node::set_next(std::unique_ptr<list_node> &&new_next)
{
	next = std::move(new_next);
}
