class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        char table[16] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
        int tem=0xF;
        uint32_t result=0;
        for (int i=1;i<=8;i++){
            result=result<<4;
            int current=0;
            current = tem&n;
            n=n>>4;
            result |= table[current];
        }
        
        return result;
    }
};
