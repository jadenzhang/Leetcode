class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        maxH.push(num);
        int t = maxH.top();
        maxH.pop();
        minH.push(t);
        if (minH.size() - maxH.size()>1){
            t = minH.top();
            minH.pop();
            maxH.push(t);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int n = maxH.size(), m = minH.size();
        if (!n && !m) return 0.0;
        if (n==m) return double(minH.top()+maxH.top())/2;
        else return n>m? maxH.top():minH.top();
    }
private:
    priority_queue<int,vector<int>> maxH;
    priority_queue<int,vector<int>,greater<int>> minH;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
