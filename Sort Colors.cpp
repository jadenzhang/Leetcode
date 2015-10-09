class Solution {
public:
    void sortColors(vector<int>& nums) {
    //second uses one pass
    int left=0,right=nums.size()-1;
    int cur=0;
    while( cur<=right){
        if (nums[cur]==1) cur++;
        else if (nums[cur]==0){
            swap(nums[cur++],nums[left++]);
        }
        else if (nums[cur]==2){
            swap(nums[cur],nums[right--]);
        }
    }
    }
};

        /*first solution uses two passes;
        int red=0,white=0,blue=0;
        for (int i=0;i<nums.size();i++){
            if(nums[i]==0) red++;
            if(nums[i]==1) white++;
            if(nums[i]==2) blue++;
        }
        
        for (int i=0;i<nums.size();i++){
            if(red){
                nums[i]=0;
                red--;
                continue;
                
            }
            if(white){
                nums[i]=1;
                white--;
                continue;
                
            }
            nums[i]=2;
        }
    }*/
   
