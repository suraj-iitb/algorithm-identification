#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,A[110],v,j;
    cin>>n;
    for(int i=0;i<n;i++)cin>>A[i];
            for(int k=0;k<n;k++){
            if(k==n-1)cout<<A[k]<<endl;
            else cout<<A[k]<<" ";
            
        }
    for(int i=1;i<n;i++){
        v=A[i];
        j=i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        for(int k=0;k<n;k++){
            if(k==n-1)cout<<A[k]<<endl;
            else cout<<A[k]<<" ";
            
        }
    }

    return 0;
}




