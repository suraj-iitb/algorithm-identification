#include<iostream>
using namespace std;

int main(){
    int n;
    int A[100];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    for (int i = 0; i < n; i++){
        int v = A[i];
        int j = i-1;
        while (j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        for (int j = 0; j < n; j++){
            if (j == n-1) cout << A[j] << endl;
            else cout << A[j] << " ";
        }
    }
}
