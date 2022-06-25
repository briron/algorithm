#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;


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

bool isEqualGreater(string& a, string& b) {
    if(a.size() > b.size()) {
        return true;
    } else if(a.size() < b.size()) {
        return false;
    }
    for(int i = 0 ; i < a.size() ; ++i) {
        if(a[i] < b[i]) {
            return false;
        } else if(a[i] > b[i]) {
            return true;
        }
    }
    return true;
}

string findFromCount(int digit, string& base) {
    string ret = "99999999999999999999";
    if(digit >= (int)base.size()) {
        return ret;
    }
    if(digit == 1) {
        for(int i = 1; i < 10 ; ++i ){
            int here = i;
            string tmp = to_string(here) + to_string(here+1);
            here += 2;
            while(isEqualGreater(base, tmp)) {
                tmp += to_string(here);
                here += 1;
            }
            if(isEqualGreater(ret, tmp)) {
                ret = tmp;
            }
        }
    } else {
        for(int i = 1 ; i <= 20 ; ++i) {
            int here = power(10, digit) - i;
            string tmp = to_string(here) + to_string(here+1);
            here += 2;
            while(isEqualGreater(base, tmp)) {
                tmp += to_string(here);
                here += 1;
            }
            if(isEqualGreater(ret, tmp)) {
                ret = tmp;
            }
        }

        int start = stoi(base.substr(digit));
        for(int i = 0 ; i < 2 ; ++i) {
            int here = start;
            string tmp = to_string(here) + to_string(here+1);
            here += 2;
            while(isEqualGreater(base, tmp)) {
                tmp += to_string(here);
                here += 1;
            }
            if(isEqualGreater(ret, tmp)) {
                ret = tmp;
            }
            start += 1;
        }

        start = power(10, digit-1);
        for(int i = 0 ; i < 2 ; ++i) {
            int here = start;
            string tmp = to_string(here) + to_string(here+1);
            here += 2;
            while(isEqualGreater(base, tmp)) {
                tmp += to_string(here);
                here += 1;
            }
            if(isEqualGreater(ret, tmp)) {
                ret = tmp;
            }
            start += 1;
        }

    }

    return ret;

}


string findRoaring(string& base) {
    string ret = "99999999999999999999";
    for(int i = 1; i <= 9 ; ++i) {
        string tmp = findFromCount(i, base);
        if(isEqualGreater(ret, tmp)) {
            ret = tmp;
        }
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