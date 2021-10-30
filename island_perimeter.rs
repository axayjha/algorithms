// https://leetcode.com/problems/island-perimeter/
impl Solution {
    pub fn island_perimeter(grid: Vec<Vec<i32>>) -> i32 {
        let mut count: i32 = 0 ;
        let mut repeats: i32 = 0;
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] == 1 {
                    count += 1;
                    if i > 0 && grid[i-1][j] == 1 {
                        repeats += 1;
                    } 
                    if j > 0 && grid[i][j-1] == 1 {
                        repeats += 1;
                    }
                }
            }
        }
        4*count - 2*repeats
    }
}
