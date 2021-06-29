#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    int b[a]={0};
    for(int i=1;i<=a;i++) cin>>b[i];
    for(int i=1;i<=a;i++){
        int v=b[i];
        int j=i-1;
        while(j>=0&&b[j]>v){
            b[j+1]=b[j];
            j--;
            b[j+1]=v;
        }
        for(int j=1;j<=a;j++){
        if(j==a) cout<<b[j]<<endl;
        else cout<<b[j]<<" ";
        }
    }
}

