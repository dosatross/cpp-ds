/*
Author: Hayden Warmington
Student ID: s3486075
*/
#include "datastructure.hpp"


unsigned datastructure::edit_distance(std::string str1, std::string str2)
{//two words that are the same edit distance? use a heap grab the ones that float to the top all the ones with the min value
	std::vector<std::vector<unsigned>> dist_table;
	unsigned str1_len = str1.length();
	unsigned str2_len = str2.length();

	dist_table.resize(str1_len + 1);
	for (unsigned i = 0; i < str1_len + 1; ++i)
	{
		dist_table[i].resize(str2_len + 1);
	}

	for (unsigned i = 0; i <= str1_len; i++)
	{
		for (unsigned j = 0; j <= str2_len; j++)
		{
			if (i == 0)
			{
				dist_table[i][j] = j;
			}
			else if (j == 0)
			{
				dist_table[i][j] = i;
			}
			else if (str1.at(i - 1) == str2.at(j - 1))
			{
				dist_table[i][j] = dist_table[i - 1][j - 1];
			}
			else
			{
				dist_table[i][j] = 1 + std::min(std::min(dist_table[i][j - 1], dist_table[i - 1][j]), dist_table[i - 1][j - 1]);
			}
		}
	}
	return dist_table[str1_len][str2_len];
}
