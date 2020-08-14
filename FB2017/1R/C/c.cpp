// Problem C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string readLine(ifstream& filein){
    string line;
    getline(filein, line);
    return line;
}
vector<ll> readWord(ifstream& filein, char delimiter){
    string line = readLine(filein);
    istringstream ss(line);
    string word;
    vector<ll> ret;
    while(getline(ss, word, delimiter)){
        ret.push_back(stol(word));
    };
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream filein("..\\FB2017\\1R\\C\\c.in");
    ofstream fileout("..\\FB2017\\1R\\C\\c.out");
    int T = stoi(readLine(filein));
    for(int t = 1 ; t <= T; ++t){
        vector<ll> nmk = readWord(filein, ' ' );
        ll N = nmk[0];
        ll M = nmk[1];
        ll K = nmk[2];
        vector<vector<vector<ll>>> g(N+1);
        for(int i = 0 ; i < M ; ++i){
            vector<ll> abg = readWord(filein, ' ');
            g[abg[0]].push_back({abg[1], abg[2]});
            g[abg[1]].push_back({abg[0], abg[2]});
        }
        vector<vector<ll>> dist(N+1, vector<ll>(N+1, -1));

        for(int i = 1 ; i <= N ; ++i){
            dist[i][i] = 0;
            priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
            pq.push({i, 0});
            while(pq.size() > 0){
                ll here = pq.top()[0];
                ll d = pq.top()[1];
                pq.pop();
                for(int j = 0 ; j < g[here].size(); ++j){
                    ll there = g[here][j][0];
                    if(dist[i][there] < 0 || dist[i][there] > d + g[here][j][1]){
                        dist[i][there] = d + g[here][j][1];
                        pq.push({there, dist[i][there]});
                    }
                }
            }
        }

        vector<vector<ll>> family(K+1);
        bool inValid = false;
        family[0] = {1, 1};
        for(int i = 1 ; i <= K ; ++i){
            family[i] = readWord(filein, ' ');
            if(dist[family[i][0]][family[i][1]] < 0 || dist[family[i-1][1]][family[i][0]] < 0){
                inValid = true;
            } 
        }
        if(inValid){
            fileout << "Case #" << t << ": "; 
            fileout << -1;
            fileout << endl;
            continue;
        }

        // DP 의 state를 2개로 해서 풀면 될 듯..
        vector<vector<ll>> dp(K+1, vector<ll>(2, LLONG_MAX / 10));

        dp[0][0] = 0;
        dp[1][0] = dist[1][family[1][0]] + dist[family[1][0]][family[1][1]];
        if(K > 1){
            dp[1][1] = dist[1][family[1][0]] + dist[family[1][0]][family[2][0]] + dist[family[2][0]][family[1][1]];
        }
        for(int i = 2 ; i <= K; ++i){
            dp[i][0] = min(dp[i-1][0] + dist[family[i-1][1]][family[i][0]] + dist[family[i][0]][family[i][1]],
                        dp[i-1][1] + dist[family[i-1][1]][family[i][1]]);
            if(i != K){
                dp[i][1] = min(dp[i-1][1] + dist[family[i-1][1]][family[i+1][0]] + dist[family[i+1][0]][family[i][1]],
                dp[i-1][0] + dist[family[i-1][1]][family[i][0]] + dist[family[i][0]][family[i+1][0]] + dist[family[i+1][0]][family[i][1]]);
            }
        }
        fileout << "Case #" << t << ": "; 
        fileout << dp[K][0];
        fileout << endl;
    }

    filein.close();
    fileout.close();

    return 0;
}