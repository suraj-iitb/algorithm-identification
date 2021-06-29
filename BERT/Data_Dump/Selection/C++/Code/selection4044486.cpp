#include<bits/stdc++.h>
using namespace std;
int s(int q[],int n){
    int cont=0,mi;
    for(int i=1;i<=n;i++){
        mi = i;
        for(int j=i;j<=n;j++)
            if(q[mi]>q[j]) mi = j;
        if(i==mi) continue;
        swap(q[i],q[mi]);
        cont++;
    }
    return cont;
}
int main(){
    int n,q[101],c;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>q[i];
    c = s(q,n);
    for(int i=1;i<=n;i++)
        if(i==1) cout<<q[i];
        else cout<<' '<<q[i];
    cout<<endl<<c<<endl;
    return 0;
}
