class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0;i<16;i++){
            result = result|((n&(1<<i))<<(31-i*2));
        }
        for(int i = 16;i<32;i++){
            result = result|((n&(1<<i))>>(i*2-31));
        }
        return result;
    }
};