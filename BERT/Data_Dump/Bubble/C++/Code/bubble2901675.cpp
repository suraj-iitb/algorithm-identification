#include <iostream>
using namespace std;
void bubblesort(int A[],int N){
    int count = 0;
    for(int i=0;(N-1)>i;i++){
        for(int j=N-1;j>i;j--){
            if (A[j-1] > A[j]){
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                count++;
            }
        }
    }
    for(int i=0;i<N-1;i++)cout<<A[i]<<' ';cout<<A[N-1];
    cout<<endl;
    cout<<count<<endl;
}
int main(int argc, const char * argv[]) {
    int N;cin>>N;
    int A[100];
    for(int i = 0;i<N;i++)cin>>A[i];
    bubblesort(A,N);
}


