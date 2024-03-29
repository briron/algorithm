#include <bits/stdc++.h>
using namespace std;
/*

vector<int> getPi(string& N){
    int n = N.size();
    int begin = 1, matched = 0;
    vector<int> pi(n+1);
    while(begin + matched < n){
        if(N[begin+matched] == N[matched]){
            ++matched;
            pi[begin+matched] = matched;
        }
        else{
            if(matched==0){
                begin += 1;
            }
            else{
                begin += matched - pi[matched];
                matched = pi[matched];
            }
        }
    }
    return pi;
}

vector<int> kmp(string& H, string& N){
    int h = H.size(), n = N.size();
    int begin = 0, matched = 0;
    vector<int> pi = getPi(N);
    vector<int> ret;
    while(begin <= h-n){
        if(matched < n && H[begin+matched] == N[matched]){
            ++matched;
            if(matched == n) ret.push_back(begin);
        }
        else{
            if(matched == 0){
                begin += 1;
            }
            else{
                begin += matched - pi[matched];
                matched = pi[matched];
            }
        }
    }
    return ret;
}

vector<int> getPi(string& N){
    int n = N.size();
    vector<int> pi(n+1);
    int begin = 1;
    int matched = 0;
    while(matched + begin < n){
        if(N[begin + matched] == N[matched]){
            ++matched;
            pi[begin + matched] = matched;
        }
        else{
            if(matched == 0){
                begin += 1;
            }
            else{
                begin += (matched - pi[matched]);
                matched = pi[matched];
            }
        }
    }
    return pi;
}

vector<int> kmp(string& H, string& N){
    int h = H.size();
    int n = N.size();
    vector<int> pi = getPi(N);
    int begin = 0;
    int matched = 0;
    vector<int> ret;
    while(begin <= h - n){
        if(matched < n && H[begin+matched] == N[matched]){
            matched += 1;
            if(matched == N){
                ret.push_back(begin);
            }
        }
        else{
            if(matched == 0){
                begin += 1;
            }
            else{
                begin += matched - pi[matched];
                matched = pi[matched];
            }
        }
    }
    return ret;
}
*/

struct Comparator {
    int t;
    vector<int>& group;
    Comparator(int _t, vector<int>& _g) : t(_t), group(_g) {}
    bool operator()(int a, int b) {
        if(group[a] != group[b]){
            return group[a] < group[b];
        }
        return group[a+t] < group[b+t]; 
    }
};

vector<int> suffixArray(string& S){
    int s = S.size();
    int t = 1;
    vector<int> group(s+1);
    vector<int> rank(s);
    for(int i = 0 ; i < s ; ++i){
        rank[i] = i;
    }
    for(int i = 0 ; i < s ; ++i){
        group[i] = S[i];
    }
    while(t < s){
        Comparator compareUsing2T(t, group);
        sort(rank.begin(), rank.end(), compareUsing2T);
        t *= 2;
        if(t >= s) break;
        vector<int> newGroup(s+1);
        int index = 1;
        newGroup[rank[0]] = index;
        for(int i = 0 ; i < s-1; ++i){
            if(compareUsing2T(rank[i],rank[i+1])){
                index++;
            }
            newGroup[rank[i+1]] = index;
        }
        group = newGroup;
   }
    return rank;
}

vector<int> getSuffixArray(string& s) {
    int N = s.size();
    vector<int> ranks(N);
    vector<int> group(N+1);
    for(int i = 0 ; i < ranks.size() ; ++i) {
        ranks[i] = i;
    }
    for(int i = 0 ; i < group.size() ; ++i) {
        group[i] = s[i];
    }
    int t = 1;
    while(t < N) {
        Comparator cp(t, group);
        sort(ranks.begin(), ranks.end(), cp);
        t *= 2;
        if(t >= N) {
            break;
        }
        vector<int> newGroup(N+1);
        int val = 1;
        newGroup[ranks[0]] = val;
        for(int i = 1 ; i < N ; ++i) {
            if(cp(ranks[i-1], ranks[i])) {
                val += 1;
            }
            newGroup[ranks[i]] = val;
        }
        group = newGroup;
    }
    return ranks;
}


int main(){
    string H = "banana";
    vector<int> ret = getSuffixArray(H);
    for(int i = 0 ; i < ret.size(); ++i){
        cout << ret[i] << " : " << H.substr(ret[i]) << endl;
    }
    return 0;
}
