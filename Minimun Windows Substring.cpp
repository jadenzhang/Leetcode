class Solution {
public:
    string minWindow(string s, string t) {
        int slen=s.size(), tlen=t.size();
        vector<int> ElementInT(256,0);
        vector<int> CountInS(256,0);
        for (int i=0;i<tlen;i++){
            ElementInT[t[i]]++;
        }
        int found=0;
        int winStart=-1,winEnd=slen;
        for (int i=0,start=0;i<slen;i++){
            if (ElementInT[s[i]] !=0){
                CountInS[s[i]]++;
                if (CountInS[s[i]]<=ElementInT[s[i]]) found++;
                if (found==tlen){
                    while(ElementInT[s[start]]==0 || CountInS[s[start]]>ElementInT[s[start]]){
                        if (ElementInT[s[start]] !=0) CountInS[s[start]]--;
                        start++;
                    }
                    
                    if (winEnd-winStart > i-start){
                        winEnd=i;
                        winStart=start;
                    }
                    
                    CountInS[s[start]]--;
                    found--;
                    start++;
                }
            }
        }
        
        return winStart==-1 ? "":s.substr(winStart, winEnd-winStart+1);
    }
};
