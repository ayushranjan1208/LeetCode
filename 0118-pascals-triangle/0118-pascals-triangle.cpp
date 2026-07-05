class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        vector<int> pre = {1};
        pascal[0] = pre;
        for(int i = 2; i <= numRows; i++){
            vector<int> cur(i);

            for(int j = 0; j < i; j++){
                if(j < i - 1) cur[j] = pre[j];
                if(j > 0) cur[j] += pre[j-1];
            }
            pascal[i-1] = cur;
            pre = cur;
        }
        return pascal;
    }
};