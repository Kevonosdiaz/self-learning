// Using a mix of hashmaps, sets, and an array (since we cannot hash pairs by default)

#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        using namespace std;

        unordered_map<int, set<int>> rows, cols;
        set<int> grid[3][3];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') { continue; }
                
                char elem = board[i][j];
                // Check for dupes
                if (rows[i].count(elem)==1 || cols[j].count(elem)==1 || grid[i/3][j/3].count(elem)==1) {
                    return false;
                }

                // Update our HashSets
                rows[i].emplace(elem);
                cols[j].emplace(elem);
                grid[i/3][j/3].emplace(elem);
            }
        }

        return true;
    }
};