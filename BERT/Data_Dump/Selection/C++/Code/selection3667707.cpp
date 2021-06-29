#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n,i;
    int q[100];
    int kaisu=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>q[i];
    }
    for(int i=0;i<n-1;i++){
        int minj = i;
        for(int j = i+1;j<n;j++){
            if(q[j]<q[minj]){
                minj = j;
            }
        }
        if(i!=minj){
            swap(q[minj],q[i]);
            kaisu++;
        }
    }
    
    for(i=0;i<n;i++){
        if(i<n-1)cout<<q[i]<<' ';
        else cout<<q[i]<<endl;
        
    }
    cout<<kaisu<<endl;
    return 0;
}




