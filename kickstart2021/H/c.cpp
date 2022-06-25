#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

bool isValid(ll index, ll priority, vector<vector<ll>>& chain) {
    ll next = chain[index][2];
    if(next == (ll)chain.size()) {
        return false;
    }
    if(chain[index][0] == -1 || chain[next][0] == -1) {
        return false;
    }
    if(priority % 10 != chain[index][0]) {
        return false;
    }
    return ( (chain[index][0]) + 1) % 10 == (chain[next][0]);
}

void change(ll index, vector<vector<ll>>& chain) {
    ll next = chain[index][2];
    if(next == (ll)chain.size()) {
        return;
    }
    ll nextnext = chain[next][2];
    if(nextnext != chain.size()) {
        chain[nextnext][1] = index;
    }
    chain[index][0] = (chain[index][0] + 2) % 10;
    chain[next][0] = -1;
    chain[index][2] = chain[next][2];
}

void findOperation(ll index, ll priority, vector<vector<ll>>& chain, priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>>& pq) {
    ll prev = chain[index][1];
    ll next = chain[index][2];
    if(prev != -1) {
        if((chain[prev][0] + 1) % 10 == chain[index][0]) {
            pq.push({priority+1, prev});
        }
    }
    if(next != (ll)chain.size()) {
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
        ll N;
        cin >> N;
        string S;
        cin >> S;

        vector<vector<ll>> chain(N, vector<ll>(3));
        for(ll i = 0 ; i < (ll)chain.size() ; ++i) {
            chain[i][0] = (S[i] - '0');
            chain[i][1] = i-1;
            chain[i][2] = i+1;
        }

        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

        for(ll i = 0 ; i < (ll)S.size() - 1 ; ++i) {
            if(((S[i] - '0') + 1 ) % 10 == (S[i+1] - '0')) {
                pq.push({S[i] - '0', i});
            }
        }

        while(!pq.empty()) {
            vector<ll> here = pq.top();
            pq.pop();
            ll priority = here[0];
            ll idx = here[1];
            if(isValid(idx, priority, chain)) {
                change(idx, chain);
                findOperation(idx, priority, chain, pq);
            }


        }

        string ret;
        for(ll i = 0 ; i < (ll)chain.size() ; ++i) {
            if(chain[i][0] != -1) {
                ret += to_string(chain[i][0]);
            }
        } 

        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}