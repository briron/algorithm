#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;


vector<int> getPrimes() {
    vector<int> primes;
    for(int i = 2 ; i <= 1000; ++i) {
        bool isPrime = true;
        for(int j = 0 ; j < primes.size() ; ++j) {
            if(i % primes[j] == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            primes.push_back(i);
        }
    }
    return primes;
}

void iterate(int& here, unordered_map<int, int>::iterator pos, unordered_map<int, int>& p, vector<int>& ret) {
    if(pos == p.end()) {
        if(here != 1) {
            ret.push_back(here);
        }
        return;
    }
    iterate(here, next(pos), p, ret);
    for(int i = 0 ; i < pos->second; ++i) {
        here *= pos->first;
        iterate(here, next(pos), p, ret);
    }
    for(int i = 0 ; i < pos->second; ++i) {
        here /= pos->first;
    }
    return;
}

vector<int> combi(unordered_map<int, int>& p) {
    vector<int> ret;
    auto pos = p.begin();
    int here = 1;
    iterate(here, pos, p, ret);
    return ret;
}

vector<int> getDividers(int here, vector<int>& primes) {
    unordered_map<int, int> p;
    for(int& prime : primes) {
        if(here == 1) {
            break;
        }
        while(here % prime == 0) {
            here /= prime;
            p[prime] += 1;
        }
    }
    if(here != 1) {
        p[here] += 1;
    }
    return combi(p);
}

int getMatry2(int here, vector<int>& dp2, vector<int>& primes) {
    if(dp2[here] != -1) {
        return dp2[here];
    }

    vector<int> dividers = getDividers(here, primes);
    int ret = 0;
    for(int i = 0 ; i < dividers.size() ; ++i) {
        ret = max(ret, 1 + getMatry2(here / dividers[i] - 1, dp2, primes));
    }

    return dp2[here] = ret;
}

int getMatry(int here, vector<int>& dp, vector<int>& dp2, vector<int>& primes) {
    if(dp[here] != -1) {
        return dp[here];
    }

    vector<int> dividers = getDividers(here, primes);
    int ret = 0;
    for(int i = 0 ; i < dividers.size() ; ++i) {
        if(dividers[i] == 2) {
            continue;
        }
        ret = max(ret, 1 + getMatry2(here / dividers[i] - 1, dp2, primes));
    }

    return dp[here] = ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> primes = getPrimes();

    vector<int> dp(1000001, -1);
    vector<int> dp2(1000001, -1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    dp2[0] = 0;
    dp2[1] = 0;
    dp2[2] = 1;

    for(int i = 1 ; i < primes.size() ; ++i) {
        dp[primes[i]] = 1;
        dp2[primes[i]] = 1;
    }

    for(int i = 3 ; i < dp.size(); ++i) {
        getMatry2(i, dp2, primes);
    }

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int N;
        cin >> N;

        int ret = getMatry(N, dp, dp2, primes);

        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}