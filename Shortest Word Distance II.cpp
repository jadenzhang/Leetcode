class WordDistance {
public:
    unordered_map<string, vector<int>> dic;
    WordDistance(vector<string>& words) {
        for (int i=0;i<words.size();i++){
            dic[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int dis = INT_MAX;
        int len1 = dic[word1].size(),len2 = dic[word2].size();
        int i=0,j=0;
        while (i<len1 && j<len2){
            dis = min(dis,abs(dic[word1][i]-dic[word2][j]));
            if (dic[word1][i]>dic[word2][j]) j++;
            else i++;
        }
        
        return dis;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
