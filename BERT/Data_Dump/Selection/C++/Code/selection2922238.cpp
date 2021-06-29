#include <iostream>
using namespace std;
int selectionSort(int A[], int N){
    int i, j, s=0, tmp, minj;
    for(i=0; i<N-1; i++){
        minj = i;
        for(j=i; j<N; j++){
            if(A[j]<A[minj]) minj = j;
        }
        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        
        if(i != minj) s++;
    }
    return s;
}

int main(void){
    int N, s;
    int A[101];
    
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    
    s = selectionSort(A, N);
    
    for(int i=0; i<N; i++){
        if(i>0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << s << endl;
    
    return 0;
}

