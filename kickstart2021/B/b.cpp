#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int N;
        cin >> N;

        vector<int> nums(N);
        for(int i = 0 ; i < N ; ++i) {
            cin >> nums[i];
        }
        if(N <= 3) {
            cout << "Case #" << t << ": " << N << endl;        
            continue;
        }

        vector<int> gaps(N-1);
        vector<int> chain(N-1);
        for(int i = 0 ; i < N-1 ; ++i) {
            gaps[i] = nums[i+1] - nums[i];
        }

        int prev = INT_MAX;

        for(int i = N-2 ; i >= 0 ; --i) {
            if(prev == gaps[i]) {
                chain[i] = chain[i+1] + 1;
            }
            else {
                chain[i] = 1;
            }
            prev = gaps[i];
        }

        int count = 1;
        int ret = 1;

        for(int i = 1 ; i < gaps.size() ; ++i) {
            if(gaps[i-1] == gaps[i]) {
                count += 1;
                ret = max(ret, count);
            }
            else {
                if(i+2 < gaps.size() && gaps[i-1] == gaps[i+2] && gaps[i-1] + gaps[i+2] == gaps[i] + gaps[i+1]) {
                    count += (2 + chain[i+2]);
                } else if(i+1 < gaps.size() && gaps[i-1] * 2 == gaps[i] + gaps[i+1]) {
                    count += 2;
                } else {
                    count += 1;
                }
                ret = max(ret, count);
                count = 1;
            }
        }

        count = 1;

        for(int i = gaps.size() - 2 ; i >= 0 ; --i) {
            if(gaps[i] == gaps[i+1]) {
                count += 1;
                ret = max(ret, count);
            }
            else {
                if(i-2 >= 0 && gaps[i+1] == gaps[i-2] && gaps[i+1] + gaps[i-2] == gaps[i] + gaps[i-1]) {
                    count += (2 + chain[i-2]);
                } else if(i-1 >= 0 && gaps[i+1] * 2 == gaps[i] + gaps[i-1]) {
                    count += 2;
                } else {
                    count += 1;
                }
                ret = max(ret, count);
                count = 1;
            }
        }


        ret += 1;

        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}