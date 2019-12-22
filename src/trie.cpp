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
		Node* search(std::string key) {

			Node *temp = this->root;
			for(char c : key) {

				if(temp->children.find(c) == temp->children.end())
					return nullptr;
				temp = temp->children[c];
			}
			return (temp->end_of_word) ? temp : nullptr;
		}
};
