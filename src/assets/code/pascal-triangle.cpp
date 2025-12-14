vector<vector<int>> pascal_triangle(int rows) {
    vector<vector<int>> ans;
    for(int row = 1; row <= rows; row++) {
        if(row == 1) {
            ans.push_back({1});
            continue;
        }
        
        vector<int> temp;
        vector<int> prev = ans.back();
        temp.push_back(1);
        for(int col = 1; col < prev.size(); col++) temp.push_back(prev[col - 1] + prev[col]);
        temp.push_back(1);

        ans.push_back(temp);
    }
    return ans;
}
