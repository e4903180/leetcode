# include <iostream>
using namespace std;


class TrieNode {
public:
    TrieNode* children[26];
    bool isend = false;

    TrieNode() {
        isend = false;
        for (int i=0; i<26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c: word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode;
            }
            node = node->children[index];
        }
        node->isend = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c: word) {
            int index = c - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return node->isend;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c: prefix) {
            int index = c - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // 輸出 1 (true)
    cout << trie.search("app") << endl;     // 輸出 0 (false)
    cout << trie.startsWith("app") << endl; // 輸出 1 (true)
    trie.insert("app");
    cout << trie.search("app") << endl;     // 輸出 1 (true)
}