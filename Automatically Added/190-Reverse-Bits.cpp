class Solution {
    string to_bin(uint32_t n){
        string bin = "";
        while(n){
            if(n%2 == 1)
                bin+="1";
            else
                bin+="0";
            n /=2;
        }
        while(bin.size() < 32)
            bin+="0";
        return bin;
    }
public:
    uint32_t reverseBits(uint32_t n) {
        return stoll(to_bin(n), nullptr, 2);
    }
};