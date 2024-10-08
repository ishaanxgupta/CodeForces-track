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
                                        
int solve(int total_people, int infected_people, vi a) {
    sort(a.begin(), a.end());
    vi diff;

    f(i, 0, infected_people - 1) {
        diff.push_back(a[i + 1] - a[i] - 1);
    }
    // Handle circular gap (between last and first house)
    diff.push_back(total_people - a[infected_people - 1] + a[0] - 1);
    sort(diff.rbegin(), diff.rend());

    // Variable to count the number of days passed
    int days = 0;
    // Variable to store the number of safe houses
    int safe = 0;

//simple simulation hai yaha manlo ki gap tha 10 din ka toh pehle din ek bacha liya aur fir 1 infect hoga toh fir matlab 10 agar unifected the toh usmein apan 9 bacha skte aur 2 din lagenge is kaam mein
//fir manlo agla diff 8 ka tha toh fir 10 mein 9 bachane mein 2 din lg gye tb tk yaha bc 4 log infect ho gye honge fir ek bachaya toh ek aur ho gya toh 8 mein se 3 bacha payenge yaha
//fir koi diff aisa aya jaha curr hi zero se km ho gya toh uske aage ke din pe toh kuch ni bacha payenge seedhi baat
//aur agar ismein kisi ka curr hi 1 tha toh bas usko bacha lenge toh woh case ginna hai bas
//acha question hai
    // Process each gap
    for(int curr : diff) {
        curr -= days * 2;
        if (curr <= 0) break;
        safe += curr-1;
        if(curr == 1) safe++;
        days += 2;
    }

    // Return the number of infected houses
    return total_people - safe;
}

// Main function
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 0;
    cin >> T;
    while(T--) {
        int total_people, infected_people;
        cin >> total_people >> infected_people;
        vi a(infected_people);
        f(i, 0, infected_people) {
            cin >> a[i];
        }
        cout << solve(total_people, infected_people, a) << endl;
    }             
    return 0;  
}