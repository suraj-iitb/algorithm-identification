#include<iostream>
using namespace std;

int main(){
    int n,A[100]={},l,c = 0;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> l;
        A[i] = l;
    }
    

    for (int i = 0;  i < n; i++){
        for (int j = n - 1; i < j; j--){
            if (A[j] < A[j-1]){
                int a = A[j-1];
                A[j-1] = A[j];
                A[j] = a;
                c += 1;
            }
        }
    }

    for (int i = 0; i < n; i++){
        if (i == n-1){
            cout << A[i] << '\n';
        }
        else {
            cout << A[i] << " ";
        }
    }
    cout << c << '\n';
    return 0;
}
