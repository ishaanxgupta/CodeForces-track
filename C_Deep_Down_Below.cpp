#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
ll mod=1000000007;
using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    ll num_caves;
    cin >> num_caves;
    
    vector<pair<ll, ll>> cave_info(num_caves);
    
    // For each cave, calculate the required power and the number of monsters
    for (int cave = 0; cave < num_caves; cave++) {
        ll num_monsters;
        cin >> num_monsters;
        
        vector<ll> monster_armors(num_monsters);
        ll min_power_required = -1;
        
        // Find the minimum required power to start in this cave
        for (int monster = 0; monster < num_monsters; monster++) {
            cin >> monster_armors[monster];
            min_power_required = max(min_power_required, monster_armors[monster] - monster + 1);
        }
        
        cave_info[cave] = {min_power_required, num_monsters};
    }
    
    sort(cave_info.begin(), cave_info.end());
    
    ll left = cave_info[0].first, right = cave_info[num_caves - 1].first;
    ll min_start_power = 1e12;
    
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll current_power = mid;
        bool can_survive = true;
        
        // Simulate the hero going through all caves
        for (int cave = 0; cave < num_caves; cave++) {
            if (current_power >= cave_info[cave].first) {
                current_power += cave_info[cave].second; // Increase power after defeating monsters
            } else {
                can_survive = false;
                break;
            }
        }
        
        // If the hero survives all caves, search for a smaller starting power
        if (can_survive) {
            min_start_power = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << min_start_power << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int test_cases;
    cin >> test_cases;
    
    while (test_cases--) {
        solve();
    }
    
    return 0;
}
