class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        deque<vector<int>> q(n, {0 ,0});
        priority_queue<vector<int>> pq;
        vector<int> count_vector(26);
        for(int i = 0 ; i < tasks.size() ; ++i){
            count_vector[tasks[i] - 'A'] += 1;
        }
        for(int i = 0 ; i < 26 ; ++i){
            if(count_vector[i] > 0){
                pq.push({count_vector[i], i});
            }
        }
        int ret = 0;
        int idle = 0;
        while(idle > 0 || pq.size() > 0) {
            vector<int> written = {1, 0};
            if(pq.size() > 0){
                written = pq.top();
                pq.pop();
            }
            written[0] -= 1;
            if(written[0] > 0){
                idle += 1;
            }
            q.push_back(written);
            
            vector<int> ready = q.front();
            q.pop_front();
            if(ready[0] > 0) {
                idle -= 1;
                pq.push(ready);
            }
            ret += 1;
        }
        return ret;
    }
};