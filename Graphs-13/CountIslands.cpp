#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
void mark_current_island(vector<vector<int>>& matrix, int x, int y, int r, int c)
{
    std::cout << "row-" << x << " col-" << y  << std::endl;
    if (x < 0 || x >= r || y < 0 || y >= c || matrix[x][y] != 1)  //Boundary case for matrix
        return;
    std::cout << "row-" << x << " col-" << y << " value- " << matrix[x][y] << std::endl;
    //Mark current cell as visited
    matrix[x][y] = 2;

    //Make recursive call in all 4 adjacent directions
    mark_current_island(matrix, x + 1, y, r, c);  //DOWN
    std::cout << "Down" << std::endl;
    mark_current_island(matrix, x, y + 1, r, c);  //RIGHT
    std::cout << "RIGHT" << std::endl;
    mark_current_island(matrix, x - 1, y, r, c);  //TOP
    std::cout << "TOP" << std::endl;
    mark_current_island(matrix, x, y - 1, r, c);  //LEFT
    std::cout << "LEFT" << std::endl;
}

int numIslands(vector<vector<int>>& grid) {

    //For FAST I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rows = grid.size();
    if (rows == 0)     //Empty grid boundary case
        return 0;
    int cols = grid[0].size();

    //Iterate for all cells of the array
    int no_of_islands = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 1)
            {
                std::cout << "row-" << i << "col-" << j << "no_of_islands:" << no_of_islands << std::endl;
                mark_current_island(grid, i, j, rows, cols);
                no_of_islands += 1;
            }
        }
    }
    return no_of_islands;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    std::vector<std::vector<int>> grid{ { 1, 1, 0, 0, 0 },
                                        { 0, 1, 0, 0, 1 },
                                        { 1, 0, 0, 1, 1 },
                                        { 0, 0, 0, 0, 0 },
                                        { 1, 0, 1, 0, 1 } };

    //1 3
    //    1 0 1
    //op - 2
    //4 5
    //    1 0 0 0 0
    //    1 1 1 1 1
    //    0 1 0 1 0
    //    1 0 0 0 1

    //op - 1
    std::cout << numIslands(grid);
    return 0;
}
