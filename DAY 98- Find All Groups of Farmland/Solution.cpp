class Solution {
public:
    // Depth First Search (DFS) function to explore the land area
    void dfs(int i, int j, vector<vector<int>>& a, vector<vector<int>>& v, int &ri, int &rj) {
        // Mark the current cell as visited
        v[i][j] = 1;

        // Explore the neighboring cells in the down and right directions
        if (i + 1 < a.size() && a[i + 1][j] == 1 && v[i + 1][j] == 0) {
            // Update the bottom-right corner coordinates of the farmland area
            ri = max(ri, i + 1);
            dfs(i + 1, j, a, v, ri, rj);
        }
        
        if (j + 1 < a[0].size() && a[i][j + 1] == 1 && v[i][j + 1] == 0) {
            // Update the bottom-right corner coordinates of the farmland area
            rj = max(rj, j + 1);
            dfs(i, j + 1, a, v, ri, rj);
        }
    }

    // Function to find farmland areas in the given grid
    vector<vector<int>> findFarmland(vector<vector<int>>& a) {
        vector<vector<int>> ans;

        int i, j;
        // Create a 2D vector to keep track of visited cells
        vector<vector<int>> v(a.size(), vector<int>(a[0].size(), 0));

        // Iterate through each cell in the grid
        for (i = 0; i < a.size(); i++) {
            for (j = 0; j < a[0].size(); j++) {
                // If the cell is not visited and represents farmland
                if (!v[i][j] && a[i][j] == 1) {
                    int li = i, lj = j, ri = i, rj = j;

                    // Call DFS to explore the farmland area
                    dfs(i, j, a, v, ri, rj);

                    // Store the coordinates of the top-left and bottom-right corners of the farmland area
                    ans.push_back({li, lj, ri, rj});
                }
            }
        }

        return ans;
    }
};
