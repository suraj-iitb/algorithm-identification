#include<iostream>
using namespace std;

int main(){
    int N,v;
    cin>>N;
    int A[N];

    for(int i=0;i<N;i++){
        cin>>A[i];
        if(i!=N-1){
            cout<<A[i]<<" ";
        }else{
            cout<<A[i]<<endl;
        }
    }

    for(int i=1;i<N;i++){
        v = A[i];
        int j=i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
            A[j+1]=v;
        }
        for(int k=0;k<N;k++){
            if(k!=N-1){
                cout<<A[k]<<" ";
            }else{
                cout<<A[k]<<endl;
            }
        }
    }

    return 0;
}
