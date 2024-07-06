// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i

char tmp;
#define SWAP(a,b)  tmp=a,a=b,b=tmp
bool canBeEqual(char* s1, char* s2){
    SWAP(s1[0],s1[2]);
    if(strcmp(s1,s2) == 0)
        return true;
    SWAP(s1[1],s1[3]);
    if(strcmp(s1,s2) == 0)
        return true;
    SWAP(s1[0],s1[2]);
    if(strcmp(s1,s2) == 0)
        return true;
    printf("%s ",s1);
    return false;
}