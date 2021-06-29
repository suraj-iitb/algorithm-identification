#include<iostream>
using namespace std;

int main(){
    int N,A[100]={},c = 0,n,l;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> l;
        A[i] = l;
    }
    for (int i =0; i < n; i++){
        int minj = i;
        for ( int j = i; j < n; j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        int a = A[i];
        A[i] = A[minj];
        A[minj] = a;
        if (A[i] != A[minj]){
            c += 1;
        }
    }
    for (int i = 0; i < n; i++){
        if (i == n-1){
            cout << A[i] << '\n';
        }
        else{
            cout << A[i] << " ";
        }
    }
    cout << c << '\n';
    return 0;
}
