#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int main() {
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; ++i) {
            cin >> arr[i];
        }
        vector<bool> willPay(N, false);
        int leftMax = 0;
        for(int i = 0 ; i < N ; ++i) {
            if(arr[i] >= leftMax) {
                willPay[i] = true;
            }
            leftMax = max(leftMax, arr[i]);
        }
        int rightMax = 0;
        for(int i = N-1 ; i >= 0 ; --i) {
            if(arr[i] >= rightMax) {
                willPay[i] = true;
            }
            rightMax = max(rightMax, arr[i]);
        }

        int ret = 0;
        for(int i = 0 ; i < N ; ++i) {
            if(willPay[i]) {
                ret += 1;
            }
        }

        cout << "Case #" << t << ": " << ret << endl;
    }
    return 0;
}