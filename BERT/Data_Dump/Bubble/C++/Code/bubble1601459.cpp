#include<iostream>
using namespace std;
int k[9999][999];
main(){int n,s;cin>>n;for(int i=0;i<n;i++){cin>>k[0][i];}
for(int i=0;i<n-1;i++){for(int j=n-2;j>=i;j--){if(k[s][j]>k[s][j+1]){s++;
for(int l=0;l<n;l++){k[s][l]=k[s-1][l];}
k[s][j]=k[s-1][j+1];k[s][j+1]=k[s-1][j];}}}
for(int i=0;i<n;i++){cout<<k[s][i];
if(i<n-1){cout<<' ';}else{cout<<endl;}}cout<<s<<endl;}
