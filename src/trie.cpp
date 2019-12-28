/*____________________________________________________________________________________

	Contact Management System
	trie.cpp - Trie data structure class definition file.

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

#include "trie.h"

Trie::Trie() {

	this->root = new Node();
}

Node* Trie::insert(std::string key) {

	Node *temp = this->root;
	for(auto c : key) {

		if(temp->children.find(c) == temp->children.end())
			temp->children[c] = new Node();
		
		temp = temp->children[c];
	}
	temp->end_of_word = true;
	return temp;
}

Node* Trie::search(Node *root, std::string key, bool *result) {

	for(auto c : key) {

		if(root->children.find(c) == root->children.end()) {

			*result = false;
			return nullptr;
		}
		root = root->children[c];
	}
	*result = (root->end_of_word) ? true : false;
	return root;
}

Node* Trie::search(std::string key, bool *result) {

	return search(this->root, key, result);
}

bool Trie::exists(std::string key) {

	bool result;
	search(this->root, key, &result);
	return result;
}

#ifdef _TRIE_DEBUG_MODE_
	void Trie::display(Node *root, char *buffer, unsigned int idx) {

		if(root->end_of_word) {

			buffer[idx] = '\0';
			std::cout << buffer << std::endl;
		}
		for(auto i : root->children) {

			buffer[idx] = i.first;
			display(i.second, buffer, idx + 1);
		}
	}
	void Trie::display() {

		char buffer[32];
		display(this->root, buffer, 0);
	}
#endif
