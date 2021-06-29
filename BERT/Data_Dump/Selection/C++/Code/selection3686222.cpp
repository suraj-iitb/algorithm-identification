#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[100];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    
    int count=0;
    
    for(int i=0; i<n; i++){
        int minj = i;
        for(int j=i; j<n; j++){
            if(A[j] < A[minj]) minj = j;
        }
        int v = A[minj];
        A[minj] = A[i];
        A[i] = v;
        if(minj != i) count++;
    }
    
    for(int k=0; k<n; k++){
        if(k>0) cout << " ";
        cout << A[k];
    }
    cout << endl;
    cout << count << endl;
    
    return 0;
}
