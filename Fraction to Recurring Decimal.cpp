class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 1) return to_string(numerator);
        if (denominator == -1) return to_string((long long)numerator*(-1));
        string ret;
        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)) ret="-";
        long long num_tem = abs((long long)numerator), de_tem = abs((long long)denominator);
        long long ints = abs(num_tem/de_tem), fractional = abs(num_tem % de_tem);
        unordered_map<int,int> table;
        int index = 0;
        ret.append(to_string(ints));
        if (fractional != 0){
            ret.append(".");
            index = ret.size();
            while (table.find(fractional) == table.end()){
                table[fractional] = index++;
                ret.append(to_string(fractional*10/de_tem));
                fractional = fractional*10%de_tem;
                if (fractional == 0) break;
            }
            
            if (fractional!=0)
            {
                ret.insert(ret.begin()+table[fractional],'(');
                ret.append(")");
                return ret;
            }
        }
        
        return ret;
    }
};
