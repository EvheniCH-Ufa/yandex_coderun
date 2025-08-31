#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n;

    int max_1{-1000002}, max_2{-1000001}, min_1{+1000001}, min_2{+1000002}, curr_num;

    while (cin >> n) {
        if (n > max_1) {
            max_2 = max_1;
            max_1 = n;
        } else if (n > max_2) {
            max_2 = n;
        }

        if (n < min_1) {
            min_2 = min_1;
            min_1 = n;
        } else if (n < min_2) {
            min_2 = n;
        }
    }

    long long prod_max = (long long)max_1 * max_2;
    long long prod_min = (long long)min_1 * min_2;

    if (prod_max > prod_min) {
        if (max_1 < max_2) {
            cout << max_1 << " " << max_2 << endl;
        } else {
            cout << max_2 << " " << max_1 << endl;
        }
    } else {
        if (min_1 < min_2) {
            cout << min_1 << " " << min_2 << endl;
        } else {
            cout << min_2 << " " << min_1 << endl;
        }
    }
}
