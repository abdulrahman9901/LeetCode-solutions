#define MAX_SIZE 1000

int compare (const void * a ,const void * b){
    return *((int*)a) - *((int*)b);
}
bool uniqueOccurrences(int* arr, int arrSize) {
    int Freq[MAX_SIZE]={0} , prev = arr[0] , freqidx=0;
    qsort(arr,arrSize,sizeof(int),compare);
    for(int i = 0 ; i < arrSize ; ++i){
       if(arr[i] != prev){
            freqidx++;   
            prev = arr[i];       
        }
        Freq[freqidx]++;
    }
    qsort(Freq,freqidx+1,sizeof(int),compare);
    for(int i = 1 ; i <= freqidx ; ++i){
        if(Freq[i] == Freq[i-1])
            return false;
    }
    return true;
}