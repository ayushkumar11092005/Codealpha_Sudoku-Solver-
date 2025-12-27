#include <iostream>
using namespace std;

bool isSafe(int grid[9][9], int r, int c, int n) {
    for (int x = 0; x < 9; x++)
        if (grid[r][x] == n || grid[x][c] == n)
            return false;

    int sr = r - r % 3, sc = c - c % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[sr + i][sc + j] == n)
                return false;

    return true;
}

bool solve(int grid[9][9]) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (grid[r][c] == 0) {
                for (int n = 1; n <= 9; n++) {
                    if (isSafe(grid, r, c, n)) {
                        grid[r][c] = n;
                        if (solve(grid)) return true;
                        grid[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int grid[9][9] = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    if (solve(grid)) {
        cout << "Solved Sudoku:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists";
    }

    return 0;
}
