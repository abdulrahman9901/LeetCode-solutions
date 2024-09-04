class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         int n = hand.size();
        
        if (n % groupSize != 0) return false;

        map<int, int> cardCount;
        for (int card : hand) {
            cardCount[card]++;
        }
        int stCount;
        for (auto &[card,count] : cardCount) {
            while (count > 0) {
                stCount = count;
                for (int i = 0; i < groupSize; ++i) {
                    if (cardCount[card + i] < stCount) return false;
                    cardCount[card + i] -= stCount;
                }
            }
        }    
    return true;
    }
};