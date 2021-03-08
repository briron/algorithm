// 489. Robot Room Cleaner
// https://leetcode.com/problems/robot-room-cleaner/

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    void cleanRoom(Robot& robot) {
        unordered_map<int, unordered_set<int>> visited;
        dfs(0, 0, 0, visited, robot);
    }
    
    void dfs(int r, int c, int dir, unordered_map<int, unordered_set<int>>& visited, Robot& robot) {
        visited[r].insert(c);
        robot.clean();
        for(int i = 0 ; i < 4 ; ++i) {
            int nr = r + dr[(dir+i)%4];
            int nc = c + dc[(dir+i)%4];
            if(visited.find(nr) != visited.end() && visited[nr].find(nc) != visited[nr].end()) {
                robot.turnRight();
                continue;
            }
            if(robot.move()) {
                dfs(nr, nc, (dir+i)%4, visited, robot);
                robot.turnLeft();
            }
            else {
                robot.turnRight();            
            }
        }
        robot.turnRight();
        robot.turnRight();
        robot.move();
    }
};