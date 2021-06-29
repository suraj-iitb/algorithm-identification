#include <iostream>
using namespace std;

void printArray(int A[], int N){
    for(int i=0; i<N; i++){
        cout << A[i];
        if ( i < N-1 ) cout << " ";
        else cout << "\n";
    }
}

int bubbleSort(int A[], int N){
    int sw = 0;
    bool flag = true;
    
    for(int i=0; flag; i++){
        flag = false;
        for(int j=N-1; j>=i+1; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                flag = true;
                sw++;
            }
        }
    }
    
    return sw;
}

int main(void){
    // Here your code !
    int N;
    int A[100];
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    int sw;
    
    sw = bubbleSort(A, N);
    printArray(A,N);
    cout << sw << endl;
        
}
