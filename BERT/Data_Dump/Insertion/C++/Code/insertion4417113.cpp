#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Ai,j;
    cin>>N;
    int A[N];

    for(int z=0;z<N;z++){
        cin>>A[z];
    }


    for (int k=0;k<N-1;k++){
        cout<<A[k]<<" ";
        }
    cout<<A[N-1]<<endl; 

    for(int i=1;i<N;i++){
        

        j=i-1;
        Ai=A[i];

        while(j>=0 && A[j]>Ai){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=Ai;

        for (int k=0;k<N-1;k++){
            cout<<A[k]<<" ";
        }
        cout<<A[N-1]<<endl;

    }
    
    return 0;
}
