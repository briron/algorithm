#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

ll power(ll base, ll exp) {
    ll ret = 1;
    while(exp > 0) {
        if(exp % 2 == 0) {
            base *= base;
            exp /= 2;
        }
        else {
            ret *= base;
            exp -= 1;
        }
    }
    return ret;
}

ll getBoringNumber(string num, int odd) {

    if(num.size() == 0) {
        return 1;
    }

    ll ret = 0;

    for(int i = odd ; i < 10 ; i += 2) {
        if(i < num[0] - '0') {
            ret += power(5, num.size() - 1);
        }
        else if(i == num[0] - '0') {
            ret += getBoringNumber(num.substr(1, num.size()-1), (odd+1)%2);
        }
        else {
            break;
        }
    }
    return ret;

}

bool isBoringNumber(string& num) {
    for(int i = 0 ; i < num.size() ; ++i) {
        if(i%2 == 0 && (num[i] - '0') % 2 == 0) {
            return false;
        }
        if(i%2 == 1 && (num[i] - '0') % 2 == 1) {
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        string L, R;
        cin >> L >> R;

        ll ret = 0;

        for(ll i = 1 ; i < R.size() ; ++i) {
            if(i < L.size()) {
                continue;
            }
            ret += power(5, i);
        }

        ret -= getBoringNumber(L, 1);
        ret += getBoringNumber(R, 1);
        if(isBoringNumber(L)) {
            ret += 1;
        }

        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}