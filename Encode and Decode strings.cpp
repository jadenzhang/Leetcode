class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto a:strs){
            res += to_string(a.size())+'$'+a;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int index=0,pos,size;
        while (index<s.size()){
            pos = s.find('$',index);
            size = stoi(s.substr(index,pos-index));
            res.push_back(s.substr(pos+1,size));
            index = pos + size + 1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
