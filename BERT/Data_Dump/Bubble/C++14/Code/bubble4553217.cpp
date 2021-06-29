#include <bits/stdc++.h>
using namespace std;

template <class T>
int bubbleSort(vector<T>& a) {
    int cnt = 0;
    bool rev = true;
    while (rev) {
        rev = false;
        for (int i = 0; i < a.size() - 1; ++i) {
            if (a[i] <= a[i+1]) continue;
            swap(a[i], a[i+1]);
            rev = true;
            cnt++;
        }
    }
    return cnt;
}

template <class T>
void printVector(vector<T>& a, string delimiter) {
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
    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    int k = bubbleSort(array);
    printVector(array, " ");
    cout << k << endl;
}

