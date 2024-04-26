class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Get the size of the matrix
        int first_min = 1e9, second_min = 1e9; // Initialize first and second minimums to a large value
        int first_index = -1, second_index = -1; // Initialize indices for the first and second minimums
        
        // Iterate through each row of the matrix
        for(int i = 0; i < n; i++) {
            if(i != 0) { // For rows after the first one
                // Update the matrix values based on previous row's minimums
                for(int j = 0; j < n; j++) {
                    if(j != first_index) 
                        matrix[i][j] += first_min;
                    else 
                        matrix[i][j] += second_min;
                }
            }
            
            // Reset first and second minimums for the current row
            first_min = 1e9;
            second_min = 1e9;
            
            // Iterate through each element of the current row
            for(int j = 0; j < n; j++) {
                // Update first and second minimums and their indices
                if(matrix[i][j] < first_min) {
                    second_min = first_min;
                    first_min = matrix[i][j];
                    first_index = j;
                } else if(matrix[i][j] < second_min) {
                    second_min = matrix[i][j];
                    second_index = j;
                }
            }
        }
        
        // Return the minimum of the first and second minimums
        return min(first_min, second_min);
    }
};
