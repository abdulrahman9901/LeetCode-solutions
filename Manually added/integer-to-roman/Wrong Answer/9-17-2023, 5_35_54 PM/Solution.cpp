// https://leetcode.com/problems/integer-to-roman

class Solution {
public:
std::string repeatString(const std::string& s, size_t count) {
    std::string result;
    for (size_t i = 0; i < count; i++) {
        result += s;
    }
    return result;
}

    string intToRoman(int num) {
        string res = "";
        size_t temp = num / 1000;
        num =num % 1000;
        if ( temp != 0) {
            res += repeatString("M" , temp);
        }
        temp = num / 100;
        num =num % 100;
        if (temp != 0) {
            if(temp < 4)
                res += repeatString("C" , temp);
            else if (temp == 4)
                res +=  "CD";
            else if (temp < 9)
                res += "D" + repeatString("C" , temp-5);
            else if (temp == 9)
                res += "CM";
        }
        temp = num / 10;
        num =num % 10;
        if (temp != 0) {
            if(temp < 4)
                res += repeatString("X" , temp);
            else if (temp == 4)
                res +=  "XL";
            else if (temp < 9)
                res += "L" + repeatString("C" , temp-5);
            else if (temp == 9)
                res += "XC";
        }
        temp = num ;
        if (temp != 0) {
            if(temp < 4)
                res += repeatString("I" , temp);
            else if (temp == 4)
                res += "IV";
            else if (temp < 9)
                res += "V" + repeatString("I" , temp-5);
            else if (temp == 9)
                res += "IX";
        }
        return res ;
    }
};