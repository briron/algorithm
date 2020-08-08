// Problem C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0 ; i < t; ++i){
        ll N;
        cin >> N;
        
        unordered_map<int,int> m;
        int maxCount = 0;
        for(int i = 0 ; i < N; ++i){
            int a;
            cin >> a;
            m[a] += 1;
            maxCount = max(maxCount, m[a]);
        }
        if(maxCount > (N+1)/2){
            cout << 0 << endl;
            continue;
        }
        int group = 0;
        for(auto it = m.begin(); it != m.end(); ++it){
            if(it->second == maxCount){
                group += 1;
            }
        }
        int left = N - group * maxCount;
        int ret = left / (maxCount - 1) + group - 1;
        cout << ret << endl;
    }

    return 0;
}