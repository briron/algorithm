#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> dp(1000001, -1);
vector<ll> subsum(1000001);


ll up_and_down(ll num){
    if(dp[num] != -1){
        return dp[num];
    }
    if(num % 2 == 0){
        return dp[num] = up_and_down(num/2) + 1;
    }
    return dp[num] = up_and_down(num+1) + 1;
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin >> T;
    dp[1] = 0;
    for(int i = 1 ; i <= 1000001; ++i){
        subsum[i] = subsum[i-1] + up_and_down(i);
    }

	for(int t = 0; t < T; ++t){
        ll N1, N2;
        cin >> N1 >> N2;
        ll ret = subsum[N2] - subsum[N1-1];
		cout << "Case #" << t+1 << "\n";
		cout << ret << "\n";
	}

	return 0;
}