#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

vector<int> makeOutput() {
    vector<int> output;
    for(int i = 0 ; i <= 29 ; ++i) {
        output.push_back(1 << i);
    }
    int sum = 0;
    for(int i = 1 ; i <= 69 ; ++i) {
        output.push_back((1 << 20) + (1 << 1) * i);
        sum += ((1 << 20) + (1 << 1) * i);
    }
    output.push_back(sum);
    return output;
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
        vector<int> input(N);
        for(int i = 0 ; i < N ; ++i){
            cin >> input[i];
        }
        vector<int> half;
        vector<int> counter;
        long long halfSum = 0;
        long long counterSum = 0;
        for(int i = 0 ; i < input.size() ; ++i) {
            if(halfSum >= counterSum) {
                counter.push_back(input[i]);
                counterSum += input[i];
            } else {
                half.push_back(input[i]);
                halfSum += input[i];
            }
        }
        for(int i = 29 ; i >= 0; --i) {
            if(halfSum >= counterSum) {
                counterSum += (1 << i);
                counter.push_back(1 << i);
            } else {
                halfSum += (1 << i);
                half.push_back(1 << i);
            }
        }
        long long sum = 0;
        for(int i = 0 ; i < half.size() ; ++i) {
            sum += half[i];
        }
        for(int i = 0 ; i < counter.size() ; ++i) {
            sum -= counter[i];
        }
        for(int i = 1 ; i <= 69 ; ++i) {
            half.push_back((1 << 20) + (1 << 1) * i);
        }
        for(int i = 0 ; i < half.size() ; ++i) {
            cout << half[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}