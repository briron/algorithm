// Problem B

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

ll power(ll base, ll exp, ll P){
    ll ret = 1;
    while(exp > 0){
        if(exp % 2 == 0){
            base *= base;
            base %= P;
            exp /= 2;
        }
        else{
            ret *= base;
            ret %= P;
            exp -= 1;
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream filein("..\\FB2019\\1R\\B\\b.in");
    ofstream fileout("..\\FB2019\\1R\\B\\b.out");

    ll P = 1000000007;
    int T = stoi(readLine(filein));
    for(int t = 1 ; t <= T; ++t){
        vector<ll> nk = readWord(filein, ' ');
        ll N = nk[0];
        ll K = nk[1];
        string s = readLine(filein);
        ll ret = 0;
        ll maxVote = 0;
        ll cur = 0;
        for(int i = N-1; i >= 0; --i){
            if(s[i] == 'A'){
                cur += 1;
            }
            else{
                cur -= 1;
            }
            if(cur - maxVote < -K){
                ret += power(2, i+1, P);
                ret %= P;
                cur += 2;
            }
            maxVote = max(maxVote, cur);
        }

        fileout << "Case #" << t << ": ";
        fileout << ret << endl;
    }

    filein.close();
    fileout.close();

    return 0;
}