#include <iostream>
using namespace std;

int cnt=0;

void selectionSort(int N, int A[]){
    int minj,tmp=0;
    for(int i=0; i<N; i++){
        minj=i;
        for(int j=i; j<N; j++){
            if(A[j]<A[minj]) minj=j;
        }
        if(A[i]>A[minj]){
            tmp=A[i];
            A[i]=A[minj];
            A[minj]=tmp;
            cnt++;
        } 
    }
}

int main(){
    int n,a[105]={};
    cin>>n;
    for(int i=0; i<n; i++)cin>>a[i];
    selectionSort(n,a);
    for(int i=0; i<n; i++){
        if(i)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
}
