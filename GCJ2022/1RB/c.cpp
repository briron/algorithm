#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;


int main() {
    std::random_device rd;
    std::default_random_engine rng(rd());
 
    mt19937_64 mt(rd());
 
    uniform_int_distribution<int> range(0, 1);
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        cout << "00000000" << endl;
        int n;
        cin >> n;
        int a = 0;
        while(n != 0) {
             if(n == 8) {
                string s = "11111111";
                shuffle(s.begin(), s.end(), rng);
                cout << s << endl;
            } else if(a % 5 != 0 && a % 5 != 2 && a % 5 != 4) {
                string s = "";
                for(int i = 0 ; i < 8 ; ++i) {
                    if(range(mt) % 2) {
                        s += "0";
                    } else {
                        s += "1";
                    }
                }
                cout << s << endl;
            } else if(n == 7) {
                string s = "11111110";
                if(range(mt) % 2 == 0) {
                    s = "11000000";
                }
                shuffle(s.begin(), s.end(), rng);
                cout << s << endl;
            } else if(n == 6) {
                string s = "11111100";
                if(range(mt) % 2 == 0) {
                    s = "10000000";
                }
                shuffle(s.begin(), s.end(), rng);
                cout << s << endl;
            } else if(n == 5) {
                string s = "11111000";
                if(range(mt) % 2 == 0) {
                    s = "11100000";
                }
                shuffle(s.begin(), s.end(), rng);
                cout << s << endl;
            } else if(n == 4) {
                string s = "11110000";
                shuffle(s.begin(), s.end(), rng);
                cout << s << endl;
            } else if(n == 3) {
                string s = "11111000";
                if(range(mt) % 2 == 0) {
                    s = "11100000";
                }
                shuffle(s.begin(), s.end(), rng);
                cout << s << endl;
            } else if(n == 2) {
                string s = "11111100";
                if(range(mt) % 2 == 0) {
                    s = "10000000";
                }
                shuffle(s.begin(), s.end(), rng);
                cout << s << endl;
            } else if(n == 1) {
                string s = "11111110";
                if(range(mt) % 2 == 0) {
                    s = "10000000";
                }
                shuffle(s.begin(), s.end(), rng);
                cout << s << endl;
            }
            a += 1;
            cin >> n;
        }
    }
    return 0;
}