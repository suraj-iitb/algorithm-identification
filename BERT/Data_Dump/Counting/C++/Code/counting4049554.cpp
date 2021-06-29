#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int i, n, t, C[10001];
    unsigned short A[2000001], B[2000001], a_max = 0;
    
    cin >> n;
    for(i = 0; i < n; i++) cin >> A[i];
    for(i = 0; i < n; i++) if(a_max < A[i]) a_max = A[i];
    for(i = 0; i < a_max + 1; i++) C[i] = 0;
    for(i = 0; i < n; i++) C[A[i]]++;
    t = 0;
    for(i = 0; i < a_max + 1; i++){
        C[i] += t;
        t = C[i];
    }
    for(i = n - 1; i >= 0; i--){
        t = C[A[i]];
        B[t - 1] = A[i];
        C[A[i]]--;
    }
    for(i = 0; i < n; i++){
        if(i > 0) cout << " ";
        cout << B[i];
    }
    cout << endl;
    return 0;
}

