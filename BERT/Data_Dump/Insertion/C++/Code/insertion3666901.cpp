#include<iostream>
using namespace std;

int main(void){
    int n,v,j,A[100];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    for (int i = 0; i < n; i++){
        cout << A[i];
        if (i != n - 1){
            cout << " ";
        }
    }
    cout << endl;
    for (int i = 1; i <= n - 1; i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j += -1;
        }
        A[j + 1] = v;
        for (int i = 0; i < n; i++){
            cout << A[i];
            if (i != n - 1){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

