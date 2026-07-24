class Solution {
public:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
    void dfs(vector<vector<int>>& image, int r, int c, int &color, int &pre_color, int &n, int &m){

        image[r][c] = color;

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m || image[nr][nc] != pre_color) continue;

            dfs(image,nr,nc,color,pre_color,n,m);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();

        int pre_color = image[sr][sc];

        if(pre_color == color) return image;

        dfs(image,sr,sc,color,pre_color,n,m);

        return image;
    }
};