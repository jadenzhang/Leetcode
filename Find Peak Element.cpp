
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int l = 0, r = num.size() - 1;
        int mid = 0;

        while(l < r)
        {
            mid = l + (r-l)/2;

            if(mid - 1 > -1 && num[mid] < num[mid - 1])
            {
                r = mid - 1;
            }
            else if(mid + 1 < num.size() && num[mid] < num[mid + 1])
            {
                l = mid + 1;
            }
            else
                return mid;
        }

        return l;
    }
};
