#include <iostream>
using namespace std;

void trace(int A[],int N){
    for(int i=0; i < N; i++){
        cout << A[i];
        if(i <N-1){
            cout << " ";
        }
    }
    cout << endl;
}
void insertionSort(int A[],int N){
    int j,i,v;
    for(i=1;i<N;i++){
        v = A[i];
        j = i-1;
        while(v<A[j] && j >=0){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A,N);
    }
}

int main(){
    int N,A[100];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    trace(A,N);
    insertionSort(A,N);
    
    return 0;
}

