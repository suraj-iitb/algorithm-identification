#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[101];
    
    for(int i=0; i<n; i++){
        cin >> A[i];
        if(i==0){
            cout << A[i];
        } else {
            cout << " " << A[i];
        }
    }
    cout <<endl;
    
    int v;
    for(int j=1; j<n; j++){
        v = A[j];
        
        int k=j-1;
        while(k>=0 && A[k]>v){
            A[k+1] = A[k];
            k--;
        }
        A[k+1] = v;
        
        cout << A[0];
        for(int l=1; l<n; l++){
            cout << " " << A[l];
        }
        cout << endl;
    }
    return 0;
}

