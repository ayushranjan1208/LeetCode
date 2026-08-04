class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        // TIME - O(N) SPACE - O(N)
        // int n = nums.size();

        // int mx = -1, mn = 101;

        // for(auto e : nums){
        //     mx = max(mx,e);
        //     mn = min(mn,e);
        // }

        // vector<int> fre(mx - mn + 1);

        // for(auto e : nums){
        //     fre[e - mn] ++;
        // }

        // vector<int> ans;

        // for(int i = 0; i < fre.size(); i++){
        //     if(fre[i] == 0) ans.push_back(i + mn);
        // }

        // TIME - O(NLOGN) SPACE - O(1)

        int n = nums.size();

        sort(nums.begin(),nums.end());

        int mn = nums[0];

        vector<int> ans;
        for(int i = 0; i < n; i++,mn++){
            if(nums[i] > mn){
                ans.push_back(mn);
                i--;
            }
        }
        return ans;
    }
};