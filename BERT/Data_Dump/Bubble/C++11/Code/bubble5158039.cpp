#include<bits/stdc++.h>

using namespace std;

int bubbleSort(int*a,int n) {
    int tot = 0;
    for (int i = 0; i < n; i++) {
        bool isSorted = true;
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                isSorted = false;
                swap(a[j], a[j - 1]);
                ++tot;
            }
        }
        if (isSorted) break;
    }
    return tot;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int &i : a) cin >> i;
    int t = bubbleSort(a,n);
    cout<<a[0];
    for (int i = 1; i < n; i++) {
        cout << " " << a[i];
    }
    cout << endl << t << endl;
    return 0;
}
