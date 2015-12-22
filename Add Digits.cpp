class Solution {
public:
    int addDigits(int num) {
        while (num/10){
            int sum = 0;
            int temp = num;
            while (temp/10){
                sum += temp%10;
                temp /= 10;
            }
            sum +=temp;
            num = sum;
        }
        return num;
    }
};
