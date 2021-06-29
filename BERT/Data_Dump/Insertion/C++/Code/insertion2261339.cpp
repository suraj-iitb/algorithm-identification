#include <iostream>
using namespace std;
int main(void){
    int n, v, j;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++){
        cout << A[i];
        if(i != n-1) cout << " ";
    }
    cout << endl;
    
    for(int i = 1; i < n; i++){
        v = A[i];
        for(j = i - 1; j >= 0 ; j--){
            if(v < A[j]){
                A[j+1] = A[j];
            }else{
                break;
            }
        }
        A[j+1] = v;
        for(int i = 0; i < n; i++){
            cout << A[i];
            if(i != n-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
    
}
