#include <bits/stdc++.h>
using namespace std;

//iska recursion chal rha memoized ni chal rha ptani kyu recrusion dekh nice one

#define vi vector<int>
#define vs vector<string>
#define vv vector<vector<int>>
#define f(i,a,b) for(int i=a;i<b;i++)
#define in cin >>
#define out cout <<
#define nl << endl;
#define input(arr) f(i,0,arr.size()) in arr[i]
#define output(arr) f(i,0,arr.size()) out arr[i] << ' '
#define mod 1e9+7
#define ps(x,y) fixed << setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf 1e18
#define sortv(a) sort(a.begin(), a.end())

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool isprime(int x) {
    for (int i = 2; i * i <= x; i++) 
        if (x % i == 0) return false;
    return (x == 1 ? false : true);
}

int recursion(vi &numbers, int n, int k, int index, int count, vv &dp) {
    //base case
    int mul = 1;
    for (int i = 0; i < n; i++) {
        mul *= numbers[i];
        if (mul % k == 0) {
            return count;
        }
        if (mul >= inf) {
            break;
        }
    }

    if (index == n) {
        return INT_MAX;
    }

    if (dp[index][count] != -1) {
        return dp[index][count];
    }

    int not_increase = recursion(numbers, n, k, index + 1, count, dp);
    
    numbers[index]++;
    int increase = recursion(numbers, n, k, index, count + 1, dp);
    numbers[index]--; 

    return dp[index][count] = min(increase, not_increase);
}

int solve(int n, int k, vi numbers) {
    vv dp(n, vi(1000, -1)); 
    return recursion(numbers, n, k, 0, 0, dp);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        in n;
        int k;
        in k;
        vi numbers(n);
        f(i, 0, n) {
            in numbers[i];
        }
        int ans = solve(n, k, numbers);
        out ans nl;
    }             
    
    return 0;
}
