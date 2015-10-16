class WordDictionary {
public:
    class TrieNode{
        public:
            TrieNode* children[26];
            bool isKey;
            TrieNode(){
                isKey=false;
                for (int i=0;i<26;i++) children[i]=NULL;
            }
    };
    
    WordDictionary(){
        root=new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* tem=root;
        for (int i=0;i<word.size();i++){
            if (tem->children[word[i]-'a']==NULL){
                tem->children[word[i]-'a']=new TrieNode();
                tem = tem->children[word[i]-'a'];
            }
            
            else tem = tem->children[word[i]-'a'];
        }
        tem->isKey=true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return tool(root,0,word);
    }
    
    bool tool(TrieNode* root, int n, string word){
        if (word.size()==n) return root->isKey;
        if (word[n]=='.'){
            for (int i=0;i<26;i++){
                if ((root->children[i] != NULL)&&tool(root->children[i],n+1,word)) return true;
            }
            return false;
        }
        else{
            if (root->children[word[n]-'a']!=NULL) return tool(root->children[word[n]-'a'],n+1,word);
            else return false;
        }
        
    }
    
private:
    TrieNode* root;
    
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
