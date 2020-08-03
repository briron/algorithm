#include <bits/c++std.h>

using namespace std;

struct DisjointSet{
    vector<int> rank;
    vector<int> parent;

    DisjointSet(int n) : parent(n), rank(n,1){
        for(int i = 0 ; i < parent.size(); ++i) parent[i] = i;
    }

    int find(int n){
        if(parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }

    void merge(int a, int b){
        a = find(a); b = find(b);
        if(a==b) return;
        if(rank[a] > rank[b]) swap(a,b);
        parent[a] = b;
        if(rank[a] == rank[b]) ++rank[b];
    }
};
