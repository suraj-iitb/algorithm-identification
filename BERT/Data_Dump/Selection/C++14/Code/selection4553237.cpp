#include <bits/stdc++.h>
using namespace std;

template <class T>
int selectionSort(vector<T>& a) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        T m = a[i];
        int minj = i;
        for (int j = i; j < a.size(); ++j) {
            if (a[j] >= m) continue;
            m = a[j];
            minj = j;
        }
        swap(a[i], a[minj]);
        if (i != minj) cnt++;
    }
    return cnt;
}

template<class T>
void printVector(vector<T> &a, string delimiter) {
    if (a.size() == 0) return;
    cout << a[0];
    for (int i = 1; i < a.size(); ++i) {
        cout << delimiter << a[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int k = selectionSort(a);
    printVector(a, " ");
    cout << k << endl;
}

