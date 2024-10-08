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

// bool check(int n,string s,int sq_root){
//     int i=0;
//     while(i<sq_root){
//         if(s[i] != 1){
//             return false;
//         }
//         i++;
//     }
//     int j = n-sq_root;
//     while(j<n){
//         if(s[j] != 1){
//             return false;
//         }
//         j++;
//     }
//     int x = 0;
//     while(x<n-sq_root){
//         if(s[x] != 1){
//             return false;
//         }
//         x = x*sq_root-1;
//     }
//     int y = sq_root;
//     while(y<n){
//         if(s[y] != 1){
//             return false;
//         }
//         y = y*sq_root-1;
//     }

//     for(int i = sq_root + 2;i<=n-sq_root-2;i++){
//         if( i % sq_root != 0){
//             continue;
//         }else{
//             if(s[i] != 0){
//                 return false;
//             }
//         }
//     }
//     return true;
    
// }  
bool check(int n, string s, int sq_root) {
    for (int i = 0; i < sq_root; ++i) {
        if (s[i] != '1' || s[n - sq_root + i] != '1') {
            return false;
        }
    }

    for (int i = 0; i < sq_root; ++i) {
        if (s[i * sq_root] != '1' || s[i * sq_root + sq_root - 1] != '1') {
            return false;
        }
    }

    for (int i = 1; i < sq_root - 1; ++i) {
        for (int j = 1; j < sq_root - 1; ++j) {
            if (s[i * sq_root + j] != '0') {
                return false;
            }
        }
    }

    return true;
}                                    
bool solve(int n,string s){
    int sq_root = floor(sqrt(n));
    if(sq_root * sq_root == n && check(n,s,sq_root)){
        return true;
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
        cin >> n;
        string s;
        for (int i = 0; i < n; i++) {
            char ch;
            cin >> ch;  
            s.push_back(ch);
        }
        if (solve(n, s)) {
            cout << "Yes\n";  
        } else {
            cout << "No\n";   
        }
    }             
    return 0;
}