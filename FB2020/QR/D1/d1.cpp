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
    ifstream filein("..\\FB2020\\QR\\D1\\d1.in");
    ofstream fileout("..\\FB2020\\QR\\D1\\d1.out");
    int T = stoi(readLine(filein));
    for(int t = 1 ; t <= T; ++t){
        vector<ll> nmvec = readWord(filein, ' ');
        ll N = nmvec[0];
        ll M = nmvec[1];
        vector<ll> cost(N+1);
        vector<ll> dp(N+1);
        for(int i = 1 ; i <= N ; ++i){
            cost[i] = stoi(readLine(filein));
        }

        ll ret = -1;
        map<ll, ll> m;
        if(M >= N-1){
            fileout << "Case #" << t << ": "; 
            fileout << 0;
            fileout << endl;
            continue;
        }
        for(int i = N-1; i >= N-M; --i){
            if(cost[i] == 0){
                continue;
            }
            m[cost[i]] += 1;
            dp[i] = cost[i];
        }

        for(int i = N-M-1; i >= 1 ; --i){
            if(m.size() == 0){
                break;
            }
            if(cost[i] != 0){
                m[cost[i] + m.begin()->first] += 1;
                dp[i] = cost[i] + m.begin()->first;
            }
            if(i != 1 && cost[i+M] != 0){
                m[dp[i+M]] -= 1;
                if(m[dp[i+M]] == 0){
                    m.erase(dp[i+M]);
                }
            }
        }
        if(m.size() > 0){
            ret = m.begin()->first;
        }

        fileout << "Case #" << t << ": "; 
        fileout << ret;
        fileout << endl;
    }

    filein.close();
    fileout.close();

    return 0;
}