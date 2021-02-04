// 621. Task Scheduler
// https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count_vector(26);
        for(int i = 0 ; i < tasks.size() ; ++i){
            count_vector[tasks[i] - 'A'] += 1;
        }
        int maxCount = 0;
        int maxDuplicate = 0;
        for(int i = 0 ; i < 26 ; ++i){
            if(maxCount < count_vector[i]) {
                maxCount = count_vector[i];
                maxDuplicate = 1;
            }
            else if(maxCount == count_vector[i]){
                maxDuplicate += 1;
            }
        }
        return max( (n+1) * (maxCount-1) + maxDuplicate, (int)tasks.size());
    }
};
