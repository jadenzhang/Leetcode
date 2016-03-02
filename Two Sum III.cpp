class TwoSum {
public:
    unordered_multiset<int> s;
    // Add the number to an internal data structure.
	void add(int number) {
	    s.insert(number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto num:s){
	        if (num*2==value){
	            if (s.count(num)>=2) return true;
	        }
	        else if (s.count(value-num)) return true;
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
