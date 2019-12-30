/*____________________________________________________________________________________

	Contact Management System
	trie.h - Header file for Trie data structure class.

	- Akshay Mohan



	MIT License

	Copyright (c) 2019 Akshay Mohan

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
____________________________________________________________________________________*/

#ifndef __TRIE_INCLUDED_
#define __TRIE_INCLUDED_

#include <map>
#ifdef _TRIE_DEBUG_MODE_
	#include <iostream>
#endif

struct Node {

	std::map<char, Node*> children;
	bool end_of_word = false;
};

class Trie {

	private:
		Node *root;

	public:
		Trie();
		
		Node* insert(std::string key);
		Node* search(Node *root, std::string key, bool *result);
		Node* search(std::string key, bool *result);
		bool exists(std::string key);
		bool remove(Node *root, char *key);
		bool remove(char *key);
		#ifdef _TRIE_DEBUG_MODE_
			void display(Node *root, char *buffer, unsigned int idx);
			void display();
		#endif
};
#endif
