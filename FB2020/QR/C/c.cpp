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

ll getLongest(ll pos, ll state, unordered_map<ll,vector<ll>>& dp, map<ll, vector<ll>>& m, vector<vector<ll>>& tree){
    if(dp.count(pos) > 0 && dp[pos][state] != -1){
        return dp[pos][state];
    }
    auto it = m.lower_bound(pos);
    if(it == m.end() || it->first != pos){
        return 0;
    }
    ll ret = 0;
    for(int i = 0 ; i < (it->second).size(); ++i){
        ll treeIdx = it->second[i];
        if(tree[treeIdx][0] == pos){
            if(state == 0){
                ret = max(ret, tree[treeIdx][1] + getLongest(pos + tree[treeIdx][1], 0, dp, m, tree));
            }
        }
        else{
            ret = max(ret, tree[treeIdx][1] + getLongest(pos + tree[treeIdx][1], 1, dp, m, tree));
        }
    }

    if(dp.count(pos) == 0){
        dp[pos] = {-1, -1};
    }

    return dp[pos][state] = ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream filein("..\\FB2020\\QR\\C\\c.in");
    ofstream fileout("..\\FB2020\\QR\\C\\c.out");
    int T = stoi(readLine(filein));
    for(int t = 1 ; t <= T; ++t){
        ll N = stol(readLine(filein));
        vector<vector<ll>> tree(N, vector<ll>(2));
        for(int i = 0 ; i < N ; ++i){
            tree[i] = readWord(filein, ' ');
        }

        sort(tree.begin(), tree.end());
        map<ll, vector<ll>> m;
        for(int i = 0 ; i < tree.size(); ++i){
            m[tree[i][0] - tree[i][1]].push_back(i);
            m[tree[i][0]].push_back(i);
        }

        unordered_map<ll, vector<ll>> dp;
        ll ret = 0;
        for(auto it = m.begin(); it != m.end(); ++it){

            ll pos = it->first;
            for(int i = 0 ; i < (it->second).size(); ++i){
                ll treeIdx = it->second[i];
                if(tree[treeIdx][0] == pos){
                    ret = max(ret, tree[treeIdx][1] + getLongest(pos + tree[treeIdx][1], 0, dp, m, tree));
                }
                else{
                    ret = max(ret, tree[treeIdx][1] + getLongest(pos + tree[treeIdx][1], 1, dp, m, tree));
                }
            }
        }


        fileout << "Case #" << t << ": "; 
        fileout << ret;
        fileout << endl;
    }

    filein.close();
    fileout.close();

    return 0;
}