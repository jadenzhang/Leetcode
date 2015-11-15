class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto a:dictionary){
            string key = a.size()<=2? a:a.front()+to_string(a.size()-2)+a.back();
            dic[key].insert(a);
        }
    }

    bool isUnique(string word) {
        string key = word.size()<=2? word:word.front()+to_string(word.size()-2)+word.back();
        return dic[key].count(word) == dic[key].size();
    }
private:
    unordered_map<string, unordered_set<string>> dic;
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
