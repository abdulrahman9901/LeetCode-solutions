#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int matches = 0;
        map<char, int> s1Map;
        map<char, int> s2Map;

        if(s1.length() > s2.length())
            return false;
        // Fill s1Map with frequencies of characters in s1
        for (int i = 0; i < s1.length(); ++i) {
            s1Map[s1[i]] += 1;
            s2Map[s2[i]] += 1;
        }


        // Check initial matches
        for (char c = 'a'; c <= 'z'; c++) {
            if (s2Map[c] == s1Map[c])
                matches++;
        }

        int i = s1.length(), l = 0;

        while (i < s2.length()) {
            if (matches == 26)
                return true;

            // Add new character to the window
            s2Map[s2[i]] += 1;
            if (s2Map[s2[i]] == s1Map[s2[i]])
                matches += 1;
            else if (s2Map[s2[i]] - 1 == s1Map[s2[i]])
                matches -= 1;

            // Remove character from the window
            s2Map[s2[l]] -= 1;
            if (s2Map[s2[l]] == s1Map[s2[l]])
                matches += 1;
            else if (s2Map[s2[l]] + 1 == s1Map[s2[l]])
                matches -= 1;

            i++;
            l++;
        }

        return matches == 26;
    }
};


