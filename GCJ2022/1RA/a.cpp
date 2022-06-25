#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int main() {
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        string s;
        cin >> s;
        vector<pair<char, int>> chain;
        for(int i = 0 ; i < s.size() ; ++i){
            chain.push_back(make_pair(s[i], 1));
            while(i+1 < s.size() && s[i] == s[i+1]) {
                chain.back().second += 1;
                ++i;
            }
        }
        string ret;
        for(int i = 0 ; i < chain.size() - 1 ; ++i) {
            if(chain[i].first < chain[i+1].first) {
                for(int j = 0 ; j < chain[i].second * 2 ; ++j) {
                    ret += chain[i].first;
                }
            } else {
                for(int j = 0 ; j < chain[i].second ; ++j) {
                    ret += chain[i].first;
                }
            }
        }
        for(int i = 0 ; i < chain.back().second ; ++i) {
            ret += chain.back().first;
        }
        cout << "Case #" << t << ": " << ret << endl;
    }
    return 0;
}