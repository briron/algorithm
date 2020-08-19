#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll base, ll exp){
    ll ret = 1;
    while(exp > 0){
        if(exp % 2 == 0){
            base *= base;
            exp /= 2;
        }
        else{
            ret *= base;
            exp -= 1;
        }
    }
    return ret;
}

ll getScore(ll num, vector<ll>& dp){
    if(dp[num] == -1){
        return 0;
    }
    else if(dp[num] > 0){
        return dp[num];
    }
    if(num < 10){
        return dp[num] = 1;
    }
    int exp = 0;
    ll ret = 0;
    while(power(10, exp) <= num){
        ll tmp = (num / power(10, exp+1)) * power(10, exp) + (num % power(10, exp));
        ret = max(ret, getScore(tmp, dp));
        exp += 1;
    }
    return dp[num] = ret + 1;
}

int main(int argc, char** argv){
	int T;
	cin >> T;
    vector<ll> prime_vec;
    vector<ll> dp(30001);
    dp[1] = -1;
    for(int i = 2 ; i <= 30000; ++i){
        bool isPrime = true;
        for(int j = 0 ; j < prime_vec.size() && prime_vec[j] * prime_vec[j] <= i; ++j){
            if(i % prime_vec[j] == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            prime_vec.push_back(i);
        }
        else{
            dp[i] = -1;
        }
    }

	for(int t = 0; t < T; ++t){
        ll A, B;
        cin >> A >> B;
        A = getScore(A, dp);
        B = getScore(B, dp);

		cout << "Case #" << t+1 << "\n";

        if(A > B){
            cout << 1 << "\n";
        }
        else if(A < B){
            cout << 2 << "\n";
        }
        else{
            cout << 3 << "\n";
        }

	}

	return 0;
}