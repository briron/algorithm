#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int main() {
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int N, K;
        cin >> N >> K;
        int gap = N*N-1-K;
        vector<int> shortcut;
        int start = 8 * ((N/2) - 1);
        if(gap % 2 == 1) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        for(int i = start ; i >= 0 ; i -= 8) {
            if(gap >= i) {
                gap -= i;
                shortcut.push_back(i + 1);
            }
        }
        for(int i = 0 ; i < shortcut.size() ; ++i) {
            if(gap > 0) {
                shortcut[i] += min(gap, 6);
                gap -= min(gap, 6);
            }
        }

        if(gap > 0) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
            continue;
        } 

        if(shortcut.size() > 0 && shortcut.back() == 1) {
            shortcut.pop_back();
        }

        cout << "Case #" << t << ": " << (int)shortcut.size() << endl;
        for(int i = 0 ; i < shortcut.size() ; ++i) {
            int idx = ((N/2)-1) - shortcut[i] / 8;
            int line = (N-1) - idx * 2;
            int base = N * N - (line - 1) * (line - 1) - line * 4 + 2; 
            if(shortcut[i] % 8 == 1) {
                cout << base + line * 3 << ' ' << base + line * 3 + shortcut[i] << endl;
            } else if(shortcut[i] % 8 == 3) {
                cout << base + line * 2 << ' ' << base + line * 2 + shortcut[i] << endl;
            } else if(shortcut[i] % 8 == 5) {
                cout << base + line * 1 << ' ' << base + line * 1 + shortcut[i] << endl;
            } else if(shortcut[i] % 8 == 7) {
                cout << base << ' ' << base + shortcut[i] << endl;
            }
        }
    }
    return 0;
}