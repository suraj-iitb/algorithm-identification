#include<iostream>
using namespace std;

int selectionSort(int A[], int N) {
    int min_j=0,sw=0;
    for(int i=0; i<N; i++) {
        min_j = i;
        for(int j=i+1; j<N; j++) {
            if(A[j]<A[min_j])min_j = j;
        }
        if(min_j!=i) {
            swap(A[i],A[min_j]);
            sw++;
        }
    }
    return sw;
}

int main() {
    int N,A[110],sw;
    while(cin>>N) {
        for(int i=0; i<N; i++)cin>>A[i];

        sw = selectionSort(A,N);

        for(int i=0; i<N-1; i++)cout<<A[i]<<' ';
        cout<<A[N-1]<<endl;
        cout<<sw<<endl;
    }
    return 0;
}

