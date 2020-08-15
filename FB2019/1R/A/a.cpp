// Problem A

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

void dijkstra(ll start, vector<vector<vector<ll>>>& g, vector<vector<ll>>& dist){
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    pq.push({0, start});
    while(pq.size() > 0){
        ll cost = pq.top()[0];
        ll here = pq.top()[1];
        pq.pop();
        for(int i = 0 ; i < g[here].size(); ++i){
            ll there = g[here][i][0];
            ll added = g[here][i][1];
            if(dist[start][there] == -1 || dist[start][there] >= cost + added){
                dist[start][there] = cost + added;
                dist[there][start] = cost + added;
                pq.push({cost+added, there});
            }
        }
    }
    return;
}


bool compare(vector<ll>& a, vector<ll>& b){
    return a.back() < b.back();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream filein("..\\FB2019\\1R\\A\\a.in");
    ofstream fileout("..\\FB2019\\1R\\A\\a.out");
    int T = stoi(readLine(filein));
    for(int t = 1 ; t <= T; ++t){
        vector<ll> nm = readWord(filein, ' ');
        ll N = nm[0];
        ll M = nm[1];
        vector<vector<ll>> req(M);
        for(int i = 0 ; i < M ; ++i){
            req[i] = readWord(filein, ' ');
        }
        sort(req.begin(), req.end(), compare);
        vector<vector<ll>> dist(N+1, vector<ll>(N+1, -1));
        vector<vector<vector<ll>>> g(N+1);
        vector<vector<ll>> ret;
        bool isValid = true;
        for(int i = 0 ; i < M ; ++i){
            ll here = req[i][0];
            ll there = req[i][1];
            dijkstra(here, g, dist);
            dijkstra(there, g, dist);
            if(dist[here][there] == -1 || dist[here][there] > req[i][2]){
                dist[here][there] = req[i][2];
                dist[there][here] = req[i][2];
                g[here].push_back({there, req[i][2]});
                g[there].push_back({here, req[i][2]});
                ret.push_back({here, there, req[i][2]});
            }
            else if(dist[here][there] < req[i][2]) {
                isValid = false;
                break;
            }
        }
        if(isValid == false){
            fileout << "Case #" << t << ": Impossible" << endl;
            continue;             
        }
        fileout << "Case #" << t << ": ";
        fileout << ret.size() << endl;
        for(int i = 0 ; i < ret.size(); ++i){
            fileout << ret[i][0] << ' ' << ret[i][1] << ' ' << ret[i][2] << endl;
        }
    }

    filein.close();
    fileout.close();

    return 0;
}