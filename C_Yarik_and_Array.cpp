#include<bits/stdc++.h>
using namespace std ; 

# define int long long int 
# define vi vector<int> 
# define vs vector<string> 
# define vb vector<bool>
# define vv vector<vector<int>>
# define f(i,a,b) for(int i=a;i<b;i++)
# define fr(i,a,b) for(int i=a;i>b;i--)
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
                                        
bool parity_check(int a, int b) {
    // Returns true if a and b have different parity
    return (abs(a) % 2) != (abs(b) % 2);
}

int solve(int n, vi &a) {
    int current_sum = 0; 
    int max_sum = a[0];

    for(int i = 0; i < n; i++) {
        if (parity_check(a[i], a[i - 1])) {
            current_sum += a[i];
        } else {
            current_sum = a[i]; 
        }

        max_sum = max(max_sum, current_sum);

        if (current_sum < 0) {
            current_sum = 0; 
        }
    }

    return max_sum;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=0;
    cin>>T;
    while(T--){
        int n;
        in n;
        vi a(n);
        f(i,0,n){
            in a[i];
        }
        out solve(n,a) nl;
    }             
    return 0;
}