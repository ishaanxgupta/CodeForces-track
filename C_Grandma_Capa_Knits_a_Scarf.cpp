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


//crack krdia hi tha 80% ismein bs yeh krna hai ki manlo mein 26 alphabets ke liye check kroonga ki woh hatane wala chunoonga ya nhi
//jaise pehle a ke liye check krelnge yahi dikkat aa rhi thi ki kaise choose kroo alphabet ke liye
//baaki toh algo hai wahi palindrome wali jsimein bas yeh dekhna ki ++ -- kab krna woh toh crackk krliya tha                                        
int solve(int n,string s){
    int ans = n+1;
    for(int c=0;c<26;c++){
        int i = 0;
        int j = s.size()-1;
        int cnt = 0;
     while(i<=j){
        if(s[i] == s[j]){
         i++;
         j--;    
    }else if(s[i] == char(c + 'a')){
        cnt++;
        i++;
    }else if(s[j] == char(c + 'a')){
        cnt++;
        j--;
    }else{
        cnt = n+1;
        break;
    }
     }
     ans = min(ans,cnt);
    }
    
    if(ans == n+1){
        return -1;
    }else{
        return ans;
    }
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
        string s;
        in s;
        out solve(n,s) nl
    }             
    
}