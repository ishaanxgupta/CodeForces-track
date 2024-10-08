// #include<bits/stdc++.h>
// using namespace std ; 

// // # define int long long int 
// # define vi vector<int> 
// # define vs vector<string> 
// # define vv vector<vector<int>>
// # define f(i,a,b) for(int i=a;i<b;i++)
// # define in cin>>
// # define out cout<<
// # define nl <<endl;
// # define input(arr) fr(0,arr.size()) in arr[i] 
// # define output(arr) fr(0,arr.size()) out arr[i]<<' ' 
// # define mod 1e9+7
// # define ps(x,y) fixed<<setprecision(y)<<x
// # define setbits(x) __builtin_popcountll(x)
// # define zrobits(x) __builtin_ctzll(x)
// # define inf 1e18
// # define sortv(a) sort(a.begin(),a.end())
                                        
// int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
// bool isprime(int x){for(int i=2;i*i<=x;i++) if(x%i==0) return 0 ;return (x==1? 0 : 1);}
                                        
// int solve(int n,vi a,vi b){
//     vi res(n);

//             for(ll i = 0 ; i < n ; i++) {
//             while(a[j] <= b[i] and j!=n) {
//                 j++;
//             }
//             if(j!=n)
//                 res[i] = n-j;
//         }

//     sort(res.begin(),res.end());
//     long long operations = 1;
//             for(long long i = 0; i < (long long)res.size(); i++) {
//             ans = ((ans%mod)*((res[i]-i)%mod))%mod;
//         }
//     return operations;
// }
// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int T=0;
//     cin>>T;
//     while(T--){
//         int n;
//         cin>> n;
//         vi a(n);
//         f(i,0,n){
//             in a[i];
//         }
//         vi b(n);
//         f(i,0,n){
//             in b[i];
//         }
//         out solve(n,a,b) nl
//     }             
//    return 0; 
// }


    #include <bits/stdc++.h>
    #define ll long long
    #define pb push_back
    #define ff first
    #define ss second
    #define mp make_pair
    #define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    using namespace std;
     
    const ll mod = 1e9+7;
    int main()
    {   
        
        ll t;
        cin>>t;
        while(t--) {
            ll n,ans = 1;
            cin>>n;
            vector < ll > a(n),b(n),res(n);
            for(ll i = 0 ; i < n ; i++) {
                cin>>a[i];
            }
            for(ll i = 0 ; i < n ; i++) {
                cin>>b[i];
            }
            sort(b.begin(),b.end());
            sort(a.begin(),a.end());
            ll j = 0;
            for(ll i = 0 ; i < n ; i++) {
                while(a[j] <= b[i] and j!=n) {
                    j++;
                }
                if(j!=n)
                    res[i] = n-j;
            }
            
            sort(res.begin(),res.end());
            for(ll i = 0 ; i < (ll)res.size() ; i++) {
                ans = ((ans%mod)*((res[i]-i)%mod))%mod;
            }
            cout<<ans<<endl;
        }
        return 0;     
     }        