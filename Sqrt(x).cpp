class Solution {
public:
    int mySqrt(int x) {
        long long i=0;
        long long j=x/2+1;
        while (i<=j){
            long long mid = (i+j)/2;
            long long sqrt = mid*mid;
            if(sqrt==x) return mid;
            else if(sqrt<x) i=mid+1;
            else j=mid-1;
        }
        
        return j;
    }
};
