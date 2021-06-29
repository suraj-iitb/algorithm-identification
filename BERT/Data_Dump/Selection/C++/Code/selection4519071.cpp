#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

void selectionSort(int n, deque<int> a) {
    int count = 0;
    for (int i = 0; i <= n - 1; ++i) {
        int minj = i;
        for (int j = i; j <= n - 1; ++j) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            int t = a[i];
            a[i] = a[minj];
            a[minj] = t;
            ++count;
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
    selectionSort(n, a);

    return 0;
}

