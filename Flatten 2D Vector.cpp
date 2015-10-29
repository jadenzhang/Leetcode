class Vector2D {
public:
    int row,col;
    vector<vector<int>> res;
    Vector2D(vector<vector<int>>& vec2d) {
        row=0;
        col=0;
        res = vec2d;
    }

    int next() {
        int ret = res[row][col];
        if (col == res[row].size()-1){
            col=0;
            row++;
        }
        else col++;
        return ret;
    }

    bool hasNext() {
        if (row == res.size()) return false;
        while (!res[row].size()) {
            row++;
            if (row == res.size()) return false;
            col=0;
        }
        if (row == res.size()-1 && col >= res[row].size()) return false;
        else return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
