#include <iostream>
using namespace std;


void bubbleSort(int *A,int N,int& count){
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=0;i!=N-1;++i){
            if(A[i]>A[i+1]){
                swap(A[i],A[i+1]);
                flag=true;
                ++count;
            }
        }
        --N;
    };
}

void print_A(int *A,int n){
    for(int i=0;i!=n;++i){
        cout<<A[i];
        if(i!=n-1)cout<<" ";
        else cout<<endl;
    }
}


int main(){
    int count=0;
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i!=n;++i){
        cin>>A[i];
    }
    
    //print_A(A,10);
    bubbleSort(A, n, count);
    print_A(A, n);
    cout<<count<<endl;

}



