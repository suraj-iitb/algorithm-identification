#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int A[N],i,v,j;
    for(i=0;i<N;i++) cin>>A[i];
    for(i=1;i<N;i++){
        for(int c=0;c<N;c++){
            cout<<A[c];
            if(c!=N-1) cout<<" ";
        }
        cout<<endl;
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
            A[j+1]=v;
        }
    }
    for(int c=0;c<N;c++){
            cout<<A[c];
            if(c!=N-1) cout<<" ";
        }
    cout<<endl;
    return 0;
}
