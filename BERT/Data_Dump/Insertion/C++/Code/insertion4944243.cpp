#include<iostream>
using namespace std;
int main() {
    int n, v, j;
    cin >> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
    for (int i=0; i<n; i++){
        if (i == n-1){
            cout << A[i] << endl;
        } else {
            cout << A[i] << " ";
        }
    }
    for (int i=1; i<n; i++){
        v = A[i];
        j = i-1;
        while (j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for (int j=0; j<n; j++){
            if (j == n-1){
                cout << A[j] << endl;
            } else {
                cout << A[j] << " ";
            }
        }
    }
    return 0;
}

