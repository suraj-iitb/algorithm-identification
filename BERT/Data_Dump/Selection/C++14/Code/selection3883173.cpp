#include <iostream>
using namespace std;

int selectionSort(int A[], int N){
    //cout << "bubbleSort() has calleed\n";
    int i, j, t, sw = 0, mini;
    for(i=0; i<N-1; i++){
        mini = i;
        for(j=i; j<N; j++){
            if(A[j] < A[mini]) mini = j;
        }
        swap(A[i], A[mini]);
        if(i != mini) sw++;
    }
    return sw;
}
    
int main(void){
    int A[100], N, i, sw;
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    
    sw = selectionSort(A, N);
    
    for(int i=0; i<N; i++){
        if (i) cout << " ";
        cout << A[i];
    }
    cout << "\n";
    
    cout << sw << "\n";
    
    return 0;    
}
