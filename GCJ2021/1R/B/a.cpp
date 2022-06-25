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
        ll A, B, C;
        cin >> A >> B >> C;

        ll Q = 12 * 60 * 60 * (ll)1e9;

        ll h = 0;
        ll m = 0;
        ll s = 0;
        ll nano = 0;

        if(A * 12 % Q == B && A * 720 % Q == C) {
            h = A / (Q/12);
            m = B / (Q/60);
            s = C / (Q/60);
        } 

        else if(A * 12 % Q == C && A * 720 % Q == B) {
            h = A / (Q/12);
            m = C / (Q/60);
            s = B / (Q/60);
        }

        else if(B * 12 % Q == C && B * 720 % Q == A) {
            h = B / (Q/12);
            m = C / (Q/60);
            s = A / (Q/60);
        }

        else if(B * 12 % Q == A && B * 720 % Q == C) {
            h = B / (Q/12);
            m = A / (Q/60);
            s = C / (Q/60);
        }
        
        else if(C * 12 % Q == A && C * 720 % Q == B) {
            h = C / (Q/12);
            m = A / (Q/60);
            s = B / (Q/60);
        }

        else {
            h = C / (Q/12);
            m = B / (Q/60);
            s = A / (Q/60);
        }

        cout << "Case #" << t << ": " << h << " " << m << " " << s << " " << nano << endl;


    }

    return 0;

}