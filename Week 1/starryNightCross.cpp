/*
Goal: Find the largest star in the 2d grid
*/

#include <iostream>
#include <vector>
using namespace std;

/*Brute Force*/

struct Points{
    int upper_left;
    int upper_right;
    int lower left;
    int lower_right; 
}


vector<int> solutionBRUTE(vector<vector<int>> matrix) {
    int row_boundary = matrix.size();
    int col_boundary = matrix[0].size();
    
    /*Since each grid is guarenteed to have one 
    and one point is considered a size 1*/
    int largest_size = 1;
    
    for (int row = 0; row < row_boundary; row++){
        for (int col = 0; col < col_boundary; col++){

            /*We only care about ones*/
            if(matrix[row][col] == 0){
                continue;
            }

            /*Distance from the center of the X*/
            int k = 1;

            largest_size = max(largest_size, 1);

            while (i - k >= 0 && i + k < m && j - k >= 0 && j + k < n) {
            
                Points points;

                /*Added for readability*/
                points.upper_left  = matrix[i - k][j - k];
                points.upper_right = matrix[i - k][j + k];
                points.lower_left  = matrix[i + k][j - k];
                points.lower_right = matrix[i + k][j + k];

                if (points.upper_left == 1 &&
                    points.upper_right == 1 &&
                    points.lower_left == 1 &&
                    points.lower_right == 1) {

                    largest_size = max(largest_size, k + 1);
                    k++;

                } 
                
                else {
                    break;
                }


            } 
        }
    
    }

    return largest_size; 
    
}

vector<int> solutionDP(vector<vector<int>> matrix) {
    // HOMEWORK DP
    int row_boundary = matrix.size();
    int col_boundary = matrix[0].size();

    /*Each diagonal length includes the current cell */
    vector<vector<Points>> dp(
        row_boundary, vector<Points>(col_boundary)
    );

    int largest_size = 0;

    /*Calculate upper-left diagonal lengths */
    for (int row = 0; row < row_boundary; row++) {
        for (int col = 0; col < col_boundary; col++) {

            if (matrix[row][col] == 1) {
                dp[row][col].upper_left = 1;

                if (row > 0 && col > 0) {
                    dp[row][col].upper_left +=
                        dp[row - 1][col - 1].upper_left;
                }
            }
        }
    }

    /*Calculate upper-right diagonal lengths */
    for (int row = 0; row < row_boundary; row++) {
        for (int col = col_boundary - 1; col >= 0; col--) {

            if (matrix[row][col] == 1) {
                dp[row][col].upper_right = 1;

                if (row > 0 && col + 1 < col_boundary) {
                    dp[row][col].upper_right +=
                        dp[row - 1][col + 1].upper_right;
                }
            }
        }
    }

    /*Calculate lower-left diagonal lengths */
    for (int row = row_boundary - 1; row >= 0; row--) {
        for (int col = 0; col < col_boundary; col++) {

            if (matrix[row][col] == 1) {
                dp[row][col].lower_left = 1;

                if (row + 1 < row_boundary && col > 0) {
                    dp[row][col].lower_left +=
                        dp[row + 1][col - 1].lower_left;
                }
            }
        }
    }

    /*Calculate lower-right diagonal lengths */
    for (int row = row_boundary - 1; row >= 0; row--) {
        for (int col = col_boundary - 1; col >= 0; col--) {

            if (matrix[row][col] == 1) {
                dp[row][col].lower_right = 1;

                if (row + 1 < row_boundary &&
                    col + 1 < col_boundary) {
                    dp[row][col].lower_right +=
                        dp[row + 1][col + 1].lower_right;
                }
            }
        }
    }

    /* Find the largest X centered at any cell */
    for (int row = 0; row < row_boundary; row++) {
        for (int col = 0; col < col_boundary; col++) {

            if (matrix[row][col] == 0) {
                continue;
            }

            /* All four diagonal directions must be long enough */
            int current_size = min({
                dp[row][col].upper_left,
                dp[row][col].upper_right,
                dp[row][col].lower_left,
                dp[row][col].lower_right
            });

            largest_size = max(largest_size, current_size);
        }
    }

    return largest_size;
}


int main(){
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    std::cout << solutionBRUTE(matrix) << std::endl;
    std::cout << solutionDP(matrix) << std::endl;

    return 0;

}