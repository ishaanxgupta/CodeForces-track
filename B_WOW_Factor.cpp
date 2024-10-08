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
                                        
int solve(string s){
  int countw = 0;
  for(int i=1;i<s.size();i++){
    if(s[i-1] == 'v' && s[i] == 'v'){
        countw++;
    }
  }
  int count = 0;
  int ans = 0;
  for(int i=1;i<s.size();i++){
   if(s[i-1] == 'v' && s[i] == 'v'){
    count++;
   }else if(s[i] == 'o'){
    ans += count*(countw-count);
   }else{
    continue;
   }
  }
  return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
        string s;
        in s;
       cout<< solve(s)<<endl;
                
    
}