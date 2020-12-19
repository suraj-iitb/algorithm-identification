#include <iostream>
using namespace std;
int main(void){
    int n, j, A[1001], v;
    cin >> n;
    for(int t = 0; t < n; t++){
        cin >> A[t];
        if(t==n-1)cout << A[t];
        else cout << A[t] << " " ;
    }
    cout <<endl;
    for(int i = 1; i <= n-1; i++){
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        for(int t = 0; t < n; t++){
        if(t==n-1)cout << A[t];
        else cout << A[t] << " " ;
        }
        cout <<endl;
    }
    
    
    return 0;
}
