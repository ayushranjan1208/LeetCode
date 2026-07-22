class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long XOR = 0;
        for(int i = 0; i < n; i++) XOR ^= nums[i];

        long bit = (XOR & (XOR - 1)) ^ XOR;

        int a = 0, b = 0;

        for(int i = 0; i < n; i++){
            if(bit & nums[i]) a ^= nums[i];
            else b ^= nums[i];
        }

        return {a,b};
    }
};