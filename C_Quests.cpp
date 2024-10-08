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
                                        
// int solve(int n,int k,vi a,vi b){
//     int uspe_hi_raho =b[0];
//     int new_exp = a[0];
//     int total_exp = a[0];
//     int i=1;
//     while(k>0){
//         if(a[i]>uspe_hi_raho){
//             total_exp += a[i];
//             i++;
//             new_exp = a[i];
//             uspe_hi_raho = max(uspe_hi_raho,b[i]);
//         }else{
//             total_exp += uspe_hi_raho;
//             i++;
//         }
//     }
//     return total_exp;
// }
// int uspe_hi_raho = b[0];  
    // int total_exp = a[0];     
    // int i = 1;                 
    // k--;                       

//     while (k > 0 && i < n) {   
//         if (a[i] > uspe_hi_raho) {
//             total_exp += a[i];  
//             uspe_hi_raho = max(uspe_hi_raho, b[i]); 
//         } else if(a[i]+(b[i]*(k-1))>uspe_hi_raho*k){
//             total_exp += a[i];
//             uspe_hi_raho = max(uspe_hi_raho, b[i]);
//         } else{
//             total_exp += uspe_hi_raho;
//         }
//         k--;   
//         i++;   
//     }
    // while(k>0){
    //     total_exp +=uspe_hi_raho;
    //     k--;
    // }

//     return total_exp;

// while(k>0 && i<n){
//     if(a[i]+(b[i]*(k-1)) > uspe_hi_raho*k){
//         total_exp += a[i];
//         uspe_hi_raho = max(uspe_hi_raho,b[i]);
//     }else if(a[i] > uspe_hi_raho && b[i]<uspe_hi_raho){
//         total_exp += a[i];
//     }else{
//         total_exp += uspe_hi_raho;
//     }
// k--;
// i++;
// }
//     while(k>0){
//         total_exp +=uspe_hi_raho;
//         k--;
//     }
// return total_exp;

int solve(int n, int k, vi a, vi b) {
    vi sum_a(n);
    sum_a[0] = a[0];
    for (int i = 1; i < n; i++) {
        sum_a[i] = a[i] + sum_a[i-1];
    }

    vi max_b(n);
    max_b[0] = b[0];
    for (int i = 1; i < n; i++) {
        max_b[i] = max(b[i], max_b[i-1]);
    }

    int exp = INT_MIN;

    for (int i = 0; i < n; i++) {
        int current_exp = sum_a[i] + (k - (i + 1)) * max_b[i];
        
        if (i + 1 <= k) {
            exp = max(exp, current_exp);
        }
    }

    return exp;
}

//yeh sabse best solution hai aur pre computation ki help se sab kr rhe aur humko har step pe total exp nikal rhe aur check kr rhe
//purani approach mein seedha max total_exp nikal rha tha jo ki glt aa rha tha humesha so this is lot better approach

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
        vi b(n);
          f(i,0,n){
            in b[i];
        }
        cout<<solve(n,k,a,b) nl
    }             
  return 0;  
}