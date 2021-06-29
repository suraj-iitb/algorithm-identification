#include <iostream>
using namespace std;

void printA(int A[100],int N){
     for(int i=0;i<N-1;i++){
       cout<<A[i]<<" ";
   }
   cout<<A[N-1]<<endl;
}

void insertionSort(int A[100],int N){
    for(int i=1;i<=N-1;i++){
        printA(A,N);
        int v=A[i];
        int j=i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
    }
}

int main(void){
   int N,A[100];
   cin>>N;
   for(int i=0;i<N;i++){
       cin>>A[i];
   }
   
   insertionSort(A,N);
   printA(A,N);
}

