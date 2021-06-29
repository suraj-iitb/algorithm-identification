#include<iostream>
using namespace std;

int main() {


    int n, A[100];
    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> A[k];
    }
    for (int i = 1; i < n; i++) {
        int v = A[i];
        int j = i - 1;
        for (int s = 0; s < n; s++) {
            cout << A[s];
        if(s < n-1)cout << " ";
        }
        cout << endl;

        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;




    }
    for (int s = 0; s < n; s++) {
        cout << A[s];
        if (s < n - 1)cout << " ";
    }
    cout << endl;


    return 0;

}
