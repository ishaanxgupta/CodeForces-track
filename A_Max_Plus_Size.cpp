#include<bits/stdc++.h>
using namespace std ; 

// # define int long long int 
# define vi vector<int> 
# define vs vector<string> 
# define vv vector<vector<int>>
# define f(i,a,b) for(int i=a;i<b;i++)
# define in cin>>
# define out cout<<
# define nl <<endl;
# define input(arr) fr(0,arr.size()) in arr[i] 
# define output(arr) fr(0,arr.size()) out arr[i]<<' ' 
# define mod 1e9+7
# define ps(x,y) fixed<<setprecision(y)<<x
# define setbits(x) __builtin_popcountll(x)
# define zrobits(x) __builtin_ctzll(x)
# define inf 1e18
# define sortv(a) sort(a.begin(),a.end())
                                        
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
bool isprime(int x){for(int i=2;i*i<=x;i++) if(x%i==0) return 0 ;return (x==1? 0 : 1);}

vector<vector<int>> dp;
int recursion(int index, const vi& a, int n, int maxVal) {
    if (index >= n) {
        return maxVal;
    }

    if (dp[index][maxVal] != 1e9) {
        return dp[index][maxVal];
    }

    int take = recursion(index + 2, a, n, max(maxVal, a[index])) + 1;
    int ntake = recursion(index + 1, a, n, maxVal);
    return dp[index][maxVal] = max(take, ntake);
}

int solve(int n, vi a) {
    dp.assign(n + 1, vector<int>(1001, 1e9));  
    return recursion(0, a, n, 0);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 0;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(n, a) << endl;
    }

    return 0;
}