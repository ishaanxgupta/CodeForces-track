#include<bits/stdc++.h>
using namespace std ; 

# define int long long 
# define vi vector<int> 
# define vs vector<string> 
# define vb vector<bool>
# define vv vector<vector<int>>
# define f(i,a,b) for(int i=a;i<b;i++)
# define fr(i,a,b) for(int i=a;i>b;i--)
# define umap unordered_map<int,int>
# define umap_char unordered_map<char,int>
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
                                        
// vi solve(int n, vi a) {
//     vi ans;
//     vb check(n, false);
//     umap mp;
//     vi prefix_copy(n);
//     vi copy = a;

//     sortv(copy);
//     prefix_copy[0] = copy[0];

//     // copy   : 1 2 4 5  7  20
//     // prefix : 1 3 7 12 19 32
//     // check  :       T  F T



//     f(i, 1, n) {
//         prefix_copy[i] = copy[i] + prefix_copy[i - 1];
//     }

//     mp[copy[n - 1]] = n - 1;
//     check[n - 1] = true;

// int index = 0;
//     for (int i = n - 2; i >= 0; i--) {
//         if(prefix_copy[i] == copy[i + 1]){
//             if (check[i + 1] == true) {
//                 mp[copy[i]] = n-1;
//                 check[i] = true;
//             } else {
//                 mp[copy[i]] = i+1;
//                 check[i] = false;
//                 index = i;
//             } 
//         }
//         else if (prefix_copy[i] > copy[i + 1]) {
//             if (check[i + 1] == true) {
//                 if(mp.find(copy[i])==mp.end()){
//                 mp[copy[i]] = i+1;
//                 }
//                 check[i] = true;
//             } else {
//                 if(mp.find(copy[i])==mp.end()){
//                 mp[copy[i]] = i+1;
//                 }
//                 check[i] = false;
//                 index = i;
//             }
//         } else {
//             mp[copy[i]] = i;
//             check[i] = false;
//             index = i;
//         }
//     }

//     f(i, 0, n) {
//         ans.push_back(mp[a[i]]);
//     }

//     return ans;
// vi ans;
//     vb check(n, false);
//     umap mp;
//     vi prefix_copy(n);
//     vi copy = a;

//     sortv(copy);
//     prefix_copy[0] = copy[0];

//     // copy   : 2 2 4 5  7  21
//     // prefix : 2 4 8 13 20 41
//     // check  : T T T T  F  T


//     f(i, 1, n) {
//         prefix_copy[i] = copy[i] + prefix_copy[i - 1];
//     }

//     mp[copy[n - 1]] = n - 1;
//     check[n - 1] = true;

//     int index = n-2;
//     for (int i = n - 2; i >= 0; i--) {
//         if(i>=1 && copy[i-1] == copy[i]){
//            if(prefix_copy[i] >= copy[i + 1]){
//         // mp[copy[i]] = index;
//         check[i] = true;
//     }else{
//         // mp[copy[i]] = i;
//         check[i] = false;
//         index = i;
//     }    
//             continue;
//         }
//         if(prefix_copy[i] >= copy[i + 1]){
//         mp[copy[i]] = index;
//         check[i] = true;
//     }else{
//         mp[copy[i]] = i;
//         check[i] = false;
//         index = i;
//     }    
//     }
        

//     f(i, 0, n) {
//         ans.push_back(mp[a[i]]);
//     }

//     return ans;
// }


    // // copy   : 1 2 4 5 7 20
    // // prefix : 1 3 7 12 19 39
    // // check  :        F  F  T

    vi solve(int n, vi a) {
    vi ans;
    vb check(n, false);
    umap mp;
    vi prefix_copy(n);
    vi copy = a;

    sortv(copy);
    prefix_copy[0] = copy[0];

    f(i, 1, n) {
        prefix_copy[i] = copy[i] + prefix_copy[i - 1];
    }

    mp[copy[n - 1]] = n - 1;
    check[n - 1] = true;

    for (int i = n - 2; i >= 0; i--) {
        if (prefix_copy[i] > copy[i + 1]) {
            if (check[i + 1] == true) {
                mp[copy[i]] = i+1;
                check[i] = true;
            } else {
                mp[copy[i]] = i+1;
                check[i] = false;
            }
        } else {
            mp[copy[i]] = i;
            check[i] = false;
        }
    }

    f(i, 0, n) {
        ans.push_back(mp[a[i]]);
    }

    return ans;
}

// vi solve(int n, vi a) {
//     vi ans(n);
//     vi copy = a;
//     sortv(copy);

//     vi prefix_sum(n);
//     prefix_sum[0] = copy[0];
//     f(i, 1, n) {
//         prefix_sum[i] = copy[i] + prefix_sum[i - 1];
//     }

//     for (int i = 0; i < n; ++i) {
//         int pos = upper_bound(copy.begin(), copy.end(), a[i]) - copy.begin();
//         int max_removal = pos;
        
//         if (pos > 0 && prefix_sum[pos - 1] <= a[i]) {
//             max_removal = pos - 1;
//         }

//         ans[i] = max_removal - 1;
//     }

//     return ans;
// }



// vi solve(int n, vi a) {
//     vi ans;
//     vi copy = a;
//     sortv(copy);

//     vi prefix_sum(n);
//     prefix_sum[0] = copy[0];
//     f(i, 1, n) {
//         prefix_sum[i] = copy[i] + prefix_sum[i - 1];
//     }

//     // Calculate the maximum elements that can be removed starting with each element
//     for (int i = 0; i < n; ++i) {
//         int pos = upper_bound(copy.begin(), copy.end(), a[i]) - copy.begin();
//         int max_removal = pos;
        
//         if (pos > 0 && prefix_sum[pos - 1] <= a[i]) {
//             max_removal = pos - 1;
//         }

//         ans.push_back(max_removal);
//     }

//     return ans;
// }

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
        vi result = solve(n,a);
        f(i,0,n){
            cout<<result[i]<<' ';
        }
        cout nl;
    }             
    return 0;
}