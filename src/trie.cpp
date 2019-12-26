#ifdef _DEBUG_MODE_
	#include <iostream>
#endif
#include <unordered_map>

struct Node {

		std::unordered_map<char, Node*> children;
		bool end_of_word = false;
};

class Trie {

	private:
		Node *root;

	public:
		Trie() {

			this->root = new Node();
		}
		Node* insert(std::string key) {

			Node* temp = this->root;
			for(char c : key) {

				if(temp->children.find(c) == temp->children.end())
					temp->children[c] = new Node();

				temp = temp->children[c];
			}
			temp->end_of_word = true;
			return temp;
		}
		Node* search(Node *root, std::string key, bool *res) {

			Node *temp = root;
			for(char c : key) {

				if(temp->children.find(c) == temp->children.end()) {

					*res = false;
					return nullptr;
				}
				temp = temp->children[c];
			}
			*res = (temp->end_of_word) ? true : false;
			return temp;
		}
		Node* search(std::string key) {

			bool res;
			return search(this->root, key, &res);
		}
		#ifdef _DEBUG_MODE_
			void display(Node *root, char *buffer, int idx) {

				if(root->end_of_word) {

					buffer[idx] = '\0';
					std::cout << buffer << std::endl;
				}
				for(auto i : root->children) {

					buffer[idx] = i.first;
					display(i.second, buffer, idx + 1);
				}
			}
			void display() {

				char buffer[32];
				display(this->root, buffer, 0);
			}
		#endif
};
