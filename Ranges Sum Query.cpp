class NumArray {
public:
    vector<int> SumRange;
    NumArray(vector<int> &nums) {
        int sum = 0;
        SumRange.push_back(sum);
        for (auto num:nums){
            sum+=num;
            SumRange.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return SumRange[j+1]-SumRange[i];
    }
};
