#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n];
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
        if(i != n-1) cout << A[i] << " ";
        else cout << A[i] << endl;
    }
    
    int v,j;
    
    for(int i = 1; i < n; i++){
        v = A[i];
        j = i-1;
        while(j >= 0 && A[j] > v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1] = v;
        cout << A[0];
        for(int k = 1; k < n; k++){
            cout << " " << A[k]; 
        }
        cout << endl;
    }
    
    return 0;
}
