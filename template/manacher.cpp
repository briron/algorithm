#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string S) {

    // $ 과 @ 을 앞뒤로 더하고 그 사이에 #을 넣어주어 새로운 문자열 T를 만든다.
    string T = "$";
    for(char c : S){
        T += '#';
        T += c;
    }
    T += "#@";

    // i 번째 문자를 중심으로 하는 가장 긴 palindrome 을 저장하는 vector를 만든다.
    vector<int> P(T.size());

    // 초기에 center과 right는 1 이다.
    // center 은 현재 영향을 미치는 것 중에 가장 긴 palindrome 의 가운데이다.
    // right 는 center 를 중심으로 palindrome 의 가장 오른쪽 위치이다.
    int center = 0, right = 0;
    int maxCenter = 0;

    // 처음부터 시작해서 끝까지 진행한다.
    // i 는 palindrome 을 구하는 가운데 지점이다.
    for(int i = 0 ; i < T.size() - 1; ++i){
        // mirror의 위치를 구하고 
        int mirror = center - (i - center);
        // 만약 right 보다 i 가 작으면 mirror 의 정보를 사용할 수 있다.
        // 다만, mirror 값의 전부를 가져갈 수는 없고, mirror의 정보와 그 정보의 한계(right-i)의 최소값을 P[i]로 한다.
        if(right > i){  
            P[i] = min(right - i, P[mirror]);
        }
        // 이제 중점에서부터 palindrome 의 길이를 확장한다. (앞에서 구해진 palindrome이 끝난 경우에는 P[i] = 0 부터 시작한다.)
        while (T[i + (1 + P[i])] == T[i - (1 + P[i])] ){
            ++P[i];
        }
        // while 문이 돌았다면 right는 증가할 수밖에 없어 시간복잡도는 O(N)이다.
        // 다시 설명하면, while 문이 도는 경우는, mirror 의 정보가 right 의 한계에 도달할 때밖에 없다. 그렇지 않은 경우에는 항상 while 문에 들어가지 못하고 false 로 끝난다.
        if(i + P[i] > right){
            center = i;
            right = i + P[i];
        }
        if(P[i] > P[maxCenter]){
            maxCenter = i;
        }
    }
    return S.substr( (maxCenter - P[maxCenter]) / 2, P[maxCenter]);
}


string longestPalindrome(string& s) {
    string p = "$";
    for(char c : s) {
        p += c;
        p += "#";
    }
    p += "@";
    vector<int> dp(p.size());
    int center = 0;
    int right = 0;
    int maxCenter = 0;
    for(int i = 0 ; i < p.size() ; ++i) {

    }
}








/*
string longestPalindrome(string s) {
    string t = "$";
    for(char c : s) {
        t += c;
        t += "#";
    }
    t += "@";
    vector<int> p(t.size());
    int center = 0;
    int right = 0;
    int maxCenter = 0;
    for(int i = 0 ; i < t.size() ; ++i) {
        int mirror = center - (i - center);
        if(i < right) {
            p[i] = min(p[mirror], right-i);
        }
        while(p[i-(p[i]+1)] == p[i+(p[i]+1)]) {
            p[i] += 1;
        }
        if(right < i + p[i]) {
            right = i + p[i];
            center = i;
        }
        if(p[i] > p[maxCenter]) {
            maxCenter = i;
        }
    }
    return s.substr( (maxCenter-p[maxCenter])/2 , p[maxCenter]);
}
*/

