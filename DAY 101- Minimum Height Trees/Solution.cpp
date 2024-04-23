class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0) {
            vector<int> tmp;
            tmp.push_back(0);
            return tmp;
        }
        unordered_map<int, list<int>> adj;

        // creating adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> leaves; // Stores current leaf nodes

        // Initialize leaves with nodes having only 1 adjacent node
        for(auto& d : adj) {
            if(d.second.size() == 1) {
                leaves.push_back(d.first);
            }
        }

        // answer can consist of max. 2 nodes (Reason explained above)
        while(n > 2) {
            vector<int> new_leaves;

            // remove current leaves
            n -= leaves.size(); 

            for(int leaf : leaves) {
                // get the only neighbour of leaf
                int neighbor = adj[leaf].front(); 
                // remove leaf from neighbour's adjacency list
                adj[neighbor].remove(leaf); 
                
                // if the adjacent node becomes a leaf node after removal, add it to the queue.
                if(adj[neighbor].size() == 1) {
                    new_leaves.push_back(neighbor); 
                }
            }
            
            // update current no of leaf nodes
            leaves = new_leaves; 
        }

        return leaves;
    }
};
