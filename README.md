Author: Hayden Warmington

Student Number: s3486075

This project is a demonstration of:

- Object oriented design
- Modern C++ programming
- Data structure use: `std::list`, `std::vector`, `std::set`, `std::map`
- Data structure implementation: binary search tree, singly linked list
- Edit distance

It will:

- read a text document and dictionary of word
- store the dictionary in the specified data structure
- store the text document words in an `std::map` with an associated count of the each word in the text document
- create a csv with the words in the dictionary
  - words that exist in the text document and their count will be sent to the output
  - each word that does not exist in the text document will be sent to the output along with a list of fuzzy words (dictionary words with lowest edit distance)




To compile: `make  `

To run: `./test_datastructures -s datastructure -d dictionary -t textfile (-o outputfile)`

where datastructure is: `list`, `set`, `vector`, `custom_list` or `custom_tree`



Library Dependencies:

- Boost
- C++14