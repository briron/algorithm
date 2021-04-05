#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int N, C;
        cin >> N >> C;
        if(C < N-1 || C > (N-1) + N*(N-1)/2) {
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
            continue;
        }
        C -= N-1;
        vector<bool> swapped(N);

        for(int i = N-1 ; i > 0 ; --i) {
            if(C >= i) {
                C -= i;
                swapped[N-1-i] = true;
            }
        }

        vector<int> arr(N);
        for(int i = 0 ; i < arr.size() ; ++i) {
            arr[i] = i+1;
        }

        for(int i = swapped.size() - 1; i >= 0 ; --i) {
            if(swapped[i]) {
                reverse(arr.begin() + i, arr.end());
            }
        }


        cout << "Case #" << t << ": ";
        for(int i = 0 ; i < arr.size(); ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
