#include <iostream>
#include <vector>
using namespace std;

int selection_sort(vector<int>& a, int n) {
    int countSwap = 0;
    for (int i = 0; i <= n - 1; i++) {
        int minj = i;
        for (int j = i; j <= n - 1; j++) {
            if (a[j] < a[minj]) {
                minj = j;
            }
        }
        if (a[i] != a[minj]) {
            swap(a[i], a[minj]);
            countSwap++;
        }
    }
    return countSwap;
}

int main() {
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    int countSwap = selection_sort(a, n);

    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << a[i] << endl;
        } else {
            cout << a[i] << " ";
        }
    }
    cout << countSwap << endl;
    return 0;
}

