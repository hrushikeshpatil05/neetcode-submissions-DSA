class Solution {
public:

    int atMost(vector<int>& nums,int k) {
        int n = nums.size();
        unordered_map<int,int>mp;

        int i=0,j=0;
        int ans = 0;

        while(j<n) {
            if(mp[nums[j]] == 0) k--;

            mp[nums[j]]++;

            while(k < 0) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    k++;
                }
                i++;
            }

            ans += (j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};