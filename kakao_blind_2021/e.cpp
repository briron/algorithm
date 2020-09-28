#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll stringToInt(string& time){
    ll h = stoi(time.substr(0, 2)) * 60 * 60;
    ll m = stoi(time.substr(3, 2)) * 60;
    ll s = stoi(time.substr(6, 2));
    return h + m + s;
}

string IntToString(ll num){
    string ret = "";
    ll h = num / (60 * 60);
    if(h < 10){
        ret += "0";
    }
    ret += to_string(h);
    ret += ":";

    num %= (60 * 60);
    ll m = num / 60;
    if(m < 10){
        ret += "0";
    }
    ret += to_string(m);
    ret += ":";

    num %= 60;
    ll s = num;
    if(s < 10){
        ret += "0";
    }
    ret += to_string(s);

    return ret;

}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    ll play_time_int = stringToInt(play_time);
    ll adv_time_int = stringToInt(adv_time);
    map<ll, ll> m;
    for(ll i = 0 ; i < logs.size(); ++i){
        string start_string = logs[i].substr(0, 8);
        string end_string = logs[i].substr(9, 8);
        ll start = stringToInt(start_string);
        ll end = stringToInt(end_string);
        m[start] += 1;
        m[end+1] -= 1;
    }

    ll cum = 0;
    ll cur = 0;
    for(ll i = 0 ; i <= adv_time_int; ++i){
        cur += m[i];
        cum += cur;
    }
    ll ret_start = 0;
    ll ret_cum = cum;
    for(ll i = adv_time_int + 1; i <= play_time_int; ++i){
        cur += m[i];
        cur -= m[i-adv_time_int-1];
        cum += cur;
        if(ret_cum < cum){
            ret_cum = cum;
            ret_start = i - adv_time_int;
        }
    }

    string ret = IntToString(ret_start);

    return ret;

}