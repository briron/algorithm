#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        ll N, Q;
        cin >> N >> Q;

        vector<string> names(N+1);

        vector<vector<bool>> graph(26, vector<bool>(26, false));

        for(int i = 1 ; i < N+1 ; ++i) {
            cin >> names[i];
        }

        vector<vector<ll>> queries(Q, vector<ll>(2));
        for(int i = 0 ; i < Q; ++i) {
            cin >> queries[i][0] >> queries[i][1];
        }

        for(int i = 1 ; i < N+1 ; ++i) {
            for(int j = 0 ; j < names[i].size() ; ++j) {
                for(int k = j+1 ; k < names[i].size(); ++k) {
                    int left = names[i][j] - 'A';
                    int right = names[i][k] - 'A';
                    graph[left][right] = true;
                    graph[right][left] = true;
                }
            }
        }

        vector<vector<ll>> shortest(26, vector<ll>(26, 26));

        for(int i = 0 ; i < 26 ; ++i) {

            queue<vector<ll>> q;

            q.push({0, i});
            shortest[i][i] = 0;

            while(q.size() > 0) {
                vector<ll> here = q.front();
                q.pop();
                for(int there = 0 ; there < 26; ++there) {
                    if(!graph[here[1]][there]) {
                        continue;
                    }
                    if(shortest[i][there] > here[0] + 1) {
                        shortest[i][there] = here[0] + 1;
                        q.push({here[0] + 1, there});
                    }
                }
            }
        }

        vector<ll> rets;
        for(int i = 0 ; i < Q; ++i) {
            ll ret = 26;
            for( char a : names[queries[i][0]] ) {
                for(char b : names[queries[i][1]] ) {
                    int left = a-'A';
                    int right = b-'A';
                    ret = min(shortest[left][right], ret);
                }
            }
            if(ret == 26) {
                ret = -1;
            } else {
                ret += 2;
            }
            rets.push_back(ret);
        }

        cout << "Case #" << t << ":";
        for(int i = 0 ; i < rets.size() ; ++i) {
            cout << ' ' << rets[i]; 
        }
        cout << endl;
    }

    return 0;

}