#include<iostream>
using namespace std;

int main(){
    int n,A[100]={},i,j,l,v;
    cin >> n;

    for (int i = 0; i < n; i++ ){
        cin >> l;
        A[i] = l;

        if (i == n-1){
            cout << A[i] << '\n';
        }
        else {
            cout << A[i] << " ";
        }
    }
    for (int i = 1; i < n; i++){
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for (int i = 0; i < n-1; i++){
            cout << A[i] << " ";
        }
        cout << A[n-1] << '\n';
    }

    return 0;
}
