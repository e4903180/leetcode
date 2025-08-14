# include <iostream>
# include <vector>
# include <string>
using namespace std;


class TrieNode {
public:
    bool isWord = false;
    vector<TrieNode*> children;
    TrieNode() {
        isWord = false;
        children = vector<TrieNode*>(26, nullptr);
    }
};


class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c: word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return dfsSearch(word, 0, root);
    }

    bool dfsSearch(string& word, int index, TrieNode* node) {
        if (!node) return false;
        if ((int)word.size() == index) return node->isWord;

        char c = word[index];
        if (c == '.') {
            for (TrieNode* child: node->children) {
                if (child && dfsSearch(word, index+1, child)) return true;
            }
            return false;
        }
        else {
            return dfsSearch(word, index+1, node->children[c - 'a']);
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

 
int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");

    cout << boolalpha;
    cout << "search(\"pad\") → " << wordDictionary.search("pad") << endl;
    cout << "search(\"bad\") → " << wordDictionary.search("bad") << endl;
    cout << "search(\".ad\") → " << wordDictionary.search(".ad") << endl;
    cout << "search(\"b..\") → " << wordDictionary.search("b..") << endl;

    return 0;
}
