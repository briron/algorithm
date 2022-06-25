#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

ll binary_search_sum(ll gap) {
    ll lo = 0;
    ll hi = 2 * 1e9;
    while(lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if(mid * (mid+1) / 2 <= gap) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

ll getSum(ll start, ll last) {
    if(last == -1) {
        return 0;
    }
    return ( (last + start) / 2) * (((last - start) / 2) + 1);
}

ll binary_search_sum2(ll left, ll start) {
    if(start > left) {
        return -1;
    }
    ll lo = 0;
    ll hi = 2 * 1e9;
    while(lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if(getSum(start, start + 2 * mid) <= left) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return start + lo * 2;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        ll L, R;
        cin >> L >> R;
        ll ret = 0;
        ll count = 0;
        ll l_start = 0;
        ll r_start = 0;
        if(L < R) {
            ll gap = R - L;
            count = binary_search_sum(gap);
            l_start = count + 1;
            r_start = count + 1;
            R -= (count * (count+1) / 2);
            if(count * (count+1) / 2 < gap) {
                l_start += 1;
            } else {
                r_start += 1;
            }
        } else {
            ll gap = L - R;
            count = binary_search_sum(gap);
            l_start = count + 1;
            r_start = count + 2;
            L -= (count * (count+1) / 2);
        }
        ll l_last = binary_search_sum2(L, l_start);
        ll r_last = binary_search_sum2(R, r_start);
        L -= getSum(l_start, l_last);
        R -= getSum(r_start, r_last);
        ret = max({l_last, r_last, count});

        cout << "Case #" << t << ": " << ret << ' ' << L << ' ' << R << endl;
    }

    return 0;

}