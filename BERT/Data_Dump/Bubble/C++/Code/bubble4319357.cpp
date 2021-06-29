#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<n; i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    int tmp;
    vector<int> integers;
    rep(i, n) {
        cin >> tmp;
        integers.push_back(tmp);
    }

    void bubble_sort(vector<int> integers, int n);
    bubble_sort(integers, n);
}

void bubble_sort(vector<int> integers, int n) {
    // bool flag = true;
    int swap_count=0;
    int i = 0;
    while (i<n) { // flag
        // flag = false;
        for (int j=n-1; j>i; j-- ) {
            if (integers[j] < integers[j-1]) {
                swap(integers[j], integers[j-1]);
                swap_count++;
                // flag = true;
            }
        }
        i++;
    }
    rep(i, n-1) cout << integers.at(i) << " ";
    cout << integers.at(n-1) << endl;
    cout << swap_count << endl;
}
