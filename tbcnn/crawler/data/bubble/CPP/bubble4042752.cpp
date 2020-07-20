#include<iostream>
using namespace std;
int s(int q[],int len){
    int cont=0;
    for(int i=0;i<len;i++)
        for(int j=len-1;j>i;j--)
            if(q[j]<q[j-1]){
                swap(q[j],q[j-1]);
                cont++;
            }
    return cont;
}

int main(){
    int n,q[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>q[i];
    int cont = s(q,n);
    for(int i=0;i<n;i++)
        if(i==0) cout<<q[i];
        else cout<<' '<<q[i];
    cout<<endl<<cont<<endl;
    return 0;
}
