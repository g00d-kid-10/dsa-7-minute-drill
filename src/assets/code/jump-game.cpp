// Keep track of farthest reach for each i
// Keep track of a leader (initially = 0)
// when i touches the leader, new leader is elected
// new leader is based on the farthest reach which was being tracked so far prior to that leader

// Final Intiuition: If we take jump from any cell between two leader snapshots it's same thing, we are saving computation considering that they we'll all result the same. (That is the reason for time complexity: O(n)) 

// Both question can be done with recursion-DP

bool canJump(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return true;
    
    int farthest = 0, leader = 0, ans = false;
    // int jumps = 0; II
    for(int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if(i == leader) {
            leader = farthest;
            // II
            // jumps++;
            
            // I
            if(leader == 0) {
                break;
            }
            if(leader >= n - 1) {
                ans = true;
                break;
            }
        }
    }

    return ans;
}