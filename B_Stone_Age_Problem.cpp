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
                                        
int solve1(vi& a, int i, int x, int& sum) {
    sum = sum - a[i] + x;  
    a[i] = x;             
    return sum;
}

int solve2(vi& a, int x, int& sum) {
    sum = x * a.size();       
    for(int i=0;i<a.size();i++){
        a[i] = x;
    }
    return sum;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int n, queries;
        cin >> n >> queries;
        
        vi a(n);
        int sum = 0; 
        
        f(i, 0, n) {
            cin >> a[i];
            sum += a[i];  
        }
        
        while (queries--) {
            int number;
            cin >> number;
            
            if (number == 1) {
                int index, x;
                cin >> index >> x;
                cout << solve1(a, index - 1, x, sum) << endl; 
            } else {
                int x;
                cin >> x;
                cout << solve2(a, x, sum) << endl;
            }
        }
    }
    return 0;
}



