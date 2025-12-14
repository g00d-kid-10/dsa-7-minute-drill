int find_number_which_appears_once_others_are_twice(vector<int>& nums) {
    int ans = 0;
    for(int num : nums) {
        ans ^= num;
    }
    return ans;
}