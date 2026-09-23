class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long total_product = 1;
        int zero_count = 0;

        // Step 1: Multiply all non-zero elements and count zeros
        for (int num : nums) {
            if (num == 0) {
                zero_count++;
            } else {
                total_product *= num;
            }
        }

        vector<int> result(nums.size());

        // Step 2: Build result based on zero cases
        for (int i = 0; i < nums.size(); i++) {
            if (zero_count > 1) {
                result[i] = 0;  // more than one zero → all outputs 0
            } else if (zero_count == 1) {
                // only one zero → only that index gets product, rest 0
                result[i] = (nums[i] == 0) ? total_product : 0;
            } else {
                // no zero → safe to divide
                result[i] = total_product / nums[i];
            }
        }

        return result;
    }
};
