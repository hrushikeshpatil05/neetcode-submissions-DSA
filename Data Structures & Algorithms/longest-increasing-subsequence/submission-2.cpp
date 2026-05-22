class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>lis;

        for(int i=0;i<n;i++) {

            if(lis.size() == 0 || lis.back() < nums[i]) {
                lis.push_back(nums[i]);
            }
            else {
                int left = 0, right = lis.size()-1;

                while(left <= right) {
                    int mid = left + (right-left)/2;
                    if(lis[mid] == nums[i]) {
                        left = mid;
                        break;
                    }
                    else if(lis[mid] > nums[i]) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                lis[left] = nums[i];
            }
        }
        return lis.size();
    }
};
