#include <bits/stdc++.h>

using namespace std;

class Karatsuba {
private:
    void normalize(vector<int>& num) {
        num.push_back(0);
        for(int i = 0 ; i < num.size() ; ++i) {
            if(num[i] < 0) {
                int borrow = (abs(num[i])) / 10 + 1;
                num[i+1] -= borrow;
                num[i] += borrow * 10;
            } else {
                num[i+1] += num[i] / 10;
                num[i] %= 10;
            }
        }
        while(num.size() > 1 && num.back() == 0) {
            num.pop_back();
        }
    }

    void addTo(vector<int>& a, const vector<int>& b, int k) {
        while((int)a.size() >= (int)b.size() + k) {
            a.push_back(0);
        }
        for(int i = 0 ; i < b.size() ; ++i) {
            a[i+k] += b[i];
        }
        normalize(a);
    }

    void subFrom(vector<int>& a, const vector<int>& b) {
        for(int i = 0 ; i < b.size() ; ++i) {
            a[i] -= b[i];
        }
        normalize(a);
    }
public:
    vector<int> multiply(const vector<int>& a, const vector<int>& b) {
        int n = a.size();
        int m = b.size();
        if(n < m) {
            return multiply(b, a);
        }
        if(n == 0) {
            return vector<int>();
        }
        if(n == 1) {
            return vector<int>{a[0] * b[0] / 10, a[0] * b[0] % 10};
        }
        int half = n / 2;
        vector<int> a0(a.begin(), a.begin() + half);
        vector<int> a1(a.begin() + half, a.end());
        vector<int> b0(b.begin(), b.begin() + half);
        vector<int> b1(b.begin() + half, b.end());

        vector<int> z0 = multiply(a0, b0);
        vector<int> z2 = multiply(a1, b1);
        addTo(a0, a1, 0);
        addTo(b0, b1, 0);
        vector<int> z1 = multiply(a0, b0);
        subFrom(z1, z0);
        subFrom(z1, z2);
        vector<int> ret;
        addTo(ret, z0, 0);
        addTo(ret, z1, half);
        addTo(ret, z2, half*2);
        return ret;
    }

};