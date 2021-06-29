#include <iostream>
#include <cstdio>
using namespace std;

void insertionSort(int [],int);
void trace(int [],int);

int main(){
    int N;
    cin >> N;
    
    int A[N];
    for(int i = 0;i<N;i++)cin >> A[i];
    
    trace(A,N);
    
    insertionSort(A,N);

    return 0;
}

void insertionSort(int A[],int N){

    int v,j,i;

    for(i=1;i<N;i++){
        v = A[i];
        j = i-1;

        while(j>=0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A,N);
    }
    return;
}

void trace(int A[],int N){
    int i;
    for(i=0;i<N;i++){
        if(i==N-1){
            cout << A[i] << "\n";
        }
        else{
            cout << A[i] << " ";
            }

    }
    return;
}
