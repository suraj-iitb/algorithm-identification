#include <iostream>
using namespace std;

void trace (int A[], int N){
    for(int i=0;i<N;i++) cout << ( i ? " " : "" ) << A[i];
    cout << endl;
}

int bubblesort(int A[], int N){
    int count = 0,flag = 1;
    int r;
    while(flag){
        flag = 0;
        for(int j=N-1;j >= 1;j--){
            if(A[j] < A[j-1]){
                r = A[j];
                A[j] = A[j-1];
                A[j-1] = r;
            flag = 1;
            count++;
            }
        }
    }
    return count;
}

int main(){
    int N,A[100+10],count;
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    count = bubblesort( A , N );
    trace( A , N );
    cout << count << endl;
}
