string longestPalindrome(string s) {
    int n = s.size();
    int start = 0, max_len = 0;
    auto spread = [&](int i, int j) -> void {
        while(i > -1 && j < n && s[i] == s[j]) {
            int len = j - i + 1;
            if(len > max_len) {
                max_len = len;
                start = i;
            }
            i--, j++;
        }
    };

    for(int i = 0; i < n; i++) {
        spread(i, i);
        spread(i, i + 1);
    }

    return s.substr(start, max_len);
}