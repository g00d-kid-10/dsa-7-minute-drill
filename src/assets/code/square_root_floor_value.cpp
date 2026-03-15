int square_root_floor_value(int num) {
    if(num <= 1) return num;
    int l = 0, r = num, ans = -1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(m <= num / m) { // Instead of m * m; Please don't forget this division overflow prevention trick. Please! Please! Please!
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}