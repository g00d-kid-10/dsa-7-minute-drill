int reverseBits(int n) {
    int ans = 0;
    for(int i = 31; i > -1; i--) {
        ans |= (n & 1) << i;
        n >>= 1;
    }
    return ans;
}