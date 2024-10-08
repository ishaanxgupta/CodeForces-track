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

/*If there is at least a prefix or a suffix with non-positive sum, we can delete that prefix/suffix and end up with an array with sum ≥
the sum of the whole array. So, if that's the case, the answer is "NO".
Otherwise, all the segments that Adel can choose will have sum <
than the sum of the whole array because the elements that are not in the segment will always have a strictly positive sum. So, in that case, the answer is "YES".*/    

bool solve(int n,vi a){
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
        if(sum <= 0) return 0;
    }
    sum = 0;
    for(int i = n - 1 ; i >= 0 ; i--){
        sum += a[i];
        if(sum <= 0) return 0;
    }
    return 1;
    
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n;
        in n;
        vi a(n);
        f(i,0,n){
            in a[i];
        }
        if(solve(n,a)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }             
    return 0;
}