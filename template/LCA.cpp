#include <bits/stdc++.h>

using namespace std;

// https://www.acmicpc.net/problem/11438

void buildParent(int here, int from, vector<vector<int>>& graph, vector<int>& depth, vector<vector<int>>& parent) {
    parent[here][0] = from;
    depth[here] = depth[from] + 1;
    for(int i = 1 ; i < parent[here].size() ; ++i) {
        int ancestor = parent[here][i-1];
        if(ancestor == 0) {
            break;
        }
        parent[here][i] = parent[ancestor][i-1];
    }
    for(int i = 0 ; i < graph[here].size() ; ++i) {
        int there = graph[here][i];
        if(depth[there] != 0) {
            continue;
        }
        buildParent(there, here, graph, depth, parent);
    }
}

int findParent(int one, int other, vector<int>& depth, vector<vector<int>>& parent) {
    if(depth[one] < depth[other]) {
        return findParent(other, one, depth, parent);
    }

    for(int i = parent[one].size() - 1 ; i >= 0 ; --i) {
        if( (1 << i) <= depth[one] - depth[other] ) {
            one = parent[one][i];
        }
    }

    if(one == other) {
        return one;
    }

    for(int i = parent[one].size() - 1 ; i >= 0 ; --i) {
        if(parent[one][i] != parent[other][i]) {
            one = parent[one][i];
            other = parent[other][i];
        }
    }

    return parent[one][0];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> graph(N+1);
    for(int i = 0 ; i < N-1 ; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> depth(N+1);
    int H = floor(log2(N)) + 1;

    vector<vector<int>> parent(N+1, vector<int>(H));

    buildParent(1, 0, graph, depth, parent);

    int M;
    cin >> M;
    for(int i = 0 ; i < M ; ++i) {
        int one, other;
        cin >> one >> other;
        cout << findParent(one, other, depth, parent) << "\n";
    }

    return 0;
}
