// https://leetcode.com/problems/hand-of-straights

int compare (const void * a ,const void * b){
    return *((int*)a) - *((int*)b);
}

bool isNStraightHand(int* hand, int handSize, int groupSize) {
    qsort(hand,handSize,sizeof(int),compare);
    int i = 0 , prev;
    if(handSize % groupSize != 0 )
            return false;

    while(i<handSize){
        if(i%groupSize == 0){
            prev = hand[i];
        }else{
            if(prev + 1 < hand[i])
                return false;
            prev = hand[i];
        }
        i++;
    }
    return true;
}