#include<iostream>

using namespace std;

int main(){
    int N;
    int count=0;
    cin>>N;
    int A[N];
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    for(int i=0; i<N; i++){
        int minj=i;
        for(int j=i; j<N; j++)  if(A[j]<A[minj])    minj=j;
        int memo=A[i];
        A[i]=A[minj];
        A[minj]=memo;
        if(A[minj]!=A[i]) count++;//{   count++; cout<<i+1<<" change"<<endl;}
        /*for(int k=0; k<N-1; k++){
            cout<<A[k]<<" ";
        }
        cout<<A[N-1]<<endl;*/
    }
    for(int i=0; i<N-1; i++)    cout<<A[i]<<" ";
    cout<<A[N-1]<<endl;
    cout<<count<<endl;
    return 0;
}
