#include<iostream>
using namespace std;

int main(){

    int v,n,A[1000];
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    for (int i = 0; i < n; i++){
            if (i != n - 1){
                cout << A[i] << " ";
            } else {
                cout << A[i];
            }
        }

        cout << endl;
    
    for (int i = 1; i <= n-1; i++){

        v = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = v;

        for (int i = 0; i < n; i++){
            if (i != n - 1){
                cout << A[i] << " ";
            } else {
                cout << A[i];
            }
        }

        cout << endl;
    }

    return 0;
    
}
