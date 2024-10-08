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
                                        
int solve(int n,vi entry,vi exit){
    reverse(entry.begin(),entry.end());
    reverse(exit.begin(),exit.end());
    vi car_ke_aage_wali_car1(n,0);
    vi car_ke_aage_wali_car2(n,0);
    int count1 = 0;
    for(int x=n-1;x>=0;x--){
        car_ke_aage_wali_car1[entry[x] - 1] = count1;
        count1++;
    }
    int count2 = 0;
    for(int x=n-1;x>=0;x--){
        car_ke_aage_wali_car2[exit[x] - 1] = count2;
        count2++;
    }
    int ans = 0;
    int i = n-1;
while(i>=0){
    int diff = car_ke_aage_wali_car2[exit[i]]-car_ke_aage_wali_car1[exit[i]];
    if(diff<0){
        ans++;
    }
    int temp = diff;
    i--;

}
    return ans;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    in n;
    vi entry(n);
    vi exit(n);
    f(i,0,n){
        in entry[i];
    }
    f(i,0,n){
        in exit[i];
    }
    cout<<solve(n,entry,exit)<<endl;             
}