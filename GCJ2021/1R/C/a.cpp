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
        ll N, K;
        cin >> N >> K;
        vector<ll> sold(N);
        for(int i = 0 ; i < N ; ++i) {
            cin >> sold[i];
        }
        sort(sold.begin(), sold.end());
        priority_queue<vector<ll>> pq;
        for(int i = 0 ; i < sold.size(); ++i) {
            if(i == 0) {
                pq.push({sold[i]-1, 0});
            } else {
                pq.push({ (sold[i] - sold[i-1]) / 2 , (sold[i] - sold[i-1] - 1) / 2});
            }
        }
        pq.push({K-sold.back(),0});

        ll get = 0;
        vector<ll> first = pq.top();
        pq.pop();
        get += first[0];
        pq.push({first[1], 0});
        vector<ll> second = pq.top();
        get += second[0];

        double ret = (double)get / K;
        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}