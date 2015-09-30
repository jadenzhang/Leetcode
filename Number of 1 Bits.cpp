class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t test=0x0001;
        int count=0;
        while (n){
            if(test&n) count++;
            n=n>>1;
        }
        return count;
    }
};
