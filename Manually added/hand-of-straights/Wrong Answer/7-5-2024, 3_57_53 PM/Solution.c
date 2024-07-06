// https://leetcode.com/problems/hand-of-straights

bool isNStraightHand(int* hand, int handSize, int groupSize) {
    if(handSize % groupSize == 0)
        return true;
    else 
        return false;
}