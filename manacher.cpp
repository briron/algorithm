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

    int center = 0, right = 0;
    int maxCenter = 0;

    // (굳이 0을 할 필요는 없다) 1부터 시작해서, 끝까지 진행한다.
    for(int i = 1 ; i < T.size() - 1; ++i){
        // mirror의 위치를 구하고
        int mirror = 2 * center - i;
        // mirror의 정보와 그 정보의 한계의 최소값을 P[i]로 한다.
        if(right > i){  
            P[i] = min(right - i, P[mirror]);
        }
        // 앞에서 구해진 palindrome이 끝난 경우에는 P[i] = 0 부터 시작한다.
        while (T[i + (1 + P[i])] == T[i - (1 + P[i])] ){
            ++P[i];
        }
        // while 문이 돌았다면 right는 증가할 수밖에 없어 시간복잡도는 O(N)이다.
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




