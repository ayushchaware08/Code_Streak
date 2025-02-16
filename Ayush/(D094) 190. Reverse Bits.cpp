// O(1) O(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse =0;
        for(int i=0; i<31; i++){
            // process curr least significant bit;
            reverse = (n%2)+reverse<<1;
            // shift right to process next bit
            n>>=1;
        }
        return reverse+n%2;
    }
};