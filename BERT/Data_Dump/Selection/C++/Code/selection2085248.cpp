#include<iostream>
using namespace std;

int selectionSort(int A[],int N){
    int mini,sw=0;
    for(int i=0;i<N;i++){
        mini = i;
        for(int j=i;j<N;j++){
            if(A[j]<A [mini]) mini=j;
        }
        if(i!=mini){
            swap(A[i],A[mini]);
            sw++;
        }
    }
    return sw;
}

int main(){
    int N,A[101],mini,sw;
    cin>>N;
    for(int i=0;i<N;i++)cin>>A[i];

    sw=selectionSort(A,N);
    for(int i=0;i<N;i++){
                if(i)cout<<" ";
                cout<<A[i];
    }
    cout<<endl;
    cout<<sw<<endl;
    return 0;
    }
