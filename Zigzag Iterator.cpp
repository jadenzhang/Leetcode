class ZigzagIterator {
public:
    vector<int>::iterator b[2],e[2];
    int cur;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        b[0]=v1.begin();
        e[0]=v1.end();
        b[1]=v2.begin();
        e[1]=v2.end();
        cur = 0;
    }

    int next() {
        int ret;
        if (b[0]==e[0]) ret = *b[1]++;
        else if (b[1]==e[1]) ret = *b[0]++;
        else{
            ret = *b[cur]++;
            cur = cur==0? 1:0;
        }
        return ret;
    }

    bool hasNext() {
        return b[0]!=e[0] || b[1]!=e[1];
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
 
/*class ZigzagIterator {
public:
    bool t[2];
    int cur;
    int index1,index2;
    vector<int> temp1;
    vector<int> temp2;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        temp1 = v1;
        temp2 = v2;
        index1 = 0;
        index2 = 0;
        t[0] = v1.size()==0? false:true;
        t[1] = v2.size()==0? false:true;
        if (t[0]==true) cur = 0;
        else cur = 1;
    }

    int next() {
        int ret;
        if (cur == 0){
            ret = temp1[index1];
            index1++;
            if (index1>=temp1.size()) t[0]=false;
            cur = 1;
        }
        else{
            ret = temp2[index2];
            index2++;
            if (index2>=temp2.size()) t[1]=false;
            cur = 0;
        }
        return ret;
    }

    bool hasNext() {
        if (t[cur]) return true;
        else{
            cur =  cur==1? 0:1;
            if (t[cur]) return true;
            else return false;
        }
    }
};*/
