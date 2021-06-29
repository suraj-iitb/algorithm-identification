#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        cout << A[i] << ((i != N-1) ? " " : "");
    }
    cout << endl;
    int i, j;
    
    for(i = 1; i < N; ++i){
        j = i - 1;
        int tmp = A[i];
        while(j>=0 && A[j] > tmp){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = tmp; 
        
        for(int k = 0; k < N; ++k) cout << A[k] << ((k != N-1) ? " " : "");
        cout << endl;
    }
    
    return 0;
}
