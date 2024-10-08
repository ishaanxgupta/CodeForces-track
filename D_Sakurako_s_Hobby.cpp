#include <bits/stdc++.h>
using namespace std;

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
                                        

vector<int> solve(int n, vector<int>& p, const string& s) {
    vector<int> result(n, 0);
    vector<bool> check(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!check[i]) {
            vector<int> cycle;
            int curr = i;
            
            while (!check[curr]) {
                check[curr] = true;
                cycle.push_back(curr);
                curr = p[curr];
            }
            
            int black_cnt = 0;
            for (int index : cycle) {
                if (s[index] == '0') {
                    black_cnt++;
                }
            }
            
            for (int index : cycle) {
                result[index] = black_cnt;
            }
        }
    }
    
    return result;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        string s;
    
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--; 
        }
        cin >> s;
        
        vector<int> ans = solve(n, p, s);
        
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}