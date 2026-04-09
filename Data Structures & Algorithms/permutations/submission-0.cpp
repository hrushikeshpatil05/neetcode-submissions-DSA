class Solution {
public:
    int n;
    void solve(int i,vector<vector<int>>& ans,vector<int>& nums) {
        if(i == n) {
            ans.push_back(nums);
            return;
        }

        for(int j=i;j<n;j++) {
            swap(nums[j],nums[i]);
            solve(i+1,ans,nums);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>ans;
        solve(0,ans,nums);
        return ans;
    }
};
