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
const int MAX = 1e6;


   // wahi hai adha check krlo ki adha agar map mein mil gya toh bas woh index+1 daldo kyonki jaise 8 5 2 3 hai toh total sum mein se 8 minus kiya toh fir bacha sum 10 ab 5 agar map mein hota tbhi toh kaam banega
   //ismein yeh wala case ho skta na 5 5 2 3 ya 5 6 4 agar 5 6 4 hai toh fir 5 pe jab honge toh remaining sum 5 hoga aur 5 map mein mil jayega toh fir dikkat ho jayegi na
   //isliye woh check krwadiya bas dry run krke dekho smjh aa jayega baaki khud hi sochlia tha poora                                   
vector<int> solve(int n, vi &a) {
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += a[i];
    }
    
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    // for(auto it:a){
    //     cout<<it<<endl;
    // }
    // for(auto it:mp){
    //     cout<<it.first;
    //     cout<<it.second<<endl;
    // }
    
    vi ans;
      for (int i = 0; i < n; i++) {
        long long temp = total_sum - a[i];
        //yaha pe temp/2 <= MAX dalna zaroori tha wrna ni chalta woh bc chutiya hai hai kuch chodho
           if (temp % 2 == 0 && temp / 2 <= MAX && mp.find(temp / 2) != mp.end()) {
            if (temp / 2 != a[i] || mp[temp / 2] > 1) {
                ans.push_back(i + 1); 
            }
        }
    }
    
    return ans;
    }
    
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    in n;
    vi a(n);
    f(i,0,n){
        in a[i];
    }
    vi ans1 = solve(n,a);
    // if(ans1.size() == 0){
    //     cout<<0<<endl;
    // }else{
    cout<<ans1.size()<<endl;

    f(i,0,ans1.size()){
        cout<< ans1[i]<<" ";
    }           
    
}