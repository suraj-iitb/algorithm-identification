#include<iostream>
using namespace std;

int main(){

    int n,A[100],minj;
    int count = 0;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    for (int i = 0; i <= n - 1; i++){
        minj = i;
        for (int j = i; j <= n - 1; j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        swap(A[i],A[minj]);
        if (A[i] != A[minj]){
            count += 1;
        }
    }

    for (int i = 0; i < n; i++){
            if (i != n - 1){
                cout << A[i] << " ";
            } else {
                cout << A[i] << endl;
            }
    }

    cout << count << endl;

    return 0;
}
