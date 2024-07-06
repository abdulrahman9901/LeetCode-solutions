// https://leetcode.com/problems/valid-tic-tac-toe-state

class Solution {
public:
    char str='x';
    bool rowfound=false;
    int ocount=0;
    int xcount=0;
    int drx=0,dry=0;
    bool validTicTacToe(vector<string>& board) {
        for(auto row:board){
            for(int i=0;i<row.size();++i){
                if(row[i]=='x'){
                    if(dry<3)
                        dry=0;
                    else if(!rowfound)
                        rowfound=true;
                    else
                        return false;
                    xcount++;
                    drx++;
                }
                else{
                    if(drx<3)
                        drx=0;
                     else if(!rowfound)
                        rowfound=true;
                    else
                        return false;
                    ocount++;
                    dry++;
                }
            }
          
        }
          if(xcount==0 ||xcount!=ocount)
                return false;
        return true;
    }
};