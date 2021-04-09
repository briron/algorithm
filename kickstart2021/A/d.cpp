#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int N;
        cin >> N;
        vector<vector<int>> matrix(N, vector<int>(N));
        vector<vector<int>> cost(N, vector<int>(N));
        vector<vector<int>> rArr(N);
        vector<vector<int>> cArr(N);

        for(int i = 0 ; i < N ; ++i) {
            for(int j = 0 ; j < N ; ++j) {
                cin >> matrix[i][j];
            }
        }

        for(int i = 0 ; i < N ; ++i) {
            for(int j = 0 ; j < N ; ++j) {
                cin >> cost[i][j];
            }
        }

        for(int i = 0 ; i < N ; ++i) {
            int a;
            cin >> a;
        }

        for(int i = 0 ; i < N ; ++i) {
            int a;
            cin >> a;
        }

        ll ret = 0;


        vector<vector<int>> start = {};

        for(int r = 0 ; r < N ; ++r) {
            for(int c = 0 ; c < N ; ++c) {
                if(matrix[r][c] == -1) {
                    rArr[r].push_back(c);
                    cArr[c].push_back(r);
                    ret += cost[r][c];
                    start.push_back({0, r, 0});
                }
            }
        }

        priority_queue<vector<int>> pq;

        vector<bool> rVisited(N);
        vector<bool> cVisited(N);


        if(start.empty()) {
            cout << "Case #" << t << ": " << ret << endl;
            continue;
        }

        for(int s = 0 ; s < start.size() ; ++s) {
            vector<int> here = start[s];
            if(rVisited[here[1]]) {
                continue;
            }

            pq.push(here);
            while(pq.size() > 0) {
                here = pq.top();
                pq.pop();

                if(here[2] == 0) {
                    int r = here[1];
                    if(rVisited[r]) {
                        continue;
                    }
                    rVisited[r] = true;
                    ret -= here[0];
                    for(int i = 0 ; i < rArr[r].size(); ++i) {
                        int c = rArr[r][i];
                        pq.push({cost[r][c], c, 1});
                    }
                }

                else {
                    int c = here[1];
                    if(cVisited[c]) {
                        continue;
                    }
                    cVisited[c] = true;
                    ret -= here[0];
                    for(int i = 0 ; i < cArr[c].size(); ++i) {
                        int r = cArr[c][i];
                        pq.push({cost[r][c], r, 0});
                    }
                }
            }

        }
        
        cout << "Case #" << t << ": " << ret << endl;

    }

    return 0;

}



/* wrong solution 
void eraseArr(vector<unordered_set<int>>& arr, vector<unordered_set<int>>& counterArr, int here, int target) {
    arr[here].erase(target);
    if(arr[here].size() == 1) {
        int next = *(arr[here].begin());
        arr[here].clear();
        eraseArr(counterArr, arr, next, here);
    }
}

void eraseAllArr(vector<unordered_set<int>>& rArr, vector<unordered_set<int>>& cArr) {
    for(int r = 0 ; r < rArr.size(); ++r) {
        if(rArr[r].size() == 1) {
            int c = *(rArr[r].begin());
            rArr[r].clear();
            eraseArr(cArr, rArr, c, r);
        }
    }

    for(int c = 0 ; c < cArr.size(); ++c) {
        if(cArr[c].size() == 1) {
            int r = *(cArr[c].begin());
            cArr[c].clear();
            eraseArr(rArr, cArr, r, c);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int N;
        cin >> N;
        vector<vector<int>> matrix(N, vector<int>(N));
        vector<vector<int>> cost(N, vector<int>(N));
        vector<unordered_set<int>> rArr(N);
        vector<unordered_set<int>> cArr(N);

        for(int i = 0 ; i < N ; ++i) {
            for(int j = 0 ; j < N ; ++j) {
                cin >> matrix[i][j];
                if(matrix[i][j] == -1) {
                    rArr[i].insert(j);
                    cArr[j].insert(i);
                }
            }
        }

        for(int i = 0 ; i < N ; ++i) {
            for(int j = 0 ; j < N ; ++j) {
                cin >> cost[i][j];
            }
        }

        for(int i = 0 ; i < N ; ++i) {
            int a;
            cin >> a;
        }

        for(int i = 0 ; i < N ; ++i) {
            int a;
            cin >> a;
        }

        eraseAllArr(rArr, cArr);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(int r = 0 ; r < N; ++r) {
            for(auto it = rArr[r].begin(); it != rArr[r].end(); ++it) {
                int c = *it;
                pq.push({cost[r][c], r, c});
            }
        }

        ll ret = 0;

        while(pq.size() > 0) {
            vector<int> here = pq.top();
            pq.pop();
            if(rArr[here[1]].find(here[2]) == rArr[here[1]].end()) {
                continue;
            }
            rArr[here[1]].erase(here[2]);
            cArr[here[2]].erase(here[1]);
            ret += cost[here[1]][here[2]];
            if(rArr[here[1]].size() == 1) {
                int c = *(rArr[here[1]].begin());
                rArr[here[1]].clear();
                eraseArr(cArr, rArr, c, here[1]);
            }
            if(cArr[here[2]].size() == 1) {
                int r = *(cArr[here[2]].begin());
                cArr[here[2]].clear();
                eraseArr(rArr, cArr, r, here[0]);
            }
        }

        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}
*/