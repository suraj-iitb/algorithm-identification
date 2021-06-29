#include<iostream>
using namespace std;

int main() {
    int n, A[100], count = 0, min = 0;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i; j < n ; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        int t = A[i]; A[i] = A[min]; A[min] = t;
        if(i != min)count++;



    }
    for (int i = 0; i < n; i++) {
        if (i > 0)cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;

    return 0;
}
