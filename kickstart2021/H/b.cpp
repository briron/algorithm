#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    unordered_set<char> R;
    unordered_set<char> Y;
    unordered_set<char> B;
    R.insert('R');
    R.insert('O');
    R.insert('P');
    R.insert('A');

    Y.insert('Y');
    Y.insert('O');
    Y.insert('G');
    Y.insert('A');

    B.insert('B');
    B.insert('G');
    B.insert('P');
    B.insert('A');

    for(int t = 1 ; t <= T ; ++t) {
        int N;
        cin >> N;
        string P;
        cin >> P;

        int count = 0;
        for(int i = 0 ; i < P.size() ; ++i) {
            if(R.find(P[i]) != R.end()) {
                if(i == 0 || R.find(P[i-1]) == R.end()) {
                    count += 1;
                }
            } 
            if(Y.find(P[i]) != Y.end()) {
                if(i == 0 || Y.find(P[i-1]) == Y.end()) {
                    count += 1;
                }
            } 
            if(B.find(P[i]) != B.end()) {
                if(i == 0 || B.find(P[i-1]) == B.end()) {
                    count += 1;
                }
            } 
        }

        cout << "Case #" << t << ": " << count << endl;;
    }

    return 0;

}
