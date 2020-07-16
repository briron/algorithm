#include <bits/stdc++.h>

using namespace std;

vector<int> getPi(const string& N){
    int n = N.size();
    int begin = 1, matched = 0;
    vector<int> pi(n);
    while(begin + matched < n){
        if(N[begin+matched] == N[matched]){
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else{
            if(matched == 0) ++begin;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

vector<int> kmp(const string& H, const string& N){
    int h = H.size(), n = N.size();
    int begin = 0, matched = 0;
    vector<int> pi = getPi(N);
    vector<int> ret;
    while(begin <= h - n){
        if(matched < n && H[begin+matched] == N[matched]){
            ++matched;
            if(matched == n) ret.push_back(begin);
        }
        else{
            if(matched == 0) begin += 1;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}