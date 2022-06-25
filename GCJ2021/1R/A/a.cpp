// g++ -std=c++17 a.cpp -o exe && ./exe && rm -rf exe

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isGreater(string& one, string& other) {
    if(one.size() < other.size()) {
        return true;
    }
    if(one.size() > other.size()) {
        return false;
    }
    for(int i = 0 ; i < one.size(); ++i) {
        if(one[i] < other[i]) {
            return true;
        }
        else if(one[i] > other[i]) {
            return false;
        }
    }
    return false;
}

bool frontEqual(string& prev, string& cur, int k) {
    for(int i = 0 ; i < k ; ++i){
        if(prev[i] != cur[i]) {
            return false;
        }
        prev[i] = cur[i];
    }
    return true;
}

bool allNine(string& prev, int k) {
    int n = prev.size();
    for(int i = 0 ; i < k ; ++i) {
        if(prev[n-1-i] != '9') {
            return false;
        }
    }
    return true;
}

string plusOne(string& prev) {
    int bonus = 1;
    for(int i = prev.size() - 1; i >= 0 ; --i) {
        if(prev[i] == '9') {
            prev[i] = 0;
        }
        else {
            prev[i] = prev[i] + 1;
            bonus = 0;
            return prev;
        }
    }
    return prev;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int N;
        cin >> N;

        vector<string> arr(N);
        for(int i = 0 ; i < N ; ++i) {
            cin >> arr[i];
        }

        string prev = arr[0];

        ll ret = 0;

        for(int i = 1 ; i < arr.size() ; ++i) {
            int k = (int)prev.size() - (int)arr[i].size();

            string cur = arr[i];

            if(k > 0) {
                for(int j = 0 ; j < k; ++j) {
                    cur += "0";
                    ret += 1;
                }
            }

            if(isGreater(prev, cur)) {
                prev = cur;
                continue;
            }

            if(!frontEqual(prev, cur, (int)prev.size() - k) || allNine(prev, k)) {
                cur += "0";
                ret += 1;
                prev = cur;
                continue;
            }

            prev = plusOne(prev);
        }




        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}


/* wrong solution

ll getDigit(ll a) {
    if(a == 0) {
        return 1;
    }
    ll ret = 0;
    while(a > 0) {
        ret += 1;
        a /= 10;
    }
    return ret;
}

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


ll getNext(ll value) {
    ll exp = 0;
    while(value > 0) {
        if(value % 10 < 9) {
            return (value+1) * power(10, exp);
        }
        value /= 10;
        exp += 1;
    }
    return power(10, exp);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int N;
        cin >> N;
        vector<ll> arr(N);
        
        for(int i = 0 ; i < N ; ++i) {
            cin >> arr[i];
        }

        ll prev = arr[0];
        ll ret = 0;

        for(int i = 1 ; i < N ; ++i) {
            if(prev < arr[i]) {
                prev = arr[i];
                continue;
            }
            
            ll prevDigit = getDigit(prev);
            ll curDigit = getDigit(arr[i]);

            if(prevDigit == curDigit) {
                ret += 1;
                prev = arr[i] * 10;
                continue;
            }

            ll cur = arr[i] * power(10, prevDigit - curDigit);
            ret += (prevDigit - curDigit);

            if(cur > prev) {
                prev = cur;
                continue;
            }

            if((prev - cur) < power(10, prevDigit - curDigit) && ( (prev % power(10, prevDigit - curDigit)) != power(10, prevDigit - curDigit) - 1)) {
                prev = prev + 1;
                continue;
            }

            ret += 1;
            cur *= 10;
            prev = cur;
        }

        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}

*/