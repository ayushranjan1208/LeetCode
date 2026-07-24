class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());

        int msb = 32 -  __builtin_clz(maxi);

        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                mp[nums[i] ^ nums[j]] = 1; 
            }
        }
        int ans = 0;
        for(int i = 0; i < (1 << msb); i++){
            for(int j = 0; j < n; j++){
                if(mp.find(i ^ nums[j]) != mp.end()){
                    ans++;
                    break;
                }
            }
        }

        return ans;

    }
};