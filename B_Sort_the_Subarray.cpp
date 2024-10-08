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
                                        
vector<pair<int, int>> solve(int n, vector<int>& a, vector<int>& b) {
    vector<pair<int, int>> ans;
    
        int l = 0, r = n - 1;
 
    while (a[l] == b[l]){
        l++;
    }
    while (a[r] == b[r]){
        r--;
    }
    while (l > 0 && b[l] >= b[l - 1]){
        l--;
    }
    while (r < n - 1 && b[r] <= b[r + 1]){
        r++;
    }
    ans.push_back({l+1,r+1});
    return ans;
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
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        vector<pair<int, int>> result = solve(n, a, b);
        for (auto& p : result) {
            cout << p.first << " " << p.second << "\n";
        }
    }             
    return 0; 
}