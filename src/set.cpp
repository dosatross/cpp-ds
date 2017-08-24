/*
Author: Hayden Warmington
Student ID: s3486075
*/
#include "set.hpp"


void set::add_line_to_dict(std::string line)
{
	dictionary.insert(line);
}

void set::add_line_to_word_map(std::string line)
{
	boost::char_separator<char> sep(DELIM);
	tokenizer tokens(line, sep);
	for (tokenizer::iterator beg = tokens.begin(); beg != tokens.end();++beg) {
		auto search = dictionary.find(*beg);
		if (search != dictionary.end())
		{
			word_count_map[*beg]++;
		}
	}
}

void set::send_word_count_to_file(std::ofstream &out_stream)
{
	std::map<std::string, unsigned>::iterator word_map_it;

	if (out_stream.good())
	{
		for (auto dict_it = dictionary.begin(); dict_it != dictionary.end(); ++dict_it)
		{
			word_map_it = word_count_map.find(*dict_it);
			if (word_map_it != word_count_map.end())
			{
				out_stream << word_map_it->first << "," << word_map_it->second << "\n";
			}
			else
			{
				unsigned ed;
				unsigned min_ed = init_min_ed;
				std::vector<std::string> fuzzy_words;
				for (auto dict_it_cmp = dictionary.begin(); dict_it_cmp != dictionary.end(); ++dict_it_cmp)
				{
					ed = edit_distance(*dict_it_cmp, *dict_it);
					if (ed < min_ed && ed != 0)
					{
						fuzzy_words.clear();
						min_ed = ed;
						fuzzy_words.push_back(*dict_it_cmp);
					}
					else if (ed == min_ed)
					{
						fuzzy_words.push_back(*dict_it_cmp);
					}
				}

				out_stream << *dict_it << " was not found in the dictionary. Similar words: ";
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
		}
	}
}