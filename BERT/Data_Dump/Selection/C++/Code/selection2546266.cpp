#include<iostream>
using namespace std;

int selectionSort(int A[],int n){
    int minj, sw=0;
    
    for(int i=0; i<n-1; i++){
        minj = i;
        for(int j=i+1; j<n; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        swap(A[i], A[minj]);
        if(i != minj) sw++;
    }
    return sw;
}

int main(){
    int A[100], sw, n;
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> A[i];
    
    sw = selectionSort(A, n);
    
    for(int i=0; i<n; i++){
        if(i) cout << ' ';
        cout << A[i];
    }
    
    cout << endl;
    cout << sw << endl;
}
