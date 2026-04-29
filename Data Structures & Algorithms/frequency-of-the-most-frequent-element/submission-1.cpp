class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int i=0,j=0;
        int n = nums.size();
        long long currSum = 0;
        int res = 0;
        while(j<n) {
            currSum += nums[j];

            while(i<j && (long long)(nums[j]*(j-i+1)) > currSum + k) {
                currSum -= nums[i];
                i++;
            }

            res = max(res,j-i+1);
            j++;
        }

        return res;
    }
};