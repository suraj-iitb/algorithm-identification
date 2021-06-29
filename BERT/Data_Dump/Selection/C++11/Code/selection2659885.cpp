#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

void trace(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
}

void selecitonSort(vector<int>& a) {
    int n = a.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        int mini = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[mini]) {
                mini = j;
            }
        }
        if (mini != i) {
            swap(a[i], a[mini]);
            count++;
        }
    }
    trace(a);
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    selecitonSort(a);
    return 0;
}
