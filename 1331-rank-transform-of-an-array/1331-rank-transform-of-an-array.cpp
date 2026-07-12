class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; i++){
            v[i] = {arr[i],i};
        }

        sort(v.begin(),v.end());

        vector<int> ans(n);

        int rank = 0, pre = INT_MIN;

        for(auto &[e,i] : v){
            if(e == pre){
                ans[i] = rank;
            }
            else{
                ans[i] = ++rank;
            }
            pre = e;
        }
        return ans;
    }
};