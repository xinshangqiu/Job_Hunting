#include <iostream>
#include <string>
#include <vector>
using namespace std;
constexpr auto ALPHABET_SIZE = 26;

struct TNode
{
    vector<TNode*> child;
    bool isEnd;
    TNode() {
        this->isEnd = false;
        this->child = vector<TNode*>(ALPHABET_SIZE, nullptr);
    }
};


void insertTire(TNode* root,const string& word) {
    TNode* node = root;
    for (auto itemWord : word) {
        if (node->child.at(itemWord - 'a') == nullptr) {
            node->child.at(itemWord - 'a') = new TNode();
        }
        node = node->child.at(itemWord - 'a');
    }
    node->isEnd = true;
}


class WordDictionary {
private:
    TNode* root;
public:
    WordDictionary() {
        root = new TNode();
    }

    void addWord(string word) {
        insertTire(root, word);
    }

    bool search(string word) {
        return dfsSearch(root, 0, word);
    }

    bool dfsSearch(TNode* node, int index, const string& word) {


        if (index == word.size()) {
            return node->isEnd;
        }

        char c = word.at(index);
        if (c >= 'a' && c <= 'z') {
            if (node->child.at(c - 'a') != nullptr) {
                return dfsSearch(node->child.at(c - 'a'), index + 1, word);
            }
        }
        else if (c == '.') {
            for (int j = 0; j < ALPHABET_SIZE; j++) {
                if (node->child.at(j) != nullptr) {
                    TNode* child = node->child.at(j);
                    if(child != nullptr && dfsSearch(child, index + 1, word)){
                        return true;
                    }
                    //return dfsSearch(child, index + 1, word);
                }
            }
        }
        return false;


    }
};
int main()
{
    WordDictionary wd;
    wd.addWord("at");
    wd.addWord("and");
    wd.addWord("an");
    wd.addWord("add");
    cout << wd.search("a") << endl;
    cout << wd.search(".at") << endl;
    wd.addWord("bat");
    cout << wd.search(".at") << endl;
    return 0;
}

