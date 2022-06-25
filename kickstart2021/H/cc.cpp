#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

bool isValid(int index, vector<vector<int>>& chain) {
    int next = chain[index][2];
    if(next == chain.size()) {
        return false;
    }
    if(chain[index][0] == -1 || chain[next][0] == -1) {
        return false;
    }
    return ( (chain[index][0]) + 1) % 10 == (chain[next][0]);
}

void change(int index, vector<vector<int>>& chain) {
    int next = chain[index][2];
    if(next == chain.size()) {
        return;
    }
    chain[index][0] = (chain[index][0] + 2) % 10;
    chain[next][0] = -1;
    chain[index][2] = chain[next][2];
}

void findOperation(int index, int priority, vector<vector<int>>& chain, priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>& pq) {
    int prev = chain[index][1];
    int next = chain[index][2];
    if(prev != -1) {
        if((chain[prev][0] + 1) % 10 == chain[index][0]) {
            pq.push({priority+1, prev});
        }
    }
    if(next != chain.size()) {
        if((chain[index][0] + 1) % 10 == chain[next][0]) {
            pq.push({priority+2, index});
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t = 1 ; t <= T ; ++t) {
        int N;
        cin >> N;
        string S;
        cin >> S;

        int here = 0;
        for(int i = 0 ; i < 4000 ; ++i) {
            string T;

            for(int s = 0 ; s < (int)S.size() ; ++s) {
                if(s+1 < S.size() && (S[s] - '0' == here) && (S[s+1] - '0' == (here+1) % 10)) {
                    cout << S[s] - '0' << ' ' << S[s+1] - '0' << endl;
                    T += to_string((here+2)%10);
                    ++s;
                } else {
                    T += S[s];
                }
            }

            here += 1;
            here %= 10;
            S = T;
        }

        cout << "Case #" << t << ": " << S << endl;;
    }

    return 0;

}