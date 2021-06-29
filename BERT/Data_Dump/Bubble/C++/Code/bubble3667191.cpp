#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n,j,i;
    int q[100];
    int kaisu=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>q[i];
    }
    int flag=1;
    
    while(flag){
        flag=0;
        for(i=n-1;i>0;i--){
            if(q[i]<q[i-1]){
                j=q[i];
                q[i]=q[i-1];
                q[i-1]=j;
                kaisu++;
                flag=1;
            }
        }
    }
    for(i=0;i<n;i++){
        if(i<n-1)cout<<q[i]<<' ';
        else cout<<q[i]<<endl;
        
    }
    cout<<kaisu<<endl;
    return 0;
}



