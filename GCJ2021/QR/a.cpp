#include <bits/stdc++.h>

using namespace std;

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
        int ret = 0;
        for(int i = 0 ; i < N-1; ++i) {
            int pos = i;
            for(int j = i ; j < N ; ++j) {
                if(i+1 == arr[j]) {
                    pos = j;
                    break;
                }
            }
            reverse(arr.begin() + i, arr.begin() + pos + 1);
            ret += (pos - i) + 1;
        }
        cout << "Case #" << t << ": " << ret << endl;
    }
    return 0;
}
