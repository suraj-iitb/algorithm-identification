#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[100];
    int a = 0;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    int flag = 1;
    while(flag){
        flag = 0;
        for (int j = n-1; j >= 1; j--){
            if (A[j] < A[j-1]){
                int v = A[j-1];
                A[j-1] = A[j];
                A[j] = v;
                flag = 1;
                a++;
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (i == n-1) cout << A[i] << endl;
        else cout << A[i] << ' ';
    }
    cout << a << endl;
}
