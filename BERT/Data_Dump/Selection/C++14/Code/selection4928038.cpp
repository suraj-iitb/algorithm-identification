#include <iostream>
using namespace std;

int selectionsort(int A[],int N){
    int count = 0;
    for (int i=0; i<N; i++){
        int minj = i;
        for (int j=i; j<N; j++){
            if (A[j] < A[minj]) minj = j;
        }
        if (i!=minj){
            int v = A[i];
            A[i] = A[minj];
            A[minj] = v;
            count += 1;
        }
        
    }
    return count;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for (int i=0; i<N; i++) cin >> A[i];
    int count = selectionsort(A,N);
    
    for (int j=0; j<N; j++){
        if (j==N-1) cout << A[j] << "\n";
        else cout << A[j] << " ";
    }
    cout << count << "\n";
    
    return 0;
}
