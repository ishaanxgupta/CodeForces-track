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
                                        

    int solve(int n,int k,vi a){

    sortv(a);
    int min_1 = 0;
    int min_2 = 1;
    int maxi = n-1;
    int sum = 0;
    f(i,0,n){
       sum += a[i];
    }
    // if(min1+min2=<maxi){
    //     k--;
    //     sum = sum - min1 - min2;
    // }else{
    //     k--;
    //     sum = sum - maxi;
    // }
   while(k > 0 ) {
        if(a[min_1] + a[min_2] <= a[maxi]) {
            sum -= (a[min_1] + a[min_2]);
            min_1 += 2;
            min_2 += 2;
        } else {
            sum -= a[maxi];
            maxi--;
        }
        k--;
    }
       return sum;
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
        int k;
        in k;
        vi a(n);
        f(i,0,n){
            in a[i];
        }
        out solve(n,k,a) nl;
    }             
    return 0; 
    }