#include <iostream>
using namespace std;

void trace (int A[], int N){
    for(int i=0;i<N;i++) cout << ( i ? " " : "" ) << A[i];
    cout << endl;
}

int selectionsort(int A[], int N){
    int count = 0, minj, r;
    for(int i=0;i<N;i++){
        minj = i;
        for(int j =i+1;j<N;j++){
            if(A[j] < A[minj]) minj = j;
        }
        if(i != minj){
            r = A[i];
            A[i] = A[minj];
            A[minj] = r;
            count++;
        }
    }
    return count;
}

int main(){
    int N,A[100+10],count;
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    count = selectionsort( A , N );
    trace( A , N );
    cout << count << endl;
}
