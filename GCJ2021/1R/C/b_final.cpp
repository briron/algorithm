#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

ll power(ll base, ll exp) {
    ll ret = 1;
    while(exp > 9) {
        if(exp % 2 == 0) {
            base *= base;
            exp /= 2;
        } else {
            ret *= base;
            exp -= 1;
        }
    }
    return ret;
}

bool compare(string& one, string& other) {
    if(one.size() > other.size()) {
        return true;
    } else if(one.size() < other.size()) {
        return false;
    }
    for(int i = 0 ; i < one.size() ; ++i) {
        if(one[i] > other[i]) {
            return true;
        } else if(one[i] < other[i]) {
            return false;
        }
    }
    return true;
}

string makeRoaring(ll num, ll count) {
    string ret = "";
    for(int i = 0 ; i < count ; ++i) {
        ret += to_string(num);
        num += 1;
    }
    return ret;
}

string binarySearch(int count, string& Y) {
    ll lo = 1;
    ll hi = stoll(Y);
    while(lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        string roaring = makeRoaring(mid, count);
        if(compare(Y, roaring)) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return makeRoaring(lo, count);
}

string getMin(string& one, string& other) {
    if(compare(one, other)) {
        return other;
    }
    return one;
}

string findRoaring(string& Y) {
    string ret = "9999999999999999999";
    for(int i = 2 ; i <= 20 ; ++i) {
        string roaring = binarySearch(i, Y);
        ret = getMin(ret, roaring);
    }
    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        string Y;
        cin >> Y;

        string ret = findRoaring(Y);

        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}