#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

bool allOne(string& s) {
    for(int i = 0 ; i < s.size() ; ++i) {
        if(s[i] == '0') {
            return false;
        }
    }
    return true;
}

string makeNot(string& s) {
    if(allOne(s)) {
        return "0";
    } else if(s == "0") {
        return "1";
    }
    string ret = "";
    bool leading = true;
    for(int i = 0 ; i < s.size() ; ++i) {
        if(s[i] == '0') {
            ret += '1';
            leading = false;
        } else if(s[i] == '1' && !leading) {
            ret += '0';
        }
    }
    return ret;
}

string makeMultiple(string& s) {
    if(s == "0") {
        return "0";
    }
    string ret = s;
    ret += '0';
    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        string S, E;
        cin >> S >> E;
        if(S == E) {
            cout << "Case #" << t << ": " << 0 << endl;
            continue;
        }

        int schange = 0;
        int echange = 0;
        char prev = '1';
        for(int i = 0 ; i < S.size() ; ++i) {
            if(prev != S[i]) {
                schange += 1;
            }
            prev = S[i];
        }
        if(prev == 1) {
            schange += 1;
        }

        prev = '1';
        for(int i = 0 ; i < E.size() ; ++i) {
            if(prev != E[i]) {
                echange += 1;
            }
            prev = E[i];
        }

//        if(echange > schange) {
//            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
//            continue;
//        }

        queue<pair<string, int>> q;
        q.push({S, 0});
        int ret = -1;
        unordered_set<string> visited;
        visited.insert(S);
        while(q.size() > 0) {
            pair<string, int> here = q.front();
            q.pop();
            if(here.second > 30) {
                ret = -1;
                break;
            }
            string reversed = makeNot(here.first);
            string multi = makeMultiple(here.first);
            if(visited.find(reversed) == visited.end()) {
                if(reversed == E) {
                    ret = here.second + 1;
                    break;
                }
                visited.insert(reversed);
                q.push({reversed, here.second + 1});
            }
            if(visited.find(multi) == visited.end()) {
                if(multi == E) {
                    ret = here.second + 1;
                    break;
                }
                visited.insert(multi);
                q.push({multi, here.second + 1});
            }
        }
        if(ret == -1) {
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
            continue;
        }
        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}