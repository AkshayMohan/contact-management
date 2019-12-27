/*____________________________________________________________________________________

	Contact Management System
	main_test.cpp - Testing file, mostly for debug.

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



	g++: g++ -D _TRIE_DEBUG_MODE_ -o main_test.exe main_test.cpp trie.cpp

____________________________________________________________________________________*/

#include <iostream>
#include <string>
#include <cstring>
#ifndef _TRIE_DEBUG_MODE_
	#define _TRIE_DEBUG_MODE_
#endif
#include "trie.h"


std::string contact_names[] = {

	"A",
	"Alex",
	"Alexa",
	"Alexander",
	"Kate",
	"Katie",
	"Than",
	"Thanos",
	"ParK",
	"ParK_iY",
	"Firstname Lastname",
	"Firstname"
};

int main() {

	Trie contacts;
	std::string name;
	Node *temp;
	bool result;
	char buffer[32];

	for(const std::string &str : contact_names)
		contacts.insert(str);

	std::cout << "Listing contacts : " << std::endl;
	contacts.display();

	while(true) {

		std::cout << "Enter a name phrase : ";
		std::cin >> name;
		std::cout << std::endl;
		if((temp = contacts.search(name, &result)) != nullptr) { //temp is now the point up to the searched phrase, if successful.

			if(result)
				std::cout << "Found!" << std::endl;
			
			strcpy_s(buffer, name.c_str()); //search phrase has to be printed along with the contents of buffer from display functions.
			contacts.display(temp, buffer, name.length());
		} else {

			std::cout << "Given phrase not found!" << std::endl;
		}
	}
	return 0;
}
