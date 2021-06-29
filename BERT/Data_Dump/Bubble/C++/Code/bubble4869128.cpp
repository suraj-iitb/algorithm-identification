#include <iostream>
using namespace std;

void printA(int A[100],int N){
     for(int i=0;i<N-1;i++){
       cout<<A[i]<<" ";
   }
   cout<<A[N-1]<<endl;
}

int bubbleSort(int A[100],int N){
    int flag=1,count=0;
    while(flag){
        flag=0;
        for(int j=N-1;j>=1;j--){
            if(A[j]<A[j-1]){
                count++;
                int tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                flag=1;
            }
        }
    }
    return count;
}

int main(void){
   int N,A[100];
   cin>>N;
   for(int i=0;i<N;i++){
       cin>>A[i];
   }
   
   int count=bubbleSort(A,N);
   printA(A,N);
   cout<<count<<endl;
}
