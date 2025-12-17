// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:

// Input: nums = [1], target = 1
// Output: 1

int find_target_sum_ways(vector<int>& numsInput, int targetInput) {
    int n;
    int target;
    vector<int> nums;
    unordered_map<string, int> cache;

    nums = numsInput;
    target = targetInput;
    n = nums.size();

    function<int(int,int)> dfs = [&](int i, int sum) -> int {
        if (i == n) {
            if (sum == target) return 1;
            return 0;
        }

        string key = to_string(i) + "+" + to_string(sum);
        if (cache.count(key)) return cache[key];

        return cache[key] = dfs(i + 1, sum + nums[i]) + dfs(i + 1, sum - nums[i]);
    };

    return dfs(0, 0);
}
