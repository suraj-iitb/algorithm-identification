#include <iostream>
using namespace std;

int A[1005]={};

void insertSort(int a[], int n){
    int v,j;
    for(int i=1; i<n; i++){
        for(int i=0; i<n; i++){
            if(i)cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
        v=a[i];
        j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
            a[j+1]=v;
        }
    }
    for(int i=0; i<n; i++){
        if(i)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
}

int main(){
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    insertSort(A,N);
}
