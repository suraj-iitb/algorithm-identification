#include<iostream>
using namespace std;

void InsertSort(int *A, int N){
    for(int i=1;i<=N-1;i++){
        int v = A[i];
        int j = i - 1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for(int i=0;i<N;i++){
            if(i!=N-1) cout << A[i] << " ";
            else cout << A[i] << endl;
        }
    }
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    for(int i=0;i<N;i++){
            if(i!=N-1) cout << A[i] << " ";
            else cout << A[i] << endl;
        }
    InsertSort(A,N);
    return 0;
}
