class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];

        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) mp[nums[i]]++;

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1] + 1){
                sum += nums[i];
            }
            else break;
        }
        while(mp.count(sum)){
            sum++;
        } 
        return sum;
    }
};