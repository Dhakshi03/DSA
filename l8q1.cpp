#include <iostream>
#include <vector>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            sum += x;
        }

        cout << (sum + n - 1) / n << "\n"; // ceiling of sum / n
    }

    return 0;
}
