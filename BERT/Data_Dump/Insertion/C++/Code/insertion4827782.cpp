#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;

void insertionSort(int A[],int N){
    int v,j;
    for(int i=1;i<N;i++){
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;//例えば、v=3で1,2,4,5の配列の時、j=1でwhileを抜け、A[2]=4のところにvを代入するが、抜けたときj=1なのでA[j+1]に代入する
        for(int k=0;k<N;k++){
            if(k==N-1)cout<<A[k]<<endl;
            else cout<<A[k]<<" ";
        }
     
    }
}

int main(){
    
    int N,l;
    cin>>N;
    int A[N];
    
    int i=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        if(i==N-1)cout<<A[i]<<endl;
            else cout<<A[i]<<" ";
    }
 
    insertionSort(A,N);
    

}
