int second_max_element(vector<int>& nums) {
    int first = INT_MIN, second = INT_MIN;
    for(int num : nums) {
        if(num > first) {
            second = first;
            first = num;
        } else if(num > second && num != first) {
            second = num;
        }
    }

    return second != INT_MIN ? second : -1;
}