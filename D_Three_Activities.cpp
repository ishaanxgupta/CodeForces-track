#include<bits/stdc++.h>
using namespace std ; 

//bekar quesiton hai chodho

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
# define MIN INT_MIN;
# define MAX INT_MAX; 
                                        
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
bool isprime(int x){for(int i=2;i*i<=x;i++) if(x%i==0) return 0 ;return (x==1? 0 : 1);}
                                        
void solve(int n,vi a,vi b,vi c){
    vi visited(n,0);
    vector<pair<int,int>>store(3);
    int max_a = MIN;
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
           in a[i] nl
        }

        vi b(n);
        f(i,0,n){
            in b[i] nl;
        }

        vi c(n);
        f(i,0,n){
            in c[i] nl;
        }
        solve(n,a,b,c);
    }             
   return 0; 
}
