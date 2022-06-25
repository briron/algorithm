#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int main() {
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int R, C;
        cin >> R >> C;

        cout << "Case #" << t << ":" << endl;

        cout << "..+";
        for(int c = 0 ; c < C-1 ; ++c) {
            cout << "-+";
        }
        cout << endl;

        cout << ".";
        for(int c = 0 ; c < C ; ++c) {
            cout << ".|";
        }
        cout << endl;

        for(int r = 0 ; r < 2*R - 1 ; ++r) {
            if(r%2 == 0) {
                cout << "+";
            } else {
                cout << "|";
            }
            for(int c = 0 ; c < C ; ++c) {
                if(r%2 == 0) {
                    cout << "-+";
                } else {
                    cout << ".|";
                }
            }
            cout << endl;
        }
    }
}