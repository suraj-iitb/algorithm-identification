#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int a = 0; a < n; a++){
        cout << A[a];
        if (a == n-1) cout << endl;
        else cout << " ";
    }
    for (int i = 1; i < n; i++) {
        int v = A[i];
        int j = i-1;
        while (j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for (int a = 0; a < n; a++){
            cout << A[a];
            if (a == n-1) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}
