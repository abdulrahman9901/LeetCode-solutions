class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        map<int,pair<int,int>> masks = {
            {16,{0xffff0000,0x0000ffff}},
            {8,{0xff00ff00,0x00ff00ff}},
            {4,{0xf0f0f0f0,0x0f0f0f0f}},
            {2,{0xcccccccc,0x33333333}},
            {1,{0xaaaaaaaa,0x55555555}},        
        };
        for(auto mask:masks)
            n = (n&mask.second.first) >> mask.first | (n&mask.second.second) << mask.first;

        return n;
    }
};