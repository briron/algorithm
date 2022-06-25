#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

vector<int> makeOutput() {
    vector<int> output;
    for(int i = 0 ; i < 10 ; ++i) {
        int base = 1 << (i*3);
        output.push_back(base * 2);
        output.push_back(base * 3);
        output.push_back(base * 4);
        output.push_back(base * 5);
        output.push_back(base * 6);
    }
    return output;
}

vector<int> getHalf(int base, int n) {
    if(n == 0) {
        return {base*4, base*6};
    } else if(n == 2) {
        return {base*4, base*5};
    } else if(n == 4) {
        return {base*3, base*5};
    } else if(n == 6) {
        return {base*2, base*5};
    } else if(n == 8) {
        return {base*6};
    } else if(n == 10) {
        return {base*5};
    } else if(n == 12) {
        return {base*4};
    } else if(n == 14) {
        return {base*3};
    }
    return {base*2};
}

int main() {
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int N;
        cin >> N;
        vector<int> output = makeOutput();
        for(int i = 0 ; i < output.size() ; ++i) {
            cout << output[i] << ' ';
        }
        cout << endl;
        vector<int> input(N/2);
        for(int i = 0 ; i < N/2 ; ++i){
            cin >> input[i];
        }
        vector<int> half;
        vector<int> counter;
        long long sum = 0;
        for(int i = 0 ; i < input.size() ; ++i) {
            if(sum >= 0) {
                counter.push_back(input[i]);
                sum -= input[i];
            } else {
                half.push_back(input[i]);
                sum += input[i];
            }
        }
        if(sum >= 0) {
            for(int i = 0 ; i < 10 ; ++i) {
                if(sum%2 == 1) {
                    sum -= 1;
                }
                int base = 1 << (i*3);
                vector<int> cand = getHalf(base, sum % 8 + (8 * ((sum / 8) % 2)));
                for(int j = 0 ; j < cand.size() ; ++j) {
                    half.push_back(cand[j]);
                }
                sum /= 8;
            }
            for(int i = 0 ; i < half.size() ; ++i) {
                cout << half[i] << ' ';
            }
            cout << endl;
        } else {
            for(int i = 0 ; i < 10 ; ++i) {
                if(sum%2 == 1) {
                    sum += 1;
                }
                int base = 1 << (i*3);
                vector<int> cand = getHalf(base, abs(sum) % 8 + (8 * ((abs(sum) / 8) % 2)));
                for(int j = 0 ; j < cand.size() ; ++j) {
                    counter.push_back(cand[j]);
                }
                sum /= 8;
            }
            for(int i = 0 ; i < counter.size() ; ++i) {
                cout << counter[i] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}