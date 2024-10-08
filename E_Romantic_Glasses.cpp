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

//same question as 525 lc woh 0101010 wala wahi count banake check kr rhe bas khud krdia poora               
bool solve(int n,vi a){
    long long count = 0;
    map<long long,long long>mp;
    mp[0] = 1;
    for(int i=0;i<a.size();i++){
        if(i%2 == 0){
            count += a[i];
        }else{
            count -= a[i];
        }
            if(mp[count]){
                return true;
            }
                mp[count]++;
    }
    return false;
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

        if(solve(n,a)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }             
    
}
