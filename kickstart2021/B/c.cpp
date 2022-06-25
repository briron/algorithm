#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

bool checkPrime(ll num, vector<ll>& primes) {
    for(ll& prime : primes) {
        if(num == prime) {
            return true;
        }
        if(num % prime == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    vector<bool> isPrimes(100000, true);
    vector<ll> primes;
    for(ll i = 2 ; i < isPrimes.size() ; ++i) {
        if(isPrimes[i]) {
            primes.push_back(i);
            for(ll j = i * 2 ; j < isPrimes.size() ; j += i) {
                isPrimes[j] = false;
            }
        }
    }
    

    for(int t = 1 ; t <= T ; ++t) {
        ll Z;
        cin >> Z;
        ll sq = (ll)sqrt(Z);
        ll prime1 = 0;
        ll prime2 = 0;
        ll prime3 = 0;
        for(ll i = sq; i >= 0 ; --i) {
            if(checkPrime(i, primes)) {
                if(prime2 == 0) {
                    prime2 = i;
                } else {
                    prime1 = i;
                    break;
                }
            }
        }
        for(ll i = sq + 1; i < Z; ++i) {
            if(checkPrime(i, primes)) {
                prime3 = i;
                break;
            }
        }

        if(prime2 * prime3 <= Z) {
            cout << "Case #" << t << ": " << prime2 * prime3 << endl;
            continue;
        }
        cout << "Case #" << t << ": " << prime1 * prime2 << endl;
    }

    return 0;

}