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
        int K;
        cin >> K;
        ll xsum = 0;
        ll ysum = 0;
        ll xhere = -1e9;
        ll yhere = -1e9;
        vector<ll> xvals;
        vector<ll> yvals;
        for(int k = 0 ; k < K ; ++k) {
            ll lx, ly, rx, ry;
            cin >> lx >> ly >> rx >> ry;
            xsum += lx - xhere;
            ysum += ly - yhere;
            xvals.push_back(lx);
            xvals.push_back(rx);
            yvals.push_back(ly);
            yvals.push_back(ry);
        }
        ll xminsum = xsum;
        ll yminsum = ysum;
        ll xret = 0;
        ll yret = 0;
        ll xcount = -K;
        ll ycount = -K;
        sort(xvals.begin(), xvals.end());
        sort(yvals.begin(), yvals.end());
        int idx = 0;
        while(idx < xvals.size()) {
            ll xgap = xvals[idx] - xhere;
            xhere = xvals[idx];
            xsum += xgap * xcount;
            if(xsum < xminsum) {
                xminsum = xsum;
                xret = xhere;
            }
            while(idx < xvals.size() && xhere == xvals[idx]) {
                xcount += 1;
                idx += 1;
            }
            if(xcount >= 0) {
                break;
            }
        }

        idx = 0;
        while(idx < yvals.size()) {
            ll ygap = yvals[idx] - yhere;
            yhere = yvals[idx];
            ysum += ygap * ycount;
            if(ysum < yminsum) {
                yminsum = ysum;
                yret = yhere;
            }
            while(idx < yvals.size() && yhere == yvals[idx]) {
                ycount += 1;
                idx += 1;
            }
            if(ycount >= 0) {
                break;
            }
        }

        cout << "Case #" << t << ": " << xret << " " << yret << endl;;
    }

    return 0;

}
