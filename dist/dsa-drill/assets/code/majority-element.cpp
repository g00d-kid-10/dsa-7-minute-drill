int majority_element(vector<int>& nums) {
    int votes = 0, ans = 0;
    for(int num : nums) {
        if(votes == 0) {
            ans = num;
        }
        ans == num ? votes++ : votes--;
    }
    return ans;
}