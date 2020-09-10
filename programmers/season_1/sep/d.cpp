#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll combi(ll n, ll r, vector<vector<ll>>& combi_dp, ll P){
    if(combi_dp[n][r] != -1){
        return combi_dp[n][r] % P;
    }
    if(r == 0){
        return combi_dp[n][r] = 1;
    }
    if(n == r){
        return combi_dp[n][r] = 1;
    }
    return combi_dp[n][r] = (combi(n-1, r-1, combi_dp, P) + combi(n-1, r, combi_dp, P)) % P;
}

int solution(vector<vector<int>> a) {
    ll r = a.size();
    ll c = a[0].size();
    ll P = 1e7 + 19;
    vector<ll> col_count(c);
    for(int i = 0 ; i < c ; ++i){
        int count = 0;
        for(int j = 0 ; j < r ; ++j){
            if(a[j][i] == 1){
                count += 1;
            }
        }
        col_count[i] = count;
    }
    vector<vector<ll>> dp(c+1, vector<ll>(r+1));
    vector<vector<ll>> combi_dp(r+1, vector<ll>(r+1, -1));
    dp[0][col_count[0]] = combi(r, col_count[0], combi_dp, P) % P;
    for(ll i = 1; i < c ; ++i){
        for(ll j = 0 ; j <= r ; ++j){
            for(ll dup = 0 ; dup <= min(j, col_count[i]); ++dup){
                ll k = j + col_count[i] - 2 * dup;
                if(r-j < col_count[i]-dup){
                    continue;
                }

                ll tmp = dp[i-1][j] * combi(j, dup, combi_dp, P);
                tmp %= P;

                tmp *= combi(r-j, (col_count[i]-dup), combi_dp, P);
                tmp %= P;
                dp[i][k] += tmp;
                dp[i][k] %= P;
            }
        }
    }

    return dp[c-1][0];
    
}

int main(){
    vector<vector<int>> a = {{{1,0,0,1,1},{0,0,0,0,0},{1,1,0,0,0},{0,0,0,0,1}}};
    vector<vector<int>> b = {{0,1,0},{1,1,1},{1,1,0},{0,1,1}};
    cout << solution(a) << endl;
    return 0;
}