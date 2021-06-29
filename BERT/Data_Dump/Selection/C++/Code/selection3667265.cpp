#include <iostream>
using namespace std;
int main(void){
    int n,A[100],count = 0,tmp,minj;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    for (int i = 0; i <= n-1; i++){
        minj = i;
        for (int j = i; j <= n-1; j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        if (A[i] != A[minj]){
            count += 1;
        }
        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
    }
    for (int i = 0; i < n; i++){
        cout << A[i];
        if (i != n - 1){
            cout << " ";
        }
    }
    cout << endl;
    cout << count << endl;
}
