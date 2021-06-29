#include <iostream>
//#include <algorithm>
using namespace std;

void iSort(int A[],int N){
    for(int i = 0; i < N-1; i++){
        cout << A[i] << " ";
    }
    cout << A[N-1] << "\n";
    
    for(int i = 1; i < N; i++){
    
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        
        for(int k = 0; k < N-1; k++){
            cout << A[k] << " ";
        }
        cout << A[N-1] << "\n";
    }
}

int main(void){
    int n;
    int A[100];
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    iSort(A,n);
    
}
