#include <iostream>
using namespace std;

const int MOD = 1000000007;
const int MAX = 4000000;

long long factorial[MAX+1];
long long mod_pow(long long base, long long power){
    long long result = 1;
    while (power>0){
        if (power%2 == 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        power /= 2;
    }
    return result;
}
long long binomial(int n, int k){
    if (k==0 || k==n) return 1;
    long long numerator = factorial[n];
    long long denominator = (factorial[k] * factorial[n-k]) % MOD;
    return (numerator * mod_pow(denominator, MOD - 2)) % MOD; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    factorial[0] = 1;
    for (int i=1; i<=N; i++){
        factorial[i] = (factorial[i-1]*i) % MOD;
    }

    cout << binomial(N, K) << '\n';
    return 0;
}