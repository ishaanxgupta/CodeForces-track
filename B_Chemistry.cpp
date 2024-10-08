
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool solve(int n, int k, string s) {
    unordered_map<char, int> mp;

    for (auto ch : s) {
        mp[ch]++;
    }

    int odd_count = 0;
    for (auto it : mp) {
        if (it.second % 2 != 0) {
            odd_count++;
        }
    }
if(odd_count == 1){
    return true;
}
    if(odd_count - k == 1){
        return true;
    }
     if(odd_count>k){
        return false;
    }
    return true;
    }
    

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        string s;
        cin >> s;
        if (solve(n, k, s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}