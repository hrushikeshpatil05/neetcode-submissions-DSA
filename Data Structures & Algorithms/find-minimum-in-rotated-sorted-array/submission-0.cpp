class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int low = 0, high = n-1;
        int res = min(nums[low], nums[high]);

        while(low <= high) {
            int mid = low + (high - low)/2;
            res = min(res,nums[mid]);
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return res;
    }
};
