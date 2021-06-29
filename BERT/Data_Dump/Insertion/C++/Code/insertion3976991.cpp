#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;int L[n];for(int i=0;i<n;i++)cin>>L[i];
    for(int i=0;i<n;i++){if(i==n-1)cout<<L[i]<<endl;else{cout<<L[i]<<' ';}}
    for(int i=1;i<n;i++){
        int v=L[i];int j=i-1;
        while(j>=0 && L[j]>v){
            L[j+1]=L[j];
            j--;
        }
        L[j+1]=v;
        for(int i=0;i<n;i++){
        if(i==n-1)cout<<L[i]<<endl;
        else{cout<<L[i]<<' ';}
    }
    }
    return 0;
}
