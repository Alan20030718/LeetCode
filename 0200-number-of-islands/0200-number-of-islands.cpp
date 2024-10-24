class Solution {
public:
    //dfs

    void dfs(int i, int j, vector<vector<char>>& grid){
        int row = grid.size();
        int col = grid[0].size();
        if(i< 0 || j< 0|| i>= row || j >= col || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int island = 0;
        for(int i = 0; i< row; i++){
            for(int j = 0; j< col; j++){
                 if(grid[i][j] == '1'){
                    island++;
                    dfs(i,j,grid);
                }
            }
        }
        return island;
    }

    
};