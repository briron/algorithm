#include <bits/stdc++.h>

using namespace std;

int findCutVertex(int here, bool isRoot, int id, vector<vector<int>>& g, vector<int>& discovered, vector<bool>& isCutVertex){
    discovered[here] = id;
    id += 1;
    int ret = discovered[here];
    int children = 0;
    for(int i = 0 ; i < g[here].size(); ++i){
        int there = g[here][i];
        if(discovered[there] == -1){
            children += 1;
            int subtree = findCutVertex(there, false, id, g, discovered, isCutVertex);
            if(!isRoot && discovered[here] <= subtree){
                isCutVertex[here] = true;
            }
            ret = min(ret, subtree);
        }
        else{
            ret = min(ret, discovered[there]);
        }
    }
    if(isRoot){
        isCutVertex[here] = (children > 1);
    }
    return ret;
}


int findBridge(int here, int id, int parent, vector<vector<int>>& g, vector<int>& discovered, vector<pair<int,int>>& bridges){
    discovered[here] = id;
    id += 1;
    int ret = discovered[here];
    for(int i = 0 ; i < g[here].size(); ++i){
        int there = g[here][i];
        if(there == parent){
            continue;
        }
        if(discovered[there] == -1){
            int subtree = findBridge(there, id, here, g, discovered, bridges);
            if(discovered[here] < subtree){
                bridges.push_back({min(here, there), max(here, there)});
            }
            ret = min(ret, subtree);
        }
        else{
            ret = min(ret, discovered[there]);
        }
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> g(V+1);

    for(int i = 0; i < E; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<pair<int,int>> bridges;
    vector<int> discovered(V+1, -1);
    findBridge(1, 1, -1, g, discovered, bridges);

    sort(bridges.begin(), bridges.end());
    cout << bridges.size() << endl;
    for(int i = 0 ; i < bridges.size(); ++i){
        cout << bridges[i].first << ' ' << bridges[i].second << endl;
    }


    return 0;

}