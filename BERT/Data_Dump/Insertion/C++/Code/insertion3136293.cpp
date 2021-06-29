#include <iostream>
#include<queue>
using namespace std;
void insertionSort(int *A,int N){
    for(int i=1;i<N+1;i++){
        
        for(int i=0;i<N;i++){
            if(i==N-1)cout<<A[i]<<endl;
            else cout<<A[i]<<' ';
        }
        int v=A[i];
        int j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=v;
    }
}
int main(){

    int n;
    cin>>n;
    int sou[n];
    for(int i=0;i<n;i++){
        cin>>sou[i];
    }
    insertionSort(sou,n);
    
    
    return 0;
}
