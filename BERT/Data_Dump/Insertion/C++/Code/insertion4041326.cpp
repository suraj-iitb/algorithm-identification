#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int q[n];
    for(int i=0;i<n;i++)
        cin>>q[i];
    for(int k=0;k<n;k++)
        if(k==n-1) cout<<q[k]<<endl;
        else cout<<q[k]<<' ';
    for(int i=1;i<n;i++){
        int j=i-1,t=q[i];
        while(j>=0 && q[j]>t){
            q[j+1] = q[j];
            j--;
        }
        q[j+1] = t;
        for(int k=0;k<n;k++)
            if(k==n-1) cout<<q[k]<<endl;
            else cout<<q[k]<<' ';
    }
    return 0;
}
