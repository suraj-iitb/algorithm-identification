#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n,i,j;
    cin >> n;
    int A[n];
    for (i=0;i<n;i++){
        cin >> A[i];
    }
    
    cout  << A[0];
    for(j=1;j<n;j++){
        cout <<" " << A[j];
    }
    cout << endl;
    
    int key;
    for(i=1;i<n;i++){
        key=A[i];
        j=i-1;
        while( j >= 0 and A[j] > key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
        cout  << A[0];
        for(j=1;j<n;j++){
            cout <<" " << A[j];
        }
        cout << endl;
    }
    
    
}

