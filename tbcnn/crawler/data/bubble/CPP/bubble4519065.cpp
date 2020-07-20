#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

void bubbleSort(int n, deque<int> a) {
    bool flag = true;
    int count = 0;
    while (flag) {
        flag = false;
        for (int j = n - 1; j >= 1; --j) {
            if (a[j] < a[j - 1]) {
                int t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
                flag = true;
                ++count;
            }
        }
    }
    for (int i = 0; i < n-1; ++i) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl << count << endl;
}

int main(int argc, char* argv[]) {
    deque<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    bubbleSort(n, a);

    return 0;
}


