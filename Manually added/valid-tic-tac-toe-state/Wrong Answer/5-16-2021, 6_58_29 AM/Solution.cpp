// https://leetcode.com/problems/valid-tic-tac-toe-state

class Solution {
public:
    bool rowfound=false;
    int ocount=0;
    int xcount=0;
    int drx=0,dry=0,arrx[3]={0,0,0},arry[3]={0,0,0};
    bool validTicTacToe(vector<string>& board) {
        for(auto row:board){
            for(int i=0;i<row.size();++i){
                if(row[i]=='X'){
                    if(dry<3)
                        dry=0;
                    else if(!rowfound)
                        rowfound=true;
                    else
                        return false;
                    arrx[i]++;
                    xcount++;
                    drx++;
                }
                else if(row[i]=='O'){
                    if(drx<3)
                        drx=0;
                     else if(!rowfound)
                        rowfound=true;
                    else
                        return false;
                    ocount++;
                    arry[i]++;
                    dry++;
                }
            }
          
        }
          if(xcount==0 ||xcount-ocount >1 ||ocount-xcount >1)
                return false;
        int three=0;
            for(int i=0;i<3;++i)
                if(arrx[i]==3 ||arry[i]==3)
                    three++;
        if(three > 1)
            return false; 
            
        return true;
    }
};