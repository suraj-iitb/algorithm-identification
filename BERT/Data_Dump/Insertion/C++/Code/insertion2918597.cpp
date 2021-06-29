//
// Created by yoshihito.hotta on 2018/06/10.
//

#include <iostream>
#include <algorithm>

using namespace std;

void printtable(int *a, int n) {
    for (int k = 0; k < n; k++) {
        if(k) {
            cout << " ";
        }

        cout << a[k];
    }
    cout << endl;
}
int main() {
    int n;
    int *a;

    cin >> n;
    a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    printtable(a, n);
    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;
        while (a[j] > v && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        printtable(a, n);
    }

    return 0;
}


