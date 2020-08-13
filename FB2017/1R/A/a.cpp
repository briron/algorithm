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


ll getMin(int day, vector<vector<ll>>& pie, vector<ll>& pointer){
    ll sday = 0;
    ll scost = LLONG_MAX;
    for(int i = 0 ; i <= day ; ++i){
        if(pie[i].size() <= pointer[i]){
            continue;
        }
        if(scost > pie[i][pointer[i]] + (pointer[i]+1)*(pointer[i]+1) - pointer[i]*pointer[i]){
            sday = i;
            scost = pie[i][pointer[i]] + (pointer[i]+1)*(pointer[i]+1) - pointer[i]*pointer[i];
        }
    }
    pointer[sday] += 1;
    return scost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream filein("..\\FB2017\\1R\\A\\a.in");
    ofstream fileout("..\\FB2017\\1R\\A\\a.out");
    int T = stoi(readLine(filein));
    for(int t = 1 ; t <= T; ++t){
        ll N, M;
        vector<ll> nm = readWord(filein, ' ');
        N = nm[0];
        M = nm[1];
        vector<vector<ll>> pie(N, vector<ll>(M));
        vector<ll> pointer(N);
        for(int i = 0 ; i < N ; ++i){
            pie[i] = readWord(filein, ' ');
            sort(pie[i].begin(), pie[i].end());
        }
        ll ret = 0;
        for(int i = 0 ; i < N ; ++i){
            ret += getMin(i, pie, pointer);
        }

        fileout << "Case #" << t << ": "; 
        fileout << ret;
        fileout << endl;
    }

    filein.close();
    fileout.close();

    return 0;
}