#include <iostream>

using namespace std;

int solve(int two_digit_number) {
    int sum = 0;
    sum += two_digit_number % 10;
    sum += two_digit_number / 10;
    return sum;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int two_digit_number;
        cin >> two_digit_number;
        cout << solve(two_digit_number) << endl;
    }
    return 0;
}