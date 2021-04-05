#include <bits/c++std.h>

using namespace std;

typedef long long ll;

// new Version
// n 개의 원소가 포함된(혹은 n 개의 단위로 나뉜) 배열의 부분합 (0~i까지)
// segment tree 와 달리 init 과정이 없고, 모든 원소들을 각각 add 함수를 통해 업데이트 해야 함.
// bit 연산을 간단히 하기 위해서 n+1 개의 tree 배열을 만들어주고,
// sum, add 함수에서는 입력된 인덱스에 1을 더해 연산함
// sum 은 0~i 까지 구하는 연산이고 -> 1~i 까지의 합은 i가 11010 이라고 할 때, 11010 + 11000 + 10000 에 나눠져 있음
// add 는 i 를 업데이트 하는 연산이기 때문에 그 구조가 다르다 -> i가 영향을 미치는..
struct BIT{
    vector<int> tree;
    BIT(int n) : tree(n+1) {}
    int sum(int pos){
        pos += 1;
        int ret = 0;
        while(pos > 0){
            ret += tree[pos];
            pos -= (pos & -pos); // (pos & -pos) 는 최소 원소를 반환함
        }
        return ret;
    }
    void add(int pos, int val){
        pos += 1;
        while(pos < tree.size()){
            tree[pos] += val;
            pos += (pos & -pos);
        }
        return;        
    }
};

/* old version

struct FenwickTree{
    vector<int> tree;
    FenwickTree(int n) : tree(n) {}
    int sum(int pos){
        pos++;
        int ret = 0;
        while(pos > 0){
            ret += tree[pos];
            pos &= (pos-1);
        }
        return ret;
    }
    void add(int pos, int val){
        pos++;
        while(pos < tree.size()){
            tree[pos] += val
            pos += (pos & -pos)
        }
    }
};

*/