#include <bits/stdc++.h>
using namespace std;

#define vi vector<long long>
#define f(i, a, b) for (int i = a; i < b; i++)
#define in cin >>
#define nl << endl

void my_f(int segmentCount, int queryCount, const vi& segments, const vi& queries) {
    unordered_map<long long, long long> freqMap;
    
    long long left = 0;
    long long right = segmentCount;

    f(i, 0, segmentCount) {
        if (i > 0) {
            long long gap = segments[i] - segments[i - 1] - 1; 
            long long area = left * right;
            freqMap[area] += gap; 
        }
        long long solution = (left * right) + right - 1; 
        freqMap[solution] += 1;
        // if (i > 0) {
        //     long long gap = segments[i] - segments[i - 1] - 1; 
        //     long long area = left * right;
        //     freqMap[area] += gap; 
        // }
        left++;
        right--;
    }

    f(i, 0, queryCount) {
        cout << freqMap[queries[i]] << " "; 
    }
    cout << endl;
}

int main() {
    int testCaseCount;
    in testCaseCount;
    
    while (testCaseCount--) {
        int segmentCount, queryCount;
        in segmentCount;
        in queryCount;

        vi segments(segmentCount);
        vi queries(queryCount); 
        
        f(i, 0, segmentCount) {
            long long value;
            in value;
            segments[i] = value;
        }
        
        f(i, 0, queryCount) {
            long long value;
            in value;
            queries[i] = value;
        }

        my_f(segmentCount, queryCount, segments, queries);
    }

    return 0;
}
