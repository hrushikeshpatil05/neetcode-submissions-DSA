class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>subSets;
        
        for(int i=0;i<(1<<n);i++) {
            vector<int>curr;
            for(int j=0;j<n;j++) {
                if((i>>j) & 1) {
                    curr.push_back(nums[j]);
                }
            }
            subSets.push_back(curr);
        }

        return subSets;

    }
};
