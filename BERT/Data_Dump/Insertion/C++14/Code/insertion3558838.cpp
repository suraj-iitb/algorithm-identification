#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> x, int n){
    for(int i = 0; i < n; i++){
        int v = x[i];
        int j = i-1;
        while(j >= 0 && x[j] > v){
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = v;
        for(int k = 0; k < n; k++){
            cout << x[k] << (k < n-1 ? " " : "");
        }
        cout << "\n";
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    insertionSort(A, N);

    return 0;
}
