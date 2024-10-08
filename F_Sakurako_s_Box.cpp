#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

const int MOD = 1e9 + 7;

// Function to calculate modular inverse of a number under MOD
long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Calculate the sum of all elements
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    
    // Calculate the sum of all pairwise products
    long long sum_of_products = 0;
    for (int i = 0; i < n; i++) {
        sum_of_products = (sum_of_products + (a[i] * (sum - a[i])) % MOD) % MOD;
    }
    
    // The number of pairs is n * (n - 1) / 2
    long long num_pairs = n * (n - 1) / 2;
    
    // The expected value P * Q^-1 mod MOD
    long long result = (sum_of_products * modInverse(num_pairs, MOD)) % MOD;
    
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
