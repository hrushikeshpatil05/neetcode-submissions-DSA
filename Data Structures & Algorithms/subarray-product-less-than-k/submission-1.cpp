class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        if (k <= 1) return 0;

        int i = 0, j = 0;
        long long product = 1;
        int res = 0;
        while(j<n) {
            product = nums[j]*product;

            while(i<n && product >= k) {
                product = product/nums[i];
                i++;
            }

            res += (j-i+1);
            if(res < 0) res = 0;
            j++;
        }
        return res;
    }
};