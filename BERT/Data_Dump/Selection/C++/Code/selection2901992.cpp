#include <iostream>
using namespace std;
int selectionSort(int A[],int N){
    int count=0,minj;
    for(int i=0;i<N-1;i++){
        minj=i;
        for(int j=i;j<N;j++){
            if(A[j] < A[minj])minj = j;
        }
        swap(A[i],A[minj]);
        if(i!=minj)count++;
    }
    return count;
}
int main(int argc, const char * argv[]) {
    int A[100],N;
    cin>>N;
    for(int i=0;i<N;i++)cin>>A[i];
    
    int sw = selectionSort(A,N);
    
    for(int i=0;i<N;i++){
        if(i>0) cout<<' ';
        cout<<A[i];
    }
    cout<<endl;
    cout<<sw<<endl;
    return 0;
}

