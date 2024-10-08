#include<bits/stdc++.h>
using namespace std ; 

# define int long long int 
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

//easy hai bas wahi hai symmetric points dekhlo krdia tha crack easily
int solve(int n, vector<vector<char>>& grid) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int s = grid[i][j] + grid[j][n-i-1] + grid[n-i-1][n-j-1] + grid[n-j-1][i];
            ans += min(s, 4 - s);
        }
    }
    return ans / 4;
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
        vector<vector<char>> grid(n, vector<char>(n));
        f(i,0,n) {
            f(j,0,n) {
                char c;
                cin >> c;
                grid[i][j] = c - '0';
            }
        }
        cout << solve(n, grid) << endl;
    }
    return 0;
}
