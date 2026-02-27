bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int power_of_two(int n) {
    if(!isPowerOfTwo) return -1;
    
    int ans = 0;
    while(n > 1) {
        n >>= 1;
        ans++;
    }
    return ans;
}