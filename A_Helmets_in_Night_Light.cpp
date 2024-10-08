#include<bits/stdc++.h>
using namespace std ; 

# define int long long int 
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
                                        
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
bool isprime(int x){for(int i=2;i*i<=x;i++) if(x%i==0) return 0 ;return (x==1? 0 : 1);}
                                        
void solve(int N,int pak_chanek_cost,vi a,vi b){
    int ans = 0;
    if(ans > pak_chanek_cost*N){
        return pak_chanek_cost*N;
    }
    
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int N;
        in N;
        int pak_chanek_cost;
        in pak_chanek_cost;
        vi a;
        f(i,0,N){
            in a[i] nl;
        }
        vi b;
        f(i,0,N){
            in b[i] nl;
        }
        solve(N,pak_chanek_cost,a,b);
    }             
   return 0; 
}