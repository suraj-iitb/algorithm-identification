//計算量はO(N^2)

#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;

int bubbleSort(int A[],int N){
    int flag=1;
    //計算を行う関数内で数を定義する
    int count=0;
    for(int i=0;flag;i++){
        flag=0;
      
        for(int j = N-1;j>i;j--){
            if(A[j]<A[j-1]){
                //A[j]とA[j-1]を入れ替える
                swap(A[j],A[j-1]);
                count++;
                flag=1;
            }
        }
    }
    return count;
}


int main(){
    int N,count;
    cin>>N;
    int A[N];
   
    

    for(int i=0;i<N;i++){
        cin>>A[i];
        }
    
    count = bubbleSort(A,N);
    
    for(int k=0;k<N;k++){
        if(k==N-1){
            cout<<A[k]<<endl;
        }
        else cout<<A[k]<<" ";
    }
    cout<<count<<endl;
}


