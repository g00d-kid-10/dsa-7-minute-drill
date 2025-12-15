vector<int> majority_element_II(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    int ans1 = INT_MIN, ans2 = INT_MIN, votes1 = 0, votes2 = 0;
    for(int num : nums) {
        if(ans1 == num) {
            votes1++;
        } else if(ans2 == num) {
            votes2++;
        } else if(votes1 == 0) {
            ans1 = num; votes1 = 1;
        } else if(votes2 == 0) {
            ans2 = num; votes2 = 1;
        } else {
            votes1--, votes2--;
        }
    }

    int c1 = count(nums.begin(), nums.end(), ans1);
    int c2 = count(nums.begin(), nums.end(), ans2);

    if(c1 > n / 3) ans.push_back(ans1);
    if(c2 > n / 3) ans.push_back(ans1);
    return ans;
}