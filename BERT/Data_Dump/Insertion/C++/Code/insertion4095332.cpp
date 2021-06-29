#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> A(n);
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
    
    for (int i=0; i<n; i++){
        if(i) cout << ' ';
        cout << A[i];
    }
    cout << endl;
    
    for (int i=1; i<n; i++){
        int key = A[i];
        int j = i-1;
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        
        for (int k=0 ;k<n; k++){
            if (k) cout << ' ';
            cout << A[k];
        }
        cout << endl;
    }
}