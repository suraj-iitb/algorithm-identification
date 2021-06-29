#include <bits/stdc++.h>
using namespace std;

int n,A[1010];

void insert(int n,int A[]){
    for(int i=1;i<n;i++){
        int v=A[i];
        int j=i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        for(int k=0;k<n;k++){
            if(k>0) cout<<" ";
            cout<<A[k];
        }
        cout<<endl;
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];
    for(int k=0;k<n;k++){
        if(k>0) cout<<" ";
        cout<<A[k];
    }
    cout<<endl;
    insert(n,A);
}
