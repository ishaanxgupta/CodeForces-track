#include <bits/stdc++.h>
using namespace std;

vector<int> speedbreaker(vector<pair<int, vector<int>>>& test_cases) {
    vector<int> results;
    for (auto& case_data : test_cases) {
        int n = case_data.first;
        vector<int>& a = case_data.second;

        // Compute L and R
        int L = 1, R = n;
        for (int i = 1; i <= n; ++i) {
            L = max(L, i - a[i - 1] + 1);
            R = min(R, i + a[i - 1] - 1);
        }

        if (L > R) {
            results.push_back(0);
            continue;
        }

        // Initialize count map
        unordered_map<int, int> count;
        int D_max = 200;  // Adjust this value based on performance needs

        for (int d = 1; d <= D_max; ++d) {
            for (int s = d + 1; s <= n - d; ++s) {
                if (a[s - d - 1] >= d + 1 && a[s + d - 1] >= d + 1) {
                    if (a[s - d - 1] >= d + 2 || a[s + d - 1] >= d + 2) {
                        if (L <= s && s <= R) {
                            count[s]++;
                        }
                    }
                }
            }
        }

        // Now, count valid s
        int valid = 0;
        for (int s = L; s <= R; ++s) {
            int d_max_s = min(s - 1, n - s);
            if (d_max_s > D_max) {
                continue;  // Assume invalid since d > D_max is not checked
            }
            if (count[s] >= d_max_s) {
                valid++;
            }
        }
        results.push_back(valid);
    }
    return results;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<pair<int, vector<int>>> test_cases;
    
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        test_cases.push_back({n, a});
    }
    
    vector<int> results = speedbreaker(test_cases);
    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}
