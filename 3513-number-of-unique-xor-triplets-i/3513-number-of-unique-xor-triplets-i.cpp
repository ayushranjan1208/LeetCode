class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int lz = __builtin_clz(n);
        int msb = 31 - lz;
        msb++;
        return 1 << msb;
    }
};