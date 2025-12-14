void merge_sorted_array(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(m == 0) {
        nums1 = nums2;
        return;
    }
    
    int i = m - 1, j = n - 1;
    while(i > -1 && j > -1) {
        if(nums1[i] > nums2[j]) {
            nums1[i + j + 1] = nums1[i--];
        } else {
            nums1[i + j + 1] = nums2[j--];
        }
    }

    while(j > -1) {
        nums1[j] = nums2[j];
        j--;
    }
}
