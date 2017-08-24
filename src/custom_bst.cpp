/*
Author: Hayden Warmington
Student ID: s3486075
*/
#include "custom_bst.hpp"

custom_bst::custom_bst()
{
	root = nullptr;
}

int custom_bst::insert(std::string str)
{
	bst_node* curr = root.get();
	std::unique_ptr<bst_node> new_node = std::make_unique<bst_node>(str);
	new_node->incr_count();

	if (root == nullptr) //if bst empty
	{
		root = std::move(new_node);
		return 0;
	}

	while (curr)
	{
		if (curr->get_string().compare(str) > 0) //if curr > newstr
		{
			if (curr->get_left() == nullptr)
			{
				new_node->set_parent(curr);
				curr->set_left(std::move(new_node));
				return 0;
			}
			else
			{
				curr = curr->get_left();
			}
		}
		else if (curr->get_string().compare(str) < 0) //if curr < newstr
		{
			if (curr->get_right() == nullptr)
			{
				new_node->set_parent(curr);
				curr->set_right(std::move(new_node));
				return 0;
			}
			else
			{
				curr = curr->get_right();
			}
		}
		else  //if curr = newstr
		{
			curr->incr_count();
			return 0;
		}
	}
}

int custom_bst::delete_one(std::string str)
{
	bst_node* parent = nullptr;
	bst_node* curr = root.get();
	direction dir = LEFT;

	while (curr)
	{
		if (curr->get_string().compare(str) > 0)
		{
			parent = curr;
			curr = curr->get_left();
			dir = LEFT;
		}
		else if (curr->get_string().compare(str) < 0)
		{
			parent = curr;
			curr = curr->get_right();
			dir = RIGHT;
		}
		else
		{
			curr->decr_count();
			if (curr->get_count() == 0)
			{
				if (curr->get_left() == nullptr && curr->get_right() == nullptr)
				{
					if (curr == root.get())
					{
						root = nullptr;
						return 0;
					}
					if (dir == LEFT)
					{
						parent->set_left(std::move(nullptr));
						return 0;
					}
					if (dir == RIGHT)
					{
						parent->set_right(std::move(nullptr));
						return 0;
					}
				}
				else if(curr->get_left() != nullptr && curr->get_right() == nullptr)
				{
					if (curr == root.get())
					{
						root = std::move(curr->get_left_ptr());
						return 0;
					}

					if (dir == LEFT)
					{
						parent->set_left(std::move(curr->get_left_ptr()));
					}
					else if (dir == RIGHT)
					{
						parent->set_right(std::move(curr->get_left_ptr()));
					}
					return 0;
				}
				else if (curr->get_left() == nullptr && curr->get_right() != nullptr)
				{
					if (curr == root.get())
					{
						root = std::move(curr->get_right_ptr());
						return 0;
					}

					if (dir == LEFT)
					{
						parent->set_left(std::move(curr->get_right_ptr()));
					}
					else if (dir == RIGHT)
					{
						parent->set_right(std::move(curr->get_right_ptr()));
					}
					return 0;
				}
				else if (curr->get_left() != nullptr && curr->get_right() != nullptr)
				{
					bst_node* replace_node = get_min(curr->get_right());
					unsigned replace_count = replace_node->get_count();
					std::string replace_string = replace_node->get_string();

					delete_one(replace_string);

					curr->set_string(replace_string);
					curr->set_count(replace_count);
					return 0;
				}
			}
			return 0;
		}
	}
	return -1;
}

int custom_bst::delete_all(std::string str)
{
	bst_node* parent = nullptr;
	bst_node* curr = root.get();
	direction dir = LEFT;
	
	while (curr)
	{
		if (curr->get_string().compare(str) > 0)
		{
			parent = curr;
			curr = curr->get_left();
			dir = LEFT;
		}
		else if (curr->get_string().compare(str) < 0)
		{
			parent = curr;
			curr = curr->get_right();
			dir = RIGHT;
		}
		else
		{
			if (curr->get_left() == nullptr && curr->get_right() == nullptr)
			{
				if (curr == root.get())
				{
					root = nullptr;
					return 0;
				}
				if (dir == LEFT)
				{
					parent->set_left(std::move(nullptr));
					return 0;
				}
				if (dir == RIGHT)
				{
					parent->set_right(std::move(nullptr));
					return 0;
				}
			}
			else if (curr->get_left() != nullptr && curr->get_right() == nullptr)
			{
				if (curr == root.get())
				{
					root = std::move(curr->get_left_ptr());
					return 0;
				}

				if (dir == LEFT)
				{
					parent->set_left(std::move(curr->get_left_ptr()));
				}
				else if (dir == RIGHT)
				{
					parent->set_right(std::move(curr->get_left_ptr()));
				}
				return 0;
			}
			else if (curr->get_left() == nullptr && curr->get_right() != nullptr)
			{
				if (curr == root.get())
				{
					root = std::move(curr->get_right_ptr());
					return 0;
				}

				if (dir == LEFT)
				{
					parent->set_left(std::move(curr->get_right_ptr()));
				}
				else if (dir == RIGHT)
				{
					parent->set_right(std::move(curr->get_right_ptr()));
				}
				return 0;
			}
			else if (curr->get_left() != nullptr && curr->get_right() != nullptr)
			{
				bst_node* replace_node = get_min(curr->get_right());
				unsigned replace_count = replace_node->get_count();
				std::string replace_string = replace_node->get_string();

				delete_one(replace_string);

				curr->set_string(replace_string);
				curr->set_count(replace_count);
				return 0;
			}
		}
	}
	return -1;
}

/*
@param
str: string to search for 

@return
0 if str found
-1 if str not found
*/
int custom_bst::search(std::string str)
{
	bst_node* curr = root.get();

	while (curr)
	{
		if (curr->get_string().compare(str) > 0)
		{
			curr = curr->get_left();
		}
		else if (curr->get_string().compare(str) < 0)
		{
			curr = curr->get_right();
		}
		else
		{
			return 0;
		}
	}
	return -1;
}

void custom_bst::ordered_print(bst_node* curr)
{
	if (curr == nullptr)
	{
		return;
	}
	
	if(curr->get_left() == nullptr)
	{
		std::cout << curr->get_string() << ": " << curr->get_count() << std::endl;
		if (curr->get_right() == nullptr)
		{
			return;
		}
		else
		{
			ordered_print(curr->get_right());
		}
	}
	else
	{
		ordered_print(curr->get_left());
		std::cout << curr->get_string() << ": " << curr->get_count() << std::endl;
		ordered_print(curr->get_right());
	}
	return;
}

bst_node* custom_bst::get_min(bst_node* curr)
{
	while (curr->get_left() != nullptr)
	{
		curr = curr->get_left();
	}
	return curr;
}

bst_node* custom_bst::get_root()
{
	return root.get();
}


void custom_bst::init_dictionary()
{
	dictionary = std::make_unique<custom_bst>();
}

void custom_bst::add_line_to_dict(std::string line)
{
	dictionary->insert(line);
}

void custom_bst::add_line_to_word_map(std::string line)
{
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	boost::char_separator<char> sep(DELIM);
	tokenizer tokens(line, sep);
	for (tokenizer::iterator beg = tokens.begin(); beg != tokens.end();++beg) {
		if (dictionary->search(*beg) == 0)
		{
			word_count_map[*beg]++;
		}

	}
}


bst_node* custom_bst::get_next(bst_node *curr)
{
	if (curr->get_right() != nullptr)
	{
		curr = curr->get_right();
		while (curr->get_left() != nullptr)
		{
			curr = curr->get_left();
		}
		return curr;
	}

	while (curr->get_parent() != nullptr)
	{
		if (curr->get_parent()->get_left() == curr)
		{
			return curr->get_parent();
		}
		curr = curr->get_parent();
	}
	return nullptr;
}


void custom_bst::send_word_count_to_file(std::ofstream &out_stream)
{
	std::map<std::string, unsigned>::iterator word_map_it;

	if (out_stream.good())
	{
		bst_node* curr = dictionary->root.get();

		while (curr)
		{
			word_map_it = word_count_map.find(curr->get_string());
			if (word_map_it != word_count_map.end())
			{
				out_stream << word_map_it->first << "," << word_map_it->second << "\n";
			}
			else
			{
				unsigned ed;
				unsigned min_ed = init_min_ed;
				std::vector<std::string> fuzzy_words;
				bst_node* curr_cmp = dictionary->root.get();
				while (curr_cmp)
				{
					ed = edit_distance(curr_cmp->get_string(), curr->get_string());
					if (ed < min_ed && ed != 0)
					{
						fuzzy_words.clear();
						min_ed = ed;
						fuzzy_words.push_back(curr_cmp->get_string());
					}
					else if (ed == min_ed)
					{
						fuzzy_words.push_back(curr_cmp->get_string());
					}
					curr_cmp = get_next(curr_cmp);
				}

				out_stream << curr->get_string() << " was not found in the dictionary. Similar words: ";
				for (auto fuzzy_it = fuzzy_words.begin(); fuzzy_it != fuzzy_words.end(); ++fuzzy_it)
				{
					if (std::next(fuzzy_it) == fuzzy_words.end())
					{
						out_stream << *fuzzy_it << "." << std::endl;
					}
					else
					{
						out_stream << *fuzzy_it << ", ";
					}
				}
			}
			curr = get_next(curr);
		}
	}
}