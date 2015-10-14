class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* children[26];
    bool isKey;
    TrieNode() {
        for (int i=0;i<26;i++) children[i]=NULL;
        isKey=false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node=root;
        for (int i=0;i<word.size();i++){
            if (node->children[word[i]-'a']==NULL) node->children[word[i]-'a']= new TrieNode();
            node=node->children[word[i]-'a'];
        }
        
        node->isKey=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node=root;
        for (int i=0;i<word.size();i++){
            if (node==NULL) break;
            else node=node->children[word[i]-'a'];
        }
        
        if (node==NULL) return false;
        else return node->isKey;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for (int i=0;i<prefix.size();i++){
            if (node == NULL) break;
            else node=node->children[prefix[i]-'a'];
        }
        
        if (node==NULL) return false;
        else return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
