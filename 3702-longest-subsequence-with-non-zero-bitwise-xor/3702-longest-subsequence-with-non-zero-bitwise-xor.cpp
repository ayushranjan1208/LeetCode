class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int XOR = 0;
        int c0 = 0;
        for(auto &e : nums){
            XOR ^= e;
            if(e == 0) c0++;
        }
        int n = nums.size();
        if(c0 == n) return 0;
        if(XOR == 0) return n - 1;
        return n;
    }
};