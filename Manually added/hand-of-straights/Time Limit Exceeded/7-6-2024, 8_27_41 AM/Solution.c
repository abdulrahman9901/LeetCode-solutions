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
            int x = i;
            while(x <= handSize){
                if(x >= handSize)
                    return false;
                if(prev + 1 == hand[x]){
                    printf("prev = %d , x=%d , i=%d, SWAP(%d,%d)\n",prev,x,i,hand[i],hand[x]);
                    prev = hand[x];
                    hand[x] = hand[i];
                    hand[i] = prev;
                    if(i + 1 < handSize )
                        qsort(hand+i+1,handSize-i-1,sizeof(int),compare);
                    break;
                }
                x++;
            }
        }
        i++;
    }
    return true;
}