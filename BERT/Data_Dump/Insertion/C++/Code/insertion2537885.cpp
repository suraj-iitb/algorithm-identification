#include <iostream>
using namespace std;
void output(int A[],int N){
    for(int i=0;i<N;i++){
            if(i)cout<<" ";
            cout<<A[i];
        }
        cout<<endl;
}

void insertionSort(int A[],int N){
    int j,key;
    for(int i = 1;i< N;i++){
        key = A[i];
        /* insert A[i] into the sorted sequence A[0,...,j-1] */
        j = i - 1;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        output(A,N);
    }
}

int main(void){
    int N;
    int A[100];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    output(A,N);
    insertionSort(A,N);
    return 0;
}
