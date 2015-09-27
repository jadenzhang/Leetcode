class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        
        vector<int> result(1, 1);
        for(int i = 1; i<= rowIndex; i++)
        {
            int colCount = i+1;
            result.resize(colCount);
            
            for(int j = i; j>0; j--)
            {
                result[j] = result[j-1] + result[j];
            }
        }
        
        return result;
    }
};
