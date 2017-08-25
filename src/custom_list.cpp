/*
Author: Hayden Warmington
Student ID: s3486075
*/
#include "custom_list.hpp"

custom_list::custom_list()
{
	length = 0;
	head = nullptr;
}

/*
inserts a string. returns 0 for success
*/
int custom_list::insert(std::string str)
{
	list_node* curr = head.get(); //pointer to head

	//increment count if string already exists
	while(curr)
	{
		if (curr->get_string().compare(str) == 0) //if string already exists
		{
			curr->incr_count();
			return 0;
		}
		curr = curr->get_next();
	}

	curr = head.get(); //reset curr to head

	//create new node to insert
	std::unique_ptr<list_node> new_node = std::make_unique<list_node>(str);
	new_node->incr_count();

	//insert new node
	if (head == nullptr) //if list empty
	{
		head = std::move(new_node); 
	}
	else
	{
		new_node->set_next(std::move(head)); 
		head = std::move(new_node);
	}
	length++; //increment length of list
	return 0;
}

/*
decrements count for data string str
deletes node if count is decremented to 0
returns 0 on success and -1 if string not found
*/
int custom_list::delete_one(std::string str)
{
	list_node* prev = nullptr;
	list_node* curr;

	if (head == nullptr) //if list is empty
	{
		return -1;
	}
	curr = head.get(); //set node pointer to head

	while (curr)
	{
		if (curr->get_string().compare(str) == 0) //string matched
		{
			curr->decr_count(); 
			if (curr->get_count() == 0) //if count decremented to 0
			{
				//delete node
				if (prev == nullptr) //if head
				{
					head = std::move(curr->get_next_ptr());
				}
				else
				{
					prev->set_next(std::move(curr->get_next_ptr()));
				}
				length--; //decrement length of list
			}
			return 0;
		}
		//get next node 
		prev = curr;
		curr = curr->get_next();
	}
	return -1; //string not found
}

/*
deletes the node that contains the data string str
return 0 on success and -1 if string not found
*/
int custom_list::delete_all(std::string str)
{
	list_node* prev = nullptr;
	list_node* curr;

	if (head == nullptr) //if list is empty
	{
		return -1;
	}
	curr = head.get(); //set node pointer to head

	while (curr)
	{
		if (curr->get_string().compare(str) == 0) //string matched
		{
			//delete node
			if (prev == nullptr) //if head
			{
				head = std::move(curr->get_next_ptr());
			}
			else
			{
				prev->set_next(std::move(curr->get_next_ptr()));
			}
			length--; //decrement length of list
			return 0;
		}
		//get next node
		prev = curr;
		curr = curr->get_next();
	}
	return -1; //string not found
}

/*
returns 0 if string found or -1 if string not found
*/
int custom_list::search(std::string str)
{
	list_node* curr;

	if (head == nullptr)
	{
		return -1; //string not found
	}
	curr = head.get();

	while (curr)
	{
		if (curr->get_string().compare(str) == 0)
		{
			return 0; //string found
		}
		curr = curr->get_next();
	}
	return -1; //string not found
}

/*
prints all data strings and their counts to std::out
format <string>: <count>
*/
void custom_list::print()
{
	list_node* curr;

	if (head == nullptr) //if list empty
	{
		return;
	}
	curr = head.get();

	while (curr)
	{
		std::cout << curr->get_string() << ": " << 
			curr->get_count() << std::endl;
		curr = curr->get_next();
	}
	return;
}

void custom_list::init_dictionary()
{
	dictionary = std::make_unique<custom_list>();
}

void custom_list::add_line_to_dict(std::string line)
{
	dictionary->insert(line);
}

/*
tokenises a string, adds it to the word count map and increments the count
*/
void custom_list::add_line_to_word_map(std::string line)
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

/*
sends all words in word count to file. format: <word>, <count>
if word is not in the dictionary, sends:
<word> was not found in the dictionary. Similar words: <csv list of fuzzy words>
*/
void custom_list::send_word_count_to_file(std::ofstream &out_stream)
{

	std::map<std::string, unsigned>::iterator word_map_it;

	if (out_stream.good())
	{
		list_node* curr = dictionary->head.get();

		while (curr)
		{
			word_map_it = word_count_map.find(curr->get_string());
			if (word_map_it != word_count_map.end())
			{
				out_stream << word_map_it->first << "," << 
					word_map_it->second << "\n";
			}
			else
			{
				unsigned ed;
				unsigned min_ed = init_min_ed;
				std::vector<std::string> fuzzy_words;
				list_node* curr_cmp = dictionary->head.get();
				while (curr_cmp)
				{
					ed = edit_distance(curr_cmp->get_string(), 
						curr->get_string());
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
					curr_cmp = curr_cmp->get_next();
				}

				out_stream << curr->get_string() << 
					" was not found in the dictionary. Similar words: ";
				for (auto fuzzy_it = fuzzy_words.begin(); 
					fuzzy_it != fuzzy_words.end(); ++fuzzy_it)
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
			curr = curr->get_next();
		}
	}
}